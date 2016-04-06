#include "spell.h"
#include "effect.h"
#include "player.h"

Spell::Spell(int id, int cost, Effect *effect) : Card(id, cost) , _play(effect)
{
}

void Spell::play(Card *target, int)
{
	if (_play) {
		throw 1;
	}

	this->owner()->cast(this);

	this->_play->trigger(target);
}

bool Spell::canPlay(int resource)
{
	return _play && Card::canPlay(resource);
}
