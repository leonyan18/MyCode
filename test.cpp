#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (ll i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
int ans[205][205];
int main(){
	//���ز���
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//ȡ��ͬ��
	std::cin.tie(0);//���cin��cout�İ󶨣���һ���ӿ�ִ��Ч�ʡ�
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n%2==0){
			cout<<"possible"<<endl;
			rep(i,0,n){
				rep(j,0,n){
					if(j==1+i){
						ans[i][j]=0;
					}
					else if(i%2==0||j%2==0){
						ans[i][j]=1;
					}
					else if(i%2==1||j%2==1){
						ans[i][j]=-1;
					}
				}
			}
			rep(i,0,n){
				rep(j,0,n){
					printf("%d ",ans[i]);
				}
				cout<<endl;
			}
		}
		else{
			cout<<"impossible"<<endl;
		}
	}
}


