/* -----------------------------------------------------------------------------
 *
 * File Name:  Doctor.cpp
 * Author: Marco Borth
 * Assignment:   EECS 560 Lab 7 – Min Heap and Max Heap
 * Description:  Doctor Class will return the Doctor information.
 * Date: 3/31/20
 *
 ---------------------------------------------------------------------------- */

#include "Doctor.h"

Doctor::Doctor(string first, string last, int patients) {
  firstName = first;
  lastName = last;
  patientsAssigned = patients;
}

Doctor::~Doctor(){}

string Doctor::getFirstName() const {
  return firstName;
}

string Doctor::getLastName() const {
  return lastName;
}

int Doctor::getPatientsAssigned() const {
  return patientsAssigned;
}
