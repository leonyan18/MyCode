#include<bits/stdc++.h>
#include<queue>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1000005;
int flag=0;
ll n,k;
int ans[100][2];
struct node{
	int pos;
	ll sum;
	int num;
	bool b[105];
};
int last[105];
int main(){
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	cin>>n>>k;
	queue<node> q;
	node first,temp;
	first.num=1;
	first.pos=1;
	first.sum=1;
	first.b[1]=1;
	q.push(first);
	first.b[1]=0;
	first.sum=-1;
	q.push(first);
	node ans;
	while(!q.empty()){
		first=q.front();
		if(first.num==k&&first.sum==n){
			ans=first;
			break;
		}
		int pos=first.pos;
		int sum=first.sum;
		int num=first.num+1;
		first.num+=1;
		first.pos=pos*2;
		first.sum=pos*2+sum;
		first.b[num]=1;
		q.push(first);
		first.b[num]=0;
		first.sum=-pos*2+sum;
		q.push(first);
		first.pos=pos*2+1;
		first.b[num]=1;
		first.sum=pos*2+1+sum;
		q.push(first);
		first.b[num]=0;
		first.sum=-pos*2-1+sum;
		q.push(first);
		q.pop();
	}
	int pos=ans.pos;
	int len=0;
	while(pos>=1){
		last[len++]=pos;
		if(pos%2==1){
			pos--;
		}
		pos=pos/2;
	}
	int p=1;
	for(int i=len-1;i>=0;i--){
		cout<<last[i]<<" ";
		if(ans.b[p]==1){
			cout<<"+"<<endl;
		}
		else{
			cout<<"-"<<endl;
		}
		p++;
	}
}



