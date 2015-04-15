/**
 * File: agent.hpp
 * Author: Antoine
 *
 * Created on April 14, 2015, 5:13 PM
 */

#ifndef AGENT_HPP
#define AGENT_HPP

#include <iostream>

#include <QObject>

#include "../../Info/infoagent.hpp"
#include "../entity.hpp"
#include "Bodies/body.hpp"
#include "Brains/brain.hpp"

//! Agent Class
/*!
 * La classe Agent implémente toutes les données
 * communes de tous les agents.
 *
 * Hérite de Entity
 */
class Agent : public Entity{

    Q_OBJECT

    public :

        ///Constructeur
        Agent(unsigned long, EntityType, EntityState, double, double, double, double, Body*, Brain*);

        ///Destructeur
        virtual ~Agent() = 0;

        ///Retourne la vitesse de l'agent
        double getSpeed() const;

        ///Retourne un pointeur sur le Body de l'agent
        Body* getBody();

        ///Retourne un pointeur sur le Brain de l'agent
        Brain* getBrain();

    public slots :

        ///Modifie la vitesse
        void setSpeed(double speed);

        ///Génére et émet les infos concernant l'agent
        virtual void emitInfo();



    protected :

        double m_speed;     ///< Vitesse de l'agent
        Body* m_body;       ///< Pointeur vers le corps de l'agent
        Brain*  m_brain;    ///< Pointeur vers le cerveau de l'agent
};

#endif // AGENT_HPP

