#include "gamepieces.h"
#include <iostream>
#include <limits>
using namespace std;

string selectGamePiece() {
    int choice;
    while (true) {
        cout << "Select a game piece:\n"
            << "1. Dog\n"
            << "2. Car\n"
            << "3. Hat\n"
            << "4. Ship\n"
            << "5. Thimble\n"
            << "6. Boot\n"
            << "7. Wheelbarrow\n"
            << "8. Iron\n"
            << "Enter your choice (1-8): ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (choice) {
        case 1: return "Dog";
        case 2: return "Car";
        case 3: return "Hat";
        case 4: return "Ship";
        case 5: return "Thimble";
        case 6: return "Boot";
        case 7: return "Wheelbarrow";
        case 8: return "Iron";
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}

std::vector<std::string> selectGamePieces(int numPlayers) {
    std::vector<std::string> chosenPieces;
    for (int i = 0; i < numPlayers; ++i) {
        cout << "Player " << i + 1 << ", ";
        string piece = selectGamePiece();

        bool taken = false;
        for (auto& p : chosenPieces) {
            if (p == piece) {
                taken = true;
                break;
            }
        }

        if (taken) {
            cout << "That piece is already taken. Try again.\n";
            i--;
        }
        else {
            chosenPieces.push_back(piece);
            cout << "Player " << i + 1 << " selected " << piece << ".\n";
        }
    }
    return chosenPieces;
}
