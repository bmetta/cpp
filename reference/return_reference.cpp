#include<iostream>
using namespace std;
 
//int x = 10;
int &fun()
{
    int x = 10;
    return x;
}
int main()
{
    fun() = 30;
    cout << fun() << endl;
    return 0;
}
