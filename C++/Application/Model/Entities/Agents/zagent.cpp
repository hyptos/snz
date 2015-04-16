#include "zagent.hpp"

//Constructeur
ZAgent::ZAgent(unsigned long id, double x, double y, double dx, double dy)
    : Agent(id, EntityType::ZOMBIE, EntityState::NORMAL, x, y, dx, dy, new Body(x, y, dx, dy), new ZBrain){
}

//Destructeur
ZAgent::~ZAgent(){

    //Destruction des éléments de l'agent
    delete m_brain;
    delete m_body;
}
