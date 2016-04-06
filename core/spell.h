#ifndef __core_spell_h__
#define __core_spell_h__

#include "card.h"

class Spell : public Card {
public:
	Spell(int id, int cost, Effect *effect);
public:
	virtual void play(Card *target, int pos) override;
};

#endif
