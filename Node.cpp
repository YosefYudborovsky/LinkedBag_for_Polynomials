
/** Yosef Yudborovsky
 Node.cpp */

#ifndef Node_CPP
#define Node_CPP

#include "Node.h"
#include <cstddef>

template<class ItemType>
Node<ItemType>::Node() : next_node_(nullptr)
{
} // end default constructor

template<class ItemType>
Node<ItemType>::Node(const ItemType& new_coefficient, const ItemType& new_exponent) : coefficient_(new_coefficient), exponent_(new_exponent), next_node_(nullptr)
{
} // end constructor
  
template<class ItemType>
Node<ItemType>::Node(const ItemType& new_coefficient, const ItemType& new_exponent, Node<ItemType>* next_node) : coefficient_(new_coefficient), exponent_(new_exponent), next_node_(next_node)
{
} // end constructor

template<class ItemType>
void Node<ItemType>::SetCoefficient(const ItemType& new_coefficient)
{
    coefficient_ = new_coefficient;
} // end SetCoefficient

template<class ItemType>
void Node<ItemType>::SetExponent(const ItemType& new_exponent)
{
   exponent_ = new_exponent;
} // end SetExponent

template<class ItemType>
void Node<ItemType>::SetNext(Node<ItemType>* next_node)
{
   next_node_ = next_node;
} // end setNext_Node_Ptr

template<class ItemType>
ItemType Node<ItemType>::GetCoefficient() const
{
    return coefficient_;
} // end getCoefficient

template<class ItemType>
ItemType Node<ItemType>::GetExponent() const
{
   return exponent_;
} // end getItem

template<class ItemType>
Node<ItemType>* Node<ItemType>::GetNext() const
{
   return next_node_;
} // end getNext_Node_Ptr

#endif  // Node_CPP

