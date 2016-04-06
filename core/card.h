#ifndef __core_card_h__
#define __core_card_h__

#include <vector>

class Effect;
class Player;
class Card {
public:
	Card(int id, int cost);
	virtual ~Card();
public:
	virtual void play(Card *target, int slot) = 0;
	Player *owner() const;
	void setOwner(Player *o);
protected:
	std::vector<Effect *> _effects;
	int _id;
	int _cost;
	Player *_owner;
};

#endif
