
#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H
#include "Node.h"
#include <iostream>
//#include "Node.cpp"

/*<programming_project chapter="4" number="1">*/

#include <stdexcept>

/** Class to implement a single linked list */
template <typename Item_Type>
class Single_Linked_List {
public:

    /** Construct an empty Single_Linked_List */
    Single_Linked_List() : head(NULL), tail(NULL), num_items(0) {
    }

    /** destructor */
    ~Single_Linked_List();

    /** Insert an item at the front of the list
        @param item The item to be inserted
     */
    void push_front(const Item_Type& item);

    /** Insert an item at the end of the list
        @param item The item to be inserted
     */
    void push_back(const Item_Type& item);

    /** Remove the front item of the list
     * If it is empty list, throw out_of_range with a message
     * "pop_front on empty list"
     */
    void pop_front();

    /** Remove the last item of the list
     * If it is empty list, throw out_of_range with a message
     * "pop_back on empty list"
     */
    void pop_back();

    /** Return a reference to the front item of the list
     * If it is empty list, throw out_of_range with a message
     * "Attempt to take front of empty list")
        @return A reference to the fron item of the list
     */
    Item_Type& front();

    /** Return a const reference to the front item of the list
     * If it is empty list, throw out_of_range with a message
     * "Attempt to take front of empty list")

        @return A const reference to the front item of the list
     */
    const Item_Type& front() const;

    /** Return a reference to the back item of the list
     * If it is empty list, throw out_of_range with a message
     * "Attempt to take back of empty list")
        @return A reference to the back item of the list
     */
    Item_Type& back();

    /** Return a const reference to the back item of the list
        @return A const reference to the back item of the list
     */
    const Item_Type& back() const;

    /** Determine if the list is empty
     * If it is empty list, throw out_of_range with a message
     * "Attempt to take back of empty list")
        @return true if the list is empty
     */
    bool empty() const;

    /** Return the number of items in the list
        @return The number of items in the list
     */
    size_t size() const;

    /** Insert item at position index (starting at 0).  Insert
        at the end of index is beyond the end of the list.
        @param index The poisition to insert the item
        @param item The item to be inserted
     */
    void insert(size_t index, const Item_Type& item);

    /** function to insert a new_node in a sorted list.
     Insert the new_node in sorted order.
     * @parm new_node Node to be inserted into the sorted linked list.
     */

    void sortedInsert(Item_Type& item);

    /** Return a reference to the item at position index
     *  If index > size, throw a message
     * "Attempt to get past size in Single_Linked_List"
        @param index The index of the item
        @return A reference to the item at index
     */
    Item_Type& get(size_t index);

    /** Return a const reference to the item at position index
        @param index The index of the item
        @return A const reference to the item at index
     */
    const Item_Type& get(size_t index) const;


    /** Remove the item at position index.
     * If index > size, throw a message
     * "Attempt to get past size in Single_Linked_List"
        @return true if the removal is sucessful; false if index is
        beyond the end of the list
     */
    bool remove(size_t index);

    /** Return the position of the first occurence of item.
     * If item is not found, throw an "item not found" exception
     * Note: this is a char* exception
        @return The position of the first occurence of the item. Return
        the size of the list if it is not found
     */
    size_t find(const Item_Type& item);

private:

    Node<Item_Type>* head;
    Node<Item_Type>* tail;
    size_t num_items;

};
/**
 * implement the functions that specified in this header file to the section
 * in below or put them in a separate file.  If you decide to put the code in
 * a separate file, don't use .cpp extension.
 */
 // #include "Single_Linked_List.tpp"


template <typename Item_Type>
Single_Linked_List<Item_Type>::~Single_Linked_List()
{
    if (head)
    {
        Node<Item_Type>* temp1 = head;
        Node<Item_Type>* temp2 = head;
        while (temp1 != NULL)
        {
            temp2 = temp1;
            temp1 = temp1->GetNext();
            delete temp2;
        }
        head = NULL;
        tail = NULL;
        num_items = 0;
    }

}


template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_front(const Item_Type& item)
{
    Node<Item_Type>* insertNodeFront = new Node<Item_Type>();
    insertNodeFront->SetData(item);
    if (head == NULL)
    {
        tail = insertNodeFront;
    }
    else
    {
        insertNodeFront->SetNext(head);
    }
    head = insertNodeFront;
    num_items++;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_back(const Item_Type& item)
{
    Node<Item_Type>* insertNodeBack = new Node<Item_Type>();
    insertNodeBack->SetData(item);
    if (head == NULL)
    {
        head = insertNodeBack;
    }
    else
    {
        tail->SetNext(insertNodeBack);
    }
    tail = insertNodeBack;
    num_items++;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_front()
{
    try {
        if (head == NULL)
        {
            throw std::out_of_range("pop_front on empty list");
        }
        if (head->GetNext() == NULL)
        {
            delete head;

        }
        else
        {
            Node<Item_Type>* temp = head;
            head = head->GetNext();
            delete temp;

        }
        num_items--;

    }
    catch (std::out_of_range& excpt)
    {
        std::cout << excpt.what() << std::endl;
    }
}


template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_back()
{
    try {
        if (head == NULL)
        {
            throw std::out_of_range("pop_back on empty list");
        }
        if (head->GetNext() == NULL)
        {
            delete head;

        }
        else
        {
            Node<Item_Type>* current = head;
            while (current->GetNext() != tail)
            {
                current = current->GetNext();
            }
            current->SetNext(NULL);
            delete tail;
            tail = current;
        }
        num_items--;
    }
    catch (std::out_of_range& excpt)
    {
        std::cout << excpt.what() << std::endl;
    }
}

template <typename Item_Type>
Item_Type& Single_Linked_List<Item_Type>::front()
{
    try
    {
        if (head == NULL)
        {
            throw std::out_of_range("Attempt to take front of empty list");
        }


        return head->GetData();
    }
    catch (std::out_of_range& excpt)
    {
        std::cout << excpt.what() << std::endl;
    }
    return head->GetData();
}


template <typename Item_Type>
const Item_Type& Single_Linked_List<Item_Type>::front() const
{

    try
    {
        if (head == NULL)
        {
            throw std::out_of_range("Attempt to take front of empty list");
        }
        else
        {
            return head->GetData();
        }
    }
    catch (std::out_of_range& excpt)
    {
        std::cout << excpt.what() << std::endl;
    }
    return head->GetData();
}


template <typename Item_Type>
Item_Type& Single_Linked_List<Item_Type>::back()
{
    try {
        if (tail == NULL)
        {
            throw std::out_of_range("Attempt to take back of empty list");
        }
        else
        {
            return tail->GetData();
        }
    }
    catch (std::out_of_range& excpt)
    {
        std::cout << excpt.what() << std::endl;
    }
    return tail->GetData();
}


template <typename Item_Type>
const Item_Type& Single_Linked_List<Item_Type>::back() const
{
    {
        try {
            if (tail == NULL)
            {
                throw std::out_of_range("Attempt to take back of empty list");
            }
            else
            {
                return tail->GetData();
            }
        }
        catch (std::out_of_range& excpt)
        {
            std::cout << excpt.what() << std::endl;
        }

    }
    return tail->GetData();
}


template <typename Item_Type>
bool Single_Linked_List<Item_Type>::empty() const {

    try {
        if (head == NULL)
        {
            throw std::out_of_range("Attempt to take back of empty list");
        }
        return false;
    }
    catch (std::out_of_range& excpt)
    {
        std::cout << excpt.what() << std::endl;
        return true;
    }
 
}


template <typename Item_Type>
size_t Single_Linked_List<Item_Type>::size() const {

    return num_items;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::insert(size_t index, const Item_Type& item)
{
    Node<Item_Type>* temp = head;

    try {
        if (index > num_items)
        {
            throw std::out_of_range("Attempt to insert beyond the linked list");
        }
        else if (index == 0 || num_items == 0)
        {
            push_front(item);
        }
        else if (index == num_items)
        {
            push_back(item);
        }
        else
        {
            for (size_t i = 0; i <= index; i++)
            {
                if (i >= 1 && i != index)
                {
                    temp = temp->GetNext();
                }
                if (i == index)
                {
                    Node<Item_Type>* temp2 = new Node<Item_Type>();
                    temp2->SetData(item);
                    temp2->SetNext(temp->GetNext());
                    temp->SetNext(temp2);
                    num_items++;
                }

            }
        }
    }
    catch (std::out_of_range& excpt)
    {
        std::cout << excpt.what() << std::endl;
    }
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::sortedInsert(Item_Type& item)
{
    //   // Node<Item_Type>* tmpptr1 = head;
    //    Node<Item_Type>* tmpptr2;
    //    Item_Type temp1;
    //    Item_Type temp2;
    //    for (int i = 1; i < num_items; i++)
    //    {
    //        temp1 = tmpptr1->GetData();
    //        tmpptr2 = tmpptr1;
    //
    //        for (int j = i; j < num_items; j++)
    //        {
    //            tmpptr2 = tmpptr2->GetNext();
    //            temp2 = tmpptr2->GetData();
    //            if (temp1 > temp2)
    //            {
    //                temp1 = temp2;
    //            }
    //        }
    //        tmpptr1->SetData(temp1);
    //        tmpptr1 = tmpptr1->GetNext();
    //    }
    ////
    size_t index = 1;
    Node<Item_Type>* temp = head;
    if (item < head->GetData())
    {
        push_front(item);
    }
    else if (tail->GetData() < item)
    {
        push_back(item);
    }
    else {
        for (size_t i = 1; i <= num_items; i++)
        {
            if (item < temp->GetNext()->GetData())
            {
                insert(index, item);
                i = num_items;
            }
            else
            {
                index++;
                temp = temp->GetNext();
            }
        }
    }
}

template <typename Item_Type>
Item_Type& Single_Linked_List<Item_Type>::get(size_t index)
{
    Node<Item_Type>* temp = head;
    try {
        if (index >= num_items)
        {
            throw std::out_of_range("Attempt to get past size in Single_Linked_List");
        }
        for (size_t i = 0; i <= index; i++)
        {
            if (i == index)
            {
                return temp->GetData();
            }
            if (temp->GetNext() != NULL)
            {
                temp = temp->GetNext();
            }
        }
    }
    catch (std::out_of_range& excpt)
    {
        std::cout << excpt.what() << std::endl;
    }
    return temp->GetData();
}

template <typename Item_Type>
const Item_Type& Single_Linked_List<Item_Type>::get(size_t index) const
{
    Node<Item_Type>* temp = head;
    try {
        if (index > num_items)
        {
            throw std::out_of_range("Attempt to get past size in Single_Linked_List");
        }
        for (size_t i = 0; i <= index; i++)
        {
            if (i == index)
            {
                return temp->GetData();
            }
            if (temp->GetNext() != NULL)
            {
                temp = temp->GetNext();
            }
        }
    }
    catch (std::out_of_range& excpt)
    {
        std::cout << excpt.what() << std::endl;
    }
    return 0;
}

template <typename Item_Type>
bool Single_Linked_List<Item_Type>::remove(size_t index)
{
    Node<Item_Type>* temp = head;
    try
    {
        if (index >= num_items)
        {
            throw std::out_of_range("Attempt to get past size in Single_Linked_List");
        }
        if (index == 0)
        {
            pop_front();
            return true;
        }
        else if (index == num_items - 1)
        {
            pop_back();
            return true;
        }
        for (size_t i = 1; i <= index; i++)
        {
            if (i == index)
            {
                Node<Item_Type>* temp2 = temp->GetNext();
                temp->SetNext(temp2->GetNext());
                delete temp2;
                num_items--;
                return true;
            }
            if (temp->GetNext() != NULL)
            {
                temp = temp->GetNext();
            }
        }
    }
    catch (std::out_of_range& excpt)
    {
        std::cout << excpt.what() << std::endl;
        return false;
    }
    return false;
}

template <typename Item_Type>
size_t Single_Linked_List<Item_Type>::find(const Item_Type& item)
{
    size_t count = 0;
    Node<Item_Type>* temp = head;
    try {
        for (size_t i = 0; i <= num_items; i++, count++)
        {
            if (i == num_items)
            {
                throw "item not found";
            }
            else if (temp->GetData() == item)
            {
                return count;
            }
            else
            {
                temp = temp->GetNext();
            }
        }
        return count;
    }
    catch (const char* str)
    {
        std::cout << str << std::endl;
        return num_items;
    }
}
#endif /* SINGLE_LINKED_LIST_H */


