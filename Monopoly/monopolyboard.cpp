#include "monopolyboard.h"
#include <iostream>
using namespace std;

MonopolyBoard::MonopolyBoard() {
    properties = {
        {"Mediterranean Avenue", 60, 1},
        {"Baltic Avenue", 60, 3}, {"Reading Railroad", 200, 5},
        {"Oriental Avenue", 100, 6}, {"Vermont Avenue", 120, 8},
        {"Connecticut Avenue", 140, 9}, {"St. Charles Place", 140, 11},
        {"Electric Company", 150, 12}, {"States Avenue", 140, 13}, {"Virginia Avenue", 160, 14},
        {"Pennsylvania Railroad", 200, 15}, {"St. James Place", 180, 16},
        {"Tennessee Avenue", 180, 18}, {"New York Avenue", 200, 19},
        {"Kentucky Avenue", 220, 21},  {"Indiana Avenue", 220, 23},
        {"Illinois Avenue", 240, 24}, {"B&O Railroad", 200, 25}, {"Atlantic Avenue", 260, 26},
        {"Ventnor Avenue", 280, 27}, {"Water Works", 150, 28}, {"Marvin Gardens", 300, 29},
        {"Pacific Avenue", 320, 31}, {"North Carolina Avenue", 350, 32},
        {"Pennsylvania Avenue", 350, 33}, {"Short Line Railroad", 200, 35},
        {"Park Place", 350, 37}, {"Boardwalk", 400, 39}
    };
}

void MonopolyBoard::displayProperties() const {
    cout << "Monopoly Properties: " << endl;
    for (const auto& property : properties) {
        cout << "Position: " << property.position << ", "
            << "Name: " << property.name << ", "
            << "Value: $" << property.value << endl;
    }
}

Property MonopolyBoard::getPropertyByPosition(int pos) const {
    for (const auto& property : properties) {
        if (property.position == pos) {
            return property;
        }
    }
    // Return dummy if not found
    return Property{ "Unknown", 0, -1 };
}

int MonopolyBoard::getBoardSize() const {
    // Standard Monopoly board size is 40 positions (0 to 39)
    return 40;
}
