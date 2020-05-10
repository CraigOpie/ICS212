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
//  FILE:           Pokemon.cpp
//
//  DESCRIPTION:    This file initiates the parent class Pokemon.
//
******************************************************************************/

#include <string>
#include <iomanip>
#include <iostream>
#include "Pokemon.h"
using namespace std;


/******************************************************************************
//
//  FUNCTIONNAME:   Pokemon
//  DESCRIPTION:    Default constructor for the Pokemon Class
//  PARAMETERS:     None
//  RETURNVALUES:   None
//
******************************************************************************/

Pokemon::Pokemon()
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Pokemon::Pokemon" << endl;
    #endif
    
    this->name = "Pokemon";

    cout << this->Name() << " Constructor" << endl;

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

Pokemon::Pokemon(string newType, float newHeight)
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Pokemon::Pokemon" << endl;
        cout << "PARAMETER - newType: " << newType << endl;
        cout << "PARAMETER - newHeight: " << newHeight << endl;
    #endif

    this->hp = 100;
    this->level = 1;
    this->speed = 10;
    this->attack = 10;
    this->defense = 10;
    this->name = "Pokemon";
    this->type = newType;
    this->height = newHeight;

    cout << this->Name() << " Constructor" << endl;

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

Pokemon::Pokemon(const Pokemon & obj)
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Pokemon::Pokemon" << endl;
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

Pokemon & Pokemon::operator = (const Pokemon & obj)
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Pokemon::Pokemon" << endl;
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

Pokemon::~Pokemon()
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Pokemon::Pokemon" << endl;
        cout << "Destructor" << endl;
    #endif

    cout << "Pokemon Destructor" << endl;
    cout << endl;

}

/******************************************************************************
//
//  FUNCTIONNAME:   printData
//  DESCRIPTION:    Prints all of the Pokemon's information for the user to see
//  PARAMETERS:     None
//  RETURNVALUES:   None
//
******************************************************************************/

void Pokemon::printData()
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Pokemon::printData" << endl;
    #endif

    cout.precision(2);
    cout.width(11);

    cout << right << setw(11) << setfill(' ') << "Name:";
    cout << right << setw(11) << setfill(' ') << this->Name() << endl;
    cout << right << setw(11) << setfill(' ') << "Type:";
    cout << right << setw(11) << setfill(' ') << this->Type() << endl;
    cout << right << setw(11) << setfill(' ') << "Height:";
    cout << right << setw(11) << setfill(' ') << fixed << this->Height() << endl;
    cout << right << setw(11) << setfill(' ') << "Hit Points:";
    cout << right << setw(11) << setfill(' ') << this->Hp() << endl;
    cout << right << setw(11) << setfill(' ') << "Level:";
    cout << right << setw(11) << setfill(' ') << this->Level() << endl;
    cout << right << setw(11) << setfill(' ') << "Speed:";
    cout << right << setw(11) << setfill(' ') << this->Speed() << endl;
    cout << right << setw(11) << setfill(' ') << "Attack:";
    cout << right << setw(11) << setfill(' ') << this->Attack() << endl;
    cout << right << setw(11) << setfill(' ') << "Defense:";
    cout << right << setw(11) << setfill(' ') << this->Defense() << endl;
    cout << endl;

}

/******************************************************************************
//
//  FUNCTIONNAME:   Name
//  DESCRIPTION:    Used to retrieve the name variable value
//  PARAMETERS:     None
//  RETURNVALUES:   name:   this->name
//
******************************************************************************/

string Pokemon::Name()
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: Pokemon::name" << endl;
    #endif

    return this->name;

}
