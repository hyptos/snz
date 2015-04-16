/**
 * File: environment.hpp
 * Author: Antoine
 *
 * Created on April 16, 2015, 8:06 AM
 */

#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP

#include <iostream>
#include <QObject>

//! Environment Class
/*!
 * La classe Environment contient toutes les données 
 * concernant l'environnement de déplacement des entitées.
 * 
 * Le model (et/ou les entités) vont interroger cette classe
 * pour déterminer si un déplacement est valide, ou simplement
 * avoir des informations sur l'état de l'environnement autour
 * d'un point (x, y).
 */
class Environment
{
	public :
		
		///Constructeur
		Environment(unsigned long, unsigned long);
		
		///Destructeur
		~Environment();

		//Retourne la longueur de l'environnement
		unsigned long getLength() const;

		//Retourne la largeur de l'environnement
		unsigned long getWidth() const;

		///Retourne si une position est valide par rapport à l'environnement
		/*!
		 * A l'heure actuelle, Environment ne regarde que si la
		 * position passée en paramètre se trouve entre 0 et la taille
		 * de l'environnement.
		 */
		bool validePosition(double, double) const;

		///Retourne des infos sur l'environnement
		/*!
		 * A l'heure actuelle cette fonction ne retourne rien.
		 *
		 * A partir d'une position (x, y) et d'un rayon/distance, 
		 * précisant ainsi une zone, Environment retourne toutes 
		 * les données concernant cette dite zone.
		 */
		void getArea(double, double, double) const;

	private :

		unsigned long m_length;		///< Longueur de l'environnement (taille sur l'axe X)
		unsigned long m_width;		///< Largeur de l'environnement (taille sur l'axe Y)
};

#endif // ENVIRONMENT_HPP