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
//  FILE:           Mewtwo.cpp
//
//  DESCRIPTION:    This file initiates the child class Mewtwo.
//
******************************************************************************/

#include <string>
#include <iostream>
#include "Mewtwo.h"
using namespace std;


/******************************************************************************
//
//  FUNCTIONNAME:   Pokemon
//  DESCRIPTION:    Default constructor for the Pokemon Class
//  PARAMETERS:     None
//  RETURNVALUES:   None
//
******************************************************************************/

Mewtwo::Mewtwo()
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Mewtwo::Mewtwo" << endl;
    #endif

    this->hp = 106;
    this->level = 1;
    this->speed = 130;
    this->attack = 110;
    this->defense = 90;
    this->name = "Mewtwo";
    this->type = "Psychic";
    this->height = 2.0;

    cout << this->Name() << " Constructor" << endl;
    cout << endl;

    this->mewtwoniteX = false;
    this->mewtwoniteY = false;

}

/******************************************************************************
//
//  FUNCTIONNAME:   Pokemon
//  DESCRIPTION:    Custom constructor which allows setting the Pokemon's
//                  type and height properties
//  PARAMETERS:     newType     :   (string)
//                  newHeight   :   (float)
//  RETURNVALUES:   None
//
******************************************************************************/

Mewtwo::Mewtwo(string newType, float newHeight)
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Mewtwo::Mewtwo" << endl;
        cout << "PARAMETER - newType: " << newType << endl;
        cout << "PARAMETER - newHeight: " << newHeight << endl;
    #endif

    this->hp = 106;
    this->level = 1;
    this->speed = 130;
    this->attack = 110;
    this->defense = 90;
    this->name = "Mewtwo";
    this->type = newType;
    this->height = newHeight;

    cout << this->Name() << " Constructor" << endl;
    cout << endl;

    this->mewtwoniteX = false;
    this->mewtwoniteY = false;

}

/******************************************************************************
//
//  FUNCTIONNAME:   Pokemon
//  DESCRIPTION:    Copy constructor for the Pokemon class that uses a
//                  reference to a Pokemon to set the variables of the class
//  PARAMETERS:     obj :   (Pokemon &)
//  RETURNVALUES:   None
//
******************************************************************************/

Mewtwo::Mewtwo(const Mewtwo & obj)
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Mewtwo::Mewtwo" << endl;
        cout << "Copy Constructor" << endl;
    #endif

    this->hp = obj.hp;
    this->level = obj.level;
    this->speed = obj.speed;
    this->attack = obj.attack;
    this->defense = obj.defense;
    this->name = obj.name;
    this->type = obj.type;
    this->height = obj.height;

    cout << this->Name() << " Copy Constructor" << endl;
    cout << endl;

    this->mewtwoniteX = obj.mewtwoniteX;
    this->mewtwoniteY = obj.mewtwoniteY;

}

/******************************************************************************
//
//  FUNCTIONNAME:   operator =
//  DESCRIPTION:    Assignment operator used to set the values of an existing
//                  Pokemon to be this Pokemon's values
//  PARAMETERS:     obj :   (Pokemon &)
//  RETURNVALUES:   this:   (Pokemon)
//
******************************************************************************/

Mewtwo & Mewtwo::operator = (const Mewtwo & obj)
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Mewtwo::Mewtwo" << endl;
        cout << "Assignment Operator" << endl;
    #endif

    this->hp = obj.hp;
    this->level = obj.level;
    this->speed = obj.speed;
    this->attack = obj.attack;
    this->defense = obj.defense;
    this->name = obj.name;
    this->type = obj.type;
    this->height = obj.height;

    this->mewtwoniteX = obj.mewtwoniteX;
    this->mewtwoniteY = obj.mewtwoniteY;

    return *this;

}

/******************************************************************************
//
//  FUNCTIONNAME:   ~Pokemon
//  DESCRIPTION:    Deconstructor for the Pokemon class
//  PARAMETERS:     None
//  RETURNVALUES:   None
//
******************************************************************************/

Mewtwo::~Mewtwo()
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Mewtwo::Mewtwo" << endl;
        cout << "Destructor" << endl;
    #endif

    cout << this->Name() << " Destructor" << endl;

}

/******************************************************************************
//
//  FUNCTIONNAME:   Name
//  DESCRIPTION:    Used to retrieve the name variable value
//  PARAMETERS:     None
//  RETURNVALUES:   name:   this->name
//
******************************************************************************/

string Mewtwo::Name()
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Mewtwo::name" << endl;
    #endif

    return this->name;

}

/******************************************************************************
//
//  FUNCTIONNAME:   Type
//  DESCRIPTION:    Used to retrieve the type variable value
//  PARAMETERS:     None
//  RETURNVALUES:   type:   this->type
//
******************************************************************************/

string Mewtwo::Type()
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Mewtwo::type" << endl;
    #endif

    return this->type;

}

/******************************************************************************
//
//  FUNCTIONNAME:   Height
//  DESCRIPTION:    Used to retrieve the height variable value
//  PARAMETERS:     None
//  RETURNVALUES:   height:   this->height
//
******************************************************************************/

float Mewtwo::Height()
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Mewtwo::height" << endl;
    #endif

    return this->height;

}

/******************************************************************************
//
//  FUNCTIONNAME:   Hp
//  DESCRIPTION:    Used to retrieve the Hit Points variable value
//  PARAMETERS:     None
//  RETURNVALUES:   hp:   this->hp
//
******************************************************************************/

int Mewtwo::Hp()
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Mewtwo::hp" << endl;
    #endif

    return this->hp;

}

/******************************************************************************
//
//  FUNCTIONNAME:   Level
//  DESCRIPTION:    Used to retrieve the level variable value
//  PARAMETERS:     None
//  RETURNVALUES:   level:   this->level
//
******************************************************************************/

int Mewtwo::Level()
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Mewtwo::level" << endl;
    #endif

    return this->level;

}

/******************************************************************************
//
//  FUNCTIONNAME:   Speed
//  DESCRIPTION:    Used to retrieve the speed variable value
//  PARAMETERS:     None
//  RETURNVALUES:   speed:   this->speed
//
******************************************************************************/

int Mewtwo::Speed()
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Mewtwo::speed" << endl;
    #endif

    return this->speed;

}

/******************************************************************************
//
//  FUNCTIONNAME:   Attack
//  DESCRIPTION:    Used to retrieve the attack variable value
//  PARAMETERS:     None
//  RETURNVALUES:   attack:   this->attack
//
******************************************************************************/

int Mewtwo::Attack()
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Mewtwo::attack" << endl;
    #endif

    return this->attack;

}

/******************************************************************************
//
//  FUNCTIONNAME:   Defense
//  DESCRIPTION:    Used to retrieve the defense variable value
//  PARAMETERS:     None
//  RETURNVALUES:   defense:   this->defense
//
******************************************************************************/

int Mewtwo::Defense()
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Mewtwo::defense" << endl;
    #endif

    return this->defense;

}

/******************************************************************************
//
//  FUNCTIONNAME:   Name(string)
//  DESCRIPTION:    Used to set the name variable value
//  PARAMETERS:     None
//  RETURNVALUES:   None
//
******************************************************************************/

void Mewtwo::Name(string newName)
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Mewtwo::name" << endl;
        cout << "PARAMETER - newName: " << newName << endl;
    #endif

    this->name = newName;

}

/******************************************************************************
//
//  FUNCTIONNAME:   Hp(deltaHp)
//  DESCRIPTION:    Used to change the hp value due to damage or healing
//  PARAMETERS:     deltaHp :   (int)
//  RETURNVALUES:   None
//
******************************************************************************/

void Mewtwo::Hp(int deltaHp)
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Mewtwo::hp" << endl;
        cout << "PARAMETER - deltaHp: " << deltaHp << endl;
    #endif

    this->hp += deltaHp;

}

/******************************************************************************
//
//  FUNCTIONNAME:   Level(deltaLevel)
//  DESCRIPTION:    Used to change the level value due to experience
//  PARAMETERS:     deltaLevel :   (int)
//  RETURNVALUES:   None
//
******************************************************************************/

void Mewtwo::Level(int deltaLevel)
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Mewtwo::level" << endl;
        cout << "PARAMETER - deltaLevel: " << deltaLevel << endl;
    #endif

    this->level += deltaLevel;

}

/******************************************************************************
//
//  FUNCTIONNAME:   Speed(deltaSpeed)
//  DESCRIPTION:    Used to change the speed value due to experience or tired
//  PARAMETERS:     deltaSpeed :   (int)
//  RETURNVALUES:   None
//
******************************************************************************/

void Mewtwo::Speed(int deltaSpeed)
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Mewtwo::speed" << endl;
        cout << "PARAMETER - deltaSpeed: " << deltaSpeed << endl;
    #endif

    this->speed += deltaSpeed;

}

/******************************************************************************
//
//  FUNCTIONNAME:   Attack(deltaAttack)
//  DESCRIPTION:    Used to change the attack value due to experience or tired
//  PARAMETERS:     deltaAttack :   (int)
//  RETURNVALUES:   None
//
******************************************************************************/

void Mewtwo::Attack(int deltaAttack)
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Mewtwo::attack" << endl;
        cout << "PARAMETER - deltaAttack: " << deltaAttack << endl;
    #endif

    this->attack += deltaAttack;

}

/******************************************************************************
//
//  FUNCTIONNAME:   Defense(deltaDefense)
//  DESCRIPTION:    Used to change the defense value due to experience or tired
//  PARAMETERS:     deltaDefense :   (int)
//  RETURNVALUES:   None
//
******************************************************************************/

void Mewtwo::Defense(int deltaDefense)
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Mewtwo::defense" << endl;
        cout << "PARAMETER - deltaDefense: " << deltaDefense << endl;
    #endif

    this->defense += deltaDefense;

}

/******************************************************************************
//
//  FUNCTIONNAME:   MegaEvolveX
//  DESCRIPTION:    Used to find out if Mewtwo is using the MewtwoniteX stone
//  PARAMETERS:     None
//  RETURNVALUES:   mewtwoniteX   : boolean
//
******************************************************************************/

bool Mewtwo::MegaEvolveX()
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Mewtwo::megaEvolveX" << endl;
    #endif

    return this->mewtwoniteX;

}

/******************************************************************************
//
//  FUNCTIONNAME:   MegaEvolveY
//  DESCRIPTION:    Used to find out if Mewtwo is using the MewtwoniteY stone
//  PARAMETERS:     None
//  RETURNVALUES:   mewtwoniteY   : boolean
//
******************************************************************************/

bool Mewtwo::MegaEvolveY()
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Mewtwo::megaEvolveY" << endl;
    #endif

    return this->mewtwoniteY;

}

/******************************************************************************
//
//  FUNCTIONNAME:   MegaEvolveX(status)
//  DESCRIPTION:    Used to set if Mewtwo is using the MewtwoniteX stone
//  PARAMETERS:     mewtwoniteX   : (boolean)
//  RETURNVALUES:   None
//
******************************************************************************/

void Mewtwo::MegaEvolveX(bool status)
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Mewtwo::megaEvolveX" << endl;
        cout << "PARAMETER - status: " << status << endl;
    #endif

    if(status)
    {
        this->mewtwoniteY = false;
        this->mewtwoniteX = true;
    }
    else
    {
        this->mewtwoniteX = false;
    }
}

/******************************************************************************
//
//  FUNCTIONNAME:   MegaEvolveY(status)
//  DESCRIPTION:    Used to set if Mewtwo is using the MewtwoniteY stone
//  PARAMETERS:     mewtwoniteY   : (boolean)
//  RETURNVALUES:   None
//
******************************************************************************/

void Mewtwo::MegaEvolveY(bool status)
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Mewtwo::megaEvolveY" << endl;
        cout << "PARAMETER - status: " << status << endl;
    #endif

    if(status)
    {
        this->mewtwoniteX = false;
        this->mewtwoniteY = true;
    }
    else
    {
        this->mewtwoniteY = false;
    }
}
