/**
*1-n的最大流 
*/
#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=INT_MAX;
const int maxn=15+1;
int a[maxn][maxn];
int flow[maxn];
int pre[maxn];
int n;
queue<int> q;
int bfs(){
	rep(i,1,n+1){
		pre[i]=-1;
	}
	while (!q.empty()) {
        q.pop();
    }
	flow[1]=INF;
	pre[1] = 0;
	q.push(1);
	while(!q.empty()){
		int index=q.front();
		q.pop();
		if(index==n){
			break;
		}
		rep(i,1,n+1){
			if(i!=index&&a[index][i]>0&&pre[i]==-1){
				pre[i]=index;
				flow[i]=min(a[index][i],flow[index]);
				q.push(i);
			}
		}
	}
//	rep(i,1,n+1){
//        	cout<<flow[i]<<" ";
//        }
//    cout<<endl;
	if(pre[n]==-1){
		return -1;
	}else{
		return flow[n];
	}
}
int maxFlow(){
	int sum=0;
	int aug=0;
	while((aug = bfs()) != -1){
		int k=n;
		while(k!=1){
			int index=pre[k];
			a[k][index]+=aug;
			a[index][k]-=aug;
			k=index;
		}
		sum+=aug;
	}
	return sum;
} 
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//11835//Desktop//in.txt","r",stdin);
	#endif
	int t,tt;
	cin>>t;
	tt=t;
	while(t--){
		clr(a);
		clr(flow);
		cout<<"Case "<<tt-t<<": ";
		int m;
		scanf("%d%d", &n, &m);
		rep(i,0,m){
			int x,y,c;
			scanf("%d%d%d", &x, &y, &c);
			if(x==y)
				continue;
			a[x][y]+=c;
		}
		int ans=maxFlow();
		cout<<ans<<endl;
	}
}



