
#include <iostream> // For cout and cin
#include <string>   // For string objects
#include "LinkedPolynomial.h"    // For ADT bag
using namespace std;

// Takes user input for a new polynomial.
// Sets a new polynomial by calling the Add function.
// Returnes the newly created polynomial
LinkedPolynomial<double> CreatePolynomialFromInput()
{
    LinkedPolynomial<double> newPoly;
    int number_of_elemnts=0;
    cout << "\nNEW POLYNOMIAL: What is the number of elements in your new polynomial: " << endl;
    cin >> number_of_elemnts;
    double new_entry_coefficient=0;
    double new_entry_exponent=0;
    for (int i=1; i<=number_of_elemnts; i++)
    {
        cout << "Please provide coefficient number " << i << ": " << endl;
        cin >> new_entry_coefficient;
        cout << "Please provide an exponenet for the above coefficient: " << endl;
        cin >> new_entry_exponent;
        
        newPoly.Add(new_entry_coefficient, new_entry_exponent);
        
    }
    return newPoly;
}
// Displays and tests polynomial for degree and abilty to change coefficient and exponents.

void TestPolynomial()
{
    double exponent=0, new_coefficient=0, returnForItemTypeCoefficient=0;
    LinkedPolynomial<double> newPoly; // New object
    newPoly = CreatePolynomialFromInput(); //New polynomial
    newPoly.DisplayPolynomial();
    cout << "\nThe degree of the above polynomial is: " << newPoly.Degree() << endl;
    cout << "Please provide an exponent: " << endl;
    cin>>exponent;
    returnForItemTypeCoefficient = newPoly.ItemTypeCoefficient(exponent); // Asigns the return value to see if exist such an exponent
    if (returnForItemTypeCoefficient==-1) // does not exist
    {
        cout << "Could not find an element with the above exponent. "<< endl;
        cout << "Please provide a new coefficient for the above exponent: " << endl;
        cin>>new_coefficient;
        cout << "ChangeCoefficient returns: " << newPoly.ChangeCoefficient(new_coefficient, exponent) << endl;
        cout << "\nAdding a new elemtnt with the above parameters. "<< endl;
        newPoly.Add(new_coefficient, exponent);

    }
    else
    {
        cout << "The coeeficient for the above expoent is: " << returnForItemTypeCoefficient << endl;
        cout << "Please provide a new coefficient for the above exponent: " << endl;
        cin>>new_coefficient;
        cout << "ChangeCoefficient returns: " << newPoly.ChangeCoefficient(new_coefficient, exponent) << endl;


    }    
        newPoly.DisplayPolynomial();
    

}
// Tests the abilty to merge two polnomials
void TestAddition()
{
    LinkedPolynomial<double> polynomial1, polynomial2; // New object
    polynomial1 = CreatePolynomialFromInput();
    polynomial2 = CreatePolynomialFromInput();
    polynomial1.AddPolynomial(polynomial2);
    polynomial1.DisplayPolynomial();
    
    
}
int main()
{
    cout << "FIRST TEST: ";
    TestPolynomial();
    cout << endl;
    cout << "SECOND TEST: ";
    TestAddition();

    return 0;
}; // end main
