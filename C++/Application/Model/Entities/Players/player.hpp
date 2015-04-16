/**
 * File: player.hpp
 * Author: Antoine
 *
 * Created on April 16, 2015, 10:31 AM
 */

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>

#include "../entity.hpp"
#include "../../constante.hpp"


//! Player Class
/*!
 * La classe Player est simplement une
 * réimplémentation de la classe Entity
 * afin de donner une représentation du
 * Joueur dans le model.
 */
class Player : public Entity
{
	public :

		///Constructeur
		Player(unsigned long, EntityType, EntityState, double, double, double, double);
		
		///Destructeur
		~Player();
	
};

#endif // PLAYER_HPP