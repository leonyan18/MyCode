#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1e5+5;
char aim[35]={
	11, 12, 13, 14, 15, 16, 17, 1,
	21, 22, 23, 24, 25, 26, 27, 1,
	31, 32, 33, 34, 35, 36, 37, 1,
	41, 42, 43, 44, 45, 46, 47, 1
};
struct node{
	int step;
	char s[35];
	bool operator<(const node b)const
	{
		return this->step>b.step;
	}
};
void move(node &now,int val){
	rep(i,0,32){
		if(now.s[i]==val){
			now.s[i]=1;
			return;
		}
	}
}
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//11835//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	int n;
	cin>>n;
	while(n--){
		node now;
		now.step=0;
		rep(i,0,4){
			rep(j,1,8){
				int temp;
				cin>>temp;
				now.s[i*8+j]=temp;
				if(temp%10==1){
					now.s[i*8+j]=1;
				}
			}
		}
		now.s[0]=11;
		now.s[8]=21;
		now.s[16]=31;
		now.s[24]=41;
		map<string,bool> mp;
		priority_queue<node> q;
		mp[now.s]=1;
		q.push(now);
		int flag=0;
		int ans=-1;
		if(strcmp(aim,now.s)==0){
			flag=1;
			ans=0;
		}
		while(!q.empty()){
			if(flag)
			break;
			now=q.top();
			q.pop();
			rep(i,0,4){
				rep(j,1,8){
					node temp=now;
					if(temp.s[i*8+j]==1&&temp.s[i*8+j-1]%10!=7&&temp.s[i*8+j-1]!=1){//当前位置是空格且前一个位置不是空格和7 
						move(temp,temp.s[i*8+j-1]+1);
						temp.s[i*8+j]=temp.s[i*8+j-1]+1;
						temp.step++;
						if(strcmp(aim,temp.s)==0){
							flag=1;
							
							ans=temp.step;
						}
						if(mp[temp.s]==0){
							mp[temp.s]=1;
							q.push(temp);
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	} 
}
