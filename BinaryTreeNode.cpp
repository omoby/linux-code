
#include<iostream>
using namespace std;
template <class Type>
class BinaryTreeNode
{
	Type m_data;//储存该节点的数据
	BinaryTreeNode<Type> *m_leftChild;//储存结点的左孩子指针
	BinaryTreeNode<Type> *m_rightChild;//储存结点的右孩子指针
public:
	BinaryTreeNode(){
		m_leftChild=m_rightChild=NULL;
	}
	BinaryTreeNode(const Type &data,BinaryTreeNode *leftChild=NULL,BinaryTreeNode *rightChild=NULL)
	{
		m_data=data;
		m_leftChild=leftChild;
		m_rightChild=rightChild;
	};
	Type & GetData(){//返回该节点数据
		return m_data;
	}
     //返回该节点的左孩子数据
	BinaryTreeNode<Type>* GetLeftChild(){//
		return m_leftChild;
	}
	//返回该结点的右孩子数据
    BinaryTreeNode<Type>* GetRightChild(){
		return m_rightChild;
	}
	//设置该节点的数据
	void SetData(const Type & data){
		m_data=data;
	}
	//设置该节点的左孩子指针域
	void SetLeftChild(BinaryTreeNode<Type>* leftChild){
		m_leftChild=leftChild;
	}
	//设置该节点右孩子的指针域
	void SetRightChild(BinaryTreeNode<Type>* rightChild){
		m_rightChild=rightChild;
	}

};
