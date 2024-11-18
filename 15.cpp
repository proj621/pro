#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;
    int height;
};

int getHeight(Node *n)
{
    return n == NULL ? 0 : n->height;
}

int getBalanceFactor(Node *n)
{
    return n == NULL ? 0 : getHeight(n->left) - getHeight(n->right);
}

Node *createNode(int key)
{
    Node *node = new Node();
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

Node *insert(Node *node, int key)
{
    if (node == NULL)
        return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int bf = getBalanceFactor(node);

    if (bf > 1 && key < node->left->key)
        return rightRotate(node);
    if (bf < -1 && key > node->right->key)
        return leftRotate(node);
    if (bf > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (bf < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

Node *minValueNode(Node *node)
{
    Node *curr = node;
    while (curr->left != NULL)
        curr = curr->left;
    return curr;
}

Node *deleteNode(Node *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        // no child or 1 child
        if ((root->left == NULL) || (root->right == NULL))
        {
            Node *temp = root->left ? root->left : root->right;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            delete temp;
        }
        else
        {
            Node *temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = getBalanceFactor(root);

    if (balance > 1 && getBalanceFactor(root->left) >= 0)
        return rightRotate(root);

    if (balance < -1 && getBalanceFactor(root->right) <= 0)
        return leftRotate(root);

    if (balance > 1 && getBalanceFactor(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalanceFactor(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorderTraversal(Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        cout << root->key << " ";
        inorderTraversal(root->right);
    }
}

int main()
{
    Node *root = NULL;
    int ch, value;

    do
    {
        cout << "AVL Tree Operations Menu:\n";
        cout << "1. Insert a node\n";
        cout << "2. Delete a node\n";
        cout << "3. Display In-order Traversal\n";
        cout << "4. Exit\n";
        cout << "Enter your choice:";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter the value to insert: ";
            cin >> value;
            root = insert(root, value);
            cout << "Inserted " << value << " into the AVL tree.\n";
            break;

        case 2:
            cout << "Enter the value to delete: ";
            cin >> value;
            root = deleteNode(root, value);
            cout << "Deleted " << value << " from the AVL tree.\n";
            break;

        case 3:
            cout << "In-order Traversal:\n";
            inorderTraversal(root);
            cout << endl
                 << endl;
            break;

        case 4:
            cout << "Exiting\n";
            break;

        default:
            cout << "Invalid choice!.\n";
        }
    } while (ch != 4);

    return 0;
}