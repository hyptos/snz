#include "agent.hpp"


//Constructeur
Agent::Agent(unsigned long id, EntityType type, EntityState state, double x, double y, double dx, double dy, Body* body, Brain* brain)
    : Entity(id, type, state, x, y, dx, dy), m_speed(0.0), m_body(body), m_brain(brain){

    //Connections Body->Brain
    QObject::connect(m_body, SIGNAL(hear_something(double,double)), m_brain, SLOT(something_heard(double,double)));

    //Connections Brain->Body
    QObject::connect(m_brain, SIGNAL(move_body_move()), m_body, SLOT(move()));
    QObject::connect(m_brain, SIGNAL(lets_go_to(double,double)), m_body, SLOT(move_to(double,double)));

    //Connection Body->Agent
    QObject::connect(body, SIGNAL(coordinates(double,double)), this, SLOT(setCoordinate(double,double)));
    QObject::connect(body, SIGNAL(direction(double,double)), this, SLOT(setDirection(double,double)));
    QObject::connect(body, SIGNAL(speed(double)), this, SLOT(setSpeed(double)));
}

//Destructeur
Agent::~Agent(){
}

double Agent::getSpeed() const{
    return m_speed;
}

//Retourne le pointeur sur le Body de l'agent
Body* Agent::getBody(){
    return m_body;
}

//Retourne le pointeur sur le Brain de l'agent
Brain* Agent::getBrain(){
    return m_brain;
}

void Agent::setSpeed(double speed){
    m_speed = speed;

    emitInfo();
}

//Génére et emet les info de l'agent
void Agent::emitInfo(){
    InfoAgent m_info(m_id, m_type, m_state, m_x, m_y, m_dx, m_dy, m_speed);
    emit info(m_info);
}
