/*******************************************************************************
//
//  NAME:           Craig Opie
//
//  HOMEWORK:       homework7a
//
//  CLASS:          ICS 212
//
//  INSTRUCTOR      Ravi Narayan
//
//  DATE:           Mar 21, 2020
//
//  FILE:           paint.c
//
//  DESCRIPTION:    This file uses recursion to calculate the total cost for 
//                  a painting a specified length of road.
//
******************************************************************************/

#include <stdio.h>
#include "paint.h"

/******************************************************************************
//
//  FUNCTION NAME:  paint
//
//  DESCRIPTION:    paint function calculates the total cost for painting a 
//                  specified length of road.
//
//  PARAMETERS:     length : double specifying the length of the road to be
//                  painted.
//
//  RETURN VALUE:   double : returns the cost of painting the road.
//
******************************************************************************/

double costofpainting(double length)
{
    double cost = 0;

    if (length > 3)
    {
        length -= 3;
        cost += 950;
        cost += costofpainting(0.7 * length) + costofpainting(0.3 * length);
    }
    else
    {
        cost += 300 * length;
    }

    return cost;
}
