#include "body.hpp"

//Constructeur
Body::Body(double x, double y, double dx, double dy)
    : m_x(x), m_y(y), m_dx(dx), m_dy(dy), m_speed(0.0){
}

//Destructeur
Body::~Body(){
}

//Fonction senseur appellée lors du déclenchement d'un son dans l'environnement
void Body::hear(double x, double y, double power){
    //On calcule la distance entre le son et le zombie
    double dist = sqrt(pow(x - m_x, 2) + pow(y - m_y, 2));

    //Si la puissance du son est assez forte pour que le zombie
    //l'entende de la distance calculée
    if(dist <= power)
        emit hear_something(x, y);
}

//Fonction moteur qui indique où aller
void Body::move_to(double x, double y){
    double dist = sqrt(pow(x - m_x, 2) + pow(y - m_y, 2));

    m_dx = (x - m_x) / dist;
    m_dy = (y - m_y) / dist;

    m_speed = 1.0;

    emit direction(m_dx, m_dy);
    emit speed(m_speed);
}

//Fonction moteur qui bouge
void Body::move(){

    double old_x = m_x;
    double old_y = m_y;

    m_x += m_dx*m_speed;
    m_y += m_dy*m_speed;

    //Si il y a eu modification des coordonnées
    if(m_x != old_x || m_y != old_y)
        emit coordinates(m_x, m_y);
}

void Body::stop_move(){

    m_speed = 0.0;

    emit speed(m_speed);
}
