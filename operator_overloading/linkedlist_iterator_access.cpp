#include <iostream>
using namespace std;

class linkedList;
class linkedListIterator;

class Node  {
  private:
    int data;
    Node *pNext;

  public:
    Node(int val) : data(val), pNext(NULL) {}

    friend class linkedList;
    friend class linkedListIterator;

};

class linkedListIterator  {
  private:
    Node *pCur;
    linkedListIterator(Node *pNode) {
      pCur = pNode;
    }

  public:
    linkedListIterator() : pCur(NULL) {}

    bool operator==(linkedListIterator it) const {
      return (pCur == it.pCur);
    }
    bool operator!=(linkedListIterator it) const {
      return (pCur != it.pCur);
    }
    void operator++ () {
      pCur = pCur->pNext;
    }
    void operator++ (int) {
      pCur = pCur->pNext;
    }
    int operator* () {
      return pCur->data;
    }
    friend class linkedList;
};

class linkedList  {
  private:
    Node *pHead;
    Node *pTail;

  public:
    linkedList() : pHead(NULL), pTail(NULL)  {}
    void push_back(int val)  {
      if(!pHead)  {
        pHead = pTail = new Node(val);
      } else {
        pTail->pNext = new Node(val);
        pTail = pTail->pNext;
      }
    }
    linkedListIterator begin() {
      return pHead;
    }
    linkedListIterator end() {
      return NULL;
    }
};

int main()
{
  linkedList list;
  linkedListIterator it;

  list.push_back(10);
  list.push_back(20);
  list.push_back(30);
  list.push_back(40);

  for(it = list.begin(); it != list.end(); it++)
  {
    cout << *it << endl;
  }
}
