#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1e5+5;
int a[maxn];
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//11835//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	int n,len;
	cin>>n>>len;
	rep(i,0,n){
		cin>>a[i];
	}
	vector<int> q;
	vector<int> ans;
	rep(i,0,len){
		q.push_back(a[i]);
	}
	sort(q.begin(),q.end());
	ans.push_back(q[(len+1)/2-1]);
	int head=0;
	int tail=len;
	rep(i,len,n){
		while(q.size()>=len){
			if(a[head]<q[(q.size()+1)/2-1]){
	        	q.erase(lower_bound(q.begin(),q.end(),a[head]));
	        	head++;
	        }
	        else{
	        	break;
	        }
		}
		q.insert(lower_bound(q.begin(),q.end(),a[i]),a[i]);
		ans.push_back(q[(q.size()+1)/2-1]);
	}
	while(q.size()>len){
		q.erase(lower_bound(q.begin(),q.end(),a[head]));
		head++;
		ans.push_back(q[(q.size()+1)/2-1]);
	}
	sort(ans.begin(),ans.end());
	cout<<ans[ans.size()-1]<<endl;
}



