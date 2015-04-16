#include "environment.hpp"

//Constructeur
Environment::Environment(int length, int width, int height = INT_MAX)
    : m_length(length), m_width(width), m_height(height) {
}

//Destructeur
Environment::~Environment(){}

//Retourne la longueur de l'environnement
int Environment::getLength() const{
	return m_length;
}

//Retourne la largeur de l'environnement
int Environment::getWidth() const{
	return m_width;
}

int Environment::getHeight() const{
    return m_height;
}

//Retourne si un emplacement est valide par rapport à l'environnement
bool Environment::validePosition(double x, double z, double y) const{

    if(x < 0 || x > m_length || z < 0 || z > m_width || y < 0 || y > m_height)
		return false;

	return true;
}

//Retourne des info sur l'environnement autour d'un point (TODO)
void Environment::getArea(double x, double y, double dist) const{
}
