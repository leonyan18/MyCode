#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1000005;
int pos[maxn];
int sup[maxn];
int main(){
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	int n,m;
	cin>>n>>m;
	int len=0;
	getchar();
	while(1){
		cin>>pos[len++];
		char c=getchar();
		if(c!=' '){
			break;
		}
	}
	rep(i,0,len){
		cin>>sup[i];
	}
	int before=0;
	int cnt=0;
	priority_queue <int,vector<int>,less<int> >q;
	rep(i,0,len){
		m+=before-pos[i];
		if(m<0){
			while(!q.empty()&&m<0){
				cnt++;
				m+=q.top();
				q.pop();
			}
			if(m<0){
				cout<<-1<<endl;
				return 0;
			}
		}
		q.push(sup[i]);
		while(!q.empty()&&m<0){
			cnt++;
			m+=q.top();
			q.pop();
		}
		if(m<0){
			cout<<-1<<endl;
			return 0;
		}
		before=pos[i];
	}
	m+=before-n;
	while(!q.empty()&&m<0){
		cnt++;
		m+=q.top();
		q.pop();
	}
	if(m<0){
		cout<<-1<<endl;
		return 0;
	}
	cout<<cnt<<endl; 
}



