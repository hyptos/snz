/**
 * File: brain.hpp
 * Author: Antoine
 *
 * Created on April 14, 2015, 4:19 PM
 */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

#include <QObject>

#include "../../../constante.hpp"

//! Brain Class
/*!
 * La classe Brain est la classe générique
 * implémentant les attributs et méthodes
 * communes de ses filles.
 *
 * Elle est abstraite pour obliger le programmeur
 * à définir le comportement du brain en fonction
 * du type de ses agents.
 *
 * Par définition le brain est la thread contenant
 * la boucle d'actions exécutés par l'agent tous les
 * t temps.
 */
class Brain : public QObject{

    Q_OBJECT

    public :

        ///Constructeur
        Brain();

        ///Destructeur
        virtual ~Brain() = 0;

    public slots :

        ///Slot Function gérant les entrée sonore
        /*!
         * Cette fonction est appellé lorsque le body à perçu un son,
         * le body fait remonter l'information au cerveau qui va exécuter
         * le traitement associé au son.
         *
         * La fonction est définie comme virtuelle pure car il faut que le
         * programmeur définisse le comportement du brain lors de la réception
         * d'un son par le body.
         */
        virtual void something_heard(double, double) = 0;

        ///Slot Function gérant la boucle d'actions
        /*!
         * Cette fonction gère la boucle d'actions faites par
         * l'agent tous les t temps.
         *
         * Elle est à définir par le programmeur lors de l'implémentation
         * de la classe fille.
         */
        virtual void actions() = 0;

    signals :

        ///Signal pour que le body bouge
        /*!
         * Signal envoyé par le cerveau lorsqu'il demande au
         * corps de déplacer l'agent dans l'environnement.
         */
        void move_body_move();

        ///Signal pour indiquer au body où aller
        /*!
         * Signal envoyé au corps lorsque le cerveau
         * a déterminé un endroit où aller
         *
         * \param x : coordonnée x de l'endroit où aller dans l'environnement
         * \param y : coordonnée y de l'endroit où aller dans l'environnement
         */
        void lets_go_to(double, double);
};


#endif // BRAIN_HPP

