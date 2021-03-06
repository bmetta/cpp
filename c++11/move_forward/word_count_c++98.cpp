#include <cstdio> // easier than iostream for formatted output
#include <iostream>
#include <iterator>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>

typedef std::map<std::string, std::size_t> WordCountMapType;

// for each word in file, return # of occurrences
WordCountMapType wordsInFile(const char * const fileName)
{
  std::ifstream file(fileName);
  WordCountMapType wordCounts;
  for (std::string word; file >> word; ) {
    ++wordCounts[word];
  }
  return wordCounts;
}

// compare 2nd components of pointed-to pairs
struct Ptr2Pair2ndGT {
  template<typename It>
    bool operator()(It it1, It it2) const { return it1->second > it2->second; }
};

// print n most common words in [begin, end)
template<typename MapIt> 
void showCommonWords(MapIt begin, MapIt end, const std::size_t n)
{
  typedef std::vector<MapIt> TempContainerType;
  typedef typename TempContainerType::iterator IterType;

  TempContainerType wordIters;

  wordIters.reserve(std::distance(begin, end));
  for (MapIt i = begin; i != end; ++i) wordIters.push_back(i);

  std::partial_sort(wordIters.begin(), wordIters.begin() + n, wordIters.end(), Ptr2Pair2ndGT());

  for (IterType it = wordIters.begin(); it != (wordIters.begin() + n); ++it) {
    std::printf(" %-10s%10u\n", (*it)->first.c_str(), (*it)->second);
  }
} 

// take list of file names on command line, print 20 most common words within
int main(int argc, const char** argv)
{
  WordCountMapType wordCounts;
  for (int argNum = 1; argNum < argc; ++argNum) {
    // copy map returned by wordsInFile (modulo compiler optimization)
    const WordCountMapType wordCountInfoForFile = wordsInFile(argv[argNum]);
    typedef typename WordCountMapType::const_iterator const_it;

    for (const_it i = wordCountInfoForFile.begin(); i != wordCountInfoForFile.end(); ++i) {
      wordCounts[i->first] += i->second;
    }
  }
  std::cout << wordCounts.size() << "words found. Most common:\n" ;
  const std::size_t maxWordsToShow = 20;
  showCommonWords(wordCounts.begin(), wordCounts.end(), std::min(wordCounts.size(), maxWordsToShow));
}

