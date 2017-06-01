
#ifndef NODE_H
#define NODE_H

class Node
{
    public:
        Node* left;
        Node* right;
        int frequency;
        char symbol;
        Node(char symbol, int frequency);
};

#endif // NODE_H