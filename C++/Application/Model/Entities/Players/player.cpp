#include "player.hpp"

Player::Player(unsigned long long id, EntityType type, EntityState state, double x, double z, double y, double dx, double dz, double dy)
    : Entity(id, type, state, x, z, y, dx, dz, dy) {
}

Player::~Player(){}
