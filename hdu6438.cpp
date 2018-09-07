#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
struct cmp{
    template<typename T, typename U>
    bool operator()(T const& a, U const &b) {
        if(a.first == b.first) return a.second < b.second;
    	return a.first > b.first;
    }
};
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//11835//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		priority_queue<pair<int ,bool>,vector<pair<int ,bool> >,cmp> q;
		ll sum=0;
		rep(i,0,n){
			int x;
			cin>>x; 
			q.push(make_pair(x,0));
			if(x>q.top().first){
				sum+=x-q.top().first;
				q.pop();
				q.push(make_pair(x,1));
			}		
		}
		int time=0;
		while(!q.empty()){
			if(q.top().second==1){
				time++;
//				cout<<q.top().first<<" "<<q.top().second<<endl;
			}
				
			q.pop();
		}
		cout<<sum<<" "<<time*2<<endl;
	}
}



