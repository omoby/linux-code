 
#include <iostream>  
using namespace std;  
typedef int T;  
class List  
{  
    struct Node  
    {  
        T data;  
        Node * next;  
        Node(const T&d=T()):data(d),next(0){}  
    };  
    Node * head;  
    public:  
        List():head(NULL)  
        {  
           // cout<<"…list初始化完成…\n";  
        }  
        void push_front(const T&d)//前插法  
            {  
                Node * p=new Node(d);  
                p->next=head;  
                head=p;  
            }  
        void push_behand(const T&d)//尾插法  
            {  
                Node *ph=head;  
                while(ph->next!=NULL) ph=ph->next;  
                Node * p=new Node(d);  
                ph->next=p;  
            }  
        void insert(const T&d,int pos)//任意位置插入  
            {  
                Node * p=new Node(d);  
                Node *& pn=getptr(pos);  
                p->next=pn;  
                pn=p;  
                /* 
                if(pos<=0) 
                { 
                    p->next=head; 
                    head=p; 
                } 
                else 
                { 
                    Node * ph=head; 
                    while(pos-->1 && ph->next !=NULL) 
                    { 
                        ph=ph->next; 
                    } 
                    p->next=ph->next; 
                    ph->next=p; 
                     
                } 
                */  
            }  
        void remove(int pos)  
        {  
            if(pos<0) return ;  
            Node *& pn=getptr(pos);  
            Node *p=pn;  
            pn=pn->next;  
            delete p;  
        }  
        Node *& getptr(int pos)  
        {  
              
            if(pos<=0) return head;  
            Node * p =head;  
            while(pos-->1 && p->next !=NULL)  
                p=p->next;  
            return (*p).next;   
        }  
        void travel()const//遍历  
        {  
            Node * p=head;  
            while(p!=NULL)  
            {  
                cout<<p->data<<' ';  
                p=p->next;  
            }  
            cout<<endl;  
        }  
        void clear()//清空内存  
        {  
            while(head != NULL)  
            {  
                Node *p=head->next;  
                delete head;  
                head=p;  
            }  
        }  
        ~List()  
        {  
            clear();  
            //cout<<"…内存释放完成…\n";  
        }  
};
