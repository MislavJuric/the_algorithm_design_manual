#include <iostream>

using namespace std;

/*
    Write a program to reverse the direction of a given singly-linked list. In other
    words, after the reversal all pointers should now point backwards. Your algorithm
    should take linear time.
*/

struct element
{
    int number;
    element* next {nullptr};
};

void printList(element* listHead)
{
    element* temp = listHead;
    while (temp != nullptr)
    {
        cout << temp->number << " ";
        temp = temp->next;
    }
    cout << endl;
}

void reverseList(element* listHead)
{
    element* temp = listHead;
    element* trail = nullptr;
    element* prevPtr = nullptr; // I have to figure out how to keep the old connection (from the element I'm changing)
    while (temp != nullptr)
    {
        trail = temp;
        prevPtr = temp->next;
        temp = prevPtr;
        temp->next = trail;
    }
    listHead = trail;
}

int main()
{
    element* listHead = nullptr;
    // manually adding some elements
    element* firstElement = new element;
    firstElement->number = 9;
    listHead = firstElement;
    element* secondElement = new element;
    secondElement->number = 2;
    firstElement->next = secondElement;
    element* thirdElement = new element;
    thirdElement->number = 5;
    secondElement->next = thirdElement;
    printList(listHead);
    reverseList(listHead);
    printList(listHead);
    // deallocation is important
    delete firstElement;
    delete secondElement;
    delete thirdElement;
    listHead = nullptr;
    return 0;
}
