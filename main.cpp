#include "Test.h"
#include <iostream>
using namespace std;

map<char,string> getHuffman(vector<char> characters, vector<int> frequencies)
{
  return generateHuffman(characters, frequencies);
}

int main (){
    test();
    return 0;
}