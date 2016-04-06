#ifndef __core_engine_h__
#define __core_engine_h__

#include <set>
#include <array>
#include <vector>
#include "event.h"

class Effect;
class Player;
class Card;
class Engine {
public:
	void registerOnEvent(KnownEvent e, Effect *effect);
	void unregisterOnEvent(KnownEvent e, Effect *effect);

	void registerAfterEvent(KnownEvent e, Effect *effect);
	void unregisterAfterEvent(KnownEvent e, Effect *effect);

public:
	void on(KnownEvent e, Card *card);
	void after(KnownEvent e, Card *card);

	int rand(int max);

private:
	std::array<std::set<Effect *>, kEventMax> _effects;
	std::array<std::set<Effect *>, kEventMax> _after_effects;
	std::vector<Card *> _all_cards;
	Player *_player1;
	Player *_player2;
};

#endif
