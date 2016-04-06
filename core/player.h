#ifndef __core_player_h__
#define __core_player_h__

#include <vector>
#include <set>

class Card;
class Weapon;
class Minion;
class Player {
public:
	void draw();
	bool isLost();

	void beginTurn();
	void endTurn();
	void equip(Weapon *weapon);
	void summon(Minion *minion, int slot);
	void cast(Card *spell);

private:
	std::vector<Card *> _hand_card;
	std::vector<Card *> _deck_card;
	std::vector<Card *> _minions;
	Card *_hero;
	Card *_hero_power;
	Card *_weapon;
};

#endif
