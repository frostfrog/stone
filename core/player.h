#ifndef __core_player_h__
#define __core_player_h__

#include <vector>
#include <set>
#include <inttypes.h>

class Card;
class Weapon;
class Minion;
class Spell;
class Engine;
class Player {
public:
	Player(Engine *_engine);
	~Player();
public:
	void draw();
	bool isLost();

	void beginTurn();
	void endTurn();

	void playCard(Card *hand_card, Card *target, int slot = -1);

	void summon(Minion *minion, int slot);
	void equip(Weapon *weapon);

	size_t minionCount();
	void setOpponent(Player *opp);
	Player *opp();

	bool isComboStat();

	Engine *engine();

	int availableResource() {
		return _resource - _overloaded_resource;
	}

private:
	std::vector<Card *> _hand_card;
	std::vector<Card *> _deck_cards;
	std::vector<Minion *> _minions;
	Minion *_hero;
	Spell *_hero_power;
	Weapon *_weapon;
	Engine *_engine;
	Player *_opp;

	int _resource;
	int _max_resource;
	int _overloading_resource;
	int _overloaded_resource;
	int _card_played_this_turn;
};

#endif
