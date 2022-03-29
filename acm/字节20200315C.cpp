#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1000005;
int cost[300][300];
int mmap[300][300];
int dir[4][2]={1,0,0,1,-1,0,0,-1};
struct node{
	int x,y;
};
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	int n,m;
	node start,end;
	map<int,pair<node,node>> mymap;
	set<int> myset;
	cin>>n>>m;
	rep(i,0,m){
		rep(j,0,n){
			cost[i][j]=2000000;
			cin>>mmap[i][j];
			int v=mmap[i][j];
			if(mmap[i][j]==-2){
				start.x=i;
				start.y=j;
			}
			if(mmap[i][j]==-3){
				end.x=i;
				end.y=j;
			}
			if(mmap[i][j]>0){
				node temp;
				temp.x=i;
				temp.y=j;
				if(myset.find(mmap[i][j])==myset.end()){
					pair<node,node> p;
					p.first=temp;
					mymap[v]=p;
				}else{
					mymap[v].second=temp;
				}
				myset.insert(mmap[i][j]);
			}
		}
	}
	queue<node> q;
	q.push(start);
	cost[start.x][start.y]=0;
	while(!q.empty()){
		node t=q.front();
		q.pop();
		rep(i,0,4){
			node temp;
			int nextx=dir[i][0]+t.x;
			int nexty=dir[i][1]+t.y;
			if(mmap[nextx][nexty]==-1){
				continue;
			}
			if(nextx>=0&&nextx<m&&nexty>=0&&nexty<n&&cost[nextx][nexty]>cost[t.x][t.y]+1){
				temp.x=nextx;
				temp.y=nexty;
				cost[nextx][nexty]=cost[t.x][t.y]+1;
				q.push(temp);
			}
		}
		if(mmap[t.x][t.y]>0){
			node temp;
			pair<node,node> tempair=mymap[mmap[t.x][t.y]];
			int nextx=tempair.first.x;
			int nexty=tempair.first.y;
			if(cost[nextx][nexty]>cost[t.x][t.y]+1){
				temp.x=nextx;
				temp.y=nexty;
				cost[nextx][nexty]=cost[t.x][t.y]+1;
				q.push(temp);
			}
			nextx=tempair.second.x;
			nexty=tempair.second.y;
			if(cost[nextx][nexty]>cost[t.x][t.y]+1){
				temp.x=nextx;
				temp.y=nexty;
				cost[nextx][nexty]=cost[t.x][t.y]+1;
				q.push(temp);
			}
		}
	}
//	rep(i,0,m){
//		rep(j,0,n)
//		cout<<" "<<cost[i][j];
//		cout<<endl;
//	}
	if(cost[end.x][end.y]==2000000){
		cout<<-1<<endl;
		return 0;
	}
	cout<<cost[end.x][end.y]<<endl; 
	
}



