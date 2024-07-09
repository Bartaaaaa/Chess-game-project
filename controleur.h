//
// Created by Grzadziel Bartlomiej on 18/01/2024.
//

#ifndef PROJETECHIQUIER_CONTROLEUR_H
#define PROJETECHIQUIER_CONTROLEUR_H
#include "Plateau.h"

class Controleur{
    int m_gagnant ;
    Plateau * m_plateau;

public :
    Controleur(const Controleur& j) = delete;
    Controleur& operator=(const Controleur& j) = delete;
    Controleur() : m_gagnant(0), m_plateau(new Plateau) {}

    bool fin_de_partie();
    bool JouerTour1();
    bool JouerTour2();
    void debut_de_partie();
    bool check_fin_partie();
    void game_loop();

};
//game_loop = 1 tour, quand fini de s'executer on change de joueur
//play = toute la partie , tant que la partie pas finie appel à game loop
#endif //PROJETECHIQUIER_CONTROLEUR_H
//
//


