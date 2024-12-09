#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <memory>
#include "property.h"

class Player {
public:
    Player(const std::string& name, int startingMoney = 1500);
    const std::string& getName() const;
    int getMoney() const;
    int getPosition() const;
    bool isBankrupt() const;
    void move(int steps, int boardSize);
    void adjustMoney(int amount);
    void setPosition(int position);
    void declareBankrupt();
    void addProperty(std::shared_ptr<Property> property);
    void removeProperty(std::shared_ptr<Property> property);
    const std::vector<std::shared_ptr<Property>>& getOwnedProperties() const;
    int getNumberOfOwnedProperties() const;
    bool canAfford(int amount) const;
    bool ownsProperty(std::shared_ptr<Property> property) const;

private:
    std::string m_name;
    int m_money;
    int m_position;
    bool m_bankrupt;
    std::vector<std::shared_ptr<Property>> m_properties;
};

#endif // PLAYER_H
