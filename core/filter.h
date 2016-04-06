#ifndef __core_filter_h__
#define __core_filter_h__

#include <vector>

class Card;
class Player;
class Filter {
	virtual std::vector<Card *> filter(Player *who) = 0;
	virtual bool match(Card *c) = 0;
	virtual bool needTarget() = 0;
};

Filter *RandomEnemy();
Filter *SelectedTarget();
Filter *EnemyHero();
Filter *RandomMinion();
Filter *RandomEnemyMinion();
Filter *EnemyTarget();
Filter *YourMinion();
Filter *EnemyMinionTarget();

#endif // FILTER_H
