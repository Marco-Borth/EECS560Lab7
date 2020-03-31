/* -----------------------------------------------------------------------------
 *
 * File Name:  Patient.cpp
 * Author: Marco Borth
 * Assignment:   EECS 560 Lab 7 – Min Heap and Max Heap
 * Description:  Patient Class will return the Patient information.
 * Date: 3/24/20
 *
 ---------------------------------------------------------------------------- */

#include "Patient.h"

Patient::Patient(string first, string last, int severity) {
  firstName = first;
  lastName = last;
  urgency = severity;
}

Patient::~Patient(){}

string Patient::getFirstName() const {
  return firstName;
}

string Patient::getLastName() const {
  return lastName;
}

int Patient::getUrgency() const {
  return urgency;
}
