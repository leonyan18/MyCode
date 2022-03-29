#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1000005;
int a[30]; 
int bsearch(int x){
	if(x>=a[0]){
		int left=0;
		int right=29;
		while(left<right){
			int mid=left+right+1>>1;
			if(x<a[mid]){
				right=mid;
			}else{
				left=mid;
			}
		}
		if(x==a[left])
			return left;
	}
	return -1;
}
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	srand((unsigned)time(0));
	rep(i,0,30)
		a[i]=rand();
	sort(a,a+30);
	rep(i,0,30){
		cout<<bsearch(a[i])<<endl;
	}
	cout<<bsearch(1212)<<endl;
}



