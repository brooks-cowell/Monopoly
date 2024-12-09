#ifndef MONOPOLYBOARD_H
#define MONOPOLYBOARD_H

#include "property.h"
#include <vector>
#include <string>

class MonopolyBoard {
public:
    MonopolyBoard();
    void displayProperties() const;
    Property getPropertyByPosition(int pos) const;
    int getBoardSize() const;

private:
    std::vector<Property> properties;
};

#endif // MONOPOLYBOARD_H
