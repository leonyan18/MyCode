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
		rep(i,1,n+1) pre[i]=i;
		rep(i,0,m){
			int l,r;
			cin>>l>>r;
			pre[r]=min(pre[r],l);
		}
		per(i,1,n){
			pre[i]=min(pre[i],pre[i+1]);
		}
		set<int> v;
		v.clear();
		int pos=1;
		rep(i,1,n){
			v.insert(i);
		}
		rep(i,1,n+1){
			while(pos<pre[i]){
				v.insert(ans[pos]);
				pos++;
			}
			ans[i]=*v.begin();
			v.erase(ans[i]);
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




