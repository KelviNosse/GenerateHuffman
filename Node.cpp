#include "Node.h"
#include <cstddef>

Node::Node(char symbol, int frequency){
    this->symbol = symbol;
    this->frequency = frequency;
    this->left = NULL;
    this->right = NULL;
}