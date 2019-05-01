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

        bool swapVal(Node<T>* node1, Node<T>* node2)
        {
            T tempData;
            tempData = node1->data;
            node1->data = node2->data;
            node2->data = tempData;
            if(node2->left || node2->right) return false;
            return true;
        }

        void kill(Node<T>* node, T data)
        {
            if (data == node->data)
            {
                if(node->left)
                {
                    if(swapVal(node, node->left)){
                        delete node->left;
                        node->left = NULL;
                    }
                    else
                        kill(node, data);
                }
                else if(node->right)
                {
                    if(swapVal(node, node->right)){
                        delete node->right;
                        node->right = NULL;
                    }
                    else
                        kill(node, data);
                }

            }
            else if(data < node->data)
            {
                if(data == node->left->data)
                {
                    if(node->left->left)
                    {
                        if(swapVal(node->left, node->left->left)){
                            delete node->left->left;
                            node->left->left = NULL;
                        }
                        else
                            kill(node->left->left, data);
                    }
                    else if (node->left->right)
                    {
                        if(swapVal(node->left, node->left->right)){
                            delete node->left->right;
                            node->left->right = NULL;
                        }
                        else
                            kill(node->left->right, data);
                    }
                    else
                    {
                        delete node->left;
                        node->left = NULL;
                    }


                }
                else
                    kill(node->left, data);
            }
            else
            {
                if(data == node->right->data)
                {
                    if(node->right->left)
                    {
                        if(swapVal(node->right, node->right->left)){
                            delete node->right->left;
                            node->right->left = NULL;
                        }
                        else
                            kill(node->right->left, data);
                    }
                    else if (node->right->right)
                    {
                        if(swapVal(node->right, node->right->right)){
                            delete node->right->right;
                            node->right->right = NULL;
                        }
                        else
                            kill(node->right->right, data);
                    }
                    else
                    {
                        delete node->right;
                        node->right = NULL;
                    }
                }
                else
                    kill(node->right, data);
            }
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
            kill(searchNode, data);
            --nodes;
            return true;
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
            return Iterator<T> (this->root);
        }

        Iterator<T> end() {
            return Iterator<T> (NULL);
        }

        ~BSTree() {
            // TODO
        }
};

#endif
