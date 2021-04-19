// Assignment #6
// Name: Dillan Poorman
// ASU Email Address: dpoorman@asu.com
// Description: Binary Search tree class, with standard Insert. 3 types of tree walks, Max, Min, and Left
// and Right rotation. I didn't comment on the stuff I didn't write, and I didn't use a few functions
// that were given because I didn't notice them until after I wrote the program.

#include <iostream> //to use cout
#include <string> //to use strings
#include <cstdlib> //to use atoi

using namespace std;

//Project represents some project information
class Project
{
private:
    string projectName;
    string region;
    int cost;
    Project* left, * right, * parent;


public:
    //The following two functions are constructors
    Project()
    {
        projectName = "?";
        region = "?";
        cost = 0;
        parent = NULL;
        left = NULL;
        right = NULL;
    }

    Project(string projectName1, string region1, int cost1)
    {
        projectName = projectName1;
        region = region1;
        cost = cost1;
        parent = NULL;
        left = NULL;
        right = NULL;
    }

    //The following functions are accessor functions
    Project* getLeft()
    {
        return left;
    }

    Project* getRight()
    {
        return right;
    }

    Project* getParent()
    {
        return parent;
    }

    string getProjectName()
    {
        return projectName;
    }
    string getRegion()
    {
        return region;
    }
    int getCost()
    {
        return cost;
    }


    //The following functions are mutator functions
    void setLeft(Project* other)
    {
        left = other;
    }

    void setRight(Project* other)
    {
        right = other;
    }

    void setParent(Project* other)
    {
        parent = other;
    }

    //The print method prints the project information
    void print()
    {
        cout << "Project Name: " << projectName << endl;
        cout << "Region: " << region << endl;
        cout << "Cost: " << cost << endl << endl;
    }

    //you can add more functions

};

//class BinarySearchTree will contains projects
class BinarySearchTree
{
private:
    Project* root;
    int size;

public:
    BinarySearchTree();
    ~BinarySearchTree();
    int postOrderTreeDelete(Project*);
    bool isEmpty();
    void inOrderTreePrint();
    void preOrderTreePrint();
    void postOrderTreePrint();
    void inOrderTreeWalk(Project*);
    void preOrderTreeWalk(Project*);
    void postOrderTreeWalk(Project*);
    Project* treeSearchNode(Project*, string);
    Project* treeSearch(string);
    Project* treeMinimum();
    Project* treeMaximum();
    Project* treeMinimumNode(Project*);
    Project* treeMaximumNode(Project*);
    Project* treeSuccessor(string);
    Project* treePredecessor(string);
    bool treeInsert(string, string, int);
    bool rightRotate(string);
    bool leftRotate(string);
};

//The constructor initialize the root to be NULL
BinarySearchTree::BinarySearchTree()
{
    root = NULL;
    size = 0;
}

//The descurtor should delete all nodes in the tree 
//and perform garbage collections starting from leaves (bottom-up order). 
//The destructor should also print “The number of nodes deleted: X” 
//where X is the number of nodes deleted
BinarySearchTree::~BinarySearchTree()
{
    int treeSize = postOrderTreeDelete(this->root);
    cout << "The number of nodes deleted: " << treeSize << endl;
}

//Post order delete function, deletes in a bottom up fashion
int BinarySearchTree::postOrderTreeDelete(Project* z)
{
    
    if(z == NULL){
        return size;
    }

    //left side recursive call
    postOrderTreeDelete(z->getLeft());

    //right side recursive call
    postOrderTreeDelete(z->getRight());
    size++;
    delete z;
    return size;
}

//Checks if the tree is empty
bool BinarySearchTree::isEmpty()
{
    if (root == NULL)
        return true;
    else
        return false;
}

//prints all nodes using in-order
void BinarySearchTree::inOrderTreePrint()
{
    if (isEmpty())
        cout << "tree is empty" << endl;
    else
    {
        cout << "\n";
        inOrderTreeWalk(root);
        cout << "\n";
    }
}

//prints all nodes using pre-order
void BinarySearchTree::preOrderTreePrint()
{
    if (isEmpty())
        cout << "tree is empty" << endl;
    else
    {
        cout << "\n";
        preOrderTreeWalk(root);
        cout << "\n";
    }
}

//prints all nodes using post-order
void BinarySearchTree::postOrderTreePrint()
{
    if (isEmpty())
        cout << "tree is empty" << endl;
    else
    {
        cout << "\n";
        postOrderTreeWalk(root);
        cout << "\n";
    }
}

//Inorder tree walk, walks, left, root, right
void BinarySearchTree::inOrderTreeWalk(Project* root)
{
    if (root != NULL) {
        
        //left recursive call
        inOrderTreeWalk(root->getLeft());

        //inorder print
        cout << endl;
        cout << "Project Name: " << root->getProjectName() << endl;
        cout << "Region: " << root->getRegion() << endl;
        cout << "Cost: " << root->getCost() << endl;
        cout << endl;

        //right recursive call
        inOrderTreeWalk(root->getRight());
    }
}

//preorder tree walk, walks root, left, right.
void BinarySearchTree::preOrderTreeWalk(Project* root)
{
    if (root == NULL) {
        return;
    }

    //preorder print
    cout << endl;
    cout << "Project Name: " << root->getProjectName() << endl;
    cout << "Region: " << root->getRegion() << endl;
    cout << "Cost: " << root->getCost() << endl;
    cout << endl;

    //left recursive call
    preOrderTreeWalk(root->getLeft());

    //right recursive call
    preOrderTreeWalk(root->getRight());
}

//post order tree walk, walks left, right, root.
void BinarySearchTree::postOrderTreeWalk(Project* root)
{
    if (root == NULL) {
        return;
    }

    //left recursive call 
    postOrderTreeWalk(root->getLeft());

    //right recursive call 
    postOrderTreeWalk(root->getRight());


    //post order print
    cout << endl;
    cout << "Project Name: " << root->getProjectName() << endl;
    cout << "Region: " << root->getRegion() << endl;
    cout << "Cost: " << root->getCost() << endl;
    cout << endl;
}

//Tree search node, checks for list, and root first, then looks left subtree, then right subtree.
Project* BinarySearchTree::treeSearchNode(Project* node, string projName)
{

    //check for list
    if((node == NULL) || (projName == node->getProjectName())){
        return node;
    }
    else{
        //search left tree
        if(projName < node->getProjectName()){
            return treeSearchNode(node->getLeft(), projName);
        }
        else{
            //search right tree
            return treeSearchNode(node->getRight(), projName);
        }
    }
}

//wrapper function for TreeSearch
Project* BinarySearchTree::treeSearch(string projName)
{
    return treeSearchNode(this->root, projName);
}

//wrapper function for tree minimun
Project* BinarySearchTree::treeMinimum()
{
    if(this->root == NULL){
        return NULL;
    }
    return treeMinimumNode(this->root);
}

//wrapper function for tree max
Project* BinarySearchTree::treeMaximum()
{
    if(this->root == NULL){
        return NULL;
    }
    return treeMaximumNode(this->root);
}

//iteratively searches the left to the most left leaf node for min
Project* BinarySearchTree::treeMinimumNode(Project* node)
{
    while (node->getLeft() != NULL) {
        node = node->getLeft();
    }
    return node;
}

//iteratively searches the right to the most right leaf node for max
Project* BinarySearchTree::treeMaximumNode(Project* node)
{
    while (node->getRight() != NULL) {
        node = node->getRight();
    }
    return node;
}

//finds the successor of a given node
Project* BinarySearchTree::treeSuccessor(string projName)
{
    //finds given node
    Project* x = treeSearch(projName);

    //temp node
    Project* y;
    if(x == NULL || root == NULL){
        return NULL;
    }

    if (x->getRight() != NULL) {

        return treeMinimumNode(x->getRight());

    }
    
    y = x->getParent();

    while ((y != NULL) && (x == y->getRight())) {
        x = y;
        y = y->getParent();
    }

    return y;
    
}

//finds the predecessor of a given node
Project* BinarySearchTree::treePredecessor(string projName)
{
    Project* x = treeSearch(projName);
    Project* y;

    if(x == NULL || root == NULL){
        return NULL;
    }
    //checking left, if left isn't null it returns max
    if(x->getLeft() != NULL){
        return treeMaximumNode(x->getLeft());
    }
    
    //setting y = x's parent
    y = x->getParent();

    while((y != NULL) && (x == y->getLeft())){
        x = y;
        y = y->getParent();
    }
    return y;
    

}

//tree insertion functon
bool BinarySearchTree::treeInsert(string name, string region, int cost)
{

    //checks for duplicated    
    Project* temp = treeSearch(name);
    if(temp != NULL){
        return false;
    }

    //creates a new project
    Project* z = new Project(name, region, cost);
    Project* y = NULL;
    Project* x = this->root;

    //iterates through tree
    while (x != NULL) {
        y = x;

        if (z->getProjectName() < x->getProjectName()) {
            x = x->getLeft();
        }
        else {
            x = x->getRight();
        }
    }

    //sets z's parent to y
    z->setParent(y);

    //if y is null set root to z
    if (y == NULL) {
        this->root = z;
        return true;
    }
    //left and right check
    else if (z->getProjectName() < y->getProjectName()) {
        y->setLeft(z);
        return true;
    }
    else{
        y->setRight(z);
        return true;
    }

    
    return false;
}

//function for right rotation
bool BinarySearchTree::rightRotate(string projName)
{
    //searches for node to rotate around
    Project* x = treeSearch(projName);
    
    //checks root and the left subtree
    if(root == NULL || x->getLeft() == NULL){
        return false;
    }
    
    //set y - x's left child
    Project* y = x->getLeft();

    //set x's left child to y's right chile
    x->setLeft(y->getRight());
    
    //check y's right child to see if it's there, and if it is, set y's right child's parent to x
    if(y->getRight() != NULL){
        y->getRight()->setParent(x);
    }

    //set y's parent to x's parent
    y->setParent(x->getParent());

    //check x's parent, if not there, set root as y, or set the parent of x's left or right to y
    if(x->getParent() == NULL){
        this->root = y;
    }
    else if(x == x->getParent()->getLeft()){
        x->getParent()->setLeft(y);
    }
    else{
        x->getParent()->setRight(y);
    }

    //set y's child to x
    y->setRight(x);

    //set x's parent to y
    x->setParent(y);

    return true;    
    
}

//function for left rotation, symmetric to right
bool BinarySearchTree::leftRotate(string projName)
{
    
    
    Project* x = treeSearch(projName);
    

    if(root == NULL || x->getRight() == NULL){
        return false;
    }

    Project* y = x->getRight();
    x->setRight(y->getLeft());

    if(y->getLeft() != NULL){
        y->getLeft()->setParent(x);
    }

    y->setParent(x->getParent());

    if(x->getParent() == NULL){
        this->root = y;
    }
    else if(x == x->getParent()->getLeft()){
        x->getParent()->setLeft(y);
    }
    else{
        x->getParent()->setRight(y);
    }

    y->setLeft(x);
    x->setParent(y);

    return true;
    
}
