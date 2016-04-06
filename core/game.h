#ifndef __core_game_h__
#define __core_game_h__

#include <set>
#include <array>
#include <vector>
#include "event.h"

class Effect;
class Player;
class Card;
class Game {
public:
	void registerEvent(KnownEvent e, Effect *effect);
	void unregisterEvent(KnownEvent e, Effect *effect);

public:
	void fire(KnownEvent e, Card *card);

private:
	std::array<std::set<Effect *>, kEventMax> _effects;
	std::vector<Card *> _all_cards;
	Player *_player1;
	Player *_player2;
};

#endif
