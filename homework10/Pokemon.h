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
//  FILE:           Pokemon.h
//
//  DESCRIPTION:    This file declares the parent class Pokemon.
//
******************************************************************************/

#ifndef _Pokemon_h
#define _Pokemon_h

#include <string>
using namespace std;

/******************************************************************************
//
//  CLASSNAME:      Pokemon
//  DESCRIPTION:    A Pokémon (pocket monster) is a fictional creature that is
//                  used to battle other Pokémon
//  PARAMETERS:     string  :   Used to set the type
//                  float   :   Used to set the height
//                  Pokemon&:   Used to copy another Pokémon
//
******************************************************************************/

class Pokemon
{
    protected:
        string name;
        string type;
        float height;
        int hp;
        int level;
        int speed;
        int attack;
        int defense;

    public:
        Pokemon();
        Pokemon(string, float);
        Pokemon(const Pokemon &);
        virtual Pokemon & operator = (const Pokemon &);
        virtual ~Pokemon();
        void printData();
        virtual string Name();
        virtual string Type() = 0;
        virtual float Height() = 0;
        virtual int Hp() = 0;
        virtual int Level() = 0;
        virtual int Speed() = 0;
        virtual int Attack() = 0;
        virtual int Defense() = 0;
        virtual void Name(string) = 0;
        virtual void Hp(int) = 0;
        virtual void Level(int) = 0;
        virtual void Speed(int) = 0;
        virtual void Attack(int) = 0;
        virtual void Defense(int) = 0;
};

#endif
