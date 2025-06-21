// Linked List

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList
{
public:
    int size;
    Node *head;

    LinkedList()
    {
        this->head = NULL;
        this->size = 0;
    }

    // Function for Insert element at Front
    void insertAtFront(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = this->head;
        this->head = newNode;
        this->size++;
        cout << "Element insert at front successfully." << endl;
    }

    // Function for Insert element at End
    void insertAtEnd(int data)
    {
        Node *newNode = new Node(data);
        if (this->head != NULL)
        {
            Node *ptr = this->head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            newNode->next = ptr->next;
            ptr->next = newNode;
            cout << "Element insert at end successfully." << endl;
        }
        else
        {
            newNode->next = this->head;
            cout << "Element insert at front successfully." << endl;
        }
        this->size++;
    }

    // Function for Insert element at Specific Position
    void insertAtIndex(int data, int index)
    {
        if (index >= 0 && index < size)
        {
            if (index == 0)
            {
                insertAtFront(data);
                return;
            }
            Node *newNode = new Node(data);
            Node *ptr = this->head;
            for (int i = 0; i < index - 1; i++)
            {
                ptr = ptr->next;
            }
            ptr->next = newNode->next;
            newNode->next = ptr->next->next;
            this->size++;
            cout << "Element insert at index successfully." << endl;
        }
        else
        {
            cout << "Index out of bounds." << endl;
        }
    }

    // Function for Delete element at Front
    void deleteAtFront()
    {
        if (this->head == NULL)
        {
            cout << "Linked List is empty." << endl;
        }
        this->head = head->next;
        this->size--;
        cout << "Element delete at front successfully." << endl;
    }

    // Function for Delete element at End
    void deleteAtEnd()
    {
        if (this->head == NULL)
        {
            cout << "Linked List is empty." << endl;
        }
        Node *ptr = this->head;
        while (ptr->next->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = NULL;
        this->size--;
        cout << "Element delete at end successfully." << endl;
    }

    // Function for Delete element at Specific position
    void deleteAtIndex(int index)
    {
        if (index >= 0 && index < size)
        {
            if (index == 0)
            {
                deleteAtFront();
                return;
            }
            Node *ptr = this->head;
            for (int i = 0; i < index - 1; i++)
            {
                ptr = ptr->next;
            }
            ptr->next = ptr->next->next;
            this->size--;
            cout << "Element delete at index successfully." << endl;
        }
        else
        {
            cout << "Index out of bounds." << endl;
        }
    }

    // Function for Update element in List
    void updateAtIndex(int data, int index)
    {
        if (index >= 0 && index < size)
        {
            Node *ptr = this->head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->data = data;
            cout << "Element updated successfully." << endl;
        }
        else
        {
            cout << "Index out of bounds." << endl;
        }
    }

    // Function for Display List
    void displayList()
    {
        cout << "Linked List is: ";
        Node *ptr = this->head;
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
};

int main()
{

    LinkedList list;
    int choice, index, element;

    do
    {
        cout << endl;
        cout << "Enter 1 for Insert At Front" << endl;
        cout << "Enter 2 for Insert At End" << endl;
        cout << "Enter 3 for Insert At Index" << endl;
        cout << "Enter 4 for Delete At Front" << endl;
        cout << "Enter 5 for Delete At End" << endl;
        cout << "Enter 6 for Delete At Index" << endl;
        cout << "Enter 7 for Update List" << endl;
        cout << "Enter 8 for Display List" << endl;
        cout << "Enter 0 for Exit" << endl;
        cout << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter element for Insert: ";
            cin >> element;
            list.insertAtFront(element);
            break;
        case 2:
            cout << "Enter element for Insert: ";
            cin >> element;
            list.insertAtEnd(element);
            break;
        case 3:
            cout << "Enter element for Insert: ";
            cin >> element;
            cout << "Enter index for Insert: ";
            cin >> index;
            list.insertAtIndex(element, index);
            break;
        case 4:
            list.deleteAtFront();
            break;
        case 5:
            list.deleteAtEnd();
            break;
        case 6:
            cout << "Enter index for Delete: ";
            cin >> index;
            list.deleteAtIndex(index);
            break;
        case 7:
            cout << "Enter element for Insert: ";
            cin >> element;
            cout << "Enter index for Insert: ";
            cin >> index;
            list.updateAtIndex(element, index);
            break;
        case 8:
            list.displayList();
            break;
        case 0:
            cout << "Exit Progran" << endl;
            break;
        default:
            cout << "Wrong choice!" << endl;
            break;
        }
    } while (choice != 0);
    return 0;
}