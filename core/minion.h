#ifndef __core_minion_h__
#define __core_minion_h__

#include "card.h"
#include <vector>

class Effect;
class Minion : public Card {
public:
	Minion(int id, int cost, int attack, int health);
	~Minion();
public:
	virtual void play(Card *target, int slot) override;
	virtual void summon();
	virtual void beginTurn() override;

	void attack(Minion *target);
	void takeDamange(int damange);
	void battlecry(Card *target);
	bool isDead();

	bool canPlay(int resource);

protected:
	Effect * _battlecry;
	std::vector<Effect *> _deathrattle;
	int _attack;
	int _health;
	int _hp;
	int _attack_times_this_turn;
	int _just_summon;
};

#endif
