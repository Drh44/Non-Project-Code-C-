// Author: Dylan Hesser
// 5-24-18
/* This program accepts user input for 3 variables and uses the numbers to calculate
the quadratic equation and display the results for the user */


#include <iostream>
using namespace std ;
#include <cmath>

int main ()
 {  // First I declared all the variables needed for the program
    double a, b, c, discriminant, root, root1, root2;
    // These next three lines are to set decimals to two points after the decimal point
    cout.setf(ios::fixed) ;
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    cout << "Hello! This program will help you solve those pesky quadratic equations!\nPlease insert the needed numbers when prompted\n" ;
    // This next section gathers all the user input that is needed to calculate the equation
   
    cout << "Please insert the value for A: " ;
    cin >> a ;
   
    cout << "\nPlease insert the value for B: " ;
    cin >> b ;
   
    cout << "\nPlease insert the value for C: " ;
    cin >> c ;
    // This next section will help simplify the math needed and be used in the if/else statements.
   
    discriminant = ( b * b ) - ( 4 * a * c ) ; //for the part in the square root of the problem
    cout << " \nThe discriminant is " << discriminant << "\n" ;
   
    root = sqrt(discriminant); // to root the discriminant
    
    /* This next section will change depending on what value the discriminant has. Each path will tell the user
    how many roots the equation has, then solve for those roots and display them to the user */
    
    if ( discriminant > 0 )
       {
         cout << " Since the value is positive, there will be two real roots.\n" ;
         root1 = ((-b + root) / (2 * a)) ;
         root2 = ((-b - root) / (2 * a)) ;
         cout << " The first root is: " << root1 << endl;
         cout << " The second root is: " << root2 << endl;
         
         
       }
    else if ( discriminant < 0 )
       {
         cout << "Since the value is negative, there will not be any real roots. This program doesn't handle negative roots since they involve imaginary numbers. " ;
         
       }
    else
       {
         cout << "Since the value is zero, there will only be one real root \n" ;
         
         root1 = (-b + root) / 2 * a ;
         cout << "This is your answer: " << root1 ;
       }
       
       return 0;
   }