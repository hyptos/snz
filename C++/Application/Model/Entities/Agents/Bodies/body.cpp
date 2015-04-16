#include "body.hpp"

//Constructeur
Body::Body(double x, double z, double y, double dx, double dz, double dy)
    : m_x(x), m_z(z), m_y(y), m_dx(dx), m_dz(z), m_dy(dy), m_speed(0.0){
}

//Destructeur
Body::~Body(){
}

//Fonction senseur appellée lors du déclenchement d'un son dans l'environnement
void Body::hear(double x, double z, double y, double power){
    //On calcule la distance entre le son et le zombie
    double dist = sqrt(pow(x - m_x, 2) + pow(z - m_z, 2) + pow(y - m_y, 2));

    //Si la puissance du son est assez forte pour que le zombie
    //l'entende de la distance calculée
    if(dist <= power)
        emit hear_something(x, z, y);
}

//Fonction moteur qui indique où aller
void Body::move_to(double x, double z){
    double dist = sqrt(pow(x - m_x, 2) + pow(z - m_z, 2));

    m_dx = (x - m_x) / dist;
    m_dz = (z - m_z) / dist;

    m_speed = 1.0;

    emit direction(m_dx, m_dz, m_dy);
    emit speed(m_speed);
}

//Fonction moteur qui bouge
void Body::move(){

    double old_x = m_x;
    double old_z = m_z;
    double old_y = m_y;

    m_x += m_dx*m_speed;
    m_z += m_dz*m_speed;
    //TODO : gestion de la hauteur

    //Si il y a eu modification des coordonnées
    if(m_x != old_x || m_z != old_z || m_y != old_y)
        emit coordinates(m_x, m_z, m_y);
}

void Body::stop_move(){

    m_speed = 0.0;

    emit speed(m_speed);
}
