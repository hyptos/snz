#include "infoagent.hpp"

//Constructeur
InfoAgent::InfoAgent(const unsigned long long& entity, const EntityType &type, const EntityState &state, const double &x, const double &z, const double &y, const double &dx, const double &dz, const double &dy, const double &speed)
    : InfoEntity(entity, type, state, x, z, y, dx, dz, dy), m_speed(speed){
}

//Destructeur
InfoAgent::~InfoAgent(){
}

//Retourne la vitesse de l'agent
double InfoAgent::getSpeed(){
    return m_speed;
}
