#include <iostream>
#include <map>
using namespace std;

bool fncomp (char lhs, char rhs) {
  cout << "fncomp: " << lhs << " " << rhs << endl;
  return lhs<rhs;
}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const {
    cout << "classcomp " << lhs << " " << rhs << endl;
    return lhs<rhs;
  }
};

void displayMap(map<char, int> myMap)
{
  map<char, int>::iterator it;
  
  for(it = myMap.begin(); it != myMap.end(); ++it) {
    cout << it->first << " " << it->second << endl;
  }
  cout << endl;
}

void displayMap(map<char, int, classcomp> myMap)
{
  map<char, int>::iterator it;
  
  for(it = myMap.begin(); it != myMap.end(); ++it) {
    cout << it->first << " " << it->second << endl;
  }
  cout << endl;
}

void displayMap(map<char, int, bool(*)(char,char)> myMap)
{
  map<char, int>::iterator it;
  
  for(it = myMap.begin(); it != myMap.end(); ++it) {
    cout << it->first << " " << it->second << endl;
  }
  cout << endl;
}

int main ()
{
  map<char,int> first;

  first['a']=10;
  first['b']=30;
  first['c']=50;
  first['d']=70;
//  displayMap(first);

  map<char,int> second (first.begin(),first.end());
//  displayMap(second);

  map<char,int> third (second);
//  displayMap(third);

  map<char,int,classcomp> fourth;                 // class as Compare
//  fourth['b']=31; cout << endl;
//  fourth['d']=71; cout << endl;
//  fourth['a']=11; cout << endl;
//  fourth['c']=51; cout << endl;
//  displayMap(fourth);

  bool(*fn_pt)(char,char) = fncomp;
  map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare
  fifth['b']=31; cout << endl;
  fifth['d']=71; cout << endl;
  fifth['a']=11; cout << endl;
  fifth['c']=51; cout << endl;
  displayMap(fifth);

  return 0;
}
