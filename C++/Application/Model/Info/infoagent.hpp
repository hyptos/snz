/**
 * File: infoagent.hpp
 * Author: Antoine
 *
 * Created on April 14, 2015, 5:50 PM
 */

#ifndef INFO_AGENT_HPP
#define INFO_AGENT_HPP

#include <iostream>

#include "infoentity.hpp"
#include "../constante.hpp"

class InfoAgent : public InfoEntity{

    public :

        //Constructeur
        InfoAgent(const EntityType&, const EntityState&, const double&, const double&, const double&, const double&, const double&);

        //Destructeur
        ~InfoAgent();

        //Retourne la vitesse de l'agent
        double getSpeed();

    protected :

        const double m_speed;   ///< Vitesse de l'agent
};

#endif // INFO_AGENT_HPP

