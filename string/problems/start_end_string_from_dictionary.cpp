#include <iostream>
#include <string>
#include <list>
#include <queue>
#include <set>
#include <map>
using namespace std;

class Graph
{
  int v;
  list <int> *pAdj;
  int *visited;

  public:
  Graph(int count);
  ~Graph();
  void addEdge(int i, int j);
  void displayAdj(string dictionary[]);
  list<string>* transform(string startWord, string stopWord, string dictionary[]);
};

bool isOneEditWord(string &w1, string &w2)
{
  int count = 0;
  for(int i = 0; i < w1.length(); i++)
  {
    if(w1[i] != w2[i])
      count++;
    if(count > 1) return false;
  }
  return count == 1 ? true : false;
}

void displayList(list<string> *wordList)
{
  list<string>::iterator it;
  for(it = wordList->begin(); it != wordList->end(); it++)
  {
    cout << *it << " -> ";
  }
  cout << endl;
}

list<string>* Graph::transform(string startWord, string stopWord, string dictionary[])
{
  queue<int> wordQueue;
  map<string,string> wordMap;

  cout << "start: " << startWord << "  "  << "stop: " << stopWord << endl;
  for(int i = 0; i < v; i++)
  {
    if(isOneEditWord(startWord, dictionary[i]))
    {
      wordQueue.push(i);
      cout << "push to Queue: " << dictionary[i] << endl;
      wordMap.insert(pair<string,string>(dictionary[i], startWord));
      cout << "insert to Map: " << dictionary[i] << " " << startWord << endl;
      visited[i] = true;
      break;
    }
  }
  
  while(!wordQueue.empty())
  {
    list<int>::iterator it;
    int temp = wordQueue.front();
    wordQueue.pop();
    cout << "pop from Queue: " << dictionary[temp] << endl;

    for(it = pAdj[temp].begin(); it != pAdj[temp].end(); it++)
    {
      if(!visited[*it])
      {
        visited[*it] = true;
        wordQueue.push(*it);
        cout << "push to Queue: " << dictionary[*it] << endl;
        wordMap.insert(pair<string,string>(dictionary[*it], dictionary[temp]));
        cout << "insert to Map: " << dictionary[*it] << " " << dictionary[temp] << endl;

        if(isOneEditWord(stopWord, dictionary[*it]))
        {
          wordMap.insert(pair<string,string>(stopWord, dictionary[*it]));
          cout << "insert to Map: " << stopWord << " " << dictionary[*it] << endl;
          list<string> *lst = new list<string>;
          string str = stopWord;

          map<string,string>::iterator mapIt;
          lst->push_front(str);
          while(startWord != str)
          {
            mapIt = wordMap.find(str);
            str = mapIt->second;
            lst->push_front(str);
          }
          return lst;
        }
      }
    }
  }
}

Graph::Graph(int V)
{
  v = V;
  pAdj = new list <int>[V];
  visited = new int[V];
  for(int i = 0; i < v; i++)
    visited[i] = false;
}

Graph::~Graph()
{
  delete []pAdj;
  delete []visited;
}

void Graph::addEdge(int i, int j)
{
  pAdj[i].push_back(j);
}

void Graph::displayAdj(string dictionary[])
{
  list<int>::iterator it;
  for(int i = 0; i < v; i++)
  {
    cout << dictionary[i] << " -> ";
    for(it = pAdj[i].begin(); it != pAdj[i].end(); it++)
      cout << dictionary[*it] << " -> ";
    cout << endl;
  }
  cout << endl;
}

int main()
{
//  string startWord = "TOON";
//  string stopWord = "PLEA";
//  string dictionary[] = {"POON", "PLEE", "SAME", "POIE", "PLEA", "PLIE", "POIN"};

//  string startWord = "cog";
//  string stopWord = "bad";
  string startWord = "bat";
  string stopWord = "fag";
  string dictionary[] = {"bag", "fog", "cag", "cat", "fag", "con", "rat", "sat"};

  int V = sizeof(dictionary)/sizeof(dictionary[0]);

  Graph g(V);
  for(int i = 0; i < V; i++)
    for(int j = 0; j < V; j++)
      if((i != j) && isOneEditWord(dictionary[i], dictionary[j]))
        g.addEdge(i, j);

  g.displayAdj(dictionary);

  list<string> *wordList = g.transform(startWord, stopWord, dictionary);
  displayList(wordList);
}
