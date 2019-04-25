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
                else
                {
                    if(searchNode->right) searchNode = searchNode->right;
                    else break;
                }

                if(searchNode->data == data) return true;

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
            // TODO
        }

        unsigned int size() {
            return this->nodes;
        }

        void print(Node<T>* node)
        {
            std::cout << node->data << std::endl;
            if(node->left) print(node->left);
            if(node->right) print(node->right);
        }

        void traversePreOrder() {
            printPreOrder(this->root);
        }

        void traverseInOrder() {
            printInOrder(this->root);
        }

        void traversePostOrder() {
            printPostOrder(this->root);
        }

        Iterator<T> begin() {
            return Iterator<T> (this->root); // hoja izquierda
        }

        Iterator<T> end() {
            return Iterator<T> (NULL); // hoja derecha
        }

        ~BSTree() {
            // TODO
        }
};

#endif
