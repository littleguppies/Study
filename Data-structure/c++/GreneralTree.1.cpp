#include<iostream>
using namespace std;
struct Node
{
	int data; // chua data nhan node.
	Node* Leftmost_Child; // Node nay d? tr? v? con tr�i nh?t.
	Node* Right_Sibling; // Node n�y d? tr? v? anh em ru?t ph?i g?n nh?t/
	Node* Parent;
};
typedef Node* Tree;
Tree Create(int v, Tree lmc, Tree rsl)
{
	Tree n = new Node; // Tao V�ng nh? cho node n;
	n->data = v; // g�n nh�n v cho nude n;
	n->Leftmost_Child = lmc;
	n->Right_Sibling = rsl;
	return n;
}
void Input(Tree &t)
{ 
	Tree t10 = Create(0, NULL, NULL);
	Tree t1 = Create(3, t10, NULL);
	Tree t2 = Create(5, NULL, t1);
	Tree t3 = Create(6, NULL, t2);


	Tree t6 = Create(9, NULL, NULL);
	Tree t5 = Create(8, NULL, t6);
	Tree t4 = Create(7, t5, t3);


	Tree t11 = Create(2, NULL, NULL);
    Tree t9 = Create(4, t4, NULL);
    //Tree t12 = Create(12, NULL, NULL);
    //Tree t13 = Create(13, NULL, NULL);
    //Tree t14 = Create(14, t12, t13);

	//Tree t15 = Create(1,t9, t11);
	t =Create(1, t9, t11);
	

}
void NLR(Tree t) // Xem nhu d�y l� ki?u duy?t ti?n t? c?a c�y.
{
	if(t!=NULL)
	{
		cout<<t->data<<" ";
		NLR(t->Leftmost_Child);
		NLR(t->Right_Sibling);
	}
}
void LNR(Tree t) // Xem nhu ki?u duy?t trung t? trong gi�o tr�nh.
{
	if(t!=NULL) // Xem nhu di?u ki?n d?ng c?a d? quy.
	{
		LNR(t->Leftmost_Child);
		cout<<t->data<<" ";
		NLR(t->Right_Sibling);
	}
}
void LRN(Tree t) // Duy?t h?u t?
{
	if(t!=NULL) // Xem nhu di?u ki?n d?ng c?a d? quy.
	{
		LNR(t->Leftmost_Child);
		NLR(t->Right_Sibling);
		cout<<t->data<<" ";
	}
}
bool Leaf(Tree p)
{
	if(p->Leftmost_Child == NULL)	
	return true;
	else return false;
}
void DeleteTree(Tree &t, int x)
{
	if(t!=NULL)
	{
		if(x==t->data)
		{
			if(Leaf(t))
			{
				if(t->Right_Sibling!=NULL)
				{
					Tree temp = t->Right_Sibling; // T?o c�y gi? anh em ru?t ph?i node c?n x�a
					*t = *temp; // G�n gi� tr? c?a anh em ru?t ph?i node c?n x�a sao d� x�a node anh em ru?t ph?i.
					t->Right_Sibling = temp->Right_Sibling; // tr? v�ng qua node anh em ru?t ph?i.
					delete(temp);
					temp = NULL;
				}
				else{

					delete(t); // Xoa c�y d� v� sau d� cho n� tr? v? NULL;
					t=NULL;
					return ; // return d? n� kh?i chay n?a m?t em n� nhe c�c b?n
				}
			
			}
			// X�a node ch? c� m?t con.
			else if(!Leaf(t) && t->Right_Sibling == NULL)
			{
				t=t->Leftmost_Child; // C?p nh?t th?ng con tr�i b?ng ph?n t? mu?n x�a. xong x�a th?ng con tr�i di
				delete(t->Leftmost_Child);
				t->Leftmost_Child = NULL;
			}
			
		}
		DeleteTree(t->Leftmost_Child, x);
	    DeleteTree(t->Right_Sibling, x);
	}
	
}
void AddNode(Tree &t, int x)
{
	if(t==NULL)
	{
		Create(x, NULL, NULL);
	}
	else
	{

	}
}
int main()
{
	Tree t;
	int x;
	Input(t);
	cout<<"Duyet Tien tu: ";NLR(t);cout<<endl;
	cout<<"Duyet Trung tu: ";LNR(t);cout<<endl;
	cout<<"Duyet Hau tu: "; LRN(t);cout<<endl;
	cout<<"Nhap vao node muon xoa: ";
	cin>>x;
	DeleteTree(t, x);
	cout<<"Duyet Tien tu sau khi xoa : ";NLR(t);cout<<endl;
	/*Tree c = Create(0, NULL, NULL);
	if(Leaf(c)) cout<<"Node la";*/
	system("pause");
	return 0;
}




