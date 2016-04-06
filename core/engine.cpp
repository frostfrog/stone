#include "engine.h"
#include "effect.h"


void Engine::registerOnEvent(KnownEvent e, Effect *effect)
{
	_effects[e].insert(effect);
}

void Engine::unregisterOnEvent(KnownEvent e, Effect *effect)
{
	_effects[e].erase(effect);
}

void Engine::registerAfterEvent(KnownEvent e, Effect *effect)
{
	_after_effects[e].insert(effect);
}

void Engine::unregisterAfterEvent(KnownEvent e, Effect *effect)
{
	_after_effects[e].erase(effect);
}

void Engine::on(KnownEvent e, Card *card)
{
	for (Effect *effect: _effects[e]) {
		effect->trigger(card);
	}
}

void Engine::after(KnownEvent e, Card *card)
{
	for (Effect *effect: _after_effects[e]) {
		effect->trigger(card);
	}
}

int Engine::rand(int max)
{
	return ::rand() % max;
}
