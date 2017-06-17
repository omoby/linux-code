
#include<iostream>
#include<queue>
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
template<class T>
class BinaryTree
{
	BinaryTreeNode<T> *m_root;
public:
	BinaryTree(){
		m_root=NULL;
	};
	BinaryTree(T data)
	{
		m_root=new BinaryTreeNode<T>(data);
	};
	virtual ~BinaryTree(); 
	//判断树是否为空
	bool IsEmpty() const {
		return m_root==NULL?true:false;
	};
	//判断结点是不是左孩子
	bool IsLeftChild(BinaryTreeNode<T> *p)
	{
		return p==GetParent(p)->GetLeftChild()? true:false;
	};
	//判断结点是否是右孩子
	bool IsRightChild(BinaryTreeNode<T> *p)
	{
		return p==GetParent(p)->GetRightChild()? true:false;
	};
	//取得整棵树的树根
	BinaryTreeNode<T>* GetRoot()
	{
		return m_root;
	};
	//取得结点的父亲结点的指针
	BinaryTreeNode<T>* GetParent(BinaryTreeNode<T> *p)
	{
		return Parent(m_root,p);
	};
	//获取结点的左子树的指针
	BinaryTreeNode<T>* LeftChild(BinaryTreeNode<T> *root) const
	{
		return root==NULL ?NULL:root->GetLeftChild();
	};
	//获取结点的右子树的指针
	BinaryTreeNode<T>* RightChild(BinaryTreeNode<T> *root) const
	{
		return root==NULL ? NULL:root->GetRightChild();
	};
	//获取结点左兄弟的指针
	BinaryTreeNode<T>* LeftSibling(BinaryTreeNode<T> *leftChild);
	//获取结点右兄弟的指针
	BinaryTreeNode<T>* RightSibling(BinaryTreeNode<T> *rightChild);
	//返回结点的数据
	T Retrieve(BinaryTreeNode<T> *p) const {
		return p->GetData();
	};
	//设置一个结点的数据
	void Assign(BinaryTreeNode<T> *p,const T&d) const{
		p->SetData(d);
	};
	//插入右孩子到当前结点
	void InsertRightChild(BinaryTreeNode<T> *p,const T &d) const;
	//插入左孩子到当前结点
	void InsertLeftChild(BinaryTreeNode<T> *p,const T &d) const;
	//删除当前结点的右孩子
	void DeleteRightChild(BinaryTreeNode<T> *p){
		Destroy(p->GetRightChild());
	}
	//删除当前结点的左孩子
	void DeleteLeftChild(BinaryTreeNode<T> *p)
	{
		Destroy(p->GetLeftChild());
	}
	//现需顺序遍历整棵树
//	virtual void PreOrderTraverse(BinaryTreeNode<T> *root) const;
	//中序遍历整棵树
//	virtual void InOrderTraverse(BinaryTreeNode<T> *root) const;
	//后序遍历整棵树
//	virtual void PostOrderTraverse(BinaryTreeNode<T> *root) const;
	//按层遍历整棵树
	virtual  void LevelOrderTraverse(BinaryTreeNode<T> *root) const;
protected:
	BinaryTreeNode<T>* Parent(BinaryTreeNode<T> *root,BinaryTreeNode<T> *p);
	void Destroy(BinaryTreeNode<T> *p);

};
template<class T>
BinaryTree<T>::~BinaryTree(void)
{
	Destroy(m_root);
	m_root=NULL;
}
template<class T>
BinaryTreeNode<T>* BinaryTree<T>::RightSibling(BinaryTreeNode<T> *p)
{
	BinaryTreeNode<T> *q;
	q=Parent(m_root,p);
	if((NULL==q)||(p==q->GetRightChild()))
		return NULL;
	else
		return q->GetRightChild();
}
template<class T>
BinaryTreeNode<T>* BinaryTree<T>::LeftSibling(BinaryTreeNode<T> *p)
{
	BinaryTreeNode<T> *q;
	q=Parent(m_root,p);
	if((NULL==q)||(p==q->GetLeftChild()))
		return NULL;
	else
		return q->GetLeftChild();
}
template<class T>
void BinaryTree<T>::InsertLeftChild(BinaryTreeNode<T> *p, const T &d) const
{
	BinaryTreeNode<T> *	q=new BinaryTreeNode<T>(d);
	q->SetLeftChild(p->GetLeftChild());
	p->SetLeftChild(q);
}
template<class T>
void BinaryTree<T>::InsertRightChild(BinaryTreeNode<T> *p, const T &d) const
{
	BinaryTreeNode<T> *	q=new BinaryTreeNode<T>(d);
	q->SetRightChild(p->GetRightChild());
	p->SetRightChild(q);

}
template<class T>
void BinaryTree<T>::Destroy(BinaryTreeNode<T> *p)
{

	if(NULL!=p)
	{
		Destroy(p->GetLeftChild());
		Destroy(p->GetRightChild());
		delete p;
	}
}
template<class T> BinaryTreeNode<T>*
BinaryTree<T>::Parent(BinaryTreeNode<T> *root,BinaryTreeNode<T> *p)
{
	BinaryTreeNode<T> *q;
	if(NULL==root)
		return NULL;
	if((p==root->GetLeftChild())||(p==root->GetRightChild()))
		return root;
	if(NULL!=(q=Parent(root->GetLeftChild(),p)))
		return q;
	else
		return Parent(root->GetRightChild(),p);
}
template<class T>
void BinaryTree<T>::LevelOrderTraverse(BinaryTreeNode<T> *root) const
{
	queue<BinaryTreeNode<T>*>q;
	if(NULL!=root)
		q.push(root);
	while(!q.empty())
			{
				root=q.front();
				q.pop();
				cout<<root->GetData();
				if(root->GetLeftChild())
					q.push(root->GetLeftChild());
				if(root->GetRightChild())
					q.push(root->GetRightChild());

			}
}
