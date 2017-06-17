#include<iostream>
#include "include/List.h"
#include "include/ArrayStack.h"
#include "include/LinkStack.h"
#include "include/Queue.h"
#include "include/BinaryTreeNode.h"
#include "include/BinaryTree.h"
using namespace std;

int main()
{
	//顺序栈
	cout<<endl<<endl;
	cout<<"顺序栈实现"<<endl;
	cout<<"**********************************************************"<<endl;
    int tmp = 0;
    SeqStack<int> *array_stack = new SeqStack<int>;
 
     cout<<"main"<<endl;
 //将10, 20, 30 依次推入栈中
    array_stack->push(10);
    array_stack->push(20);
    array_stack->push(30);
   
    // 将“栈顶元素”赋值给tmp，并删除“栈顶元素”
    tmp = array_stack->pop();
    cout<<"tmp="<<tmp<<endl;
   
    // 只将“栈顶”赋值给tmp，不删除该元素
    tmp = array_stack->top();
    cout<<"tmp="<<tmp<<endl;
   
    array_stack->push(40);
   
    while(!array_stack->empty())
    {
     tmp = array_stack->pop();
     cout<<"tmp="<<tmp<<endl;
 }
	
		//链表栈
	cout<<endl<<endl;
	cout<<"链栈的实现"<<endl;
	cout<<"***********************************************************"<<endl;
   string tmps;
   LinkStack<string> *link_stack = new LinkStack<string>;
 
   cout<<"main"<<endl;
 
  //将"cat"、"dog"、"pig"依次推入栈中
    link_stack->push("cat");
    link_stack->push("dog");
	link_stack->push("pig");
   
    // 将“栈顶元素”赋值给tmp，并删除“栈顶元素”
    tmps = link_stack->pop();
    cout<<"tmps="<<tmps<<endl;
   
    // 只将“栈顶”赋值给tmp，不删除该元素
    tmps =link_stack->top();
    cout<<"tmps="<<tmps<<endl;
   
    link_stack->push("duck");
   
    while(!link_stack->empty())
    {
     tmps = link_stack->pop();
     cout<<"tmps="<<tmps<<endl;
 }

	//链表实现
	cout<<endl<<endl;
	cout<<"链表实现"<<endl;
	cout<<"*************************************************************"<<endl;
	 List l;
	l.push_front(5);
    l.push_front(4);
    l.push_front(7);
    l.push_front(6);
    l.push_behand(45);
    l.push_behand(48);
    l.insert(100,0);//小于0位置就插入到最前
    l.insert(99,6);//插入到指定位置
    l.insert(991,100);//大于最后位置就插入到最后
    l.remove(1);
    l.remove(0);
    l.travel();


	//队列实现
    cout<<endl<<endl;
	cout<<"队列实现"<<endl;
     cout<<"**********************************************************"<<endl;
    CommQueue queue;
    init_queue(&queue);
    int ret;
    int a[10] = {0, 1,2,3,4,5,6,7,8,9};
    ret = writeQueue(a, 10, &queue);

    if (ret <= 0)
    {
		cout<<"队列已经满了！"<<endl;
		//printf("the queue is full/n");
        return -1;
    }
    int buf[20] = {0};
    ret = readQueue(buf, 5, &queue);
    if (ret > 0)
    {
		for(int i=0;i<5;i++)
			cout<<buf[i]<<" ";
		cout<<endl;
   
    }
    ret = readQueue(buf, 5, &queue);
    if (ret > 0)
    {
		for(int i=0;i<5;i++)
			cout<<buf[i]<<" ";
		cout<<endl;
;
    }

    ret = writeQueue(a, 10, &queue);
        for(int i=0;i<10;i++)
			cout<<a[i]<<" ";
		cout<<endl;
		//二叉树实现
	cout<<endl<<endl;
	cout<<"二叉树实现"<<endl;
	cout<<"********************************************************"<<endl;
	BinaryTree<char> myBinTree('a');
	myBinTree.InsertLeftChild(myBinTree.GetRoot(),'D');
	myBinTree.InsertRightChild(myBinTree.GetRoot(),'G');
	myBinTree.InsertLeftChild(myBinTree.GetRoot(),'B');
	myBinTree.InsertRightChild(myBinTree.GetRoot()->GetLeftChild(),'E');
	myBinTree.InsertRightChild(myBinTree.GetRoot(),'C');
	myBinTree.InsertLeftChild(myBinTree.GetRoot()->GetRightChild(),'F');
	cout<<"该二叉树是否为空?:"<<myBinTree.IsEmpty()<<endl;
	cout<<"该二叉树的根结点中存储的数据是："<<myBinTree.Retrieve(myBinTree.GetRoot());
    cout<<endl<<"将二叉树的根节点中的数据赋值为A!"<<endl;
	myBinTree.Assign(myBinTree.GetRoot(),'A');
	cout<<"当前二叉树的根节点中存储的数据是："<<myBinTree.Retrieve(myBinTree.GetRoot())<<endl;
	cout<<"层次遍历如下"<<endl;
	myBinTree.LevelOrderTraverse(myBinTree.GetRoot());
	cout<<endl<<endl;
	return 0;
}
