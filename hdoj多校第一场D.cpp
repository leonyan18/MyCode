#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
int ans[100005];
int pre[100005];
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
		int n,m;
		clr(ans);
		cin>>n>>m;
		rep(i,1,n+1) pre[i]=i;//初始化左边的端点 
		rep(i,0,m){
			int l,r;
			cin>>l>>r;
			pre[r]=min(pre[r],l); 
		}
		per(i,1,n){
			pre[i]=min(pre[i],pre[i+1]);//倒着更新左边的端点 
		}
		set<int> v;
		v.clear();
		int pos=1;//下标 
		rep(i,1,n){
			v.insert(i);//初始化set里面的数字 
		}
		rep(i,1,n+1){
			while(pos<pre[i]){//pos小于左边的区间说明前面的数字要加回set里 
				v.insert(ans[pos]);
				pos++;
			}
			ans[i]=*v.begin();//等于set里最小的 
			v.erase(ans[i]);//擦去这个数 
		}
		rep(i,1,n+1){
			cout<<ans[i];
			if(i!=n){
				cout<<" ";
			} 
		}
		cout<<endl;
	} 
}




