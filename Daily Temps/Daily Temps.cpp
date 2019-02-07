//Author: Dylan Hesser
//Date: 7/15/2018
/* This program will allow one to gather the temperatures for 24 hours on each of two days. 
It will then compute the mean and standard deviance of these two days. */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>
using namespace std;
ifstream inStream; 
//Standard intro function
void intro()
   {
       cout << "Hello! This program will allow you to compare the temperatures of the hours of two days. \nIt will then give you the mean and the standard deviation." << endl ;
   }
//This will print the two dates that show up on the file first
string printDate ( string date1, string date2  )
   {
       cout << "Hour              ";
       cout << date1 << "              ";
       cout << date2 << endl;
   }
//This will read the file and gather up all the different variables and assign them. 
string readFile(ifstream& inStream, string &date1, string &date2, double temp1[], double temp2[], int hours) 
   { 
       int i;
       inStream >> date1;
       inStream >> date2;
       for (i = 1; i <= 24; i++)
         {
            inStream >> temp1[i];
            inStream >> temp2[i];

         }
   }
//Will print the results to the console   
string printResults (int hours, double temp1[], double temp2[],double mean1,double mean2,double deviation1,double deviation2)
   {
        int i;
        for ( i= 1; i <= hours; i++)
          {
            cout << i << "                  \t";
            cout << temp1[i] << "                    \t";
            cout << temp2[i] << endl;
          }
         cout << "******************************************************************" << endl;
         cout << "Mean Temerature     \t" << mean1 << "                    \t" << mean2 << endl;
         cout << "Standard deviation \t"<< deviation1 <<"                     \t" << deviation2 << endl;
   }
//Will compute and return the mean of both days 
double meanTemperature ( int hours, double temp1[], double temp2[], double& mean1, double& mean2)
   {
      int i = 1;
      double total1= 0, total2 = 0;
      for ( i= 1; i <= hours; i++)
         {
            total1 = total1 + temp1[i];
            total2 = total2 + temp2[i];
         }
      mean1 = total1 / hours ;
      mean2 = total2 / hours ;  
   }
/* Will print the deviation of the temperatures for each day,
this will be done through multiple steps in the function */
double standardDeviation ( double& deviation1, double& deviation2, double mean1, double mean2, int hours, double temp1[], double temp2[])
   {
    int i;
      double total1 = 0, total2 = 0, subtractedTemp1, subtractedTemp2;
      for ( i=1; i <= hours; i++)
       {
// loop to get each temperature subtracted by the mean into a total for each day
         subtractedTemp1 = temp1[i] - mean1;
         subtractedTemp2 = temp2[i] - mean2;
         total1 = total1 + ( subtractedTemp1 * subtractedTemp1);
         total2 = total2 + ( subtractedTemp2 * subtractedTemp2);
       }
// divide by the total hours
      total1 = total1 / hours ;
      total2 = total2 / hours ;
// square root the above result to get the deviation
      deviation1 = sqrt(total1);
      deviation2 = sqrt(total2);  
   }
       
int main()
   {
//Variable declaration to be used in all of the functions   
      int hours = 24 ;
      string date1, date2;
      double temp1[hours], temp2[hours], mean1, mean2, deviation1, deviation2;
      intro();
      inStream.open("dailyTemps.txt");
      if (inStream.fail())
        {   
            cout<< "Input file opening failed.\n";
            exit(1);
        }
//Next three lines used to set the decimal place to 2 points after the decimal
      cout.setf(ios::fixed) ;
      cout.setf(ios::showpoint);
      cout.precision(2);
      readFile(inStream, date1, date2, temp1, temp2, hours);
      printDate (date1, date2);
      meanTemperature (hours, temp1, temp2, mean1, mean2);
      standardDeviation ( deviation1, deviation2, mean1,  mean2,  hours,  temp1,  temp2);
      printResults (hours, temp1, temp2, mean1, mean2, deviation1, deviation2);
      inStream.close();
   }