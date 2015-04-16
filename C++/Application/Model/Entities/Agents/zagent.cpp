#include "zagent.hpp"

//Constructeur
ZAgent::ZAgent(unsigned long long id, double x, double z, double y, double dx, double dz, double dy)
    : Agent(id, EntityType::ZOMBIE, EntityState::NORMAL, x, z, y, dx, dz, dy, new Body(x, y, z, dx, dz, dy), new ZBrain){
}

//Destructeur
ZAgent::~ZAgent(){

    //Destruction des éléments de l'agent
    delete m_brain;
    delete m_body;
}
