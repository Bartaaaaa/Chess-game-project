//
// Created by Grzadziel Bartlomiej on 01/01/2024.
//
#ifndef PROJETECHIQUIER_PIONS_H
#define PROJETECHIQUIER_PIONS_H
#include <string>
#include <iostream>


#include <iostream>
using namespace std;



class Pion {
    string m_couleur;
    string m_name;
    int m_position[2];
public :
    Pion(const string &n, const string &c,  int x , int  y)
            : m_name(n), m_couleur(c) {
        m_position[0] = x;
        m_position[1] = y;
    }

    string getName() const {
        return m_name;
    }
    string  getCouleur() const {
        return m_couleur;
    }
    int getPositionX() const {
        return m_position[0];
    }

    int getPositionY() const {
        return m_position[1];
    }


};

class Roi : public Pion {

public:
    Roi(const string &n, const string &c) : Pion(n, c,  (c == "Blanc") ? 0 : 7,5) {}


};


class Tour : public Pion {
public :
    Tour(const string &n, const string &c, int y) : Pion(n, c, (c=="Blanc") ?7 :0,y ) {}
};

class Fou : public Pion {
public :
    Fou(const string &n, const string &c, int y) : Pion(n, c, (c=="Blanc") ?7 :0,y ) {}
};

class Cavalier : public Pion {
public :
    Cavalier(const string &n, const string &c, int y) : Pion(n, c, (c=="Blanc") ?7 :0,y ) {}
};

class Reine : public Pion {
public :
    Reine(const string &n, const string &c) : Pion(n, c, (c=="Blanc") ?7 :0,3 ) {}
};



#endif //PROJETECHIQUIER_PIONS_H
