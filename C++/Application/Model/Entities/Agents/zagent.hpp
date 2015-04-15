/**
 * File: zagent.hpp
 * Author: Antoine
 *
 * Created on April 13, 2015, 2:24 PM
 */

#ifndef ZAGENT_HPP
#define ZAGENT_HPP

#include <QObject>

#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>

#include "agent.hpp"
#include "Brains/zbrain.hpp"

//! ZAgent Class
/*!
 * La classe ZAgent est l'entité contenant, implémentant
 * et connectant le différentes parties de l'agent (body, brain).
 * Ce sont des objets ZAgent qui seront créés dans le modèle, les
 * objets ZAgent gérant eux même la création de leurs parties.
 */
class ZAgent : public Agent{

    public :

        ///Constructeur
        /*!
         * Initialise les différents attributs de l'agent.
         * Connecte le body et le brain entre eux.
         */
        ZAgent(unsigned long, double, double, double, double);

        ///Destructeur
        ~ZAgent();
};

#endif // ZAGENT_HPP

