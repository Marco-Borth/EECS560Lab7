/* -----------------------------------------------------------------------------
 *
 * File Name:  Doctor.h
 * Author: Marco Borth
 * Assignment:   EECS 560 Lab 7 – Min Heap and Max Heap
 * Description:  Doctor Class is defined.
 * Date: 3/31/20
 *
 ---------------------------------------------------------------------------- */

#ifndef DOCTOR_H
#define DOCTOR_H

#include <string>
#include <iostream>
using namespace std;

class Doctor
{
private:
  string firstName, lastName;
  int patientsAssigned;

public:

/**
* @return the firstName of the Doctor.
*/
  string getFirstName() const;

/**
* @return the lastName of the Doctor.
*/
  string getLastName() const;

/**
* @return the number of patientsAssigned to the Doctor.
*/
  int getPatientsAssigned() const;

/**
* @param first, last, and symptoms are valid strings, years and rating are valid ints.
* @post construct Doctor with all of its characteristics defined.
*/
  Doctor(string first, string last, int patients);

/**
* @post deletes Doctor and its characteristicss.
*/
  ~Doctor();
};

#endif
