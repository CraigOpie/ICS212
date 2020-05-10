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
//  FILE:           Arceus.h
//
//  DESCRIPTION:    This file declares the child class Arceus.
//
******************************************************************************/

#ifndef _Arceus_h
#define _Arceus_h

#include <string>
#include "Pokemon.h"
using namespace std;

/******************************************************************************
//
//  CLASSNAME:      Arceus
//  DESCRIPTION:    A Pokémon that inherits from the Pokemon class
//  PARAMETERS:     string  :   Used to set the type
//                  float   :   Used to set the height
//                  Arceus& :   Used to copy another Arceus
//
******************************************************************************/

class Arceus : public Pokemon
{
    public:
        Arceus();
        Arceus(string, float);
        Arceus(const Arceus &);
        Arceus & operator = (const Arceus &);
        virtual ~Arceus();
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
        void ChangeType(string);
};

#endif
