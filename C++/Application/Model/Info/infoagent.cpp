#include "infoagent.hpp"

//Constructeur
InfoAgent::InfoAgent(const EntityType &type, const EntityState &state, const double &x, const double &y, const double &dx, const double &dy, const double &speed)
    : InfoEntity(type, state, x, y, dx, dy), m_speed(speed){
}

//Destructeur
InfoAgent::~InfoAgent(){
}

//Retourne la vitesse de l'agent
double InfoAgent::getSpeed(){
    return m_speed;
}
