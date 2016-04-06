#ifndef __core_filter_h__
#define __core_filter_h__

#include <vector>

class Card;
class Filter {
	virtual std::vector<Card *> filter(Player &who) = 0;
};

#endif // FILTER_H
