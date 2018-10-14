#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1e3+5;
struct node{
	int pos;
	int value;
	node(int pos,int value):pos(pos),value(value){
	}
	bool operator < (const node & a) const
    {
        return value>a.value;
    }
};
bool cmp(int a,int b){
	return a>b;
}
int a[maxn][maxn];
int next[maxn];
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//11835//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	int n,m,k;
	cin>>n>>m>>k;
	clr(next);
	rep(i,0,n){
		rep(j,0,m){
			int value;
			cin>>value;
			a[i][j]=value;
		}
	}
	rep(i,0,n){
		sort(a[i],a[i]+m,cmp);
	}
	priority_queue<node> q;
	rep(i,0,n){
		q.push(node(i,a[i][0]));
	}
	long long sum=0;
	rep(i,0,k){
		node temp=q.top();
		sum+=temp.value;
		cout<<temp.value<<endl;
		int pos=temp.pos;
		q.pop();
		if(next[pos]<m-1)	
		q.push(node(temp.pos,a[temp.pos][++next[pos]]));
	}
	cout<<sum<<endl;
}



