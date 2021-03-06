#ifndef BSTREE_H
#define BSTREE_H

#include "node.h"
#include "iterator.h"

template <typename T>
class BSTree {
private:
    Node<T> *root;
    int nodes;

    void printPreOrder(Node<T>* node)
    {
        std::cout << node->data << std::endl;
        if(node->left) printPreOrder(node->left);
        if(node->right) printPreOrder(node->right);
    }

    void printInOrder(Node<T>* node)
    {
        if(node->left) printInOrder(node->left);
        std::cout << node->data << std::endl;
        if(node->right) printInOrder(node->right);
    }

    void printPostOrder(Node<T>* node)
    {
        if(node->left) printPostOrder(node->left);
        if(node->right) printPostOrder(node->right);
        std::cout << node->data << std::endl;
    }


    Node<T>* minValueNode(Node<T>* node)
    {
        auto currentNode = node;
        while(currentNode && currentNode->left)
            currentNode = currentNode->left;

        return currentNode;
    }

    Node<T>* kill(Node<T>* node, T data)
    {
        if (!node) return node;

        if (data < node->data)
            node->left = kill(node->left, data);

        else if (data > node->data)
            node->right = kill(node->right, data);

        else
        {
            if(!node->left)
            {
                auto tempNode = node->right;
                free(node);
                return tempNode;
            }

            else if(!node->right)
            {
                auto tempNode = node->left;
                free(node);
                return tempNode;
            }

            auto tempNode = minValueNode(node->right);

            node->data = tempNode->data;
            node->right = kill(node->right, tempNode->data);
        }
        return node;

    }

public:
    BSTree() : root(nullptr), nodes(0) {};

    bool find(T data) {
        Node<T> *searchNode = this->root;

        while(searchNode)
        {
            if(data < searchNode->data)
            {
                if(searchNode->left) searchNode = searchNode->left;
                else break;
            }
            else if (data > searchNode->data)
            {
                if(searchNode->right) searchNode = searchNode->right;
                else break;
            }
            else if(searchNode->data == data) return true;
        }
        return false;
    }

    bool insert(T data) {
        Node<T> *searchNode = this -> root;
        if (find(data)) return false;

        if (!searchNode) this->root = new Node<T>(data);
        else
        {
            while(searchNode)
            {
                if(data < searchNode->data)
                {
                    if(searchNode->left) searchNode = searchNode->left;
                    else {searchNode->left = new Node<T>(data); break;}
                }
                else
                {
                    if(searchNode->right) searchNode = searchNode->right;
                    else {searchNode->right = new Node<T>(data); break;}
                }
            }
        }
        ++nodes;
        return true;
    }

    bool remove(T data) {
        Node<T> *searchNode = this -> root;
        if (!find(data) || !searchNode) return false;
        this->root = kill(searchNode, data);
        --nodes;
        return true;
    }

    unsigned int size() {
        return this->nodes;
    }

    void traversePreOrder() {
        if(this->root) printPreOrder(this->root);
    }

    void traverseInOrder() {
        if(this->root) printInOrder(this->root);
    }

    void traversePostOrder() {
        if(this->root) printPostOrder(this->root);
    }

    Iterator<T> begin() {
        return Iterator<T> (this->root);
    }

    Iterator<T> end() {
        return Iterator<T> ();
    }

    ~BSTree() {
        // Falta controlar el caso del árbol vacío
        this->root->killself(this->root);
    }
};

#endif
