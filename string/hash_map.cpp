#include <iostream>
#include <hash_map>
#define _DEFINE_DEPRECATED_HASH_CLASSES 0
typedef pair <int, int> Int_Pair;
 
using namespace std;
using namespace stdext;
 
int main()
{
  hash_map <int, int> hm1;
  hash_map <int, int> :: iterator hm1_Iter;
  hash_map <int, int> :: const_iterator hm1_cIter;
 
  hm1.insert (Int_Pair(0, 0));
  hm1.insert (Int_Pair(1, 1));
  hm1.insert (Int_Pair(2, 4));

  hm1_cIter = hm1.begin ( );
  cout <<"The first element of hm1 is "<<hm1_cIter -> first<<"."<<endl;
 
  hm1_Iter = hm1.begin ( );
  hm1.erase ( hm1_Iter );
 
  // The following 2 lines would err because the iterator is const
  // hm1_cIter = hm1.begin ( );
  // hm1.erase ( hm1_cIter );
 
   hm1_cIter = hm1.begin( );
   cout <<"The first element of hm1 is now "<<hm1_cIter -> first<<"."<<endl;
 
  return 0;
}
