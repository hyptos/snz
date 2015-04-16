/**
 * File: infoentity.hpp
 * Author: Antoine
 *
 * Created on April 14, 2015, 3:06 PM
 */

#ifndef INFO_ENTITY_HPP
#define INFO_ENTITY_HPP

#include <iostream>

#include "../constante.hpp"

//! InfoEntity Class
/*!
 * La classe InfoEntity contient les données
 * concernant une entité. (à instant t non précisé)
 */
class InfoEntity{
    public :

        ///Constructeur
        InfoEntity(const EntityType&, const EntityState&, const double&, const double&, const double&, const double&);

        ///Destructeur
        ~InfoEntity();

        ///Retourne le type de l'entité
        EntityType getType();

        ///Retourne l'état de l'entité
        EntityState getState();

        ///Retourne la coordonnée X de l'entité dans l'environnement
        double getX();

        ///Retourne la coordonnée Y de l'entité dans l'environnement
        double getY();

        ///Retourne la coordonnée X du vecteur direction de l'entité
        double getDX();

        ///Retourne la coordonnée Y du vecteur direction de l'entité
        double getDY();

    protected :

        const EntityType m_type;    ///< Type de l'entité
        const EntityState m_state;  ///< Etat de l'entité

        const double m_x;           ///< Coordonnée X de l'entité dans l'environnement
        const double m_y;           ///< Coordonnée Y de l'entité dans l'environnement
        const double m_dx;          ///< Coordonnée X du vecteur direction de l'entité
        const double m_dy;          ///< Coordonnée Y du vecteur direction de l'entité

};

#endif // INFO_ENTITY_HPP

