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
//  FILE:           Giratina.cpp
//
//  DESCRIPTION:    This file initiates the child class Giratina.
//
******************************************************************************/

#include <string>
#include <iostream>
#include "Giratina.h"
using namespace std;


/******************************************************************************
//
//  FUNCTIONNAME:   Pokemon
//  DESCRIPTION:    Default constructor for the Pokemon Class
//  PARAMETERS:     None
//  RETURNVALUES:   None
//
******************************************************************************/

Giratina::Giratina()
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Giratina::Giratina" << endl;
    #endif

    this->hp = 150;
    this->level = 1;
    this->speed = 90;
    this->attack = 120;
    this->defense = 100;
    this->name = "Giratina";
    this->type = "Ghost";
    this->height = 6.9;

    cout << this->Name() << " Constructor" << endl;
    cout << endl;

    this->thisDimension = true;

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

Giratina::Giratina(string newType, float newHeight)
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Giratina::Giratina" << endl;
        cout << "PARAMETER - newType: " << newType << endl;
        cout << "PARAMETER - newHeight: " << newHeight << endl;
    #endif

    this->hp = 150;
    this->level = 1;
    this->speed = 90;
    this->attack = 120;
    this->defense = 100;
    this->name = "Giratina";
    this->type = newType;
    this->height = newHeight;

    cout << this->Name() << " Constructor" << endl;
    cout << endl;

    this->thisDimension = true;

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

Giratina::Giratina(const Giratina & obj)
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Giratina::Giratina" << endl;
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

    this->thisDimension = obj.thisDimension;

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

Giratina & Giratina::operator = (const Giratina & obj)
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Giratina::Giratina" << endl;
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

    this->thisDimension = obj.thisDimension;

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

Giratina::~Giratina()
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Giratina::Giratina" << endl;
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

string Giratina::Name()
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Giratina::name" << endl;
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

string Giratina::Type()
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Giratina::type" << endl;
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

float Giratina::Height()
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Giratina::height" << endl;
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

int Giratina::Hp()
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Giratina::hp" << endl;
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

int Giratina::Level()
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Giratina::level" << endl;
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

int Giratina::Speed()
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Giratina::speed" << endl;
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

int Giratina::Attack()
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Giratina::attack" << endl;
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

int Giratina::Defense()
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Giratina::defense" << endl;
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

void Giratina::Name(string newName)
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Giratina::name" << endl;
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

void Giratina::Hp(int deltaHp)
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Giratina::hp" << endl;
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

void Giratina::Level(int deltaLevel)
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Giratina::level" << endl;
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

void Giratina::Speed(int deltaSpeed)
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Giratina::speed" << endl;
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

void Giratina::Attack(int deltaAttack)
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Giratina::attack" << endl;
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

void Giratina::Defense(int deltaDefense)
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Giratina::defense" << endl;
        cout << "PARAMETER - deltaDefense: " << deltaDefense << endl;
    #endif

    this->defense += deltaDefense;

}

/******************************************************************************
//
//  FUNCTIONNAME:   ThisDimension
//  DESCRIPTION:    Used to find out if the Giratina is in our dimension
//  PARAMETERS:     None
//  RETURNVALUES:   thisDimension   : boolean
//
******************************************************************************/

bool Giratina::ThisDimension()
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Giratina::thisDimension" << endl;
    #endif

    return this->thisDimension;

}

/******************************************************************************
//
//  FUNCTIONNAME:   ThisDimension(status)
//  DESCRIPTION:    Used to set whether the Giratina is in our dimension
//  PARAMETERS:     status  : (boolean)
//  RETURNVALUES:   None
//
******************************************************************************/

void Giratina::ThisDimension(bool status)
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Giratina::thisDimension" << endl;
        cout << "PARAMETER - status: " << status << endl;
    #endif

    this->thisDimension = status;

}
