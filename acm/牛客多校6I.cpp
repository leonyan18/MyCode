#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int mod=998244353;
//(0)定义
const int MAXN=200010;
struct node{
	int l,r;
	int id;
	bool operator<(const node &A)const{
		if(l==A.l) return r<A.r;
		return l<A.l;
	}
};
node a[MAXN];
int ans[MAXN<<2];
int b[MAXN];
int p[MAXN];
int n,m;
int res,num;
//a[]为原序列信息，ans[]模拟线段树维护最大的右端点 b[]为第几次被破坏 p[]l的有序序列方便二分查找 
//(1)更新结点信息
void PushUp(int rt)
{
    ans[rt]=max(ans[rt<<1],ans[rt<<1|1]);
}
//(2)建树
void Build(int l,int r,int rt)
{
	ans[rt]=0;
    if (l==r)
    {
        ans[rt]=a[l].r;
        return;
    }
    int mid=(l+r)>>1;
    Build(l,mid,rt<<1);
    Build(mid+1,r,rt<<1|1);
    PushUp(rt);
}
//(5)区间更新
void Update(int L,int R,int x,int index,int l,int r,int rt)
{
	if(ans[rt]<x) return;//如果x在最大的右端点右边return 
	if(L>R || l>r) return; 
    if (l==r)
    {
    	ans[rt]=-INF;//该点的右端点设为无穷小 
        b[a[l].id]=index;//记录第几次被破坏 
        num++;//个数增加 
        res=res*a[l].id%mod;//累乘 
        return;
    }
    int mid=(l+r)>>1;
    if (L<=mid) Update(L,R,x,index,l,mid,rt<<1);
    if (R>mid) Update(L,R,x,index,mid+1,r,rt<<1|1);
    PushUp(rt);
}
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	int t;
	cin>>t;
	rep(ca,1,t+1) {
		clr(b);
		clr(ans);
		clr(p);
		clr(a);
		printf("Case #%d:\n",ca);
		cin>>n>>m;
		rep(i,1,n+1){
			cin>>a[i].l>>a[i].r;
			a[i].id=i;
			p[i]=a[i].l;
		}
		sort(a+1,a+n+1);
		sort(p+1,p+n+1);
		Build(1,n,1);
		rep(i,1,m+1){
			int x;
			cin>>x;
			x^=res;
			int pos=upper_bound(p+1,p+n+1,x)-p-1;//找出l小于等于x的区间 
			res=1;num=0;//初始化res和num 
			Update(1,pos,x,i,1,n,1);//更新 
			printf("%d\n",num);
			if(num==0) res=0;
		}
		rep(i,1,n+1) printf("%d%c",b[i],i==n?'\n':' ');
	}
}


