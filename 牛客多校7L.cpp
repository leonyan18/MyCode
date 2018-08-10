#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
char a[1005][1005];
struct pos{
    int x,y;
}b[1005][1005];
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
    rep(i,1,n+1){
        rep(j,1,m+1){
        	cin>>a[i][j];
		}
    }
    rep(i,1,n+1){
        rep(j,1,m+1){
        	b[i][j].y=0;
            for(int k=1;k<52&&k<i;k++){
                if(a[i][j]!=a[i-k][j]){
                    b[i][j].y=k;
                }
                else{
                    break;
                }
            }
            for(int k=1;k<52&&k<j;k++){
                if(a[i][j]!=a[i][j-k]){
                    b[i][j].x=k;
                }
                else{
                    break;
                }
            }
            b[i][j].x=min(b[i][j].x,b[i][j-1].x+1);
            b[i][j].y=min(b[i][j].y,b[i-1][j].y+1);
        }
    }
//  rep(i,1,n+1){
//      rep(j,1,m+1){
//          cout<<b[i][j].x<<","<<b[i][j].y<<"   ";
//      }
//      cout<<endl;
//  }
    ll sum=0;
    int l[52];
    rep(i,1,n+1){
        rep(j,1,m+1){
            sum+=b[i][j].x+b[i][j].y;
            int temp=b[i][j].x;
            clr(l);
            l[1]=b[i][j-1].y;
            rep(k,2,b[i][j].x+1)
            	l[k]=min(l[k-1],b[i][j-k].y);
            int now=b[i][j].x;
            rep(k,1,b[i][j].y+1){
            	while(l[now]<k&&now>0)
            		now--;
            	temp=min(temp,min(b[i-k][j].x,now));
                sum+=temp;
            }
        }
    }
    cout<<sum+n*m<<endl;
}
