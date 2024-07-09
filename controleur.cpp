//
// Created by Grzadziel Bartlomiej on 19/01/2024.
//

#include "controleur.h"
void Controleur::debut_de_partie() {
    m_plateau->afficherPlateau();
    cout << "Debut de partie" << endl;
    cout << "Joueur 1 : " << endl;
   // JouerTour1();
}

bool Controleur::JouerTour1() {

    cout << "Veuillez entrer les coordonnees du pion BLANC a deplacer" << endl;
    cout << "Veuillez entrer la ligne du pion a deplacer" << endl;
    int x;
    cin >> x;
    cout << "Veuillez entrer la colonne du pion a deplacer" << endl;
    int y;
    cin >> y;
    cout << "Veuillez entrer les coordonnees de la case ou vous voulez deplacer le pion" << endl;
    cout << "Veuillez entrer la ligne de la case ou vous voulez deplacer le pion" << endl;
    int x2;
    cin >> x2;
    cout << "Veuillez entrer la colonne de la case ou vous voulez deplacer le pion" << endl;
    int y2;
    cin >> y2;
    if(m_plateau->getNomPion(x,y) == "BPion") {
        cout << "SALUUUT" << endl;

        m_plateau->deplacerPion(x, y, x2, y2);
        return true;
    }
    else if(m_plateau->getNomPion(x,y) == "BTour"){
        m_plateau->deplacerTour(x,y,x2,y2);
        return true;
        }
    else if(m_plateau->getNomPion(x,y) == "BFou"){
        m_plateau->deplacerFou(x,y,x2,y2);return true;
    }
    else if(m_plateau->getNomPion(x,y) == "BRoi"){
        m_plateau->deplacerRoi(x,y,x2,y2);return true;
    }
    else if(m_plateau->getNomPion(x,y) == "BReine"){
        m_plateau->deplacerReine(x,y,x2,y2);return true;
    }
    else if(m_plateau->getNomPion(x,y) == "BCavalier"){
        m_plateau->deplacerCavalier(x,y,x2,y2);return true;
    }
    else{
        cout << "ERREEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEUR" << endl;

        return false;
    }
}
bool Controleur::JouerTour2() {
    cout << "Veuillez entrer les coordonnees du pion NOIR a deplacer" << endl;
    cout << "Veuillez entrer la ligne du pion a deplacer" << endl;
    int x;
    cin >> x;
    cout << "Veuillez entrer la colonne du pion a deplacer" << endl;
    int y;
    cin >> y;
    cout << "Veuillez entrer les coordonnees de la case ou vous voulez deplacer le pion" << endl;
    cout << "Veuillez entrer la ligne de la case ou vous voulez deplacer le pion" << endl;
    int x2;
    cin >> x2;
    cout << "Veuillez entrer la colonne de la case ou vous voulez deplacer le pion" << endl;
    int y2;
    cin >> y2;
    if(m_plateau->getNomPion(x,y) == "NPion") {
        cout << "SALUUUT" << endl;

        m_plateau->deplacerPion(x, y, x2, y2);
        return true;
    }
    else if(m_plateau->getNomPion(x,y) == "NTour"){
        m_plateau->deplacerTour(x,y,x2,y2);
        return true;
    }
    else if(m_plateau->getNomPion(x,y) == "NFou"){
        m_plateau->deplacerFou(x,y,x2,y2);return true;
    }
    else if(m_plateau->getNomPion(x,y) == "NRoi"){
        m_plateau->deplacerRoi(x,y,x2,y2);return true;
    }
    else if(m_plateau->getNomPion(x,y) == "NReine"){
        m_plateau->deplacerReine(x,y,x2,y2);return true;
    }
    else if(m_plateau->getNomPion(x,y) == "NCavalier"){
        m_plateau->deplacerCavalier(x,y,x2,y2);return true;
    }
    else{
        cout << "ERREEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEUR" << endl;
        return false;
    }
}

void Controleur::game_loop() {
    while(!fin_de_partie()){
        m_plateau->afficherPlateau();
        if(JouerTour1()){
            m_plateau->afficherPlateau();
        }
            cout << "Joueur 2 : " << endl;
            if(JouerTour2()){
                m_plateau->afficherPlateau();
                cout << "Joueur 1 : " << endl;
            }

    }
}

bool Controleur::fin_de_partie() {
    int compteurCaseVide = 0;
    if (m_plateau->verifPlateauVide()) {
        return true;
    }else{
        return false;
    }

}