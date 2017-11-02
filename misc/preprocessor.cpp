#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define toStr(str) #str
#define io(v) cin >> v
#define INF INT_MAX
#define foreach(a, b) for(int b = 0; b < a.size(); ++b)

#define FUNCTION(fun, op) \
void fun(int &mn, int val) {\
  mn = mn op val ? mn : val;\
}\

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main()
{
  int n; cin >> n;
  vector<int> v(n);

  foreach(v, i) {
    io(v)[i];
  }

  int mn = INF;
  int mx = -INF;

  foreach(v, i) {
    minimum(mn, v[i]);
    maximum(mx, v[i]);
  }
  int ans = mx - mn;
  cout << toStr(Result =) << ' ' << ans;
  return 0;
}
