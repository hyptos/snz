/**
 * File: entity.hpp
 * Author: Antoine
 *
 * Created on April 14, 2015, 3:06 PM
 */

#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <iostream>

#include <QObject>

#include "../constante.hpp"
#include "../Info/infoentity.hpp"


//! Entity Class
/*!
 * La classe Entity est la classe générique
 * dont vont hériter toutes les entités du
 * model (joueurs, agents, objets).
 *
 * Elle contient les attributs nécessaires
 * à toutes les entités.
 *
 * Hérite de QObject, puisque les entités
 * peuvent possiblement instancier des
 * signaux et des slots.
 */
class Entity : public QObject
{

    Q_OBJECT

    public :

        ///Constructeur
        Entity(unsigned long long, EntityType, EntityState, double, double, double, double, double, double);

        ///Destructeur
        /*!
         * Le destructeur de Entity est
         * virtuelle pur pour ne pas pouvoir
         * instancier d'objet Entity
         */
        virtual ~Entity() = 0;

        ///Retourne id de l'entité
        unsigned long long getId() const;

        ///Retourne le type de l'entité
        EntityType getType() const;

        ///Retourne l'état de l'entité
        EntityState getState() const;

        ///Retourne la coordonnée X de l'entité dans l'environnement
        double getX() const;

        ///Retourne la coordonnée Z de l'entité dans l'environnement
        double getZ() const;

        ///Retourne la coordonnée Y de l'entité dans l'environnement
        double getY() const;

        ///Retourne la coordonnée X du vecteur direction de l'entité
        double getDX() const;

        ///Retourne la coordonnée Z du vecteur direction de l'entité
        double getDZ() const;

        ///Retourne la coordonnée Z du vecteur direction de l'entité
        double getDY() const;

    public slots :

        ///Modifie la valeur de l'id de l'entité
        void setId(unsigned long long);

        ///Modife l'état de l'entité
        void setState(EntityState);

        ///Modifie la coordonnée X de l'entité
        void setX(double);

        ///Modifie la coordonnée Z de l'entité
        void setZ(double);

        ///Modifie la coordonnée Y de l'entité
        void setY(double);

        ///Modife la coordonnée X du vecteur direction de l'entité
        void setDX(double);

        ///Modife la coordonnée Z du vecteur direction de l'entité
        void setDZ(double);

        ///Modife la coordonnée Y du vecteur direction de l'entité
        void setDY(double);

        ///Modifie les coordonnées X, Z et Y de l'entité
        void setCoordinate(double, double, double);

        ///Modifie le vecteur direction de l'entité
        void setDirection(double, double, double);

        //Génére et émet les infos concernant l'entité
        virtual void emitInfo();

    signals :

        ///Emet les coordonnées X, Z et Y de l'entité dans l'environnement
        void coordinates(double, double, double);

        ///Emet les coordonnées X, Z et Y du vecteur direction de l'entité
        void direction(double, double, double);

        //Emet l'état de l'entité
        void actualState(EntityState);

        //Emet l'id de l'entité ainsi que les info le concernant
        void info(InfoEntity);

    protected :

        unsigned long long m_id;         ///< Id de l'entité

        const EntityType m_type;    ///< Type de l'entité (constant)
        EntityState m_state;        ///< Etat de l'entité

        double m_x;                 ///< Coordonnée X de l'entité dans l'environnement
        double m_z;                 ///< Coordonnée Z de l'entité dans l'environnement
        double m_y;                 ///< Coordonnée Y de l'entité dans l'environnement
        double m_dx;                ///< Coordonnée X du vecteur direction de l'entité
        double m_dz;                ///< Coordonnée Z du vecteur direction de l'entité
        double m_dy;                ///< Coordonnée Y du vecteur direction de l'entité
};

#endif // ENTITY_HPP

