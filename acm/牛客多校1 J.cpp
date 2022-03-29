
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
	    for(int i=1;i<=N;i++) scanf("%d",&A[i]);//A原数组 
	 	for(int i=1;i<=N;i++) A[N+i]=A[i];//A原数组 
	 	N=N*2;
	    for(int i=N;i>=1;i--)
	    {
	        if(!show[A[i]])//show没出现过 
	        {
	            show[A[i]] = i;
	            fir[i] = true;//当前位置的数是第一次出现 
	        }
	        else
	        {//show出现过 
	            Next[i] = show[A[i]];//记录他下一次出现的位置 
	            fir[Next[i]] = false;//下一个位置不是第一次出现 
	            fir[i] = true;//这个位置是第一次出现
	            show[A[i]] = i;//记录出现位置
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
	        if(fir[i])//如果这个数是第一次出现 
	        {
	            modify(i,1);//初始化
	        }
//	    int qtemp = q[1].l;//当前位置 
	    int ptr = 1;//下标位置 
	    for(int i=1;i<=M;i++)
	    {
	        for(;ptr<q[i].l;ptr++)
	        {
	            if(fir[ptr])//如果第一次出现 
	            {
	                modify(ptr,-1); 
//	                fir[ptr] = false;//下标在l之前不在区间内 
	                if(Next[ptr])//如果后面还有重复 
	                {
	                    fir[Next[ptr]] = true;//下一个是第一次出现 
	                    modify(Next[ptr],1);//这个位置的前一个位置次数
	                }
	            }
	        }
//	        ptr = q[i].l;
//	        qtemp = q[i].l;
	        res[q[i].pos] = sum(q[i].r) - sum(q[i].l-1);//之间1的个数就是区间内第一次出现的个数 
	    }
	    for(int i=1;i<=M;i++) printf("%d\n",res[i]);
	}
    return 0;
}
