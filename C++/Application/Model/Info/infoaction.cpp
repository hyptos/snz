#include "infoaction.hpp"

//Constructeur
InfoAction::InfoAction(const EntityAction& action, const unsigned long long& entity, const unsigned long long& cible)
	: m_action(action), m_entity(entity), m_cible(cible) {
}

//Destructeur
InfoAction::~InfoAction(){}

//Retourne l'action effectué par l'entité
EntityAction InfoAction::getAction(){
	return m_action;
}

//Retourne l'entité faisant l'action
unsigned long long InfoAction::getEntity(){
	return m_entity;
}

//Retourne l'entité ciblé par l'action
unsigned long long InfoAction::getCible(){
	return m_cible;
}
