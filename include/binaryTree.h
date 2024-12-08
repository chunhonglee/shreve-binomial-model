#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <memory>
#include "node.h"

// A class to represent the BinaryTree
class BinaryTree {
    private:
        int n;
        std::shared_ptr<Node> head;

        std::shared_ptr<Node> buildTree(int n);

    public:
        BinaryTree(int n);

        int getHeight();

        std::shared_ptr<Node> getHead();
};

#endif