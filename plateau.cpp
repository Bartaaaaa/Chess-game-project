//
// Created by Grzadziel Bartlomiej on 14/01/2024.
//

#include "plateau.h"

bool Plateau::verifRange(int x, int y, int x2, int y2) {
    if (x2 >7 || x2 < 0 || y2 < 0 || y2 > 7) {
        return false;
    }
    if(x2 == x && y2 == y) {
        return false;
    }
    if (m_plateau[x2][y2]->getCouleur()== m_plateau[x][y]->getCouleur()) {
        return false;
    }
    else{
        return true;
    }
}



bool verifRangeRoi(int x, int y, int x2, int y2) {
    if (x2 > x+1 || x2 < x-1 || y2 < y-1 || y2 > y+1) {
        cout << "Deplacement impossible" << endl;
        return false;
    }
    else{
        return true;
    }
}
bool Plateau::verifDeplacement(int x, int y, int x2, int y2) {
    //DEPLACEMENT HORIZONTAUX ET VERTICAUX
    if (x=x2 && y!=y2) {
        if(y2>y){
            for (int i = y;i<y2;i++) {
                //déplacement vers le bas du tableau
                if (m_plateau[x][i]->getName() != "") {
                    return false;
                }
            }
        }
        else if (y2<y) {
            for (int i = y;i>y2;i--) {
                //déplacement vers le haut du tableau
                if (m_plateau[x][i]->getName() != "") {
                    return false;
                }
            }
        }
        return true;
    }
    else if (y=y2 && x!=x2) {
        if(x2>x){
            for (int i = x;i<x2;i++) {
                //déplacement vers la droite du tableau
                if (m_plateau[i][y]->getName() != "") {
                    return false;
                }
            }
        }
        else if (x2<x) {
            for (int i = x;i>x2;i--) {
                //déplacement vers la gauche du tableau
                if (m_plateau[i][y]->getName() != "") {
                    return false;
                }
            }
        }
        return true;
    }
    //DEPLACEMENT DIAGONAUX
    //deplacement bas droite
    if (x2>x && y2>y){
        for (int i =x;i<x2;i++){
            for (int j =y; j<y2;j++){
                if (m_plateau[i][j]->getName()!=""){
                    return false;
                }
            }
        }
    }
    //deplacement bas gauche
    if (x2>x && y2<y){
        for (int i=x;i<x2;i++){
            for (int j=y2;j<y;j--){
                if (m_plateau[i][j]->getName()!=""){
                    return false;
                }
            }
        }
    }
    //deplacement haut droite
    if (x2<x&& y2>y){
        for (int i=x2;i<x;i++){
            for (int j=y;j<y2;j++){
                if (m_plateau[i][j]->getName()!=""){
                    return false;
                }
            }
        }
    }
    //deplacement haut gauche
    if (x2<x && y2<y){
        for (int i=x2;i<x;i++){
            for (int j=y2;j<y;j++){
                if (m_plateau[i][j]->getName()!=""){
                    return false;
                }
            }
        }
    }
    else {
        return true;
    }

}



bool Plateau::verifCavalier(int x, int y, int x2, int y2){
    if ((x2 == x+2 && y2 == y+1) || (x2==x+1 && y2==y+2) || (x2==x-1 && y2==y+2) || (x2==x-2 && y2==y+1) || (x2==x-2 && y2==y-1) || (x2==x-1 && y2==y-2) || (x2==x+1 && y2==y-2) || (x2==x+2 && y2==y-1)) {
        return true;
    }
    return false;
}

bool Plateau::verifFou(int x, int y, int x2, int y2) {
   for (int i=0; i<8; i++){
        if (x2==x+i && y2==y+i) {
            return true;
        }
       if (x2==x-i && y2==y-i) {
           return true;
       }
       if (x2==x+i && y2==y-i) {
           return true;
       }
         if (x2==x-i && y2==y+i) {
              return true;
         }
   }
   return false;
}

bool Plateau::verifReine(int x, int y, int x2, int y2) {
    for (int i = 0; i<8;i++){
        //Mouvements verticaux
        if (x==x2 && y2==i ) {
            return true;
        }
        //mouvements horizontaux
        if  (y==y2 && x2==i) {
            return true;
        }
        //mouvements diagonaux
        if (x2==i && y2==i) {
            return true;
        }
    }
    return false;
}

void Plateau::deplacerReine(int x, int y, int x2, int y2) {
    if (verifRange(x,y,x2,y2) && verifReine(x,y,x2,y2) && verifDeplacement(x,y,x2,y2)){
        if (m_plateau[x][y]->getCouleur()=="Blanc"){
            if (m_plateau[x2][y2]->getCouleur()=="Noir" || m_plateau[x2][y2]->getCouleur()==""){
                m_plateau[x2][y2]=m_plateau[x][y];
                m_plateau[x][y]=new Pion("","",x,y);
            }
        }
        else if (m_plateau[x][y]->getCouleur()=="Noir"){
            if (m_plateau[x2][y2]->getCouleur()=="Blanc" || m_plateau[x2][y2]->getCouleur()==""){
                m_plateau[x2][y2]=m_plateau[x][y];
                m_plateau[x][y]=new Pion("","",x,y);
            }
        }
    }
    else {
        cout << "Deplacement impossible" << endl;
    }
}


void Plateau::deplacerFou(int x, int y, int x2, int y2) {
    if (verifFou(x, y, x2, y2) && verifRange(x,y,x2,y2) && verifDeplacement(x,y,x2,y2)) {
        if (m_plateau[x][y]->getCouleur()=="Blanc"){
            if(m_plateau[x2][y2]->getCouleur()=="Noir" || m_plateau[x2][y2]->getCouleur()==""){
                m_plateau[x2][y2]=m_plateau[x][y];
                m_plateau[x][y]=new Pion("","",x,y);
            }
        }
        else if (m_plateau[x][y]->getCouleur()=="Noir"){
            if (m_plateau[x2][y2]->getCouleur()=="Blanc" || m_plateau[x2][y2]->getCouleur()==""){
                m_plateau[x2][y2]=m_plateau[x][y];
                m_plateau[x][y]=new Pion("","",x,y);
            }
        }
    }
    else{
        cout << "Deplacement impossible" << endl;
    }
}

void Plateau::afficherPlateau() {
    cout <<  "0 1 2 3 4 5 6 7" << endl;
    cout << "-----------------" << endl;
    for (int i = 0; i < 8; ++i) { cout << i;
        for (int j = 0; j < 8; ++j) {
            cout << "|";
            if (m_plateau[i][j]->getName() == "") { //ICI CORRIGER DE probleme d'affichage, voir comment faire les coordinnes i et j
                cout << "-";
            } else {
                cout << m_plateau[i][j]->getName();
                }
        }
        cout << "|" << endl;
    }
    cout << "-----------------" << endl;
}

void Plateau::deplacerPion(int x, int y, int x2, int y2) {
    if (verifRange(x, y, x2, y2)) {
        if (m_plateau[x][y]->getCouleur() == "Blanc") {
            if ((x2 == x - 1 && y2 == y - 1 && m_plateau[x2][y2]->getCouleur() == "Noir") || (x2 == x - 1 && y2 == y + 1 && m_plateau[x2][y2]->getCouleur() == "Noir") ) {
                m_plateau[x2][y2] = m_plateau[x][y];
                m_plateau[x][y] = new Pion("", "", 0, 0);
            } else if (x-1 == x2 && y2 == y  && m_plateau[x2][y2]->getCouleur() == "") {
                m_plateau[x2][y2] = m_plateau[x][y];
                m_plateau[x][y] = new Pion("", "", 0, 0);
            } else {
                cout << "Deplacement impossible 1 " << endl;
            }
        } else if (m_plateau[x][y]->getCouleur() == "Noir") {
            if ((x2 == x + 1 && y2 == y + 1 && m_plateau[x2][y2]->getCouleur() == "Blanc")|| (x2 == x + 1 && y2 == y - 1 && m_plateau[x2][y2]->getCouleur() == "Blanc")) {
                m_plateau[x2][y2] = m_plateau[x][y];
                m_plateau[x][y] = new Pion("", "", 0, 0);
            } else if (x+ 1 == x2 && y2 == y  && m_plateau[x2][y2]->getCouleur() == "") {
                m_plateau[x2][y2] = m_plateau[x][y];
                m_plateau[x][y] = new Pion("", "", 0, 0);
            } else {
                cout << "Deplacement impossible 2" << endl;
            }
        } else {
            cout << "Deplacement impossible 3" << endl;
        }
    }
    cout << "Deplacement impossible car pas dans le bon range " << endl;
}



void Plateau::deplacerRoi(int x, int y, int x2, int y2) {
    if( verifRangeRoi(x, y, x2, y2) && verifRange(x, y, x2, y2)) {
        if (m_plateau[x][y]->getCouleur() == "Blanc") {
            if ( m_plateau[x2][y2]->getCouleur() == "Noir" || m_plateau[x2][y2]->getCouleur() == "") {
                m_plateau[x2][y2] = m_plateau[x][y];
                m_plateau[x][y] = new Pion("", "", 0, 0);
            } else if ( m_plateau[x2][y2]->getCouleur() == "Blanc") {
                cout << "Deplacement impossible" << endl;
            } else {
                cout << "Deplacement impossible" << endl;
            }
        } else if (m_plateau[x][y]->getCouleur() == "Noir") {
            if ( m_plateau[x2][y2]->getCouleur() == "Blanc" || m_plateau[x2][y2]->getCouleur() == "") {
                m_plateau[x2][y2] = m_plateau[x][y];
                m_plateau[x][y] = new Pion("", "", 0, 0);
            } else if ( m_plateau[x2][y2]->getCouleur() == "Noir") {
                cout << "Deplacement impossible" << endl;
            } else {
                cout << "Deplacement impossible" << endl;
            }

        } else {
            cout << "Deplacement impossible" << endl;
        }
    }
}



void Plateau::deplacerTour(int x, int y, int x2, int y2) {
    if (verifRange(x,y,x2,y2) && verifDeplacement(x,y,x2,y2)) {
        if (m_plateau[x][y]->getCouleur()=="Blanc"){
            if (m_plateau[x2][y2]->getCouleur()=="Noir" || m_plateau[x2][y2]->getCouleur()==""){
                m_plateau[x2][y2]=m_plateau[x][y];
                m_plateau[x][y]=new Pion("","",0,0);
            }
            else if (m_plateau[x2][y2]->getCouleur()=="Blanc"){
                cout << "Deplacement impossible" << endl;
            }

        }
        else if (m_plateau[x][y]->getCouleur()=="Noir"){
            if (m_plateau[x2][y2]->getCouleur()=="Blanc" || m_plateau[x2][y2]->getCouleur()==""){
                m_plateau[x2][y2]=m_plateau[x][y];
                m_plateau[x][y]=new Pion("","",0,0);
            }
            else if (m_plateau[x2][y2]->getCouleur()=="Noir"){
                cout << "Deplacement impossible" << endl;
            }
            else{
                cout << "Deplacement impossible" << endl;
            }
        }
        else{
            cout << "Deplacement impossible" << endl;
        }
    }
}

void Plateau::deplacerCavalier(int x, int y, int x2, int y2) {
    if (verifCavalier(x,y,x2,y2) && verifRange(x,y,x2,y2) ){
        if (m_plateau[x][y]->getCouleur()=="Blanc"){
            if (m_plateau[x2][y2]->getCouleur()=="Noir" || m_plateau[x2][y2]->getCouleur()==""){
                m_plateau[x2][y2]=m_plateau[x][y];
                m_plateau[x][y]=new Pion("","",0,0);
            }
            else if (m_plateau[x2][y2]->getCouleur()=="Blanc"){
                cout << "Deplacement impossible" << endl;
            }

        }
        else if (m_plateau[x][y]->getCouleur()=="Noir"){
            if (m_plateau[x2][y2]->getCouleur()=="Blanc" || m_plateau[x2][y2]->getCouleur()==""){
                m_plateau[x2][y2]=m_plateau[x][y];
                m_plateau[x][y]=new Pion("","",0,0);
            }
            else if (m_plateau[x2][y2]->getCouleur()=="Noir"){
                cout << "Deplacement impossible" << endl;
            }
            else{
                cout << "Deplacement impossible" << endl;
            }
        }
        else{
            cout << "Deplacement impossible" << endl;
        }
    }
}

bool Plateau::verifPlateauVide() {
    int compteurCaseVide = 0;
    for (int i = 0; i < 8; i++) {
        for (int j =0;j<8;j++){
            if (m_plateau[i][j]->getName()==""){
                compteurCaseVide++;
            }

        }
    }
    if (compteurCaseVide==64){
        return true;
    }
    else{
        return false;
    }
}

string Plateau::getNomPion(int x, int y) {
    return m_plateau[x][y]->getName();
}