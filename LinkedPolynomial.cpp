
/** Yosef Yudborovsky
 LinkedPolynomial.cpp */

#ifndef LinkedPolynomial_cpp
#define LinkedPolynomial_cpp

#include <iostream> // For cout and cin
#include "LinkedPolynomial.h"
#include "Node.h"
#include <cstddef>
using namespace std;

template<class ItemType>
LinkedPolynomial<ItemType>::LinkedPolynomial() : head_ptr_(nullptr), item_count_(0)
{
}  

template<class ItemType>
LinkedPolynomial<ItemType>::LinkedPolynomial(const LinkedPolynomial<ItemType>& polynomial)
{
  CopyNodesFrom(polynomial);
}  

template<class ItemType>
LinkedPolynomial<ItemType>& LinkedPolynomial<ItemType>::operator=(const LinkedPolynomial<ItemType>& right_hand_side) {
  if (this != &right_hand_side) {  
    Clear(); // First deallocate all memory.
    CopyNodesFrom(right_hand_side);  // Then copy everything.
  }
  return *this;  // Return self.
}

template<class ItemType>
LinkedPolynomial<ItemType>::~LinkedPolynomial()
{
  Clear();
}  

template<class ItemType>
bool LinkedPolynomial<ItemType>::IsEmpty() const
{
  return item_count_ == 0;
}  

template<class ItemType>
int LinkedPolynomial<ItemType>::GetCurrentSize() const
{
  return item_count_;
}  

template<class ItemType>
bool LinkedPolynomial<ItemType>::Add(const ItemType& new_entry_coefficient, const ItemType& new_entry_exponent)
{
    Node<ItemType>* next_node_ptr = new Node<ItemType>(new_entry_coefficient, new_entry_exponent);
    Node <ItemType>* tempPtr = head_ptr_; // first equal to head
    
    if ( head_ptr_ != NULL)
    {
        while (tempPtr->GetNext() != NULL) // runs through the list while not null
        {
            if (new_entry_exponent == tempPtr->GetExponent()) // if our new exponent entry is already exist
            
            {
                delete next_node_ptr;
                return false;
            }
            tempPtr = tempPtr->GetNext(); // otherwise assign pointer.next to the temporery one
        }
        if (new_entry_exponent == tempPtr->GetExponent()) // if our new exponent entry is already exist
            
        {
            delete next_node_ptr;
            return false;
        }
        
        tempPtr->SetNext(next_node_ptr);
    }
    else
    {
        head_ptr_ = next_node_ptr; // if empty list
        
    }
    item_count_++;
    return true;
  
}  

template<class ItemType>
void LinkedPolynomial<ItemType>::Clear()
{
  Node<ItemType>* current_node_to_delete = head_ptr_;
  while (head_ptr_ != nullptr) {
    head_ptr_ = head_ptr_->GetNext();
    // Return node to the system
    current_node_to_delete->SetNext(nullptr);
    delete current_node_to_delete;
    current_node_to_delete = head_ptr_;  // Move to the next one.
  }  // end while
  item_count_ = 0;
}  

template<class ItemType>
int LinkedPolynomial<ItemType>::GetFrequencyOf(const ItemType& exponent_entry) const
{
  int frequency = 0;
  int counter = 0;
  Node<ItemType>* current_ptr = head_ptr_;
  while (current_ptr != nullptr){
    if (exponent_entry == current_ptr->GetExponent()) {
      frequency++;
    } // end if
    counter++;
    current_ptr = current_ptr->GetNext();
    // Check for possible serious error.
    if (counter > item_count_) {
       cout << "Serious error in LinkedPolynomial<ItemType>::GetFrequencyOf" << endl;
       return frequency;
    }
  } // end while
  return frequency;
} 

template<class ItemType>
bool LinkedPolynomial<ItemType>::Contains(const ItemType& an_entry) const
{
  return (GetPointerTo(an_entry) != nullptr);
}  // end Contains

template<class ItemType>
void LinkedPolynomial<ItemType>::DisplayPolynomial() const
{
    Node<ItemType>* current_ptr = head_ptr_;
    while (current_ptr->GetNext() != nullptr){
        cout << current_ptr->GetCoefficient() << "*x^" << current_ptr->GetExponent() << " + ";

        current_ptr = current_ptr->GetNext();
        if (current_ptr->GetNext() == nullptr)
            cout << current_ptr->GetCoefficient() << "*x^" << current_ptr->GetExponent(); // last print without plus sign

    
    /*while (current_ptr != nullptr){
        cout << current_ptr->GetCoefficient() << "*x^" << current_ptr->GetExponent() << " + ";
        current_ptr = current_ptr->GetNext();*/

    } // end if

    cout << endl;

    
} // end DisplayPolynomial

template<class ItemType>
int LinkedPolynomial<ItemType>::Degree() const
{
    Node<ItemType>* current_ptr = head_ptr_; // equate to hedptr
    if ( head_ptr_ != NULL) // if not empty
    {
        int degree = current_ptr->GetExponent(); // degree equals first-elemt's exponent
        while (current_ptr != nullptr){
            if (current_ptr->GetExponent() > degree) {
                degree = current_ptr->GetExponent();
            }
            current_ptr = current_ptr->GetNext();
    
        } // end if
        return degree;
    }
    else return -1;
    
} // end Degree

template<class ItemType>
double LinkedPolynomial<ItemType>::ItemTypeCoefficient(const ItemType& exponent) const
{
    Node<ItemType>* current_ptr = head_ptr_; // equate to hedptr
    if ( head_ptr_ != NULL) // if not empty
    {
        while (current_ptr != nullptr){ // run through the list
            double result = current_ptr->GetExponent();
            //current_ptr->GetCoefficient(); // return its coefficient

            if (result == exponent) //if any exponent equals target exponent
            {
                result = current_ptr->GetCoefficient(); // return its coefficien and exit
                return result;
                break;

            }
            
            current_ptr = current_ptr->GetNext();
        } // end of while
    } // end of if
    return -1;
    
} // end ItemTypeCoefficient

template<class ItemType>
bool LinkedPolynomial<ItemType>::ChangeCoefficient(ItemType new_coefficient, ItemType exponent)
{
    Node<ItemType>* current_ptr = head_ptr_; // equate to hedptr
    while (current_ptr != nullptr){ // run through the list
        if (current_ptr->GetExponent() == exponent){ //if any exponent equals target exponent
            current_ptr->SetCoefficient(new_coefficient); // sets the new coefficient
            return true;
        } // end if
        current_ptr = current_ptr->GetNext();
    } // end while
    return false; // if exponent was not found

} // end ChangeCoefficient

template<class ItemType>
void LinkedPolynomial<ItemType>::AddPolynomial(const LinkedPolynomial<ItemType>& b_polynomial)
{
    // An iterator to run through each elemnt of b and store it in ex, co.
    // ex and co will be then set to a by using the Add function
    double newCoeff, newExpo, oldCoeff;
    item_count_ = b_polynomial.item_count_;
    Node<ItemType>* b_polynomial_current_pointer = b_polynomial.head_ptr_;  // Pointer to poin to the first element of b_polynomial.
    
    while (b_polynomial_current_pointer != nullptr) {  // a_bag is not empty.
        newCoeff = b_polynomial_current_pointer->GetCoefficient(); //assign current coefficient to co
        newExpo = b_polynomial_current_pointer->GetExponent(); //assign current exponent to ex
        // call the function Change coeeficient based on the above ex and change its coefficient to be added with co
        oldCoeff = ItemTypeCoefficient(newExpo); // check if such exponent already exist
        if (oldCoeff !=-1) // if, based on the expoenent argument, such coefficient exist
            ChangeCoefficient((oldCoeff+newCoeff), newExpo);
        else
            Add(newCoeff,newExpo);
        
        b_polynomial_current_pointer = b_polynomial_current_pointer->GetNext(); // move to the next one
    } // end of while
}

template<class ItemType>
Node<ItemType>* LinkedPolynomial<ItemType>::GetPointerTo(const ItemType& exponent_entry) const
{
   Node<ItemType> *current_ptr = head_ptr_;
   
   while (current_ptr != nullptr) {
     if (exponent_entry == current_ptr->GetExponent())
       return current_ptr;
     else
       current_ptr = current_ptr->GetNext();
   } // end while 
   return nullptr;
} 


template<class ItemType>
void LinkedPolynomial<ItemType>::CopyNodesFrom(const LinkedPolynomial<ItemType> &polynomial) {
  item_count_ = polynomial.item_count_;
  Node<ItemType>* polynomial_current_pointer = polynomial.head_ptr_;  // Pointer to beginning of polynomial.
   
  if (polynomial_current_pointer == nullptr) {  // polynomial is empty.
    head_ptr_ = nullptr;  
    return;
  } 
  // Copy first node
  head_ptr_ = new Node<ItemType>();
  head_ptr_->SetCoefficient(polynomial_current_pointer->GetCoefficient());
    head_ptr_->SetExponent(polynomial_current_pointer->GetExponent());

  // Copy remaining nodes
  Node<ItemType>* last_pointer = head_ptr_;      // Points to last node in new chain
  polynomial_current_pointer = polynomial_current_pointer->GetNext();     // Advance original-chain pointer
  
  while (polynomial_current_pointer != nullptr) {
    // Create a new node holding the item of polynomial_current_pointer.
    Node<ItemType>* new_node_pointer = new Node<ItemType>(polynomial_current_pointer->GetCoefficient(), polynomial_current_pointer->GetExponent());
    
    // Link new node to end of new chain
    last_pointer->SetNext(new_node_pointer);
    
    // Advance pointer to new last node
    last_pointer = last_pointer->GetNext();
    
    // Advance original-chain pointer
    polynomial_current_pointer = polynomial_current_pointer->GetNext();
  }  // end while
  last_pointer->SetNext(nullptr); 
}

#endif  // LinkedPolynomial_cpp

