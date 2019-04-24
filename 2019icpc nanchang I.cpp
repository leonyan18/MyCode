#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1000005;
int a[maxn];
int sum[maxn];
int maxv=0;
int minv=INF;
int sta[maxn];
int lmin[maxn];
int rmin[maxn];
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	int n;
	cin>>n;
	rep(i,1,n+1){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	int tempmin=INF;
	int l=1,r=0;
	rep(i,1,n+1){
		int lpos=i;
		while(r>=l&&a[sta[r]]>a[i]){
			lpos=sta[r];
			len--;
		}
		sta[len++]=i;
		lmin[i]=lpos;
	}
	len=0;
}



