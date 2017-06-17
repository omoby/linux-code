#ifndef _LINKSTACK_H
#define _LINKSTACK_H

#include<iostream>
using namespace std;

template<class T>
struct Node
{
 T data; //数据域
 Node *next; //指针域
};

template<class T>
class LinkStack
{
 private:
  Node<T> *topPointer;
 public:
  LinkStack();
  ~LinkStack();
 
  void push(T e);
  T pop();
  T top();
 
  bool empty();
};

template<class T>
LinkStack<T>::LinkStack()
{
 topPointer=new Node<T>;
 topPointer->next=NULL;
} 

template<class T> 
LinkStack<T>::~LinkStack()
{
 delete topPointer;
}

template<class T>
void LinkStack<T>::push(T e)
{
 Node <T> *aNode;
 aNode=new Node<T>;
 aNode->data=e;
 aNode->next=topPointer;
 topPointer=aNode;
}

template<class T>
T LinkStack<T>::pop()
{
 if(topPointer==NULL)
  throw "下溢";
 Node <T> *p;
 p=topPointer;
 T rtndata = topPointer->data;
 topPointer=topPointer->next;
 delete p;
 return rtndata;
}

template<class T>
T LinkStack<T>::top()
{
 if(topPointer==NULL)
  throw "Empty";
 return topPointer->data;
}

template<class T>
bool LinkStack<T>::empty()
{
 if(topPointer==NULL)
  return true;
 return false;
}

#endif// _LINKSTACK_H
