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
//  FILE:           Giratina.h
//
//  DESCRIPTION:    This file declares the child class Giratina.
//
******************************************************************************/

#ifndef _Giratina_h
#define _Giratina_h

#include <string>
#include "Pokemon.h"
using namespace std;

/******************************************************************************
//
//  CLASSNAME:      Giratina
//  DESCRIPTION:    A Pokémon that inherits from the Pokemon class
//  PARAMETERS:     string      :   Used to set the type
//                  float       :   Used to set the height
//                  Giratina&   :   Used to copy another Giratina
//
******************************************************************************/

class Giratina : public Pokemon
{
    private:
        bool thisDimension;

    public:
        Giratina();
        Giratina(string, float);
        Giratina(const Giratina &);
        Giratina & operator = (const Giratina &);
        virtual ~Giratina();
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
        bool ThisDimension();
        void ThisDimension(bool);
};

#endif
