#include "infoagent.hpp"

//Constructeur
InfoAgent::InfoAgent(const unsigned long& entity, const EntityType &type, const EntityState &state, const double &x, const double &y, const double &dx, const double &dy, const double &speed)
    : InfoEntity(entity, type, state, x, y, dx, dy), m_speed(speed){
}

//Destructeur
InfoAgent::~InfoAgent(){
}

//Retourne la vitesse de l'agent
double InfoAgent::getSpeed(){
    return m_speed;
}
