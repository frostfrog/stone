#ifndef __core_card_h__
#define __core_card_h__

#include <vector>

class Effect;
class Player;
class Engine;
class Card {
public:
	Card(int id, int cost);
	virtual ~Card();
public:
	virtual void play(Card *target, int slot) = 0;
	Player *owner() const;
	void setOwner(Player *o);

	virtual bool canPlay(int resource);
	virtual void beginTurn();
	virtual void endTurn();
protected:
	std::vector<Effect *> _effects;
	std::vector<Effect *> _one_turn_effects;

	int _id;
	int _cost;
	Effect *_combo;
	Player *_owner;
};

#endif
