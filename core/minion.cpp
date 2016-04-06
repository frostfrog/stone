#include "minion.h"
#include "effect.h"
#include "player.h"

Minion::Minion(int id, int cost, int attack, int health) : Card(id, cost), _attack(attack), _health(health)
{

}

Minion::~Minion()
{
	for (Effect *e : _battlecry) {
		delete e;
	}

	for (Effect *e : _deathrattle) {
		delete e;
	}
}

void Minion::play(Card *target, int slot)
{
	this->owner()->summon(this, slot);
	battlecry(target);
	// fire summon event
}

void Minion::summon()
{
	this->_hp = this->_health;
}

void Minion::beginTurn()
{
	Card::beginTurn();

	_just_summon = 0;
	_attack_times_this_turn = 0;
}

void Minion::battlecry(Card *target)
{
	for (Effect *e : _battlecry) {
		e->trigger(target);
	}
}
