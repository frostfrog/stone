#include "spell.h"
#include "effect.h"
#include "player.h"
#include "engine.h"
#include "event.h"

Spell::Spell(int id, int cost, Effect *effect) : Card(id, cost) , _play(effect)
{
}

void Spell::play(Card *target, int)
{
	if (_play) {
		throw 1;
	}
	this->owner()->engine()->on(kSpellCasting, this);

	this->_play->trigger(target);

	this->owner()->engine()->on(kSpellCasting, this);
}

bool Spell::canPlay(int resource)
{
	return _play && Card::canPlay(resource);
}
