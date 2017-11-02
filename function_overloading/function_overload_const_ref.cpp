#include<iostream>
using namespace std;
 
void fun(const int &i)
{
    cout << "fun(const int &) called \n";
}
void fun(int &i)
{
    cout << "fun(int &) called \n" ;
}
int main()
{
    const int i = 10;
    int j = 10;
    fun(i);
    fun(j);
    cout << 25u - 50 << endl;
    return 0;
}

