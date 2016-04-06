#include "card.h"
#include "effect.h"

Card::Card(int id, int cost) : _id(id), _cost(cost)
{

}

Card::~Card()
{
	for (Effect *e: _effects) {
		delete e;
	}
}

Player *Card::owner() const
{
	return _owner;
}

void Card::setOwner(Player *o)
{
	_owner = o;
}

bool Card::canPlay(int resource)
{
	return resource >= _cost;
}

void Card::beginTurn()
{

}

void Card::endTurn()
{
	for (Effect *e: _one_turn_effects) {
		delete e;
	}
}
