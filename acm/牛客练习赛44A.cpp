#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=100005;
int a[maxn];
struct node{
	int start;
	int end;
};
node mm[maxn];
bool compare(node a,node b){
	return (a.end-a.start)>(b.end-b.start);
}
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	int n,m;
	cin>>n>>m;
	rep(i,1,n+1){
		cin>>a[i];
		if(mm[a[i]].start==0)
			mm[a[i]].start=i;
		mm[a[i]].end=i;
	}
	rep(i,1,m+1){
		int tempi=i;
		while(mm[tempi].start==0&&tempi<=m){
			tempi++;
		}
		rep(j,i,tempi){
			mm[j].start=mm[tempi].start;
			mm[j].end=mm[tempi].end;
		}
	}
	rep(i,1,m+1){
		cout<<mm[i].start<<" "<<mm[i].end<<endl;	
	}
}



