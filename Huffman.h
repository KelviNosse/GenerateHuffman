#ifndef HUFFMAN_H
#define HUFFMAN_H
#include "Node.h"
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <map>
#include <queue>
#include <list>
using namespace std;

int index_of_root(int child);
void swap(vector<Node*>* heap, int root, int child);
void push_min_heap(vector<Node*>* heap, Node* node);
void heapify(vector<Node*>* heap);
Node* pop(vector<Node*>* heap);
void backtrack(map<char,string>* answer, Node* root, string code);
void modify_node(vector<Node*>* heap, Node* left, Node* right);
map<char,string> generateHuffman(vector<char> characters, vector<int> frequencies);

#endif //HUFFMAN_H
