#include "infoentity.hpp"

//Constructeur
InfoEntity::InfoEntity(const unsigned long& entity, const EntityType &type, const EntityState& state, const double& x, const double& y, const double &dx, const double &dy)
    : m_entity(entity), m_type(type), m_state(state), m_x(x), m_y(y), m_dx(dx), m_dy(dy){
}

//Destructeur
InfoEntity::~InfoEntity(){
}

//Retourne l'id de l'entité
unsigned long InfoEntity::getEntity(){
	return m_entity;
}

//Retourne le type de l'entité
EntityType InfoEntity::getType(){
    return m_type;
}

//Retourne l'état de l'entité
EntityState InfoEntity::getState(){
    return m_state;
}

//Retourne la coordonnée X de l'entité dans l'environnement
double InfoEntity::getX(){
    return m_x;
}

//Retourne la coordonnée Y de l'entité dans l'environnement
double InfoEntity::getY(){
    return m_y;
}

//Retourne la coordonnée X du vecteur direction de l'entité
double InfoEntity::getDX(){
    return m_dx;
}

//Retourne la coordonnée Y du vecteur direction de l'entité
double InfoEntity::getDY(){
    return m_dy;
}
