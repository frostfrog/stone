#ifndef __core_effect_h__
#define __core_effect_h__

#include "event.h"

class Filter;
class Effect {
public:
	Effect();
	virtual ~Effect();
public:
	// registers
	Effect *after(KnownEvent event, Filter *filter);
	Effect *on(KnownEvent event, Filter *filter);
	Effect *has(KnownEvent event, Filter *filter);
	virtual void trigger(Player *who, Card *what) = 0;

	void unregister();
	virtual bool needTarget() = 0;
};


Effect *DealDamage(int damage, Filter *filter);
Effect *DrawCard(int number, Filter *filter);
Effect *Destroy(int number, Filter *filter);
Effect *Give(int attack, int health, Filter *filter, ...);
Effect *Restore(int hp, Filter *filter);
Effect *Summon(int id, int amount);

#endif
