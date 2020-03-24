/* -----------------------------------------------------------------------------
 *
 * File Name:  Patient.h
 * Author: Marco Borth
 * Assignment:   EECS-268 Lab 10 Program
 * Description:  Patient Class is defined.
 * Date: 5/9/19
 *
 ---------------------------------------------------------------------------- */

#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <iostream>
using namespace std;

class Patient
{
private:
  string firstName, lastName;
  int urgency;

public:

/**
* @return the firstName of the Patient.
*/
  string getFirstName() const;

/**
* @return the lastName of the Patient.
*/
  string getLastName() const;

/**
* @return the urgency of the Patient.
*/
  int getUrgency() const;

/**
* @param first, last, and symptoms are valid strings, years and rating are valid ints.
* @post construct Patient with all of its characteristics defined.
*/
  Patient(string first, string last, int severity);

/**
* @post deletes Patient and its characteristicss.
*/
  ~Patient();
};

#endif
