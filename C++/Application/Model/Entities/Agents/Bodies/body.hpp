/**
 * File: body.hpp
 * Author: Antoine
 *
 * Created on April 14, 2015, 3:17 PM
 */

#ifndef BODY_HPP
#define BODY_HPP

#include <iostream>
#include <cmath>

#include <QObject>

#include "../../../constante.hpp"

//! Body Class
/*!
 * La classe Body implémente les données
 * communes de tous les Body, ainsi que
 * le comportement par défaut des différents
 * Body.
 */
class Body : public QObject{

    Q_OBJECT

    public :

        ///Constructeur
        Body(double, double, double, double);

        ///Destructeur
        virtual ~Body();

    public slots :

        ///Fonction senseur appellée lors de l'émition d'un son quelque part dans l'environnement
        virtual void hear(double, double, double);

        ///Fonction moteur appellée par le brain pour indiquer une direction au body
        virtual void move_to(double, double);

        ///Fonction moteur appellée tous les t temps par le brain
        virtual void move();

        //Fonction moteur appellée par le brain pour indiquer au body de s'arréter de se déplacer
        virtual void stop_move();

    signals :

        ///Emet les coordonnées d'un son entendu au Brain
        void hear_something(double, double);

        ///Emet les coordonnées du Body
        void coordinates(double, double);

        //Emet la direction du Body
        void direction(double, double);

        //Emet la vitesse du Body
        void speed(double);

    protected :

        double m_x;         ///< Coordonnées X du Body de l'Agent
        double m_y;         ///< Coordonnées Y du Body de l'Agent
        double m_dx;        ///< Coordonnées DX du Body de l'Agent
        double m_dy;        ///< Coordonnées DY du Body de l'Agent
        double m_speed;     ///< Vitesse de l'agent dans l'environnement
};

#endif // BODY_HPP

