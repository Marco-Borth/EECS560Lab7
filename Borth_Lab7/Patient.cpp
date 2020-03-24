/* -----------------------------------------------------------------------------
 *
 * File Name:  Patient.cpp
 * Author: Marco Borth
 * Assignment:   EECS-268 Lab 10 Program
 * Description:  Patient Class will return the Patient information.
 * Date: 5/9/19
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
