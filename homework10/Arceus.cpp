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
//  FILE:           Arceus.cpp
//
//  DESCRIPTION:    This file initiates the child class Arceus.
//
******************************************************************************/

#include <string>
#include <iostream>
#include "Arceus.h"
using namespace std;


/******************************************************************************
//
//  FUNCTIONNAME:   Pokemon
//  DESCRIPTION:    Default constructor for the Pokemon Class
//  PARAMETERS:     None
//  RETURNVALUES:   None
//
******************************************************************************/

Arceus::Arceus()
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Arceus::Arceus" << endl;
    #endif

    this->hp = 120;
    this->level = 1;
    this->speed = 120;
    this->attack = 120;
    this->defense = 120;
    this->name = "Arceus";
    this->type = "Normal";
    this->height = 3.2;

    cout << this->Name() << " Constructor" << endl;
    cout << endl;

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

Arceus::Arceus(string newType, float newHeight)
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Arceus::Arceus" << endl;
        cout << "PARAMETER - newType: " << newType << endl;
        cout << "PARAMETER - newHeight: " << newHeight << endl;
    #endif

    this->hp = 120;
    this->level = 1;
    this->speed = 120;
    this->attack = 120;
    this->defense = 120;
    this->name = "Arceus";
    this->type = newType;
    this->height = newHeight;

    cout << this->Name() << " Constructor" << endl;
    cout << endl;

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

Arceus::Arceus(const Arceus & obj)
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Arceus::Arceus" << endl;
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

Arceus & Arceus::operator = (const Arceus & obj)
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Arceus::Arceus" << endl;
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

Arceus::~Arceus()
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Arceus::Arceus" << endl;
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

string Arceus::Name()
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Arceus::name" << endl;
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

string Arceus::Type()
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Arceus::type" << endl;
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

float Arceus::Height()
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Arceus::height" << endl;
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

int Arceus::Hp()
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Arceus::hp" << endl;
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

int Arceus::Level()
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Arceus::level" << endl;
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

int Arceus::Speed()
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Arceus::speed" << endl;
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

int Arceus::Attack()
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Arceus::attack" << endl;
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

int Arceus::Defense()
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Arceus::defense" << endl;
    #endif

    return this->defense;

}

/******************************************************************************
//
//  FUNCTIONNAME:   Name(newName)
//  DESCRIPTION:    Used to set the name variable value
//  PARAMETERS:     newName : (string)
//  RETURNVALUES:   None
//
******************************************************************************/

void Arceus::Name(string newName)
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Arceus::name" << endl;
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

void Arceus::Hp(int deltaHp)
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Arceus::hp" << endl;
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

void Arceus::Level(int deltaLevel)
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Arceus::level" << endl;
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

void Arceus::Speed(int deltaSpeed)
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Arceus::speed" << endl;
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

void Arceus::Attack(int deltaAttack)
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Arceus::attack" << endl;
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

void Arceus::Defense(int deltaDefense)
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Arceus::defense" << endl;
        cout << "PARAMETER - deltaDefense: " << deltaDefense << endl;
    #endif

    this->defense += deltaDefense;

}

/******************************************************************************
//
//  FUNCTIONNAME:   ChangeType(newType)
//  DESCRIPTION:    Used to change the type value (special ability)
//  PARAMETERS:     newType :   (string)
//  RETURNVALUES:   None
//
******************************************************************************/

void Arceus::ChangeType(string newType)
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Arceus::changeType" << endl;
        cout << "PARAMETER - newType: " << newType << endl;
    #endif

    this->type = newType;

}
