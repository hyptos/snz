#include "player.hpp"

Player::Player(unsigned long id, EntityType type, EntityState state, double x, double y, double dx, double dy)
	: Entity(id, type, state, x, y, dx, dy) {
}

Player::~Player(){}
