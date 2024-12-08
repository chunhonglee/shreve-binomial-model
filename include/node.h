#ifndef NODE_H
#define NODE_H

#include <memory>

class Node {
    private:
        double value = 0;
        std::shared_ptr<Node> left = nullptr;
        std::shared_ptr<Node> right = nullptr;

    public:
        Node();

        Node(double value);

        Node(double value, std::shared_ptr<Node>& left, std::shared_ptr<Node>& right);

        double getValue();

        std::shared_ptr<Node> getLeft();

        std::shared_ptr<Node> getRight();

        void setValue(double value);

        void setLeft(std::shared_ptr<Node>& left);

        void setRight(std::shared_ptr<Node>& right);
};

#endif