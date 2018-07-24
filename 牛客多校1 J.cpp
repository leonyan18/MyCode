
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
 
 
using namespace std;
 
 
int N,M;
const int SIZE = 250005;
int c[SIZE];
int A[SIZE];
int Next[SIZE];
int res[200005];
int show[2000005];
bool fir[SIZE];
 
 
struct Q
{
    int l,r;
    int pos;
}q[200005];

int lowbit(int k)
{
    return k&(-k);
}

void modify(int n,int v)
{
    while(n <= N)
    {
        c[n] += v;
        n += lowbit(n);
    }
}
 
 
int sum(int n)
{
    int ans = 0;
    while(n > 0)
    {
        ans += c[n];
        n -= lowbit(n);
    }
    return ans;
}
 
 
int cmp(Q a, Q b)
{
    return a.l < b.l;
}
 
 
int main()
{
    while(~scanf("%d",&N)){
    	memset(res,0,sizeof(res));
    	memset(c,0,sizeof(c));
    	memset(A,0,sizeof(A));
    	memset(Next,0,sizeof(Next));
    	memset(fir,0,sizeof(fir));
    	memset(show,0,sizeof(show));
    	scanf("%d",&M);
	    for(int i=1;i<=N;i++) scanf("%d",&A[i]);//Aԭ���� 
	 	for(int i=1;i<=N;i++) A[N+i]=A[i];//Aԭ���� 
	 	N=N*2;
	    for(int i=N;i>=1;i--)
	    {
	        if(!show[A[i]])//showû���ֹ� 
	        {
	            show[A[i]] = i;
	            fir[i] = true;//��ǰλ�õ����ǵ�һ�γ��� 
	        }
	        else
	        {//show���ֹ� 
	            Next[i] = show[A[i]];//��¼����һ�γ��ֵ�λ�� 
	            fir[Next[i]] = false;//��һ��λ�ò��ǵ�һ�γ��� 
	            fir[i] = true;//���λ���ǵ�һ�γ���
	            show[A[i]] = i;//��¼����λ��
	        }
	    }
	 
	    for(int i=1;i<=M;i++)
	    {
	    	int l,r;
	        scanf("%d%d",&l,&r);
	        q[i].l=r;
	        q[i].r=l+N/2;
//	        cout<<q[i].l<<q[i].r<<endl;
	        q[i].pos = i;
	    }
	    sort(q+1,q+1+M,cmp);
	 
	 
	    for(int i=1;i<=N;i++)
	        if(fir[i])//���������ǵ�һ�γ��� 
	        {
	            modify(i,1);//��ʼ��
	        }
//	    int qtemp = q[1].l;//��ǰλ�� 
	    int ptr = 1;//�±�λ�� 
	    for(int i=1;i<=M;i++)
	    {
	        for(;ptr<q[i].l;ptr++)
	        {
	            if(fir[ptr])//�����һ�γ��� 
	            {
	                modify(ptr,-1); 
//	                fir[ptr] = false;//�±���l֮ǰ���������� 
	                if(Next[ptr])//������滹���ظ� 
	                {
	                    fir[Next[ptr]] = true;//��һ���ǵ�һ�γ��� 
	                    modify(Next[ptr],1);//���λ�õ�ǰһ��λ�ô���
	                }
	            }
	        }
//	        ptr = q[i].l;
//	        qtemp = q[i].l;
	        res[q[i].pos] = sum(q[i].r) - sum(q[i].l-1);//֮��1�ĸ������������ڵ�һ�γ��ֵĸ��� 
	    }
	    for(int i=1;i<=M;i++) printf("%d\n",res[i]);
	}
    return 0;
}
