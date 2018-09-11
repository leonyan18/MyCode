/*
一个点在1 一点在n 两个人去中间的某一点时间最少 
*/
#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1e5+5;
struct node{
	int pos;
	int w;
	node(){		
	}
	node(int pos,int w):pos(pos),w(w){	
	}
	bool operator < (const node & a) const
    {
        return w>a.w;
    }
};
bool cmp(node a,node b){
	if(a.pos==b.pos)
	return a.w<b.w;
	return a.pos<b.pos;
}
ll dis1[maxn*2];
ll disn[maxn*2];
vector<node> pmap[maxn*2];
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//11835//Desktop//in.txt","r",stdin);
//    freopen("C://Users//11835//Desktop//out.txt","w",stdout);
	#endif
	int t;
	scanf("%d",&t);
	int tt=t;
	while(t--){
		cout<<"Case #"<<tt-t<<": ";
		int n,m;
		memset(dis1,0x3f,sizeof(dis1));
		memset(disn,0x3f,sizeof(disn));
		scanf("%d%d",&n,&m);
		rep(i,0,m){
			int time,num;
			int a[maxn];
			scanf("%d%d",&time,&num);
			rep(j,0,num){
				cin>>a[j];
			}
			rep(j,0,num){
				pmap[i+n+1].push_back(node(a[j],time));
				pmap[a[j]].push_back(node(i+n+1,time));
			}
		}
		dis1[1]=0;
		priority_queue <node> q;
		q.push(node(1,0));
		while(!q.empty()){
			node temp=q.top();
			q.pop();
			rep(i,0,pmap[temp.pos].size()){
				int next=pmap[temp.pos][i].pos;
				if(pmap[temp.pos][i].w+temp.w<dis1[next]){
					dis1[next]=pmap[temp.pos][i].w+temp.w;
					q.push(node(next,dis1[next]));
				}
					
			}
		}
		disn[n]=0;
		q.push(node(n,0));
		while(!q.empty()){
			node temp=q.top();
			q.pop();
			rep(i,0,pmap[temp.pos].size()){
				int next=pmap[temp.pos][i].pos;
				if(pmap[temp.pos][i].w+temp.w<disn[next]){
					disn[next]=pmap[temp.pos][i].w+temp.w;
					q.push(node(next,disn[next]));
				}
					
			}
		}
		ll ans=dis1[0];
		rep(i,1,n+1){
			ans=min(ans,max(dis1[i],disn[i]));
		}
		if(ans!=dis1[0]){
			cout<<ans/2<<endl;
			int flag=0;
			rep(i,1,n+1){
				if(ans==max(dis1[i],disn[i])){
					if(flag==1)cout<<" ";
					cout<<i;
					flag=1;
				}
			}
			cout<<endl;
		}		
		else
		cout<<"Evil John"<<endl;
		rep(i,0,n+m+1){
			pmap[i].clear();
		}
	}
}
