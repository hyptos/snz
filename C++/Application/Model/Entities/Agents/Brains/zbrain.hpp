/**
 * File: zbrain.hpp
 * Author: Antoine
 *
 * Created on April 12, 2015, 3:58 PM
 */

#ifndef ZBRAIN_HPP
#define ZBRAIN_HPP

#include <QObject>
#include <QTimer>

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <thread>
#include <chrono>

#include "brain.hpp"


//! ZBrain Class.
/*!
 * La classe ZBrain instancie le "cerveau" d'un agent de type zombie.
 * On y définie les comportements qu'a le zombie leurs de la réceptions
 * de signaux émis par le corps, le cerveau déclenche un certain nombre
 * d'opérations, voir délègue ces calculs aux modules de la couche raisonnement.
 *
 * Un zombie ayant un comportement très basique, le cerveau fait directement
 * les calculs (du moins, pour l'instant).
*/
class ZBrain : public Brain{

    //Macro pour les signaux et les slots
    Q_OBJECT

    public :

        ///Constructeur par défaut
        /*!
        * Initialise les divers attributs du body
        */
        ZBrain();

        ///Destructeur
        virtual ~ZBrain();

    public slots :

        //Boucle d'actions à effectuer par l'agent
        virtual void actions();

        ///Slot Function gérant les entrée sonore
        /*!
         * Cette fonction est appellé lorsque le body à perçu un son,
         * le body fait remonter l'information au cerveau qui va exécuter
         * le traitement associé au son.
         *
         * Ici le brain indique simplement au body de se diriger vers
         * l'épicentre du son.
         */
        virtual void something_heard(double x, double z, double y);

};

#endif // ZBRAIN_HPP

