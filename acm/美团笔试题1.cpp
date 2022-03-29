#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1000005;
int dir[4][2]={1,0,0,1,-1,0,0,-1};
int a[maxn];
int vis[2][maxn];
int sum[2];
struct node //运算符重载<
{
    int x;
    int pos;
    node(int a,int b) {x = a;pos=b;}
    bool operator<(const node& a) const
    {
        return x > a.x; //大顶堆
    }
};
struct node2 //运算符重载<
{
    int x;
    int pos;
    node2(node b) {x = b.x;pos=b.pos;}
    bool operator<(const node2& a) const
    {
        return x < a.x; //大顶堆
    }
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
	cin>>n>>m;
	int pos=0;
	rep(i,0,n){
		rep(j,0,m){
			cin>>a[pos++];
		}
	}
	rep(i,0,pos){
		vis[i%2][a[i]]++;
		sum[i%2]++;
	}
	priority_queue <node > q3;
	rep(i,0,maxn){
		if(vis[0][i]>0){
			q3.push(node(vis[0][i],i));
			if(q3.size()>2){
				q3.pop();
			}
		}	
	}
	priority_queue <node2 > q1;
	while(!q3.empty()){
		q1.push(node2(q3.top()));
		q3.pop();
	}
	priority_queue <node > q4;
	rep(i,0,maxn){
		if(vis[1][i]>0){
			q4.push(node(vis[1][i],i));
			if(q4.size()>2){
				q4.pop();
			}
		}
	}
	priority_queue <node2 > q2;
	while(!q4.empty()){
		q2.push(node2(q4.top()));
		q4.pop();
	}
	int ans=0;
	if(n==m&&n==1){
		ans=0;
	}
	else if(q1.top().pos==q2.top().pos){
		if(q1.size()==1&&q2.size()!=1){
			q2.pop();
			ans=sum[0]-q1.top().x+sum[1]-q2.top().x;
		}else if(q2.size()==1&&q1.size()!=1){
			q1.pop();
			ans=sum[0]-q1.top().x+sum[1]-q2.top().x;
		}else if(q2.size()==1&&q1.size()==1){
			ans=min(sum[0],sum[1]);
		}else{
			node2 temp1=q1.top();
			node2 temp2=q2.top();
			q1.pop();
			q2.pop();
			if(temp1.x-q1.top().x>temp2.x-q2.top().x){
				temp2=q2.top();
			}else{
				temp1=q1.top();
			}
			ans=sum[0]-temp1.x+sum[1]-temp2.x;
		}
		
	}else{
		ans=sum[0]-q1.top().x+sum[1]-q2.top().x;
	}
	cout<<ans<<endl;
	return 0;
}



