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

              for (int i = 0; i < PatientNetwork.getSize(); i++) {
                /*cout << "\n" << PatientNetwork.getEntry(i)->getFirstName()
                     << ", " << PatientNetwork.getEntry(i)->getLastName()
                     << ", " << PatientNetwork.getEntry(i)->getPriority();*/
                if ( PatientNetwork.getEntry(i)->getFirstName() == alias &&
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
        // 2. Treat Patient - Complete!
        else if (option == 2) {
          try {
            tempPatient = PatientNetwork.getEntry(0);
            cout << "\nTreating the most urgent Paitent...\n";

            cout << "\nMost urgent Patient listed:";
            cout << "\nFirst Name: " << tempPatient->getFirstName();
            cout << "\nLast Name: " << tempPatient->getLastName();
            cout << "\nUrgency Rating: " << tempPatient->getPriority();


            PatientNetwork.remove(0);

            cout << "\n\nPatient has been treated.\n\n";
            //delete tempPatient;
          } catch (runtime_error) {
            cout << "\n\n> Output: ERROR! There are no more Paitents in the Hospital Queue.\n\n";
          }
        }
        // 3. Change Urgency - Complete!
        else if (option == 3) {
          try {
            string alias, surname;
            int condition;

            cout << "Enter Patient's ID:\n";
            cout << "\nFirst Name: ";
            cin >> alias;
            cout << "\nLast Name: ";
            cin >> surname;

            bool recordFound = false;
            int index = 0;

            for (int i = 0; i < PatientNetwork.getSize(); i++) {
              if ( PatientNetwork.getEntry(i)->getFirstName() == alias &&
                  PatientNetwork.getEntry(i)->getLastName() == surname ) {
                    recordFound = true;
                    index = i;
              }
            }

            if (recordFound) {
              cout << "\n\nCurrent Patient listed:";
              cout << "\nFirst Name: " << PatientNetwork.getEntry(index)->getFirstName();
              cout << "\nLast Name: " << PatientNetwork.getEntry(index)->getLastName();
              cout << "\nUrgency Rating: " << PatientNetwork.getEntry(index)->getPriority();

              cout << "\n\nEnter new Urgency Rating: ";
              cin >> condition;

              while(1) {
                if(cin.fail()) {
                  cin.clear();
                  cin.ignore(numeric_limits<streamsize>::max(),'\n');
                  cout << "\nERROR! Invalid Input!\n\n"; //if not an int, must try again.
                  cout << "\nEnter new Urgency Rating: ";
                  cin >> condition;
                } else {
                  PatientNetwork.remove(index);
                  tempPatient = new Person(alias, surname, condition);
                  PatientNetwork.add(tempPatient);
                  PatientNetwork.bottomUpHeapify();

                  cout << "\n\nPatient Record has been updated.\n\n";

                  break;
                }
              }
            } else {
              cout << "\n\nEntry not Found!\n\n";
            }
          } catch (runtime_error) {
            cout << "\n\n> Output: ERROR! There are no more Paitents in the Hospital Queue.\n\n";
          }
        }
        // 4. Next Patient - Complete!
        else if (option == 4) {
          if (!PatientNetwork.isEmpty()) {
            if (PatientNetwork.getSize() == 1) {
              cout << "\nThere is only the current patient listed:\n\n";
              cout << "\nFirst Name: " << PatientNetwork.getEntry(0)->getFirstName();
              cout << "\nLast Name: " << PatientNetwork.getEntry(0)->getLastName();
              cout << "\nUrgency Rating: " << PatientNetwork.getEntry(0)->getPriority();
            } else  {
              int index = 1;
              if (PatientNetwork.getSize() == 2) {
                index = 1;
              } else if (PatientNetwork.getSize() == 3) {
                if(PatientNetwork.getEntry(1)->getPriority() < PatientNetwork.getEntry(2)->getPriority()) {
                  index = 2;
                }
              } else {
                for (int j = 2; j <= 3; j++) {
        					if (PatientNetwork.getEntry(index)->getPriority() < PatientNetwork.getEntry(j)->getPriority()) {
        						index = j;
        					}
          			}
              }
              cout << "\nNext Patient listed:\n\n";
              cout << "\nFirst Name: " << PatientNetwork.getEntry(index)->getFirstName();
              cout << "\nLast Name: " << PatientNetwork.getEntry(index)->getLastName();
              cout << "\nUrgency Rating: " << PatientNetwork.getEntry(index)->getPriority();
            }
            cout << "\n\n";
          } else {
            cout << "\n> Output: ERROR! There are no more Paitents in the Hospital Queue.\n\n";
          }
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

              for (int i = 0; i < DoctorNetwork.getSize(); i++) {
                /*cout << "\n" << DoctorNetwork.getEntry(i)->getFirstName()
                     << ", " << DoctorNetwork.getEntry(i)->getLastName()
                     << ", " << DoctorNetwork.getEntry(i)->getPriority();*/
                if ( DoctorNetwork.getEntry(i)->getFirstName() == alias &&
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
        // 3. Update Patients - Complete!
        else if (option == 3) {
          try {
            string alias, surname;
            int patients;

            cout << "Enter Doctor's ID for their Number of Patients Assigned to be updated:\n";
            cout << "\nFirst Name: ";
            cin >> alias;
            cout << "\nLast Name: ";
            cin >> surname;

            bool recordFound = false;
            int index = 0;

            for (int i = 0; i < DoctorNetwork.getSize(); i++) {
              if ( DoctorNetwork.getEntry(i)->getFirstName() == alias &&
                  DoctorNetwork.getEntry(i)->getLastName() == surname ) {
                    recordFound = true;
                    index = i;
              }
            }

            if (recordFound) {
              int increment, direction;
              cout << "\n\nCurrent Patient listed:";
              cout << "\nFirst Name: " << DoctorNetwork.getEntry(index)->getFirstName();
              cout << "\nLast Name: " << DoctorNetwork.getEntry(index)->getLastName();
              cout << "\nNumber of Patients Assigned: " << DoctorNetwork.getEntry(index)->getPriority();

              cout << "\n\nSelect 1 to add patients or 0 to reduce patients: ";
              cin >> direction;

              while(1) {
                if (direction != 1 && direction != 0) {
                  cout << "\nERROR! Invalid Input!\n\n"; //if not an int, must try again.
                  cout << "Select 1 to add patients or 0 to reduce patients: ";
                  cin >> direction;
                } else {
                  break;
                }
              }

              cout << "\n\n>Enter the updated count: ";
              cin >> increment;

              while(1) {
                if(cin.fail()) {
                  cin.clear();
                  cin.ignore(numeric_limits<streamsize>::max(),'\n');
                  cout << "\nERROR! Invalid Input!\n\n"; //if not an int, must try again.
                  cout << "\nEnter the updated count: ";
                  cin >> increment;
                } else {
                  if (direction == 1) {
                    patients = DoctorNetwork.getEntry(index)->getPriority() + increment;
                  } else {
                    patients = DoctorNetwork.getEntry(index)->getPriority() - increment;
                  }

                  if (patients < 0) {
                    patients = 0;
                  } else if (patients > 25) {
                    patients = 25;
                  }

                  DoctorNetwork.remove(index);
                  tempDoctor = new Person(alias, surname, patients);
                  DoctorNetwork.add(tempDoctor);
                  DoctorNetwork.bottomUpHeapify();

                  cout << "\n\nDoctor Record has been updated.\n\n";

                  break;
                }
              }
            } else {
              cout << "\n\nEntry not Found!\n\n";
            }
          } catch (runtime_error) {
            cout << "\n\n> Output: ERROR! There are no more Doctors in the Hospital.\n\n";
          }
        }
        // 4. Remove Doctor - Complete!
        else if (option == 4) {
          try {
            tempDoctor = DoctorNetwork.getEntry(0);
            cout << "\nRemoving Doctor with the lowest Number of Assigned Patients from the network...\n";

            cout << "\nDocter listed:";
            cout << "\nFirst Name: " << tempDoctor->getFirstName();
            cout << "\nLast Name: " << tempDoctor->getLastName();
            cout << "\nUrgency Rating: " << tempDoctor->getPriority();


            DoctorNetwork.remove(0);

            cout << "\n\nDoctor has been remove from the network.\n\n";
            //delete tempPatient;
          } catch (runtime_error) {
            cout << "\n\n> Output: ERROR! There are no more Doctors in the Hospital.\n\n";
          }
        }
        // 5. Next Available Doctor - Complete!
        else if (option == 5) {
          if (!DoctorNetwork.isEmpty()) {
            if (DoctorNetwork.getSize() == 1) {
              cout << "\nThere is only the current Doctor Available:\n\n";
              cout << "\nFirst Name: " << DoctorNetwork.getEntry(0)->getFirstName();
              cout << "\nLast Name: " << DoctorNetwork.getEntry(0)->getLastName();
              cout << "\nUrgency Rating: " << DoctorNetwork.getEntry(0)->getPriority();
            } else  {
              int index = 1;
              if (PatientNetwork.getSize() == 2) {
                index = 1;
              } else if (PatientNetwork.getSize() == 3) {
                if(DoctorNetwork.getEntry(1)->getPriority() > DoctorNetwork.getEntry(2)->getPriority()) {
                  index = 2;
                }
              } else {
                for (int j = 2; j <= 3; j++) {
        					if (DoctorNetwork.getEntry(index)->getPriority() > DoctorNetwork.getEntry(j)->getPriority()) {
        						index = j;
        					}
          			}
              }
              cout << "\nNext Doctor Available:\n\n";
              cout << "\nFirst Name: " << DoctorNetwork.getEntry(index)->getFirstName();
              cout << "\nLast Name: " << DoctorNetwork.getEntry(index)->getLastName();
              cout << "\nUrgency Rating: " << DoctorNetwork.getEntry(index)->getPriority();
            }
            cout << "\n\n";
          } else {
            cout << "\n> Output: ERROR! There are no more Paitents in the Hospital Queue.\n\n";
          }
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
