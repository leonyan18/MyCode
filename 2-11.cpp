#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1e5+5;
int num[maxn];
struct node{
	int value;
	node *next;
};
node *numl[maxn];
void ArrayMerge(int c[],int d[],int l,int m,int r)//合并c[l:m]和c[m+1:r]到d[l:r]并合并回来 
{
	int i=l,j=m+1,k=l;
	while((i<=m)&&(j<=r))
	{
		if(c[i]<=c[j])
			d[l++]=c[i++];
		else
			d[l++]=c[j++];
	}
	if(i>m)					
		rep(q,j,r+1)
			d[l++]=c[q];
	else
		rep(p,i,m+1)       
			d[l++]=c[p];
	rep(i,k,r+1){
		c[i]=d[i];
	}
}
void ArrayMergeSort(int a[],int n)
{
	while(1){
		int *b=new int[n];
		int len=1;
		num[0]=0;
		rep(i,1,n){
			if(a[i-1]>a[i])
				num[len++]=i-1;
		}
		num[len]=n;
		if(len<=1){
			break;
		} 
		rep(i,0,len-1){
			ArrayMerge(a,b,num[i],num[i+1],num[i+2]);
			i++;
		}
	}
	rep(i,0,n){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
void LinkMerge(node* l,node* m,node* r)
{
	node *k=r;
	node *result=new node;
	node *i=l;
	node *j=m;
	node *temp=result;
	while(i!=m&&j!=k){
		if(i->value>j->value){
			temp->value=j->value;
			temp->next=new node;
			temp=temp->next;
			j=j->next;
		}
		else{
			temp->value=i->value;
			temp->next=new node;
			temp=temp->next;
			i=i->next;
		}
	}
	if(i!=m){
		while(i!=m){
			temp->value=i->value;
			temp->next=new node;
			temp=temp->next;
			temp->next=NULL;
			temp->value=-1*INF;
			i=i->next;
		}
	}
	else{
		while(j!=r){
			temp->value=j->value;
			temp->next=new node;
			temp=temp->next;
			temp->next=NULL;
			temp->value=-1*INF;
			j=j->next;
		}
	}
	l->value=result->value;
	l->next=result->next;
	while(result!=r){
		if(result->next->value==-1*INF){
			result->next=r;
		}
		result=result->next;
	}
}
void LinkMergeSort(node *a)
{
	while(1){
		int len=1;
		numl[0]=a;
		node *last=a;
		while(last->next!=NULL){
			node *nxt=last->next;
			if(last->value>nxt->value)
				numl[len++]=nxt;
			last=last->next;
		}
		numl[len]=last->next;
		if(len<=1){
			break;
		} 
		rep(i,0,len-1){
			LinkMerge(numl[i],numl[i+1],numl[i+2]);
			i++;
		}
	}
}
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//11835//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	int a[]={1,5,9,3,5,7,8,4,2,6,9,6};
	node *head=new node;
	head->value=a[0];
	node *last=head;
	rep(i,1,12){
		node *temp=new node;
		temp->value=a[i];
		last->next=temp;
		last=temp;
	}
	last->next=NULL;
	ArrayMergeSort(a,12);
	LinkMergeSort(head);
	last=head;
	while(last!=NULL){
		cout<<last->value<<" ";
		last=last->next;
	}
	cout<<endl;
}



