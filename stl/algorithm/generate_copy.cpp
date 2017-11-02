#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

struct g
{
	g():n(0){}
	int operator()() { return n++; }
	int n;
};

int main()
{
	int a[10];
	generate(a, a+10, g());

//	copy(a, a+10, ostream_iterator<int>(cout, " "));

  ostream_iterator<int> out_it(cout, " ");
	copy(a, a+10, out_it);
}
