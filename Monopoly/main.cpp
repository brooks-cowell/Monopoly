#include <iostream>
#include <cstdlib>
#include <ctime>
#include "monopolyboard.h"
#include "players.h"
#include "randomchancecards.h"
#include "gamepieces.h"

using namespace std;

int main() {
    srand((unsigned)time(NULL));

    cout << "Welcome to Monopoly!\n";
    cout << "How many players (2-4)? ";
    int numPlayers;
    cin >> numPlayers;
    if (numPlayers < 2 || numPlayers > 4) {
        cout << "Invalid number of players.\n";
        return 0;
    }

    // Select game pieces
    vector<string> pieces = selectGamePieces(numPlayers);

    // Create players
    vector<Player> players;
    for (int i = 0; i < numPlayers; i++) {
        // Player name could be "Player 1", or prompt for name
        string playerName = "Player " + to_string(i+1) + " (" + pieces[i] + ")";
        players.push_back(Player(playerName));
    }

    MonopolyBoard board;
    RandomChanceCards cards;

    cout << "\nInitial player standings:\n";
    for (auto &p : players) {
        cout << p.getName() << " - Money: $" << p.getMoney() << " Position: " << p.getPosition() << endl;
    }

    cout << "\nProperties on the board:\n";
    board.displayProperties();

    // Simple game loop for a few turns
    int turnCount = 1;
    int boardSize = board.getBoardSize();
    while (turnCount <= 5) { // Just do 5 turns total for demonstration
        cout << "\n--- Turn " << turnCount << " ---\n";
        for (int i = 0; i < numPlayers; i++) {
            if (players[i].isBankrupt()) {
                cout << players[i].getName() << " is bankrupt and cannot move.\n";
                continue;
            }

            cout << players[i].getName() << "'s turn. Press enter to roll dice.\n";
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin.get(); // wait for user

            int diceRoll = (rand() % 6 + 1) + (rand() % 6 + 1);
            cout << players[i].getName() << " rolled a " << diceRoll << "!\n";
            players[i].move(diceRoll, boardSize);
            int pos = players[i].getPosition();
            cout << players[i].getName() << " lands on position " << pos << ".\n";

            // Check if landed on property
            Property landedProp = board.getPropertyByPosition(pos);
            if (landedProp.position == pos && landedProp.position != -1) {
                cout << players[i].getName() << " lands on " << landedProp.name << " (cost $" << landedProp.value << ")\n";
                if (players[i].canAfford(landedProp.value)) {
                    cout << players[i].getName() << " buys " << landedProp.name << " for $" << landedProp.value << ".\n";
                    players[i].adjustMoney(-landedProp.value);
                    // Add property ownership
                    players[i].addProperty(std::make_shared<Property>(landedProp));
                } else {
                    cout << players[i].getName() << " cannot afford this property.\n";
                }
            } else {
                cout << players[i].getName() << " landed on a non-property space.\n";
            }

            // Chance or Community Chest example:
            if (pos == 7) { 
                cout << players[i].getName() << " landed on Chance!\n";
                cards.drawChanceCard(players[i]);
            }
            if (pos == 2) {
                cout << players[i].getName() << " landed on Community Chest!\n";
                cards.drawCommunityChestCard(players[i]);
            }

            cout << players[i].getName() << " now has $" << players[i].getMoney() << "\n";
        }
        turnCount++;
    }

    cout << "\n--- Game Over ---\n";
    for (auto &p : players) {
        cout << p.getName() << " ended with $" << p.getMoney() << " and owns "
             << p.getNumberOfOwnedProperties() << " properties.\n";
    }

    return 0;
}
