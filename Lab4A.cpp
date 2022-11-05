////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Title                : Lab 4a "String Operations by using Pointers"                                         //
//Author               : Wellington Verduga Macias                                                            //
//Version and Date     : V0.1 11/04/2022                                                                      //
//Copyright disclaimer :                                                                                      //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;

void RequestingNames();//Function to request names from User
void CheckingNames();//Function to check the User Input and split them
void DisplayingResults();//Function to display the First Names and Last Names

string UserNames[5], UserFirstNames[5], UserLastNames[5];
char *FirstNameChecker, *LastNameChecker = nullptr;
int LengthOfNames[5];

int main ()
{
    RequestingNames();
    CheckingNames();
    DisplayingResults();
    delete [] FirstNameChecker, LastNameChecker;
}

void RequestingNames()
{
    cout<<"Enter 5 student's names in format 'Jhon Doe':"<<endl;
    for (int i=0; i<5; i++)//Iteration for User input
    {
        getline(cin, UserNames[i]);//User inputs Names into the array
    }
    
    cout<<"You entered the following names: "<<endl;
    for (int i=0; i<5; i++)//Iteration to display User Input
    {
        cout<<UserNames[i]<<endl;
        LengthOfNames[i] = UserNames[i].length();//Storing the size of strings
    }
}

void CheckingNames()
{
    cout<<"Checking..."<<endl;
    cout<<"..."<<endl;
    cout<<"..."<<endl;
    for (int i=0; i<5; i++)//Iteration to check each string and separate them
    {
        FirstNameChecker = (char *) UserNames[i].c_str();//copies string into char
        for (int j=0; j<LengthOfNames[i]; j++)
        {
            if ( *(FirstNameChecker+j) == ' ')//Scanner for space to end FirstName pointer and start LastName pointer
            {
                FirstNameChecker[j] = '\0';
                LastNameChecker = &(FirstNameChecker[j+1]);
            }
        }
        UserFirstNames[i].assign(FirstNameChecker);//Store the obtained First Name into a string array
        UserLastNames[i].assign(LastNameChecker);//Store the obtained Last Name into a string array
    }
}

void DisplayingResults()
{
    for (int i=0; i<5; i++)//Iteration to display the Full name and its break down to First and Last
    {
        cout<<"The "<<i+1<<"th student's Full name is: "<<FirstNameChecker<<endl;
        cout<<"His/Her first name is: "<<UserFirstNames[i]<<endl;
        cout<<"His/Her last name is: "<<UserLastNames[i]<<endl;
    }
}
