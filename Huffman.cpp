#include "Huffman.h"

int index_of_root(int child){
  return (child % 2 == 0) ? (child - 2)/2 : (child - 1)/2;
}

void swap(vector<Node*>* heap, int root, int child){
  Node* temp = (*heap)[root];
  (*heap)[root] = (*heap)[child];
  (*heap)[child] = temp;
}

void push_min_heap(vector<Node*>* heap, Node* node){
  heap->push_back(node);
  int child = heap->size() - 1, root = 0;
  while(child != 0){
    root = index_of_root(child);
    if((*heap)[child]->frequency > (*heap)[root]->frequency) 
    break;
    swap(heap, root, child);
    child = root;
  }
}

void heapify(vector<Node*>* heap){
  int root_pos = 0;
  int left = root_pos*2 + 1;
  int right = root_pos*2 + 2;
  int lowest = 0;
  while(left < (int)heap->size()){
    if(right < (int)heap->size()) 
    lowest = (*heap)[left]->frequency < (*heap)[right]->frequency ? left : right;
    else lowest = left;
    if((*heap)[root_pos]->frequency > (*heap)[lowest]->frequency) swap(heap, root_pos, lowest);
    else break;
    root_pos = lowest;
    left = root_pos*2 + 1;
    right = root_pos*2 + 2;
  }
}

Node* pop(vector<Node*>* heap){
  Node* node = (*heap)[0];
  (*heap)[0] = (*heap)[heap->size() - 1];
  heap->erase(heap->end() - 1);
  heapify(heap);
  return node;
}

void backtrack(map<char,string>* answer, Node* root, string code){
    if(root){
      if(root->symbol != '.') (*answer)[root->symbol] = code;
      backtrack(answer, root->left, code + "0");
      backtrack(answer, root->right, code + "1");
    }else return;
}

void modify_node(vector<Node*>* heap, Node* left, Node* right){
  Node* node = new Node('.', left->frequency + right->frequency);
  node->left = left;
  node->right = right;
  push_min_heap(heap, node);
}

map<char,string> generateHuffman(vector<char> characters, vector<int> frequencies){
  vector<Node*> nodes, min_heap;
  for(int i = 0; i < (int)characters.size(); i++) nodes.push_back(new Node(characters[i], frequencies[i]));
  for(int i = 0; i < (int)nodes.size(); i++) push_min_heap(&min_heap, nodes[i]);
  while(min_heap.size() > 1)
  {
    Node* right = pop(&min_heap);
    Node* left = pop(&min_heap);
    modify_node(&min_heap, left, right);
  }
  map<char,string> answer;
  backtrack(&answer, min_heap[0], "");
  return answer;
}