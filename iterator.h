#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"
#include <stack>

template <typename T>
class Iterator {
    private:
        Node<T> *current;
        std::stack<Node<T>> stackInc;
        std::stack<Node<T>> stackDec;

        void pushAll(Node<T> *node)
        {
            while(node)
            {
                stackInc.push(*node);
                node = node->left;
            }
        }

    public:
        Iterator() {
            current = NULL;
        }

        Iterator(Node<T> *node) {
            this->pushAll(node);
            *current = stackInc.top();
        }

        Iterator<T> operator=(Iterator<T> other) {
            this->current = other.current;
        }

        bool operator!=(Iterator<T> other) {
            return &(this->current) != &(other.current);
        }

        Iterator<T> operator++() {
            *current = stackInc.top();
            stackDec.push(stackInc.top());
            stackInc.pop();
            *current = stackInc.top();
            if(current->right)
            {
                stackInc.pop();
                pushAll(current->right);
                stackInc.push(*current);
            }

            return (*this);
        }

        Iterator<T> operator--() {
            // TODO
        }

        T operator*() {
            *current = stackInc.top();
            return current->data;
        }
};

#endif
