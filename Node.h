/** Yosef Yudborovsky
 Node.h */

#ifndef Node_H
#define Node_H

template<class ItemType>
class Node {   
public:
   Node();
   // @param new_exponent and new_coefficient.
   // Constucts a node holding new_exponent and new_exponent pointing to nullptr.
   Node(const ItemType& new_coefficient, const ItemType& new_exponent);
   
   // @param new_exponent and new_coefficient.
   // @param next_node pointer to next_nodex
   // Constucts a node holding an_item and pointing to next_node.
   Node(const ItemType& new_coefficient, const ItemType& new_exponent, Node<ItemType>* next_node);

   // @param new_coefficient
   // Sets the coefficient_ to new_coefficient.
   void SetCoefficient(const ItemType& new_coefficient);
    
    // @param new_exponent
    // Sets the exponent_ to new_exponent.
    void SetExponent(const ItemType& new_exponent);

   // @param next_node pointer to next node.
   // Sets next point to next_node.
   void SetNext(Node<ItemType>* next_node);

   // @return current coefficient.
   ItemType GetCoefficient() const;
    
    // @return current exponent.
    ItemType GetExponent() const;

   // @return pointer to next node.
   Node<ItemType>* GetNext() const;

private:
    ItemType   coefficient_; // A data item
    ItemType   exponent_; // A data item

   Node<ItemType>* next_node_; // Pointer to next node
}; // end Node

#include "Node.cpp"
#endif  // Node_H
