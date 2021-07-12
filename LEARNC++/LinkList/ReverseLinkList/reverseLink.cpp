#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }

    void insert(int data);
};

void Node::insert(int data)
{
    Node *tem = new Node(data);
    Node *n = this;
    while (n->next != NULL)
    {
        n = n->next;
    }
    n->next = tem;
}

//Print all the Nodes
void print(Node *head)
{
    Node *list = head;
    while (list != NULL)
    {
        cout << list->data << " ";
        list = list->next;
    }
}

Node *reverse(Node *head)
{
    Node *revnode = NULL;
    while (head != NULL)
    {
        Node *tem = new Node(head->data);
        tem->next = revnode;
        revnode = tem;

        head = head->next;
    }
    return revnode;
}

bool checkPalindrome(Node *node)
{
    Node *list1 = node;
    Node *list2 = reverse(node);
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->data != list2->data)
            return false;
        list1 = list1->next;
        list2 = list2->next;
    } 

    return (list1 == NULL) && (list2 == NULL);
}

void deleteN(Node *node, int data)
{
    Node *current = node;
    while (current->next->data != data)
    {
        current = current->next;
    }
    Node *toDelete = current->next;
    current->next = current->next->next;
    delete toDelete;
}

int main()
{
    Node *head = new Node(3);
    head->insert(5);
    head->insert(4);
    head->insert(7);
    head->insert(8);
    print(head);
    head = reverse(head);
    cout << endl; 
    deleteN(head, 4);
    print(head);
}