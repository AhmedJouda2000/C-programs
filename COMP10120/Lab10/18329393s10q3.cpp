/*
This is set 10 Question 3. In C++, create a Student Class which a university
uses to represent the students in a university management system. The Student
Class should have appropriate data members to uniquely identify a student,
provide their name, address, phone number, field of study, stage and current GPA.
The Student Class should also have appropriate mutator and accessor member
functions. Member functions to increase a student’s stage should be provided.
Additionally member functions to decrease and decrease the student’s GPA are
required. Finally a warning should be issued if the GPA of a student falls
below 2.

This is the work of Ahmed Jouda (Student Number 18329393)
Created on 19/04/2019
*/

//include the libraries needed
#include <iostream>
#include <string>
#include <iomanip>  //contains setpercision()
using namespace std;

// StudentClass class definition
class studentClass
{
  private:

      //variable definitions for each data required
      string studentPhoneNo;  //make sure phone number is a string so 0 at start is stored
      int studentStage;
      float studentGPA;
      string studentcourse;
      string studentName;
      string studentAddress;

  public:

      //function that sets the name by the user input
      void setName(string name)
      {
        studentName = name;
      }
      //function that returns the student name to print it
      string getName() const
      {
        return studentName;
      }

      //function that sets the address by the user input
      void setAddress(string address)
      {
        studentAddress = address;
      }

      //function that returns the address to print it
      string getAddress() const
      {
        return studentAddress;
      }

      //function that sets the phone number by the user input
      void setPhoneNo(string phNumber)
      {
        studentPhoneNo = phNumber;
      }

      //function that returns the phone number to print it
      string getPhoneNo() const
      {
        return studentPhoneNo;
      }

      //function that sets the field of study by the user input
      void setcourse(string course)
      {
        studentcourse = course;
      }

      //function that returns the field of study to print it
      string getcourse() const
      {
        return studentcourse;
      }

      //function that sets the stage(year) by the user input
      void setStage(int stage)
      {
        studentStage = stage;
      }

      // function to increment student's stage(year) by 1 if needed and return
      //the updated stage(year)
      void increaseStage()
      {
        studentStage++;
      }

      //function that returns the stage(year) to print it
      int getStage() const
      {
        return studentStage;
      }

      //function that sets the GPA by the user input
      void setStudentGPA(double GPA)
      {
        studentGPA = GPA;
      }

      // function to increase student's GPA if needed and return the updated GPA
      void increaseGPA(float update)
      {
        studentGPA = studentGPA + update;
      }

      // function to decrease student's GPA if needed and return the updated GPA
      void decreaseGPA(float update)
      {
        studentGPA = studentGPA - update;
      }

      //function that returns the GPA to print it
      float getStudentGPA() const
      {
        return studentGPA;
      }

};

//declare the function main that returns 0
int main()
{
  //declare variables needed such as variables to store user's choice and data
  int choice = 0;
  int student_choice = 0;
  int edit_choice = 0;
  int stage;
  string name, address, course;
  float GPA;
  float update = 0;
  string phone_number;

  //declare 2 student objects
  studentClass student_1;
  studentClass student_2;

  //while the user didnt want to exit the program (enter 3), keep looping
  while(student_choice == 0)
  {
    //prompt the user to choose which student he wants to view, store the choice in "student_choice"
    cout << "\n** Home ** \n\nEnter 1 to choose the first Student \nEnter 2 to choose the second Student \nEnter 3 to exit the program\n";
    cin >> student_choice;
    choice = 0; //assign 0 to "choice" each time this loops

      //if user inputed 1, enter the following statement
      if(student_choice == 1)
      {
        //assign 0 to student_choice so we stay in the outter while loop
        student_choice = 0;

        //keep looping the following until user inputs 4
        while(choice == 0)
        {
          //prompt the user to input the action he wants and store his choice in "choice"
          cout << "\n ** 1st Student **\n\nEnter 1 to add  a new record \nEnter 2 to view current details \nEnter 3 to update the record \nEnter 4 to return to Home\n";
          cin >> choice;

          //if the user chooses to add a new record enter the following statement
          if(choice == 1)
          {
            //re-assign 0 to choice so we stay in the inner while loop
            choice = 0;

            //prompt the user to input the student's data
            //as getline() is used after << I duplicate the call as the 1st time getline() takes in \n left from << (only for strings)
            //then we store the variable into the correct student class variable
            //we do this to all the data required
            cout << "Student Name: ";
            getline(cin, name);
            getline(cin, name);
            student_1.setName(name);

            cout << "Address: ";
            getline(cin, address);
            student_1.setAddress(address);

            cout << "Phone Number: ";
            cin >>  phone_number;
            student_1.setPhoneNo(phone_number);

            cout << "Field of Study: ";
            getline(cin, course);
            getline(cin, course);
            student_1.setcourse(course);

            cout << "Stage: ";
            cin >>  stage;
            student_1.setStage(stage);

            cout << "GPA: ";
            cin >>  GPA;
            student_1.setStudentGPA(GPA);
            cout << endl;

          }

          //else if the user chooses to view the details
          else if(choice == 2)
          {
            //re-assign 0 to choice so we stay in the inner while loop
            choice = 0;

            //print out all the data stored using the get functions that return the required data values
            cout << "\n ** 1st Student Details **\n\nStudent Name: " << student_1.getName()  << "\nAddress: " << student_1.getAddress() << "\nPhone Number: " << student_1.getPhoneNo() << "\nField of Study: " << student_1.getcourse() << "\nStage: Year " << student_1.getStage() << "\nGPA: " << setprecision(5) << student_1.getStudentGPA() << endl;

            //incase the student's GPA is less than 2, display a warning
            if(student_1.getStudentGPA() < 2.0)
            {
              cout << " WARNING - GPA less than 2.0 " << endl;
            }
          }

          //If the user chooses to update the student's details enter the following statement
          else if(choice == 3)
          {
            //while the user didnt enter 4
            while(edit_choice == 0)
            {
              //prompt the user to select what type of update he wants to perform, store the choice in edit_choice
              cout << "\n** Update 1st Student Details **\n\nEnter 1 to update stage\nEnter 2 to increase GPA\nEnter 3 to decrease GPA\nEnter 4 to return to Home\n";
              cin >> edit_choice;

              //if the user chooses to increase stage enter the following statement
              if(edit_choice == 1)
              {
                //re-assign 0 to edit_choice to stay in the inner while loop
                edit_choice = 0;
                //call the increase stage function for student 1
                student_1.increaseStage();
                cout << "\nIncreased Stage\n";
              }

              //if the user chooses to increase GPA enter the following statement
              else if(edit_choice == 2)
              {
                //re-assign 0 to edit_choice to stay in the inner while loop
                edit_choice = 0;
                //prompt the user to specify how much he wants to increase the GPA by and store the number in "update"
                cout << "Increase GPA by: ";
                cin >> update;
                //call the increaseGPA  function for student 1 with "update" as the parameter
                student_1.increaseGPA(update);
                cout << "\nIncreased GPA\n";
              }

              //if the user chooses to decrease GPA enter the following statement
              else if(edit_choice == 3)
              {
                //re-assign 0 to edit_choice to stay in the inner while loop
                edit_choice = 0;
                //prompt the user to specify how much he wants to decrease the GPA by and store the number in "update"
                cout << "Decrease GPA by: ";
                cin >> update;
                //call the decreaseGPA function for student 1 with "update" as the parameter
                student_1.decreaseGPA(update);
                cout << "\nDecreased GPA\n";
              }

              //if the user inputs 4 enter the following statement
              else if(edit_choice == 4)
              {
                //re-assign 0 to edit_choice
                edit_choice = 0;
                //return to home page (previous while loop) using break;
                cout << "\n\nBack to Homepage" << endl;
                break;
              }
            }
          }

          //if the user chooses 4
          else if(choice == 4)
          {
            //return to the HomePage using break;
            cout << "\n\nBack to Homepage" << endl;
            break;
          }

          //if another number was inputted display an invalid input message
          else
          {
            cout << "\n\nPlease check entry and try again!" << endl;
          }
        }
      }



      //for student 2 the exact same algorithm as above is used
      else if(student_choice == 2)
      {
        student_choice = 0;

        while(choice == 0)
        {
          cout << "\n ** 2nd Student**\n\nEnter 1 to add a new record \nEnter 2 to view current details\nEnter 3 to update details\nEnter 4 to return to Home\n";
          cin >> choice;

          if(choice == 1)
          {
            choice = 0;

            cout << "Student Name: ";
            getline(cin, name);
            getline(cin, name);
            student_2.setName(name);

            cout << "Address: ";
            getline(cin, address);
            student_2.setAddress(address);

            cout << "Phone Number: ";
            cin >>  phone_number;
            student_2.setPhoneNo(phone_number);

            cout << "Field of Study: ";
            getline(cin, course);
            getline(cin, course);
            student_2.setcourse(course);

            cout << "Stage: ";
            cin >>  stage;
            student_2.setStage(stage);

            cout << "GPA: ";
            cin >>  GPA;
            student_2.setStudentGPA(GPA);
            cout << endl;

          }

          else if(choice == 2)
          {
            choice = 0;

            cout << "\n ** 2nd Student Details**\n\nStudent Name: " << student_2.getName() << "\nAddress: " << student_2.getAddress() << "\nPhone Number: " << student_2.getPhoneNo() << "\nField of Study: " << student_2.getcourse() << "\nStage: Year " << student_2.getStage() << "\nGPA: " << student_2.getStudentGPA() << endl;

            if(student_2.getStudentGPA() < 2.0)
            {
              cout << " WARNING - GPA less than 2.0 " << endl;
            }
          }

          else if(choice == 3)
          {
            while(edit_choice == 0)
            {
              cout << "\n ** Update 2nd Student Details**\n\nEnter 1 to increase stage\nEnter 2 to increase GPA\nEnter 3 to decrease GPA\nEnter 4 to return to Home\n";
              cin >> edit_choice;

              if(edit_choice == 1)
              {
                edit_choice = 0;
                student_2.increaseStage();
                cout << "\nIncreased Stage\n";
              }

              else if(edit_choice == 2)
              {
                edit_choice = 0;
                cout << "Increase GPA by: ";
                cin >> update;
                student_2.increaseGPA(update);
                cout << "\nIncreased GPA\n";
              }

              else if(edit_choice == 3)
              {
                edit_choice = 0;
                cout << "Decrease GPA by: ";
                cin >> update;
                student_2.decreaseGPA(update);
                cout << "\nDecreased GPA\n";
              }

              else if(edit_choice == 4)
              {
                edit_choice = 0;
                cout << "\n\nBack to Homepage" << endl;
                break;
              }
            }
          }

          else if(choice == 4)
          {
            cout << "\n\nBack to Homepage" << endl;
            break;
          }

          else
          {
            cout << "\n\nInvalid Input" << endl;
          }
        }
      }

      else if(student_choice == 3)
      {
        cout << "\nTHANK YOU!" << endl;
        return 0;
      }

      else
      {
        cout << "\nCheck your input\n" << endl;
        student_choice = 0;
      }
  }

  return 0;
}
