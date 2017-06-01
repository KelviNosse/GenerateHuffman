#ifndef EVALUADOR_H
#define EVALUADOR_H
#include "Node.h"
#include "Huffman.h"
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <map>
#include <queue>
#include <list>
using namespace std;

void test();
map<char,string> getHuffman(vector<char> characters, vector<int> frequencies);

#endif // EVALUADOR_H
