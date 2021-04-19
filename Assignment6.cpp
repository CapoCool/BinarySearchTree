
// Assignment #6
// Name: Dillan
// Description: This program displays a menu of choices to a user
//        and performs the chosen task. It will keep asking a user to
//        enter the next choice until the choice of 'Q' (Quit) is entered.

#include <iostream> //to use cin and cout
#include <string> //to use strings
#include <cstdlib> //to use string functions
#include "BinarySearchTree.h"

using namespace std;

void printMenu();

int main()
{
    // instantiate a Binary Tree object
    BinarySearchTree* tree1 = new BinarySearchTree();

    char input1;
    bool success = false;
    string line, inputStr, projectName, region, costStr;
    int cost;
    Project* temp; //it will be used to hold a returned the input info

    printMenu();

    do  // will ask for user input
    {
        cout << "What action would you like to perform?\n";
        cin.get(input1);
        input1 = toupper(input1);
        cin.ignore(20, '\n'); //flush the buffer
        // matches one of the case regionment
        switch (input1)
        {
        case 'A':   //Inorder Print
            tree1->inOrderTreePrint();
            break;
        case 'B':   //Preorder Print
            tree1->preOrderTreePrint();
            break;
        case 'C':   //Postorder Print
            tree1->postOrderTreePrint();
            break;
        case 'D':   //Tree Minimum
            temp = tree1->treeMinimum();
            if (temp == NULL)
                cout << "tree is empty" << endl;
            else
            {
                cout << "The first project is ";
                temp->print();
                cout << endl;
            }
            break;
        case 'E':   //Tree Maximum
            temp = tree1->treeMaximum();
            if (temp == NULL)
                cout << "tree is empty" << endl;
            else
            {
                cout << "The last project is ";
                temp->print();
                cout << endl;
            }
            break;
        case 'F':   //Tree Predecessor
            cout << "Please enter a project name to find its predecessor:\n";
            getline(cin, projectName);

            temp = tree1->treePredecessor(projectName);
            if (temp == NULL)
                cout << projectName << " does not have any predecessor\n";
            else
            {
                cout << "The predecessor of "
                    << projectName << " is ";
                temp->print();
                cout << endl;
            }
            break;
        case 'G':   //Tree Successor
            cout << "Please enter a project name to find its successor:\n";
            getline(cin, projectName);

            temp = tree1->treeSuccessor(projectName);
            if (temp == NULL)
                cout << projectName << " does not have any successor\n";
            else
            {
                cout << "The successor of "
                    << projectName << " is ";
                temp->print();
                cout << endl;
            }
            break;
        case 'H':   //Tree Search
            cout << "Please enter a project name to search:\n";
            getline(cin, projectName);

            temp = tree1->treeSearch(projectName);
            if (temp != NULL)
                cout << projectName << " has its region/cost: " << temp->getRegion() << "/" << temp->getCost() << endl;
            else
                cout << projectName << " not found\n";
            break;
        case 'I':   //Tree Insert
            cout << "Please enter a projectName/region/cost to insert:\n";
            cout << "Enter a project name\n";
            getline(cin, projectName);
            cout << "Enter its region\n";
            getline(cin, region);
            cout << "Enter its cost\n";
            getline(cin, costStr);
            cost = stoi(costStr.c_str());

            success = tree1->treeInsert(projectName, region, cost);

            if (success == true)
            {
                cout << projectName << " with its region/cost: " << region << "/" << cost;
                cout << " inserted\n";
            }
            else
            {
                cout << projectName << " with its region/cost: " << region << "/" << cost;
                cout << " not inserted\n";
            }
            break;
        case 'J':  //Right Rotation
            cout << "Please enter a projectName to right-rotate:\n";
            getline(cin, projectName);

            success = tree1->rightRotate(projectName);
            if (success == true)
                cout << "Right Rotation around " << projectName << " is successful\n";
            else
            {
                cout << "Right Rotation cannot be performed around ";
                cout << projectName << endl;
            }
            break;
        case 'K':  //Left Rotation
            cout << "Please enter a projectName to left-rotate:\n";
            getline(cin, projectName);

            success = tree1->leftRotate(projectName);
            if (success == true)
            {
                cout << "Left Rotation around " << projectName << " is successful\n";
            }
            else
            {
                cout << "Left Rotation cannot be performed around ";
                cout << projectName << endl;
            }
            break;
        case 'Q':   //Quit
            delete tree1;
            break;
        case '?':   //Display Menu
            printMenu();
            break;
        default:
            cout << "Unknown action\n";
            break;
        }
    } while (input1 != 'Q');

    return 0;
}

/** The method printMenu displays the menu to a user**/
void printMenu()
{
    cout << "Choice\t\tAction\n";
    cout << "------\t\t------\n";
    cout << "A\t\tInorder Print\n";
    cout << "B\t\tPreorder Print\n";
    cout << "C\t\tPostorder Print\n";
    cout << "D\t\tTree Minimum\n";
    cout << "E\t\tTree Maximum\n";
    cout << "F\t\tTree Predecessor\n";
    cout << "G\t\tTree Successor\n";
    cout << "H\t\tTree Search\n";
    cout << "I\t\tTree Insert\n";
    cout << "J\t\tRight Rotation\n";
    cout << "K\t\tLeft Rotation\n";
    cout << "Q\t\tQuit\n";
    cout << "?\t\tDisplay Help\n\n";
}
