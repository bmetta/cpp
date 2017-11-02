#include <iostream>
#include <string>
#include <iomanip>
#include <set>
using namespace std;

string findWord(string str);
void printString(string str)
{
  for(int i = 0; i < str.length(); i++)
  {
    cout << setw(3) << i;
  }
  cout << endl;
  for(int i = 0; i < str.length(); i++)
  {
    cout << setw(3) << str[i];
  }
  cout << endl;
}

string firstRepeatedWord(string str)
{
  string subStr = "";
  set<string> mySet;
  set<string>::iterator it;

  for(int i = 0; i < str.length() && str[i] != ';';)
  {
    if(str[i] != ' ')
    {
      subStr = findWord(str.substr(i, str.length()-i));
      cout << subStr << endl;
      i += subStr.length();

      it = mySet.find(subStr);
      if(it == mySet.end())
      {
        mySet.insert(subStr);
      }
      else
      {
        return subStr;
      }
    }
    else
      i++;
  }
  return "";
}

string findWord(string str)
{
  int inWord = 0, start = 0;
  string subStr = "";
//  cout << str << endl;

  for(int i = 0; i < str.length(); i++)
  {
    /* non character */
    if(str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == ';')
    {
      /* word ends */
      if(inWord)
      {
        subStr = str.substr(start, i-start);
        break;
      }
      inWord = 0;
    }
    else /* characters */
    {
      /* word starts */
      if(!inWord)
      {
        inWord = 1;
        start = i;
      }
    }
  }
  return (subStr);
}

int main()
{
  string str = "   He had quite enough of he this nonsense;   ";
 
//  printString(str);

  cout << "first repeated word: " << firstRepeatedWord(str) << endl;
}
