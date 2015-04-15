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
        QObject::connect(zagent, SIGNAL(info(ulong,InfoEntity)), this, SLOT(entity_maj(ulong,InfoEntity)));

        //On ajoute l'agent dans la liste
        m_entities.push_back(zagent);
    }

    QTimer* timer = new QTimer();
    timer->connect(timer, SIGNAL(timeout()), this, SLOT(actions()));
    timer->start(100);
}

//Destructeur
SNZ_Model::~SNZ_Model(){
}

//Actions sur les agents
void SNZ_Model::actions(){
     emit sound(rand() % m_envX, rand() % m_envY, 50);
}

//Transmet les info des entités à la vue
void SNZ_Model::entity_maj(unsigned long id, InfoEntity info){
    emit maj_view(id, info);
}


