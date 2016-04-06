#include "weapon.h"
#include "player.h"
#include "card.h"
#include "effect.h"

Weapon::Weapon(int id, int cost, int attack, int durability) : Card(id, cost), _attack(attack), _durability(durability)
{

}

Weapon::~Weapon()
{
	for (Effect *e : _battlecry) {
		delete e;
	}

	for (Effect *e : _deathrattle) {
		delete e;
	}
}

void Weapon::play(Card *, int )
{
	this->owner()->equip(this);
}

void Weapon::equip()
{

}
