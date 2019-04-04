#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=205;
int sg[maxn*2];
int vis[maxn*2];
void init(){
	sg[0]=0;
	sg[1]=sg[2]=sg[3]=1;
	rep(i,4,205){
		clr(vis);
		rep(j,0,i){
			int pre=j-2;
			int next=i-j-3;
			if(pre<0){
				pre=0;
			}
			if(next<0){
				next=0;
			}
			vis[sg[pre]^sg[next]]=1;
		}
		rep(j,0,i){
			if(!vis[j]){
				sg[i]=j;
				break;
			}
		}
	}
}
int isWin(string s){
	int ans=0;
	int len=s.length();
	string temp=s;
//	cout<<s<<endl;
	rep(i,2,len){
		int temp2= s[i-2]=='X';
		int temp1= s[i-1]=='X';
		int temp= s[i]=='X';
		if(temp1+temp2+temp==3){
			return 0;
		}
	}
	rep(i,2,len){
		int temp2= s[i-2]=='X';
		int temp1= s[i-1]=='X';
		int temp= s[i]=='X';
		if(temp1+temp2+temp==2){
			return 1;
		}
	}
	rep(i,0,len){
		if(s[i]=='X')
		rep(j,-2,3){
			if(i-j>=0&&i-j<len){
				temp[i-j]='X';
			}
		}
	}
	s=temp;
	rep(i,0,len){
		if(s[i]=='.'){
			int sum=0;
			while(s[i]=='.'&&i<len){
				sum++;
				i++;
			}
			ans=ans^sg[sum];
		}
	}
	return ans;
}
int a[maxn];
int anslen;
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	int q;
	init();
	cin>>q;
	while(q--){
		anslen=0;
		string s;
		cin>>s;
		int pos=0;
		int ans=0;
		int len=s.length();
		ans=isWin(s);
		if(ans){
			cout<<"WINNING"<<endl;
			if(ans!=0){
				rep(i,0,len){
					if(s[i]=='.'){
						s[i]='X';
						int temp=isWin(s);
//						cout<<temp;
						if(temp==0){
							a[anslen++]=i+1;
						}
						s[i]='.';
					}
				}
			}
			int flag=0;
			int pre=-1;
			sort(a,a+anslen);
			rep(i,0,anslen){
				if(pre==a[i]){
					continue;
				}
				if(!flag){
					cout<<a[i];
				}else{
					cout<<" "<<a[i];
				}
				flag=1;
			}
			cout<<endl;
		}else{
			cout<<"LOSING"<<endl<<endl;
		}
	}
}
