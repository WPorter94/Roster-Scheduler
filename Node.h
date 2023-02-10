
#ifndef NODE_H
#define NODE_H

#include <cstddef>


template <typename Item_Type>
class Node {
public:

    // Constructor
    Node() : data(), next(NULL) {}
    /** Creates a new Node that points to another Node.
        @param data_item The data stored
        @param next_ptr Pointer to the Node that is
                        pointed to by the new Node
     */
    Node(const Item_Type& data_item, Node* next_ptr);

    // copy constructor
    //Node(const Node& orig);

    // destructor
    //virtual ~Node();

    // accessor and mutator methods    
    void SetNext(Node* next);
    Node* GetNext() const;
    Node*& GetNext();
    void SetData(Item_Type data);
    Item_Type GetData() const;
    Item_Type& GetData();

private:
    // Data Fields
    /** The data */
    Item_Type data;
    /** The pointer to the next node. */
    Node* next;
};
//template <typename Item_Type>
//Node<Item_Type>::Node() {
//    this->data = NULL;
//    this->next = NULL;
//}

template <typename Item_Type>
Node<Item_Type>::Node(const Item_Type& data_item, Node* next_ptr) {
    this->data = data_item;
    this->next = next_ptr;
}
//template <typename Item_Type>
//Node<Item_Type>::Node(const Node& orig) {
//    this->data = orig.data;
 //   this->next = NULL;

//}
//template <typename Item_Type>
//Node<Item_Type>::~Node() {
//    this->data = NULL;
//    this->next = NULL;
//}
template <typename Item_Type>
void Node<Item_Type>::SetNext(Node* next) {
    this->next = next;
}
template <typename Item_Type>
Node<Item_Type>* Node<Item_Type>::GetNext() const {
    return this->next;
}
template <typename Item_Type>
Node<Item_Type>*& Node<Item_Type>::GetNext() {
    return this->next;
}
template <typename Item_Type>
void Node<Item_Type>::SetData(Item_Type data) {
    this->data = data;
}
template <typename Item_Type>
Item_Type Node<Item_Type>::GetData() const {
    return this->data;
}
template <typename Item_Type>
Item_Type& Node<Item_Type>::GetData() {
    return this->data;
}




#endif /* NODE_H */
