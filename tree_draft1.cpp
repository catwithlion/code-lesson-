#include<iostream>
#include<string>
//I expect to understand the meaning and the advantage of  using tree in languages  
//I had previous concept that the tree is the way to organize to data in way absolutely not linear 
using namespace std;
struct BSTNode
{
    string word;
    string meaning;
    BSTNode *leftchild;
    BSTNode *rightchild;
};
//this above struct is complete one unit of node 
class BinarySearchTree //can you define abeni the importance of this class 
{
private:

    BSTNode *root;
    //we have created  where we just created pointer we dont what it is pointing to 
    // Recursive Helper Functions

    void inorder(BSTNode *ptr); 
    void preorder(BSTNode *ptr);
    void postorder(BSTNode *ptr);

    BSTNode* findMin(BSTNode *ptr);
    BSTNode* findMax(BSTNode *ptr);

    int countNodes(BSTNode *ptr);
    int countLeafNodes(BSTNode *ptr);
    int findHeight(BSTNode *ptr);

    int countInternalNodes(BSTNode *ptr);

    void destroyTree(BSTNode *ptr);

public:

    BinarySearchTree();

    ~BinarySearchTree();

    BSTNode* createNode(string word, string meaning);

    void insert(string word, string meaning);

    bool search(string word);

    void deleteNode(string word);

    void inorder();

    void preorder();

    void postorder();

    void displayDictionary();

    void updateMeaning(string word, string newMeaning);

    bool isEmpty();

    BSTNode* findMin();

    BSTNode* findMax();

    int countNodes();

    int countLeafNodes();

    int findHeight();

    int countInternalNodes();

    void displayMenu();
};

// Constructor

BinarySearchTree::BinarySearchTree()
{
    root = NULL;
}

// Destructor

BinarySearchTree::~BinarySearchTree()
{
    destroyTree(root);
}

// Create Node

BSTNode* BinarySearchTree::createNode(string word, string meaning)
{
    BSTNode *newNode = new BSTNode;
//here we created new node that lives 
    newNode->word = word;
    newNode->meaning = meaning;

    newNode->leftchild = NULL;
    newNode->rightchild = NULL;

    return newNode;
}

// Insert

void BinarySearchTree::insert(string word, string meaning)
{
    BSTNode *newNode = createNode(word, meaning);//why didn't we use the dynamic memory allocation here ? I think we can directly create the node without the need of the dynamic memory allocation because we are not going to use the node outside the function so why we need to create it in the heap ?
    //I didn't 
 //can you explain all the concept of dynamic memoy allocation  and why we ae interchangeing things like
 //once we are creating the node in the heap and once we are creating it in the stack ?
 //Dynamic memory allocation is a powerful feature in programming that allows you to allocate memory at runtime, rather than at compile time. This means that you can create data structures like linked lists, trees, and graphs that can grow and shrink as needed during the execution of your program.
 //in this context when in creat node  because we need to return the node inpendently that means we need the 
 //node to live out side of the function so we need to create it in the heap because if we create it in the stack it will be destroyed once the function ends but if we create it in the heap it will live until we explicitly delete it so that's why we need to create it in the heap in this case because we need to return 
 //the node and use it outside of the function but when we are inserting the node into the tree we don't need to create it in the heap because we are not going to use it outside of the function so we can directly create it in the stack and then insert it into the tree without any problem so that's why we are interchanging 
 //things like once we are creating the node in the heap s theand once we are creating it in the stack because it depends on how we are going to use the node and whether we need it to live outside of the function or not so that's why we are interchanging things like that.
 //is there no anothe case when we need to use dynamic memory allocation over  DOC ?is it just when we 
 //want to 
    if(root == NULL)
    {
        root = newNode;
        return;
    }

    BSTNode *current = root;//what do we call this pointer? it is  

    BSTNode *parent = NULL;//what about this one ? it is also pointer but it is used to keep track of the parent node while we are traversing the tree to find the correct position to insert the new node so we can call it parent pointer because it is used to keep track of the parent node while we are traversing the tree to find the correct position to insert the new node so we can call it parent pointer because it is used to keep track of the parent node while we are traversing the tree to find the correct position to insert the new node so we can call it parent pointer because it is used to keep track of the parent node while we are traversing the tree to find the correct position to insert the new node so we can call it parent pointer because it is used to keep track of the parent node while we are traversing the tree to find the correct position to insert the new node so we can call it parent pointer because it is used to keep track of the parent node while we are traversing the tree to find the correct position to insert the new node so we can call it parent pointer because it is used to keep track of the parent node while we are traversing the tree to find the correct position to insert the new node so we can call it parent pointer because it is used to keep track of the parent node while we are traversing the tree to find the correct position to insert the new node so we can call it parent pointer because it is used to keep track of the parent node while we are traversing the tree to find the correct position to insert the new node so we can call it parent pointer because it is used to keep track of the parent node while we are traversing the tree to find the correct position to insert the new node so we can call it parent pointer because it is used to keep track of the parent node while we are traversing the tree to find the correct position to insert the new node so we can call it parent pointer because it is used to keep track of the parent node while we are traversing the tree to find the correct position to insert the new node so we can call it parent pointer because it is used to keep track of the parent node while we are traversing

    while(current != NULL)
    {
        parent = current;//this keep truck

        if(word < current->word)
            current = current->leftchild;

        else if(word > current->word)
            current = current->rightchild;

        else
        {
            cout << "\nWord already exists.";

            delete newNode;

            return;
        }
        //once we found  then when we find the positio we break out of the bond . but what d we do with 
        // the parent we find out of this loop ? 
    }

    if(word < parent->word)
        parent->leftchild = newNode;

    else
        parent->rightchild = newNode;
        
}

// Search

bool BinarySearchTree::search(string word)
{
    BSTNode *current = root;

    while(current != NULL)
    {
        if(word == current->word)
        {
            cout << "\nWord Found";

            cout << "Meaning: "
                 << current->meaning
                 << endl;

            return true;
        }

        else if(word < current->word)
            current = current->leftchild;

        else
            current = current->rightchild;
    }

    cout << "\nWord Not Found";

    return false;
}

// Delete Node

void BinarySearchTree::deleteNode(string word)
{
    BSTNode *parent = NULL;
    BSTNode *current = root;

    while(current != NULL &&
          current->word != word)
    {
        parent = current;

        if(word < current->word)
            current = current->leftchild;

        else
            current = current->rightchild;
    }

    if(current == NULL)
    {
        cout << "\nWord not found.";

        return;
    }

    // Case 1 : No Child

    if(current->leftchild == NULL &&
       current->rightchild == NULL)
    {
        if(current == root)
            root = NULL;

        else if(parent->leftchild == current)
            parent->leftchild = NULL;

        else
            parent->rightchild = NULL;

        delete current;
    }

    // Case 2 : Only Right Child

    else if(current->leftchild == NULL)
    {
        if(current == root)
            root = current->rightchild;

        else if(parent->leftchild == current)
            parent->leftchild =
            current->rightchild;

        else
            parent->rightchild =
            current->rightchild;

        delete current;
    }

    // Case 3 : Only Left Child

else if(current->rightchild == NULL)
    {
        if(current == root)
            root = current->leftchild;

        else if(parent->leftchild == current)
            parent->leftchild =
            current->leftchild;

        else
            parent->rightchild =
            current->leftchild;

        delete current;
    }

    // Case 4 : Two Children

    else
    {
        BSTNode *successorParent = current;

        BSTNode *successor =
        current->rightchild;

        while(successor->leftchild != NULL)
        {
            successorParent = successor;

            successor = successor->leftchild;
        }

        current->word = successor->word;

        current->meaning =
        successor->meaning;

        if(successorParent->leftchild
           == successor)

            successorParent->leftchild =
            successor->rightchild;

        else

            successorParent->rightchild =
            successor->rightchild;

        delete successor;
    }

    cout << "Word deleted successfully.\n";
}

// Inorder Traversal

void BinarySearchTree::inorder()
{
    inorder(root);
}

void BinarySearchTree::inorder(BSTNode *ptr)
{
    if(ptr != NULL)
    {
        inorder(ptr->leftchild);

        cout << ptr->word
             << " -> "
             << ptr->meaning
             << endl;

        inorder(ptr->rightchild);
    }
}

// Preorder Traversal

void BinarySearchTree::preorder()
{
    preorder(root);
}

void BinarySearchTree::preorder(BSTNode *ptr)
{
    if(ptr != NULL)
    {
        cout << ptr->word
             << " -> "
             << ptr->meaning
             << endl;

        preorder(ptr->leftchild);

        preorder(ptr->rightchild);
    }
}

// Postorder Traversal

void BinarySearchTree::postorder()
{
    postorder(root);
}

void BinarySearchTree::postorder(BSTNode *ptr)
{
    if(ptr != NULL)
    {
        postorder(ptr->leftchild);

        postorder(ptr->rightchild);

        cout << ptr->word
             << " -> "
             << ptr->meaning
             << endl;
    }
}

// Find Minimum

BSTNode* BinarySearchTree::findMin()
{
    return findMin(root);
}

BSTNode* BinarySearchTree::findMin(BSTNode *ptr)
{
    if(ptr == NULL)
        return NULL;

    if(ptr->leftchild == NULL)
        return ptr;

    return findMin(ptr->leftchild);
}

// Find Maximum

BSTNode* BinarySearchTree::findMax()
{
    return findMax(root);
}

BSTNode* BinarySearchTree::findMax(BSTNode *ptr)
{
    if(ptr == NULL)
        return NULL;

    if(ptr->rightchild == NULL)
        return ptr;

    return findMax(ptr->rightchild);
}

// Count Total Nodes

int BinarySearchTree::countNodes()
{
    return countNodes(root);
}

int BinarySearchTree::countNodes(BSTNode *ptr)
{
    if(ptr == NULL)
        return 0;

    return 1 +
           countNodes(ptr->leftchild) +
           countNodes(ptr->rightchild);
}

// Count Leaf Nodes

int BinarySearchTree::countLeafNodes()
{
    return countLeafNodes(root);
}

int BinarySearchTree::countLeafNodes(BSTNode *ptr)
{
    if(ptr == NULL)
        return 0;

    if(ptr->leftchild == NULL &&
       ptr->rightchild == NULL)
        return 1;

    return countLeafNodes(ptr->leftchild) +
           countLeafNodes(ptr->rightchild);
}

// Find Height

int BinarySearchTree::findHeight()
{
    return findHeight(root);
}

int BinarySearchTree::findHeight(BSTNode *ptr)
{
    if(ptr == NULL)
        return -1;

    int leftHeight =
    findHeight(ptr->leftchild);

    int rightHeight =
    findHeight(ptr->rightchild);

    if(leftHeight > rightHeight)
        return leftHeight + 1;

    else
        return rightHeight + 1;
}

// Count Internal Nodes

int BinarySearchTree::countInternalNodes()
{
    return countInternalNodes(root);
}

int BinarySearchTree::countInternalNodes(BSTNode *ptr)
{
    if(ptr == NULL)
        return 0;

    if(ptr->leftchild == NULL &&
       ptr->rightchild == NULL)
        return 0;

    return 1 +
           countInternalNodes(ptr->leftchild) +
           countInternalNodes(ptr->rightchild);
}

// Update Meaning

void BinarySearchTree::updateMeaning
(string word, string newMeaning)
{
    BSTNode *current = root;

    while(current != NULL)
    {
        if(word == current->word)
        {
            current->meaning =
            newMeaning;

            cout << "Meaning updated.\n";

            return;
        }

        else if(word < current->word)
            current = current->leftchild;

        else
            current = current->rightchild;
    }

    cout << "\nWord not found.";
}

// Check Empty Tree

bool BinarySearchTree::isEmpty()
{
    return root == NULL;
}

// Destroy Tree

void BinarySearchTree::destroyTree(BSTNode *ptr)
{
    if(ptr != NULL)
    {
        destroyTree(ptr->leftchild);

        destroyTree(ptr->rightchild);

        delete ptr;
    }
}

// Display Dictionary

void BinarySearchTree::displayDictionary()
{
    inorder();
}

// Display Menu

void BinarySearchTree::displayMenu()
{
    cout << "\n===== BST Dictionary System =====\n";

    cout << "\n1. Insert Word";
    cout << "\n2. Search Word";
    cout << "\n3. Delete Word";
    cout << "\n4. Update Meaning";
    cout << "\n5. Inorder Traversal";
    cout << "\n6. Preorder Traversal";
    cout << "\n7. Postorder Traversal";
    cout << "\n8. Find first word alphabetically in the dictionary (Smallest Word)";
    cout << "\n9. Find last word alphabetically in the dictionary (Largest Word)";
    cout << "\n10. Count Total Words(Nodes)";
    cout << "\n11. Count Leaf Nodes";
    cout << "\n12. Find Height";
    cout << "\n13. Count Internal Nodes";
    cout << "\n0. Exit";
}

// Main Function
int main()
{
    BinarySearchTree bst;

    int choice;

    char again = 'Y';

    string word;
    string meaning;

    do
    {
        bst.displayMenu();

        cout << "\nEnter Choice: ";

        cin >> choice;

        while(cin.fail())
        {
            cout << "Invalid Input. Enter Number Only: ";

            cin.clear();

            cin.ignore(1000, '\n');

            cin >> choice;
        }

        cin.ignore(1000, '\n');

        switch(choice)
        {
        case 1:

            cout << "Enter Word: ";

            getline(cin, word);

            cout << "Enter Meaning: ";

            getline(cin, meaning);

            bst.insert(word, meaning);

            break;

        case 2:

            cout << "Enter the Word you want to Search: ";

            getline(cin, word);

            bst.search(word);

            break;

        case 3:

            cout << "Enter the Word you want to Delete: ";

            getline(cin, word);

            bst.deleteNode(word);

            break;

        case 4:

            cout << "Enter the Word: ";

            getline(cin, word);

            cout << "Enter New Meaning: ";

            getline(cin, meaning);

            bst.updateMeaning(word, meaning);

            break;

        case 5:

            bst.inorder();

            break;

        case 6:

            bst.preorder();

            break;

        case 7:

            bst.postorder();

            break;

        case 8:
        {
            BSTNode *minNode = bst.findMin();

            if(minNode != NULL)
            {
                cout << "\nThe first word is: "
                     << minNode->word
                     << endl;
            }

            break;
        }

        case 9:
        {
            BSTNode *maxNode = bst.findMax();

            if(maxNode != NULL)
            {
                cout << "\nThe last word is: "
                     << maxNode->word
                     << endl;
            }

            break;
        }

        case 10:

            cout << "\nTotal words are: "
                 << bst.countNodes()
                 << endl;

            break;

        case 11:

            cout << "\nLeaf Nodes: "
                 << bst.countLeafNodes()
                 << endl;

            break;

        case 12:

            cout << "\nHeight of Tree: "
                 << bst.findHeight()
                 << endl;

            break;

        case 13:

            cout << "\nInternal Nodes: "
                 << bst.countInternalNodes()
                 << endl;

            break;

        case 0:

            cout << "\nProgram Ended.\n";

            return 0;

        default:

            cout << "\nInvalid Choice.";
        }

        do
        {
            cout << "\nDo you want to continue another operation? (Y/N): ";

            cin >> again;

            cin.ignore(1000, '\n');

            if(again != 'Y' &&
               again != 'y' &&
               again != 'N' &&
               again != 'n')
            {
                cout << "\nInvalid Input. Try Again.";
            }

        }while(again != 'Y' &&
               again != 'y' &&
               again != 'N' &&
               again != 'n');

    }while(again == 'Y' || again == 'y');

    cout << "\nProgram Ended.\n";

    return 0;
}

