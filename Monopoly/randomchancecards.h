#ifndef RANDOMCHANCECARDS_H
#define RANDOMCHANCECARDS_H

#include <string>
#include <vector>
#include "players.h"

class RandomChanceCards {
public:
    RandomChanceCards();
    ~RandomChanceCards();
    void drawChanceCard(Player& player);
    void drawCommunityChestCard(Player& player);
    void shuffleChanceDeck();
    void shuffleCommunityChestDeck();

private:
    struct Card {
        std::string description;
        int moneyChange;
    };

    std::vector<Card> chanceDeck;
    std::vector<Card> communityChestDeck;
};

#endif // RANDOMCHANCECARDS_H
