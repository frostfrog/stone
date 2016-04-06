#include "minion.h"
#include "effect.h"
#include "player.h"
#include "engine.h"

Minion::Minion(int id, int cost, int attack, int health) :
	Card(id, cost), _battlecry(nullptr),
	_attack(attack), _health(health), _hp(0), _attack_times_this_turn(0), _just_summon(0)
{

}

Minion::~Minion()
{
	delete _battlecry;

	for (Effect *e : _deathrattle) {
		delete e;
	}
}

void Minion::play(Card *target, int slot)
{
	owner()->engine()->on(kMinionSummoning, this);

	_hp = _health;
	_just_summon = 1;

	summon();

	owner()->summon(this, slot);

	battlecry(target);

	owner()->engine()->after(kMinionSummoning, this);
}

void Minion::summon()
{

}

void Minion::beginTurn()
{
	Card::beginTurn();

	_just_summon = 0;
	_attack_times_this_turn = 0;
}

void Minion::battlecry(Card *target)
{
	if (_combo && owner()->isComboStat()) {
		_combo->trigger(target);

		return;
	}

	if (_battlecry) {
		_battlecry->trigger(target);
	}
}

bool Minion::isDead()
{
	return _hp <= 0;
}

bool Minion::canPlay(int resource)
{
	return Card::canPlay(resource) && owner()->minionCount() < 0;
}
