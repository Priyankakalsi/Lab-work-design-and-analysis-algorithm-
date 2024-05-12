// Write a program to insert and print the elements of the Binary Search Tree.
#include <iostream>
using namespace std;

// Define the structure for a node in the BST
struct TreeNode
{
    int value;
    TreeNode *left;
    TreeNode *right;

    // Constructor to initialize the node
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Function to insert a value into the BST
TreeNode *insert(TreeNode *root, int value)
{
    if (root == nullptr)
    {
        return new TreeNode(value);
    }
    if (value < root->value)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }
    return root;
}

// Function to print the BST in an in-order traversal (left, root, right)
void printInOrder(TreeNode *root)
{
    if (root != nullptr)
    {
        printInOrder(root->left);
        cout << root->value << " ";
        printInOrder(root->right);
    }
}

int main()
{
    TreeNode *root = nullptr;
    int numElements, value;

    cout << "How many elements do you want to insert into the BST? ";
    cin >> numElements;

    for (int i = 0; i < numElements; i++)
    {
        cout << "Enter value to insert: ";
        cin >> value;
        root = insert(root, value);
    }

    cout << "In-order traversal of the BST: ";
    printInOrder(root);
    cout << endl;

    return 0;
}
