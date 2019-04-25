#include <iostream>
//#include "tester/tester.h"

#include "bstree.h"

using namespace std;

int main(int argc, char *argv[]) {
    cout << "===========================================================" << endl;
    cout << "Binary Search Tree Practice" << endl;
    cout << "===========================================================" << endl << endl;

    //Tester::execute();

    BSTree<int> *tree = new BSTree<int>();


    //cout << *(tree->root->data) << endl;
    cout << "Hola" << endl;
    cout << "Insert 5: " << tree->insert(5) << endl;
    cout << "Insert 7: " << tree->insert(7) << endl;
    cout << "Insert 9: " << tree->insert(9) << endl;
    cout << "Insert 3: " << tree->insert(3) << endl;
    cout << "Insert 7: " << tree->insert(7) << endl;
    cout << "Insert 2: " << tree->insert(2) << endl;
    cout << "Insert 6: " << tree->insert(6) << endl;
    cout << "Insert 9: " << tree->insert(9) << endl;
    cout << "Size: " << tree->size() << endl;

    cout << endl << "Traverse Pre Order: " << endl;
    tree->traversePreOrder();

    cout << endl << "Traverse In Order: " << endl;
    tree->traverseInOrder();

    cout << endl << "Traverse Post Order: " << endl;
    tree->traversePostOrder();

    return EXIT_SUCCESS;
}
