/******************************************************************************
//
//  NAME:           Craig Opie
//
//  HOMEWORK:       8
//
//  CLASS:          ICS 212
//
//  INSTRUCTOR:     Ravi Narayan
//
//  DATE:           Mar 30, 2020
//
//  FILE:           homework8.c
//
//  DESCRIPTION:    This program uses a function containing a for-loop to
//                  generate a list of inches vs centimeters, starting from 0
//                  inches to the user provided numer, with an interval of 0.50
//                  inches.
// https://www3.ntu.edu.sg/home/ehchua/programming/java/JavaNativeInterface.html
//
******************************************************************************/

#include <stdio.h>
#include "jni.h"
#include "jni_md.h"


JNIEXPORT jdouble JNICALL 

Java_Homework9_convert(JNIEnv * env, jobject obj, jdouble inch)
{
    return (inch * 2.54);
}