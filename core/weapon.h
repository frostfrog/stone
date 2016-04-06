#ifndef __core_minion_h__
#define __core_minion_h__

#include "card.h"
#include <vector>

class Weapon : public Card {
public:
	Weapon(int id, int cost, int attack, int durability);
	~Weapon();
public:
	virtual void play(Card *, int) override;
	virtual void equip();

protected:
	int _attack;
	int _durability;
	std::vector<Effect *> _battlecry;
	std::vector<Effect *> _deathrattle;
};

#endif
