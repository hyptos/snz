#include "model.hpp"

//Constructeur
SNZ_Model::SNZ_Model(int size, int nbZ)
    : m_envX(size), m_envY(size), m_nbEntities(0){

    std::srand(std::time(NULL));

    for(int i = 0 ; i < nbZ ; i++){

        //Création de l'agent
        ZAgent* zagent = new ZAgent(m_nbEntities++, rand() % size, rand() % size, 0.35, -0.58);

        //Connexion son->body
        QObject::connect(this, SIGNAL(sound(double,double,double)), zagent->getBody(), SLOT(hear(double,double,double)));

        //Connexion agent->model
        QObject::connect(zagent, SIGNAL(info(InfoEntity)), this, SLOT(entity_maj(InfoEntity)));

        //On ajoute l'agent dans la liste
        m_entities.push_back(zagent);
    }
}

//Destructeur
SNZ_Model::~SNZ_Model(){
}

//Actions sur les agents
void SNZ_Model::entity_action(InfoAction info){
    emit maj_action(info);
}

//Transmet les info des entités à la vue
void SNZ_Model::entity_maj(InfoEntity info){
    emit maj_entity(info);
}


