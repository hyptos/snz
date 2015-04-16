#include "zbrain.hpp"

//Constructeur
ZBrain::ZBrain() : Brain(){
    QTimer* timer = new QTimer();
    timer->connect(timer, SIGNAL(timeout()), this, SLOT(actions()));
    timer->start(100);
}

//Destructeur
ZBrain::~ZBrain(){
}

//Slot Something Heard
void ZBrain::something_heard(double x, double y){

    emit lets_go_to(x, y);
}

//Actions faite par l'agent
void ZBrain::actions(){
    emit move_body_move();
}
