//
// Created by Grzadziel Bartlomiej on 14/01/2024.
//

#ifndef PROJETECHIQUIER_PLATEAU_H
#define PROJETECHIQUIER_PLATEAU_H
#include "pions.h"



class Plateau {
    Pion * m_plateau[8][8];
public :
    Plateau() {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                m_plateau[i][j] = new Pion("", "", i, j);
            }
        }
        for (int i = 0; i < 8; ++i) {
            m_plateau[1][i] = new Pion("NPion", "Noir", 1, i);
            m_plateau[6][i] = new Pion("BPion", "Blanc", 6, i);

        }
            m_plateau[0][4] = new Roi("BRoi", "Blanc");
        m_plateau[7][4] = new Roi("NRoi", "Noir");

        m_plateau[0][0] = new Tour("NTour", "Noir", 0);
        m_plateau[0][7] = new Tour("NTour", "Noir", 7);
        m_plateau[7][0] = new Tour("BTour", "Blanc", 0);
        m_plateau[7][7] = new Tour("BTour", "Blanc", 7);

        m_plateau[0][1] = new Cavalier("NCavalier", "Noir", 1);
        m_plateau[0][6] = new Cavalier("NCavalier", "Noir", 6);
        m_plateau[7][1] = new Cavalier("BCavalier", "Blanc", 1);
        m_plateau[7][6] = new Cavalier("BCavalier", "Blanc", 6);

        m_plateau[0][2] = new Fou("NFou", "Noir", 2);
        m_plateau[0][5] = new Fou("NFou", "Noir", 5);
        m_plateau[7][2] = new Fou("BFou", "Blanc", 2);
        m_plateau[7][5] = new Fou("BFou", "Blanc", 5);

        m_plateau[0][3] = new Pion("NReine", "Noir", 0, 3);
        m_plateau[7][3] = new Pion("BReine", "Blanc", 7, 3);

    }
    bool verifDeplacement(int x, int y, int x2, int y2);
    bool verifRange(int x, int y, int x2, int y2);
    bool verifCavalier(int x, int y, int x2, int y2);
    bool verifFou(int x, int y, int x2, int y2);
    bool verifReine(int x, int y, int x2, int y2);
    bool verifTour(int x, int y, int x2, int y2);
    void deplacerPion(int x, int y, int x2, int y2);
    void deplacerRoi(int x, int y, int x2, int y2);
        void afficherPlateau();
    void deplacerTour(int x, int y, int x2, int y2);

    void deplacerCavalier(int x, int y, int x2, int y2);

    void deplacerFou(int x, int y, int x2, int y2);
    void deplacerReine(int x, int y, int x2, int y2);
    bool verifPlateauVide();

    string getNomPion(int x, int y);
};
#endif //PROJETECHIQUIER_PLATEAU_H
