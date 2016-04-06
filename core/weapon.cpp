#include "weapon.h"
#include "player.h"
#include "card.h"
#include "effect.h"
#include "engine.h"
#include "event.h"

Weapon::Weapon(int id, int cost, int attack, int durability) :
	Card(id, cost),
	_attack(attack), _durability(durability), _battlecry(nullptr)
{

}

Weapon::~Weapon()
{
	if (_battlecry) {
		delete _battlecry;
	}

	for (Effect *e : _deathrattle) {
		delete e;
	}
}

void Weapon::play(Card *target, int)
{
	this->owner()->engine()->on(kWeaponEquiping, this);

	this->owner()->equip(this);
	this->equip();

	battlecry(target);

	this->owner()->engine()->after(kWeaponEquiping, this);
}

void Weapon::equip()
{

}

void Weapon::battlecry(Card *target)
{
	if (_combo && owner()->isComboStat()) {
		_combo->trigger(target);
		return;
	}

	if (_battlecry) {
		_battlecry->trigger(target);
	}
}
