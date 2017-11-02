#include <iostream>
#include <string>
using namespace std;
/*
int strStr(string str, string subStr)
{
  cout << str << endl;
  cout << subStr << endl;

  for(int i = 0; i < str.length(); i++)
  {
    int j;
    for(j = 0; j < subStr.length(); j++)
    {
      if(str[i + j] != subStr[j])
        break;
    }
    if(j == subStr.length())
      return 1;
  }
  return 0;
}
*/

int main()
{
  string str = "hello world hello how world are you.";
  string subStr;

//  const char *ptr = str.c_str();
//  for(int i = 0; ptr[i] != '\0'; i++)
//    cout << ptr[i];
//  cout << endl;

  cout << str.data() << endl;
//  for(int i = 0; i < str.length(); i++)
//    cout << i << ": " << str.at(i) << endl;
//  cout << endl;

  int inWord = 0;
  int start;
  for(int i = 0; i < str.length(); i++)
  {
    if(str.at(i) == ' ' || str.at(i) == '\t' || str.at(i) == '.')
    {
      if(inWord)
      {
        inWord = 0;
        string subS = str.substr(start, i-start);
        int pos = str.find(subS, start + 1);
        cout << subS << "  " << start << " ";
        if(pos!=string::npos)
          cout << "found : " << str.substr(pos, i-start) << endl;
        else
          cout << "not found" << endl;
      }
    }
    else if(!inWord)
    {
      inWord = 1;
      start = i;
    }
  }

//  if(strStr(str, subStr))
//    cout << "Found" << endl;
//  else
//    cout << "not found" << endl;
}
