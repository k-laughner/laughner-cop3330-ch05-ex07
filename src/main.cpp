/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Kaylee Laughner
 */
#include "main.h"

class quadEq {
  // function to print only real results
  public: void printRealResult(double root1, double root2) {
    std::cout << "\n\nx = " << root1 << " or x = " << root2;
  } 
  // function to print only imaginary results
  public: void printImaginaryResult(double root1f, double root1b, double root2f, double root2b) {
    std::cout << "\n\nNo real result was found.\nThe following imaginary results were found:\n" << "x = " << root1f << " + " << root1b << "i or " << "x = " << root2f << " - " << root2b << "i";
  }
  // function to calculate real results using quad formula
  public: void posDeterminantCalc(double a, double b, double c) {
    double root1 = ((-b) + sqrt(pow(b,2) - 4*a*c)) / (2*a);
    double root2 = ((-b) - sqrt(pow(b,2) - 4*a*c)) / (2*a);
    printRealResult(root1, root2);

    // checking roots as asked in exercise question
    std::cout << "\n\nThe found roots can be checked by plugging them into the formula with a, b, and c coefficients.\n";    
    checkRoots(a, b, c, root1);
    std::cout <<"\nThe first root has been checked.\n";
    checkRoots(a, b, c, root2);
    std::cout <<"\nThe second root has been checked.";
  }
  // function to calculate imaginary results 
  public: void negDeterminantCalc(double a, double b, double c) {
   double root1f = (-b) / (2*a);
   double root1b = sqrt(- (pow(b, 2) - 4*a*c)) / (2*a);

   double root2f = (-b)/(2*a);
   double root2b =  sqrt(- (pow(b, 2) - 4*a*c)) / (2*a);

   printImaginaryResult(root1f, root1b, root2f, root2b);
  }
  // function to calculate real results when determinant is 0
  public: void zeroDeterminantCalc(double a, double b, double c) {
    double root1 = (-b) / (2*a);
    double root2 = (-b) / (2*a);
    printRealResult(root1, root2);

    // checking roots as asked in exercise question
    std::cout << "\n\nThe found roots can be checked by plugging them into the formula with a, b, and c coefficients.\n";    
    checkRoots(a, b, c, root1);
    std::cout << "\nThe root has been checked.";
  }
  public: void checkRoots(double a, double b, double c, double root) {
    double result = (a*pow(root,2)) + (b*root) + c; 
    std::cout << a << "*(" << root << "^2) + " << b << "*(" << root << ") + " << c << " = " << result;
  }
  // calling calculator function based on the determinant
  public: void calculate(double a, double b, double c) {
    double det = pow(b, 2) - 4*a*c;
    if (det > 0) {
      posDeterminantCalc(a, b, c);
    }
    if (det < 0) {
      negDeterminantCalc(a, b, c);
    }
    if (det == 0) {
      zeroDeterminantCalc(a, b, c);
    }
  }
};
class checkResult{

};
int main() {
  double a;
  double b;
  double c;
  // asking for and getting input
  std::cout << "Enter coefficients a, b, and c seperated by spaces: ";
  std::cin >> a >> b >> c;

  // call quadEq class to perform calcs 
  quadEq q;
  q.calculate(a, b, c);
} 
