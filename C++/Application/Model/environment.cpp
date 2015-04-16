#include "environment.hpp"

//Constructeur
Environment::Environment(unsigned long length, unsigned long width) 
	: m_length(length), m_width(width) {
}

//Destructeur
Environment::~Environment(){}

//Retourne la longueur de l'environnement
unsigned long Environment::getLength() const{
	return m_length;
}

//Retourne la largeur de l'environnement
unsigned long Environment::getWidth() const{
	return m_width;
}

//Retourne si un emplacement est valide par rapport à l'environnement
bool Environment::validePosition(double x, double y) const{

	if(x < 0 || x > m_length || y < 0 || y > m_width)
		return false;

	return true;
}

//Retourne des info sur l'environnement autour d'un point (TODO)
void Environment::getArea(double x, double y, double dist) const{
}