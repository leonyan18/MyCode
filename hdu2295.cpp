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
	double x;
	double y;
};
node r[maxn],c[maxn];
bool vis[maxn];
int main(){
	//���ز���
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//11835//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//ȡ��ͬ��
	std::cin.tie(0);//���cin��cout�İ󶨣���һ���ӿ�ִ��Ч�ʡ�
	int t;
	cin>>t;
	while(t--){
		clr(r);
		clr(c); 
		int n,m,k;
		cin>>n>>m>>k;
		rep(i,0,n){
			cin>>c[i].x>>c[i].y;//���� 
		}
		rep(i,0,m){
			cin>>r[i].x>>r[i].y;//�״� 
		}
		double le=0,ri=1000.0,mid;//�������״� 
		while(ri-le>1e-8){
			mid=(le+ri)/2;
			clr(vis);
			int sumc=0;
			int flag=0;
//			cout<<"mid  "<<mid<<endl;
			rep(i,0,n){
				flag=0;
				rep(j,0,m){
					double dis=(r[j].x-c[i].x)*(r[j].x-c[i].x)+(r[j].y-c[i].y)*(r[j].y-c[i].y);
//					cout<<i<<" "<<j<<" "<<sqrt(dis)<<endl;
					if(mid>=sqrt(dis)){
						flag=1;
						vis[j]=1;
					}
				}
				if(flag)
					sumc++;
//				cout<<endl;
			}
//			cout<<"sumc  "<<sumc<<endl;
			int sumr=0;
			rep(j,0,m){
				if(vis[j])
					sumr++;
			}
		    if(sumc==n)
		    
		    
				ri=mid;
			else 
				le=mid;
//			printf("%.6lf %.6lf\n",le,ri);
		}
		printf("%.6lf\n",ri);
	} 
}



