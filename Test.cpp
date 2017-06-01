#include "Test.h"

bool checkCodesAreDifferent(map<char,string> codes)
{
  for(map<char,string>::iterator i = codes.begin(); i != codes.end(); i++)
  {
    map<char,string>::iterator j = i;
    j++;
    for(; j != codes.end(); j++)
    {
      if((*i).second == (*j).second)
      {
        return false;
      }
    }
  }
  return true;
}

void test()
{
    static const char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    vector<char> vector1_test1 (arr, arr + sizeof(arr) / sizeof(arr[0]) );

    static const int arr2[] = {10, 5, 3, 7, 9, 20};
    vector<int> vector2_test1 (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );

    map<char,string> answer1 = getHuffman(vector1_test1, vector2_test1);

    static const char arrx[] = {'x', 'y', 'z'};
    vector<char> vector1_test2 (arrx, arrx + sizeof(arrx) / sizeof(arrx[0]) );

    static const int arr2x[] = {10, 5, 15,};
    vector<int> vector2_test2 (arr2x, arr2x + sizeof(arr2x) / sizeof(arr2x[0]) );

    map<char,string> answer2 = getHuffman(vector1_test2, vector2_test2);

    if(answer1['a'].length() == 3// == "111"
       && answer1['b'].length() == 4// == "1011"
       && answer1['c'].length() == 4// == "1010"
       && answer1['d'].length() == 3// == "100"
       && answer1['e'].length() == 3// == "110"
       && answer1['f'].length() == 1// == "0"
       && checkCodesAreDifferent(answer1)

       && answer2['x'].length() == 2// == "11"
       && answer2['y'].length() == 2// == "10"
       && answer2['z'].length() == 1// == "0"
       && checkCodesAreDifferent(answer2)
       )
    {
        cout<<"Test: Pass"<<endl;
    }else
    {
        cout<<"Test: Fail"<<endl;
    }
}
