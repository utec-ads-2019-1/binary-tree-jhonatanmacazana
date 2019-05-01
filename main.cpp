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
    cout << "Insert 17: " << tree->insert(17) << endl;
    cout << "Insert 20: " << tree->insert(20) << endl;
    cout << "Insert 10: " << tree->insert(10) << endl;
    cout << "Insert 5: " << tree->insert(5) << endl;
    cout << "Insert 2: " << tree->insert(2) << endl;
    cout << "Insert 16: " << tree->insert(16) << endl;
    cout << "Insert 13: " << tree->insert(13) << endl;
    cout << "Insert 12: " << tree->insert(12) << endl;
    cout << "Insert 15: " << tree->insert(15) << endl;
    cout << "Size: " << tree->size() << endl;


    tree->traverseInOrder();


    Iterator<int> it = tree->begin();
    cout << "Iterator: " << *it << endl;
    ++it;
    cout << "Iterator: " << *it << endl;
    ++it;
    cout << "Iterator: " << *it << endl;
    ++it;
    cout << "Iterator: " << *it << endl;
    ++it;
    cout << "Iterator: " << *it << endl;
    ++it;
    cout << "Iterator: " << *it << endl;
    ++it;
    cout << "Iterator: " << *it << endl;

    return EXIT_SUCCESS;
}
