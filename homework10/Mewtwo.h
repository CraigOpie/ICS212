/*******************************************************************************
//
//  NAME:           Craig Opie
//
//  HOMEWORK:       10
//
//  CLASS:          ICS 212
//
//  INSTRUCTOR:     Ravi Narayan
//
//  DATE:           May 06, 2020
//
//  FILE:           Mewtwo.h
//
//  DESCRIPTION:    This file declares the child class Mewtwo.
//
******************************************************************************/

#ifndef _Mewtwo_h
#define _Mewtwo_h

#include <string>
#include "Pokemon.h"
using namespace std;

/******************************************************************************
//
//  CLASSNAME:      Mewtwo
//  DESCRIPTION:    A Pokémon that inherits from the Pokemon class
//  PARAMETERS:     string  :   Used to set the type
//                  float   :   Used to set the height
//                  Mewtwo& :   Used to copy another Mewtwo
//
******************************************************************************/

class Mewtwo : public Pokemon
{
    private:
        bool mewtwoniteX;
        bool mewtwoniteY;

    public:
        Mewtwo();
        Mewtwo(string, float);
        Mewtwo(const Mewtwo &);
        Mewtwo & operator = (const Mewtwo &);
        virtual ~Mewtwo();
        string Name();
        string Type();
        float Height();
        int Hp();
        int Level();
        int Speed();
        int Attack();
        int Defense();
        void Name(string);
        void Hp(int);
        void Level(int);
        void Speed(int);
        void Attack(int);
        void Defense(int);
        bool MegaEvolveX();
        bool MegaEvolveY();
        void MegaEvolveX(bool);
        void MegaEvolveY(bool);
};

#endif
