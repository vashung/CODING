#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *left, *right;
    Node(int root)
    {
        this->data = root;
        left = NULL;
        right = NULL;
    }
    void insert(int);
    void print(Node *);
    bool check(Node *, int);
};

void Node::print(Node *tree)
{
    if (tree == NULL)
        return;

    else
    {
        cout << tree->data << endl;
        if (tree->left == NULL || tree->right == NULL)
        {
            return;
        }
        print(tree->left);
        cout << "  ";
        print(tree->right);
    }
}

bool Node::check(Node *tree, int data)
{
    if (tree == NULL)
    {
        return false;
    }
    if (tree->data == data)
        return true;
    check(tree->left, data);
    check(tree->right, data);
}

int main()
{
    Node *tree = new Node(4);
    int x = 1234;
    tree->left = new Node(23);
    tree->right = new Node(34);

    tree->left->left = new Node(25);
    tree->left->right = new Node(18);

    tree->right->left = new Node(13);
    tree->right->right = new Node(45);
    tree->print(tree);

    cout << tree->check(tree, 3) << endl;
    cout << tree->check(tree, 45) << endl;
    cout << tree->check(tree, 17) << endl;
}