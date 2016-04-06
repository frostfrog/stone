#include "player.h"
#include "card.h"
#include "engine.h"
#include "event.h"
#include "minion.h"
#include "weapon.h"

#include <algorithm>

Player::Player(Engine *game) : _engine(game)
{

}

Player::~Player()
{

}

void Player::draw()
{
	_engine->on(kCardDrawing, _hero);

	int index = _engine->rand(_deck_cards.size());

	if (_deck_cards[index] != _deck_cards.back()) {
		std::swap(_deck_cards[index], _deck_cards.back());
	}

	_hand_card.push_back(_deck_cards.back());

	_deck_cards.pop_back();

	_engine->after(kCardDrawing, _hero);
}

bool Player::isLost()
{
	return _hero->isDead();
}

void Player::beginTurn()
{
	_engine->on(kTurnBegining, this->_hero);

	for (Minion* m : _minions) {
		m->beginTurn();
	}

	if (_max_resource < 10) {
		_max_resource += 1;
	}

	_resource = _max_resource;
	_overloaded_resource = _overloading_resource;
	_overloading_resource = 0;
	_card_played_this_turn = 0;

	this->draw();

	_engine->after(kTurnBegining, this->_hero);
}

void Player::endTurn()
{
	_engine->on(kTurnEnding, this->_hero);

	for (Minion* m : _minions) {
		m->endTurn();
	}

	_engine->after(kTurnEnding, this->_hero);
}

void Player::playCard(Card *card, Card *target, int slot)
{
	std::vector<Card *>::iterator it = std::find(_hand_card.begin(), _hand_card.end(), card);

	_engine->on(kCardPlaying, card);

	card->play(target, slot);

	_hand_card.erase(it);

	_engine->after(kCardPlaying, card);
}

void Player::summon(Minion *minion, int slot)
{
	_minions.insert(_minions.begin() + slot, minion);
}

void Player::equip(Weapon *weapon)
{
	this->_weapon = weapon;
}

size_t Player::minionCount()
{
	return this->_minions.size();
}

void Player::setOpponent(Player *opp)
{
	_opp = opp;
}

Player *Player::opp()
{
	return _opp;
}

bool Player::isComboStat()
{
	return _card_played_this_turn > 0;
}

Engine *Player::engine()
{
	return _engine;
}
