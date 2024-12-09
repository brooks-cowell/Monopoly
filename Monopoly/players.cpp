#include "players.h"
#include <algorithm>

Player::Player(const std::string& name, int startingMoney)
    : m_name(name),
    m_money(startingMoney),
    m_position(0),
    m_bankrupt(false)
{}

const std::string& Player::getName() const {
    return m_name;
}

int Player::getMoney() const {
    return m_money;
}

int Player::getPosition() const {
    return m_position;
}

bool Player::isBankrupt() const {
    return m_bankrupt;
}

void Player::move(int steps, int boardSize) {
    m_position += steps;
    m_position = (m_position % boardSize + boardSize) % boardSize;
}

void Player::adjustMoney(int amount) {
    m_money += amount;
    if (m_money < 0) {
        // In a full game, might handle bankruptcy checks here
        // For now, just let negative money stand (or you could auto declare bankruptcy)
    }
}

void Player::setPosition(int position) {
    m_position = position;
}

void Player::declareBankrupt() {
    m_bankrupt = true;
    m_money = 0;
    m_properties.clear();
}

void Player::addProperty(std::shared_ptr<Property> property) {
    if (property && !ownsProperty(property)) {
        m_properties.push_back(property);
    }
}

void Player::removeProperty(std::shared_ptr<Property> property) {
    m_properties.erase(
        std::remove(m_properties.begin(), m_properties.end(), property),
        m_properties.end()
    );
}

const std::vector<std::shared_ptr<Property>>& Player::getOwnedProperties() const {
    return m_properties;
}

int Player::getNumberOfOwnedProperties() const {
    return (int)m_properties.size();
}

bool Player::canAfford(int amount) const {
    return m_money >= amount;
}

bool Player::ownsProperty(std::shared_ptr<Property> property) const {
    return std::find(m_properties.begin(), m_properties.end(), property) != m_properties.end();
}
