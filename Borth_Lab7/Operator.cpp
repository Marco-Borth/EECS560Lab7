/* -----------------------------------------------------------------------------
 *
 * File Name:  Operator.cpp
 * Author: Marco Borth
 * Assignment:   EECS-560 Lab 6 – Implementation of Binary Search Trees
 * Description:  Operator Class will run the Interactive program for a Binary Search Tree.
 * Date: 3/12/20
 *
 ---------------------------------------------------------------------------- */

#include "Operator.h"
#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

Operator::Operator(string file1, string file2){
  doctersFile = file1;
  DoctorNetwork.setKary(3);
  DoctorNetwork.setPriority("min");
  paitientsFile = file2;
  PatientNetwork.setKary(3);
  PatientNetwork.setPriority("max");

  //Open File.
  inFile.open(doctersFile);

  if (!inFile.is_open()) {
    cout << "Doctors Network File name not valid!\n\n";
  } else {
    string alias, surname, patients;
    int InputFailures = 0;
    while (!inFile.eof()) {
      inFile >> input;
      alias = "";
      surname = "";
      patients = "";

      if(inFile.fail()) {
        inFile.clear();
        inFile.ignore(numeric_limits<streamsize>::max(),'\n');
        InputFailures++;
      } else {
        int j = 0;
        for(int i = 0; i < input.length(); i++) {
          if(input.at(i) != ',') {
            if(j == 0)
              alias = alias + input.at(i);
            else if (j == 1)
              surname = surname + input.at(i);
            else
              patients = patients + input.at(i);
          } else {
            j++;
          }
        }
        //cout << alias << " " << surname << " " << condition << "\n";

        tempDoctor = new Person(alias, surname, stoi(patients));
        DoctorNetwork.add(tempDoctor);
      }
    }

    if(InputFailures > 1)
      cout << "ERROR! Invalid Input for Doctor Network Detected: " << InputFailures << "\n";
  }

  inFile.close();
  // Close File.
  DoctorNetwork.bottomUpHeapify();

  //Open File.
  inFile.open(paitientsFile);

  if (!inFile.is_open()) {
    cout << "Patients Queue File name not valid!\n\n";
  } else {
    string alias, surname, condition;
    int InputFailures = 0;
    while (!inFile.eof()) {
      inFile >> input;
      alias = "";
      surname = "";
      condition = "";

      if(inFile.fail()) {
        inFile.clear();
        inFile.ignore(numeric_limits<streamsize>::max(),'\n');
        InputFailures++;
      } else {
        int j = 0;
        for(int i = 0; i < input.length(); i++) {
          if(input.at(i) != ',') {
            if(j == 0)
              alias = alias + input.at(i);
            else if (j == 1)
              surname = surname + input.at(i);
            else
              condition = condition + input.at(i);
          } else {
            j++;
          }
        }
        //cout << alias << " " << surname << " " << condition << "\n";

        tempPatient = new Person(alias, surname, stoi(condition));
        PatientNetwork.add(tempPatient);
      }
    }

    if(InputFailures > 1)
      cout << "ERROR! Invalid Input for Doctor Network Detected: " << InputFailures << "\n";
  }

  inFile.close();
  // Close File.
  PatientNetwork.bottomUpHeapify();
}

void Operator::MainMenu() {
  cout << "----------------------------------Hospital Patient & Doctor Management System------------------------\n\n";
  cout << "1. Patient Management\n";
  cout << "2. Doctor Assignment\n";
  cout << "3. Exit\n\n> ";
}

void Operator::printDoctorTerminal() {
  cout << "---------------------------------------------Doctor Assignment System-----------------------------------------\n\n";
  cout << "1.  New Doctor\n";
  cout << "2.  Assign Patient\n";
  cout << "3.  Update Patients\n";
  cout << "4.  Remove Doctor\n";
  cout << "5.  Next Available Doctor\n";
  cout << "6.  Check Availability\n";
  cout << "7.  Total Doctor Count\n";
  cout << "8.  Available Doctor Count\n";
  cout << "9.  Available Doctors Report\n";
  cout << "10. Busy Doctors List\n";
  cout << "11. Go Back to Menu\n\n> ";
}

void Operator::printPatientPortal() {
  cout << "---------------------------------------------Patient Management System--------------------------------------\n\n";
  cout << "1. New Patient\n";
  cout << "2. Treat Patient\n";
  cout << "3. Change Urgency\n";
  cout << "4. Next Patient\n";
  cout << "5. Last Patient\n";
  cout << "6. Patient Token\n";
  cout << "7. Patients Count\n";
  cout << "8. Patients Report\n";
  cout << "9. Go Back to Menu\n\n> ";
}

void Operator::run() {
  cout << "\nWelcome to the Interactive Binary Search Tree Program!\n\n";

  do {
    MainMenu();
    cin >> option;

    while(1) {
      // Error Handling for an non-number entry.
      if(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "\nERROR! Invalid Option!\n\n"; //if not an int, must try again.
        MainMenu();
        cin >> option;
      }
      // Operation Number has been selected.
      else {
        // 1. Patient Management - Complete!
        if (option == 1) {
          PatientManagementSystem();
        }
        // 2. Doctor Assignment - Complete!
        else if (option == 2) {
          DoctorManagementSystem();
        }
        // 3. Exit - Complete!
        else if (option == 3) {
          cout << "\nClosing Program...\n";
        }
        // Otherwise - Complete!
        else {
          cout << "\nERROR! Invalid Option!\n\n";
        }

        break;
      }
    }
  } while(option != 3);

  cout << "\nBye Bye!\n";
  cout << "\nHave a nice day!...\n\n";
}

void Operator::PatientManagementSystem() {
  do {
    printPatientPortal();
    cin >> option;

    while(1) {
      // Error Handling for an non-number entry.
      if(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "\nERROR! Invalid Option!\n\n"; //if not an int, must try again.
        printPatientPortal();
        cin >> option;
      }
      // Operation Number has been selected.
      else {
        // 1. New Patient - Complete!
        if (option == 1) {
          string alias, surname;
          int condition;

          cout << "\nEnter New Patient's ID and their urgency rating:\n";
          cout << "\nFirst Name: ";
          cin >> alias;
          cout << "\nLast Name: ";
          cin >> surname;
          cout << "\nUrgency Rating: ";
          cin >> condition;

          while(1) {
            if(cin.fail()) {
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(),'\n');
              cout << "\nERROR! Invalid Input!\n\n"; //if not an int, must try again.
              cout << "\nCheck the input for New Patient's ID and Urgency Rating:\n";
              cout << "\nFirst Name: ";
              cin >> alias;
              cout << "\nLast Name: ";
              cin >> surname;
              cout << "\nUrgency Rating: ";
              cin >> condition;
            } else {
              bool notADuplicate = true;

              for(int i = 0; i < PatientNetwork.getSize(); i++) {
                /*cout << "\n" << PatientNetwork.getEntry(i)->getFirstName()
                     << ", " << PatientNetwork.getEntry(i)->getLastName()
                     << ", " << PatientNetwork.getEntry(i)->getPriority();*/
                if( PatientNetwork.getEntry(i)->getFirstName() == alias &&
                    PatientNetwork.getEntry(i)->getLastName() == surname &&
                    PatientNetwork.getEntry(i)->getPriority() == condition ) {
                      notADuplicate = false;
                }
              }
              //cout << "\n\n";

              if (notADuplicate) {
                tempPatient = new Person(alias, surname, condition);
                PatientNetwork.add(tempPatient);
                PatientNetwork.bottomUpHeapify();
              } else {
                cout << "\nERROR! Duplicate Entry Already Exists.\n\n";
              }

              break;
            }
          }

        }
        // 2. Doctor Assignment - Complete!
        else if (option == 2) {
          //DoctorManagementSystem();
        }
        // 9. Exit - Complete!
        else if (option == 9) {
          cout << "\nExiting Patient Management System...\n\n";
        }
        // Otherwise - Complete!
        else {
          cout << "\nERROR! Invalid Option!\n\n";
        }

        break;
      }
    }
  } while (option != 9);
}

void Operator::DoctorManagementSystem() {
  do {
    printDoctorTerminal();
    cin >> option;

    while(1) {
      // Error Handling for an non-number entry.
      if(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "\nERROR! Invalid Option!\n\n"; //if not an int, must try again.
        printDoctorTerminal();
        cin >> option;
      }
      // Operation Number has been selected.
      else {
        // 1. New Doctor - Complete!
        if (option == 1) {
          string alias, surname;

          cout << "\nEnter New Doctor's ID:\n";
          cout << "\nFirst Name: ";
          cin >> alias;
          cout << "\nLast Name: ";
          cin >> surname;

          while(1) {
            if(cin.fail()) {
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(),'\n');
              cout << "\nERROR! Invalid Input!\n\n"; //if not an int, must try again.
              cout << "\nCheck the input for New Doctor's ID:\n";
              cout << "\nFirst Name: ";
              cin >> alias;
              cout << "\nLast Name: ";
              cin >> surname;
            } else {
              bool notADuplicate = true;

              for(int i = 0; i < DoctorNetwork.getSize(); i++) {
                /*cout << "\n" << DoctorNetwork.getEntry(i)->getFirstName()
                     << ", " << DoctorNetwork.getEntry(i)->getLastName()
                     << ", " << DoctorNetwork.getEntry(i)->getPriority();*/
                if( DoctorNetwork.getEntry(i)->getFirstName() == alias &&
                    DoctorNetwork.getEntry(i)->getLastName() == surname) {
                      notADuplicate = false;
                }
              }
              //cout << "\n\n";

              if (notADuplicate) {
                tempDoctor = new Person(alias, surname, 0);
                DoctorNetwork.add(tempDoctor);
                DoctorNetwork.bottomUpHeapify();
              } else {
                cout << "\nERROR! Duplicate Entry Already Exists.\n\n";
              }

              break;
            }
          }

        }
        // 2. Doctor Assignment - Complete!
        else if (option == 2) {
          //DoctorManagementSystem();
        }
        // 11. Exit - Complete!
        else if (option == 11) {
          cout << "\nExiting Doctor Management System...\n\n";
        }
        // Otherwise - Complete!
        else {
          cout << "\nERROR! Invalid Option!\n\n";
        }

        break;
      }
    }
  } while (option != 11);
}
