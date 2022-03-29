#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=100005;
struct point {
	int start,end;
	int w;
}a[maxn*4];
struct p{
	int start;
	int w;
	int cos;
};
int pos[maxn*4];
int cost[maxn];
bool cmp(point a,point b){
	if(a.start==b.start)
		return a.end<b.end; 
	return a.start<b.start;
}
bool operator<(const p & x,const p & y)
{
 	if(x.start==y.start) {
 		if(x.w==y.w){
 			return x.cos<y.cos;
		}
 		return x.w<y.w;
	}
    return x.start<y.start;
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
	while(cin>>n>>m){
		set<p> sp;
		clr(pos);
		clr(a);
		rep(i,1,n+1){
			cost[i]=n+1;
		}
		rep(i,0,2*m){
			cin>>a[i].start>>a[i].end>>a[i].w;
			pos[i]=a[i].start;
			a[i+1].start=a[i].end;
			pos[i]=a[i+1].start;
			a[i+1].end=a[i].start;
			a[i+1].w=a[i].w;
			i++;
		}
		sort(a,a+2*m,cmp);
		sort(pos,pos+2*m);
		queue<p> q;
		p temp;
		for(int i=0;a[i].start==1;i++){
			temp.start=a[i].end;
			temp.w=a[i].w;
			temp.cos=1;
			cost[a[i].end]=1;
			q.push(temp);
		}
		while(!q.empty()){
			if(cost[n]<=q.front().cos){
				q.pop();
				continue;
			}
			int pos1=lower_bound(pos,pos+2*m,q.front().start)-pos;
//			cout<<pos1<<endl;
	   		for(int i=pos1;;i++){
	   			if(a[i].start!=q.front().start)
	   				break;
	   			int tempcost=q.front().cos;
	   			if(q.front().w!=a[i].w)
	   				tempcost++;
	   			if(cost[a[i].end]<=tempcost)
	   				continue;
	   			temp.start=a[i].end;
	   			temp.w=a[i].w;
	   			temp.cos=tempcost;
	   			cost[a[i].end]=tempcost;
	   			int len=sp.size();
	   			sp.insert(temp);
	   			if(sp.size()!=len) 
	   			q.push(temp);
	   		}
	   		q.pop();
	   		sp.erase(q.front());
   		}
   		int ans=cost[n]==n+1?-1:cost[n];
   		cout<<ans<<endl;
	}
}


