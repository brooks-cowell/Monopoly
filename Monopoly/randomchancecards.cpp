#include "randomchancecards.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

RandomChanceCards::RandomChanceCards() {
    srand((unsigned)time(NULL));
    shuffleChanceDeck();
    shuffleCommunityChestDeck();
}

RandomChanceCards::~RandomChanceCards() {}

void RandomChanceCards::drawChanceCard(Player& player) {
    if (chanceDeck.empty()) {
        cout << "Reshuffling Chance Deck...\n";
        shuffleChanceDeck();
    }

    int randomIndex = rand() % chanceDeck.size();
    Card drawnCard = chanceDeck[randomIndex];

    int cardLength = (int)drawnCard.description.size();
    for (int i = 0; i < cardLength + 4; i++) cout << "-";
    cout << "\n|" << setw(cardLength + 3) << "|\n";
    cout << "| " << drawnCard.description << " |\n";
    cout << "|" << setw(cardLength + 3) << "|\n";
    for (int i = 0; i < cardLength + 4; i++) cout << "-";
    cout << endl;

    cout << "Money Change: " << drawnCard.moneyChange << endl;
    player.adjustMoney(drawnCard.moneyChange);
    cout << player.getName() << "'s new balance: $" << player.getMoney() << endl;

    chanceDeck.erase(chanceDeck.begin() + randomIndex);
}

void RandomChanceCards::drawCommunityChestCard(Player& player) {
    if (communityChestDeck.empty()) {
        cout << "Reshuffling Community Chest Deck...\n";
        shuffleCommunityChestDeck();
    }

    int randomIndex = rand() % communityChestDeck.size();
    Card drawnCard = communityChestDeck[randomIndex];

    int cardLength = (int)drawnCard.description.size();
    for (int i = 0; i < cardLength + 4; i++) cout << "-";
    cout << "\n|" << setw(cardLength + 3) << "|\n";
    cout << "| " << drawnCard.description << " |\n";
    cout << "|" << setw(cardLength + 3) << "|\n";
    for (int i = 0; i < cardLength + 4; i++) cout << "-";
    cout << endl;

    cout << "Money Change: " << drawnCard.moneyChange << endl;
    player.adjustMoney(drawnCard.moneyChange);
    cout << player.getName() << "'s new balance: $" << player.getMoney() << endl;

    communityChestDeck.erase(communityChestDeck.begin() + randomIndex);
}

void RandomChanceCards::shuffleChanceDeck() {
    chanceDeck = {
      {"Advance to Go", 200 },
      {"Advance to Nearest Railroad", 0},
      {"Advance to Nearest Utility", 0},
      {"You Have Become Addicted to Gambling Lose $200", -200 },
      {"You Have Won a Beauty Contest Collect $100", 100},
      {"Invested in the wrong cryptocurrency. Lose $100.", -100},
      {"Stuck in traffic. Lose one turn.", 0},
      {"Your smart home malfunctions. Pay $50." , -50},
      {"Random security check. Pay $50." , -50},
      {"Upgrade console. Pay $300." , -300},
      {"Right crypto investment. Collect $100.", 100},
      {"Won in the Casino. Collect $200", 200},
    };
}

void RandomChanceCards::shuffleCommunityChestDeck() {
    communityChestDeck = {
      {"GoFundMe successful. Collect $200", 200},
      {"Cancelled. Pay $200.", -200},
      {"Order arrives early! Move forward 3 spaces", 0},
      {"Renew subscription. Pay $15.", -15},
      {"5-star shop rating! Collect $50.", 50},
      {"Car repair needed. Pay $200.", -200},
      {"Pet internet star! Collect $100.", 100},
      {"Binge-watching. Lose one turn.", 0},
      {"New restaurant. Pay $30.", -30},
      {"Forgotten IOU repaid. Collect $20.", 20},
    };
}
