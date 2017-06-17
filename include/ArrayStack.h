#ifndef _ARRAYSTACK_H
#define _ARRAYSTACK_H

#include<iostream>
using namespace std;

const int MAX_SIZE=100;

template <class T>
class SeqStack
{
 private:
  T *data;
  int topPointer;
 public:
  SeqStack();
  ~SeqStack();
 
  void push(T e);
  T pop();
  T top();
 
  bool empty();
};

template <class T>
SeqStack<T>::SeqStack()
{
 topPointer=-1;
 data=new T[MAX_SIZE];
}

template <class T>
SeqStack<T>::~SeqStack()
{
 topPointer=-1;
 delete []data;
}

template <class T>
void SeqStack<T>::push(T e) //入栈操作
{
 if(topPointer==MAX_SIZE-1) 
 {
  cout<<"OVERFLOW"<<endl;   return;
 }
 topPointer++;
 data[topPointer]=e;
}

template <class T>
T SeqStack<T>::pop() //出栈操作
{
 if(topPointer==-1)
 {
  throw "栈空";
 }
 return data[topPointer--];
}

template <class T>
T SeqStack<T>::top()
{
 if(topPointer==-1)
 {
  throw "栈空";
 }
 return data[topPointer];
}

template <class T>
bool SeqStack<T>::empty()
{
 if(topPointer==-1)
 {
  return true;
 }
 return false;
}

#endif//_ARRAYSTACK_H
