//Code Binary Trees (full)
#pragma warning (disable : 4996);
#include <iostream>
using namespace std;
typedef int ElementType;

struct Node{
    ElementType data;
    Node *left; // node d? tr? c�y con b�n tr�i
    Node *right; // node d? tr? c�y con b�n ph?i
	int iDepth;
};

typedef struct Node* Tree; // c�i c�y ki?u Node*;
const Tree emptyTree = 0;
void EmptyTree(Tree &t)
{
	t = NULL; // Tro g?c c�y d?n NULL kh�ng ch?a Node n�o c?.
}
int IsEmpty(Tree t)
{
    return t==NULL; // cho c�y tr? d?n null.
}
void Addx(Tree &t, int x, int dem) // ham th�m ph?n t? x v�o c�y.
{
    
	if(t==NULL) // d?u ti�n gi? s? c�y r?ng
	{
	
		Node* p = new Node; // Kh?i t?o bi?n tham chi?u p. m?t c�y m?t nut p sau d� cho tham chi?u d?n t.
		p->data = x;
		p->left = NULL;
		p->right = NULL;
		p->iDepth = dem;
		t=p; // node p ch�nh l� node g?c. x ch�nh l� nh?n node g?c
		// vung nho cua p luc n�y d� b? h?y.
	}
	else
	{
	   dem++;
       if(x<t->data) Addx(t->left, x, dem); // g?i d? quy sang tr�i d? t�m v? tr� th�ch h?p d? th�m
       else if(x>t->data) Addx(t->right, x, dem); // tuong t? l?n sang b�n ph?i.
	}
}
void themang(Tree &t, Tree &p)
{

	if(t->right!=NULL) themang(t->right, p); // de quy tim phan tu phai nhat.
	else
	{
		p->data = t->data;
		t=t->left;
		p=t;

	}
}
void Delete(Tree &t, int x)
{
	if(t==NULL) return;
	// xoa node chi mot con hoc khong co con nao ca.
	if(x<t->data) Delete(t->left, x); // �? quy sang tr�i d? t�m x.
	else if(x>t->data) Delete(t->right, x); // d? quy sang ph?i d? t�m x.
	else // khi d� t�m th?y x( d� kh�ng c�n d? quy n?a.)
	{
		Node* p = t; // dung con tro p giu chan node can xoa lai.
		if(t->left==NULL)
		{
			t=t->right; // Chi c?n cho n� tr? d?n NULL l� xem nhu d� x�a.
		
		}
		else if(t->right==NULL)
		{
			t=t->left; // neu co mot con trai.
		   
		}
		else themang(t->left, p); // truong hop co hai con.
		delete p;

	}
}
void Input(Tree &t)
{
	int n;
	cout<<"Nhap vao so node: ";
	cin>>n;
	int x;
	for(int i = 0; i < n; i++)
	{
		int dem = 0;
        cin>>x;
        Addx(t, x, dem);
	}
}
void NLR(Tree t) // ki thu?t duy?t tuong t? ti?n t?
{
	if(t!=NULL)
	{
	    cout<<t->data<<" ";
	    NLR(t->left);
	    NLR(t->right);
	}
}void LNR(Tree t)
{
	if(t!=NULL)
	{
		cout<<"\n"<<t->data<<" "<<&t->data<<" "<<t->iDepth;
	    LNR(t->left);
	   
	    LNR(t->right);
	}
}
int demam(Tree t) // dem so luong phan tu am trong c�y.
{
	if(t==NULL)
		return 0;
	int left = demam(t->left);
	int right = demam(t->right);
	if(t->data<0)
		return (1 + left +right); // return cho c�y con.
	return (left + right); // return cho c? c�y c�y l?n.
}
int demduong(Tree t) // d�m s? ph?n t? duong.
{
	if(t==NULL) return 0;
	int left = demduong(t->left);
	int right = demduong(t->right);
	if(t->data>0)
		return(1+left+right);
	return(left+right);
}
int tongduong(Tree t) // t�nh t?ng duong trong c�y.
{
	// �?u ti�n xem c�y ch? c� m?t nut. vi?t b�nh thu?ng. sau d� d? n� t? d? quy
	if(t==NULL)
		return 0;
	// hai d�ng n�y vi?t sau.
	int left = tongduong(t->left);
	int right = tongduong(t->right);
	// �?u ti�n vi?t 2 dong nay tru?c.
	if(t->data>0) // n?u ph?n t? duong. ban d�u gi? su tr�i ph?i d?u l� null return 0 h?t.
		return(t->data+left+right); // return t?ng tr�i t?ng ph?i tr�n c�y v?i noot root.
	return left + right;
}
int kiemtra(Tree t)
{
	if(t==NULL) return 0;
	if(kiemtra(t->left)==1) return 1;
	if(kiemtra(t->right)==1) return 1;
	// ban dau viet cho cay co mot nut. ban dau la viet 2 dong duoi truoc khi viet 2 dong tren.
	if(t->data==0) return 1; // neu co phan tu 0 thi return 1 dung.
	return 0; // nguoc lai return 0 sai. sau do minh moi len tren cho no re ve 2 nha.
}
void InChan(Tree t)
{
	if(t==NULL) return;
	if(t->data%2==0)
	{ 
		cout<<t->data<<" ";
	}
	InChan(t->left);
	InChan(t->right);
}
void InDuong(Tree t)
{
	if(t==NULL) return;
	
	InDuong(t->left);
	if(t->data>0) cout<<"\n"<<t->data<<" "<<&t->data;
	InDuong(t->right);
	
}
void InTangK(Tree t, int k)
{
    if(t==NULL) return;
    InTangK(t->left, k);
    if(t->iDepth==k) cout<<" "<<t->data;
    InTangK(t->right, k);
}
int ChieuDaiCay(Tree t)
{
	if(t==NULL) return 0;

	int a = ChieuDaiCay(t->left); // Kh�ng bi?t gi?i th�ch sao gi�nh th?i gian nghi�n c?u th�i.
	int b = ChieuDaiCay(t->right);
	if(a>b) return a+1; // ? d�y cung z gi�nh th?i gian nghi�n c?u th�i.
	return b+1; 

}
void InTungTang(Tree t, int h)
{
	for(int i  = 0; i < h; i++)
	{
		cout<<"Phan tu thang thu "<<i+1;
		cout<<endl;
		InTangK(t, i);
		cout<<endl;
		
	}
}
void Max(Tree t)
{

}
int kythuatdem(Tree t)
{
	if(t==NULL) return 0;

	int left = kythuatdem(t->left);
	int right = kythuatdem(t->right);
	if((t->left==NULL&&t->right!=NULL)||(t->left!=NULL&&t->right==NULL))
	 return left+right+1;
	return left+right;
}
int kythuatdem2(Tree t, int k)
{
	if(t==NULL) return 0;

	int left = kythuatdem2(t->left, k);
	int right = kythuatdem2(t->right, k);
	if(t->iDepth+1==k)
	 return left+right+1;
	return left+right;
}
int Dem(Tree c, int k)
{
    if (c!=NULL)
    {
        k--;
        int a = Dem(c->left,k);
        int b = Dem(c->right,k);
        if (k==0)
            return 1 + a + b;
        return a + b;
    }
    return 0;
}
int main()
{
freopen("in.txt", "r", stdin);
freopen("out.txt", "w", stdout);

    Tree t;
	EmptyTree(t); // khoi tao cay rong.
	Input(t);
	NLR(t);
	cout<<"\nso luong phan tu am: "<<demam(t);
	cout<<"\nSo luong phan tu duong: "<<demduong(t);
	cout<<"\nTong so duong trong cay: "<<tongduong(t);
	if(kiemtra(t)) cout<<"\nCo phan tu 0 trong cay";
	else cout<<"\nKhong co phan tu 0 trong cay";
	//Delete(t, -3);
	cout<<"\nDanh sach pt chan";
	InChan(t);
	cout<<"\nDanh sach pt duong";
	InDuong(t);
	int k = 3;
	cout<<"\nSo phan tu tang thu "<<k<<" la: ";
	InTangK(t, k);
	//NLR(t);
    cout<<"\nChieu Dai cay: "<<ChieuDaiCay(t);
	cout<<"ke qua in tung tang\n";
	InTungTang(t, ChieuDaiCay(t));
	cout<<"\nSo luong phan tu cua cay la: "<<kythuatdem(t);
	cout<<"\nSo luong phan tu cua cay la: "<<kythuatdem2(t, 5);
	cout<<"\nSo luong nut tren trang 4 la: "<<Dem(t, 4);
	system("pause");
	return 0;
} 
//
////   
//#include<stdio.h>
//#include<conio.h>
//#include<ctime>
//int Min(int A[], int n)
//{
//	if (n == 0)
//		return -1;
//	if (n == 1)
//		return A[0];
//	else
//	{
//		if (A[n - 1] < Min(A, n - 1))
//			return A[n - 1];
//		else
//			return Min(A, n - 1);
//	}
//}
//
//int Max(int A[], int n)
//{
//	if (n == 0)
//		return -1;
//	if (n == 1)
//		return A[0];
//	else
//	{
//		if (A[n - 1] > Max(A, n - 1))
//			return A[n - 1];
//		else
//			return Max(A, n - 1);
//	}
//}
//int min(int a[], int n)
//{
//	int m = a[0];
//	for(int i = 0; i < n;i++)
//		if(m>a[i]) m = a[i];
//return m;
//}
//int main()
//{
//	unsigned int n;
//	int A[10] = { 4, 6, 3, 56, 45, 7, 8, 9, 22, 20};
//	float start = clock();
//	for(int i = 0; i < 100000; i++)
//		//Min(A, 10);
//			Min(A, 10);
//	float end = clock();
//
//	printf("Gia Tri Nho Nhat Cua Mang: %f\n", (end-start)/CLOCKS_PER_SEC);
//	//printf("Gia Tri Lon Nhat Cua Mang: %d\n", Max(A, 10));
//	getch();
//	return 0;
//}
