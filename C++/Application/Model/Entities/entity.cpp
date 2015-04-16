#include "entity.hpp"

//Constructeur
Entity::Entity(unsigned long id, EntityType type, EntityState state, double x, double y, double dx, double dy)
    : m_id(id), m_type(type), m_state(state), m_x(x), m_y(y), m_dx(dx), m_dy(dy){
}

//Destructeur
Entity::~Entity(){
}

//Retourne l'id de l'entité
unsigned long Entity::getId() const{
    return m_id;
}

//Retourne le type de l'entité
EntityType Entity::getType() const{
    return m_type;
}

//Retourne l'état de l'entité
EntityState Entity::getState() const{
    return m_state;
}

//Retourne la coordonnée X de l'entité dans l'environnement
double Entity::getX() const{
    return m_x;
}

//Retourne la coordonnée Y de l'entité dans l'environnement
double Entity::getY() const{
    return m_y;
}

//Retourne la coordonnée X du vecteur direction de l'entité
double Entity::getDX() const{
    return m_dx;
}

//Retourne la coordonnée Y du vecteur direction de l'entité
double Entity::getDY() const{
    return m_dy;
}

//Modifie l'id de l'entité
void Entity::setId(unsigned long id){
    m_id = id;

    emitInfo();
}

//Modifie l'état de l'entité
void Entity::setState(EntityState state){
    m_state = state;

    emitInfo();
}

//Modifie la coordonnée X de l'entité dans l'environnement
void Entity::setX(double x){
    m_x = x;

    emitInfo();
}

//Modifie la coordonnée Y de l'entité dans l'environnement
void Entity::setY(double y){
    m_y = y;

    emitInfo();
}

//Modifie la coordonnée X du vecteur direction de l'entité
void Entity::setDX(double dx){
    m_dx = dx;

    emitInfo();
}

//Modifie la coordonnée Y du vecteur direction de l'entité
void Entity::setDY(double dy){
    m_dy = dy;

    emitInfo();
}

//Modifie les coordonnée X et Y de l'entité dans l'environnement
void Entity::setCoordinate(double x, double y){
    m_x = x;
    m_y = y;

    emitInfo();
}

//Modifie les coordonnée X et Y du vecteur direction de l'entité
void Entity::setDirection(double dx, double dy){
    m_dx = dx;
    m_dy = dy;

    emitInfo();
}

//Génére et émet les info concernant l'entité
void Entity::emitInfo(){

    InfoEntity m_info(m_id, m_type, m_state, m_x, m_y, m_dx, m_dy);

    emit info(m_info);
}
