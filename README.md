# LinkedBag_for_Polynomials: (algorithms & data structures II)

A LinkedBag implementation to store and carry operations on polynomials of one parameter

For example:
The polynomial -3*x^7 + 4.1 * x^5 + 7 * x^3 + 9 * x^0 can be represented as: 

head_ptr_→ [-3, 7] → [4.1, 5] → [7, 3] → [9, 0] → nullptr
(The degree of the above polynomial is 7.)

The Program:

(a) Adds at the end of the list by taking two parameters, a coefficient and an exponent (should not add a node with an exponent that is already there.) 

(b) Traverse the list and print out the coefficients and exponents. 

(c) Returns the degree of the polynomial (or -1 if the polynomial is empty).

(d) Returns the coefficient of a given exponent. For examplepolynomial.Coefficient(5) should return 4.1

(e) Changes a coefficient for a given exponent.

make all - To compile all sections.

make clean - To remove all *.o and executable files.

