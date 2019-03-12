#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1000005;
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
//    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	long long int m,n,t,i=1,j,c;
    scanf("%lld %lld %lld",&n,&m,&t);
    long long int move;
    long long int b;
    long long int a[100003]={0},d[100003]={0};
   for(c=0;c<t;c++)
   {
 
 
        scanf("%lld %lld",&move,&b);
        if(move==1){
            for(j=0;j<m;j++){
                a[b-1]=i;
            }
        }
        else if(move==2){
           for(j=0;j<n;j++){
            d[b-1]=i;
           }
        }
        i++;
        move=0;
        b=0;
   }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("%lld ",a[i]>d[j] ? a[i] : d[j]);
        }
        printf("\n");
    }
    return 0;
}



