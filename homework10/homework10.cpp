/******************************************************************************
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
//  FILE:           homework10.cpp
//
//  DESCRIPTION:    This program creates three different Pokémon types on the
//                  heap (Arceus/Mewtwo/Giratina).  The program then loads the
//                  Pokémon into a vector.  The program then iterates through
//                  the vector to print the information for each Pokémon using
//                  the pokedex function.  The program then loads the Pokémon
//                  into a map and repeats the iteration and pokedex function.
//                  The Pokémon are then set free and cleared from the heap. 
//
******************************************************************************/

#include <string>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include "Pokemon.h"
#include "Arceus.h"
#include "Mewtwo.h"
#include "Giratina.h"
using namespace std;

void checkPokedex(Pokemon *);

/******************************************************************************
//
//  FUNCTIONNAME:   main
//  DESCRIPTION:    This program creates three different Pokémon types on the
//                  heap (Arceus/Mewtwo/Giratina).  The program then loads the
//                  Pokémon into a vector.  The program then iterates through
//                  the vector to print the information for each Pokémon using
//                  the pokedex function.  The program then loads the Pokémon
//                  into a map and repeats the iteration and pokedex function.
//                  The Pokémon are then set free and cleared from the heap. 
//  PARAMETERS:     None
//  RETURNVALUES:   0 : success
//
******************************************************************************/

int main(int argc, char *argv [])
{
    cout << "Creating three different Pokemon:" << endl;
    Pokemon * arceus = new Arceus();
    Pokemon * mewtwo = new Mewtwo();
    Pokemon * giratina = new Giratina();

    
    vector<Pokemon*> myVector;

    myVector.push_back(arceus);
    myVector.push_back(mewtwo);
    myVector.push_back(giratina);
    
    map<const string, Pokemon*> myMap;
    myMap.insert(pair<const string, Pokemon*>("arceus", arceus));
    myMap.insert(pair<const string, Pokemon*>("mewtwo", mewtwo));
    myMap.insert(pair<const string, Pokemon*>("giratina", giratina));

    cout << "Displaying the Pokedex for Pokemon stored in my Vector:" << endl;
    vector<Pokemon*>::iterator vectorItr;
    for(vectorItr = myVector.begin(); vectorItr != myVector.end(); ++vectorItr)
    {
        checkPokedex(*vectorItr);
    }

    cout << "Displaying the Pokedex for Pokemon stored in my Map:" << endl;
    map<const string, Pokemon*>::iterator mapItr;
    for(mapItr = myMap.begin(); mapItr != myMap.end(); ++mapItr)
    {
        checkPokedex(mapItr->second);
    }

    cout << "Deleting the Pokemon before exiting the application:" << endl;
    delete giratina;
    delete mewtwo;
    delete arceus;

    return 0;
}

/******************************************************************************
//
//  FUNCTIONNAME:   checkPokedex
//  DESCRIPTION:    Calls the parent class print function to display the childs
//                  detailed information.  Text if formated for readability.
//  PARAMETERS:     None
//  RETURNVALUES:   None
//
******************************************************************************/

void checkPokedex(Pokemon * pokemon)
{
    pokemon->printData();
}
