#ifndef __core_minion_h__
#define __core_minion_h__

#include "card.h"
#include <vector>

class Effect;
class Minion : public Card {
public:
	Minion(int id, int cost, int attack, int health);

public:
	virtual void play(Card *target, int slot) override;
	virtual void summon();

protected:
	std::vector<Effect *> _battlecry;
	std::vector<Effect *> _deathrattle;
	int _attack;
	int _health;
};

#endif
