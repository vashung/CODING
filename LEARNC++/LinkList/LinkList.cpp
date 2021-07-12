#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

//insert data one after another
void insert(Node *head, int data)
{
    Node *newnode = new Node();
    newnode->data = data;
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    // while(head != NULL){
    //     head = head->next;
    // }
    // newnode->next = head->next;
    // head->next = newnode;
}

//insert data at the beginning
void insertF(Node *list, int data)
{
    Node *newnode = new Node();
    newnode->data = data;
    newnode->next = list->next;
    list->next = newnode;
}

void print(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

Node *reverse(Node *node)
{
    Node *revnode = NULL; // Create an empty linklist
    while(node != NULL)
    {
        Node *tem = new Node();  //create a node and add data from node/head;
        tem->data = node->data;

        tem->next = revnode; // Set the node next to 
        revnode = tem;


        node = node->next;
    }
    return revnode;
}

int main()
{

    Node *list = new Node();
    // insertF(list, 4);
    // insertF(list, 5);
    // insertF(list, 6);
    // insertF(list, 8);
    insert(list, 4);
    insert(list, 5);
    insert(list, 6);
    insert(list, 8);
    print(list);
    cout<<endl;
    list = reverse(list);

    print(list);
}