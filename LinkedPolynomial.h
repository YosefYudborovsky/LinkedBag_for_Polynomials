
/** Yosef Yudborovsky
 LinkedPolynomial.h */

#ifndef LinkedPolynomial_H
#define LinkedPolynomial_H

#include <vector>
#include "Node.h"
using namespace std;

template<class ItemType>
class LinkedPolynomial //: public BagInterface<ItemType>
{
public:
   LinkedPolynomial();
   LinkedPolynomial(const LinkedPolynomial<ItemType>& a_bag); // Copy constructor.
   LinkedPolynomial<ItemType>& operator=(const LinkedPolynomial<ItemType>& right_hand_side); // Overloading of the assignment operator.
   virtual ~LinkedPolynomial();                       // Destructor should be virtual
   int GetCurrentSize() const;
   bool IsEmpty() const;
   bool Add(const ItemType& new_entry_coefficient, const ItemType& new_entry_exponent);
   void Clear();
   bool Contains(const ItemType& an_ntry) const;
   int GetFrequencyOf(const ItemType& an_entry) const;
    void DisplayPolynomial() const; // to run through the list and display coefficients and exponents
    int Degree() const; // to display the polynomial degree
    double ItemTypeCoefficient(const ItemType& exponent) const; // to display coefficient of given exponent
    bool ChangeCoefficient(ItemType new_coefficient, ItemType exponent); // to change coefficient of a given exponent
    void AddPolynomial(const LinkedPolynomial<ItemType>& b_polynomial); // to add polynomial b to existing polynomil
    
private:
   Node<ItemType>* head_ptr_; // Pointer to first node
   int item_count_;           // Current count of bag items
   
   // @return either a pointer to the node containing a given entry
   // or the null pointer if the entry is not in the bag.
   Node<ItemType>* GetPointerTo(const ItemType& target) const;
   
   // Allocates space and copies all the nodes from a polynomial.
   // The function does not check whether this bag contains
   // any items, but it assumes that it is empty.
   void CopyNodesFrom(const LinkedPolynomial<ItemType> &polynomial);
}; // end LinkedPolynomial

#include "LinkedPolynomial.cpp"
#endif  // LinkedPolynomial_H
