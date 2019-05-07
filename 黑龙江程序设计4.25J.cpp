#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=300005;
struct node{
	ll x,y;
}a1[maxn],a2[maxn],a3[maxn],a4[maxn];
bool compare1(node a,node b){
	return a.x+a.y<b.x+b.y; 
}
bool compare2(node a,node b){
	return a.x-a.y<b.x-b.y; 
}
bool compare3(node a,node b){
	return -a.x+a.y<-b.x+b.y; 
}
bool compare4(node a,node b){
	return -a.x-a.y<-b.x-b.y; 
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
	while(t--){
		int n;
		cin>>n;
		rep(i,1,n+1){
			cin>>a1[i].y;
			a1[i].y*=a1[i].y;
			a1[i].x=i*i;
			a2[i]=a1[i];
			a3[i]=a1[i];
			a4[i]=a1[i];
		}
		ll ans=max(a1[0])
	} 
}



