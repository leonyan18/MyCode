#include <iostream>
#include <math.h>
using namespace std;
typedef long long ll;
<<<<<<< HEAD
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
int lowbit(int x){
    return x&(-x);
}
void dfs(int n,int t){
	if(t==4){
		cout<<n<<endl;
		return;
	}
	dfs(lowbit(n)+n,t+1);
	dfs(n-lowbit(n),t+1);
}
int main(){
	//���ز���
	#ifdef ONLINE_JUDGE
	#else
//    freopen("C://Users//yan//Desktop//in.txt","w",stdout);
	#endif
	ios::sync_with_stdio(false);//ȡ��ͬ��
	std::cin.tie(0);//���cin��cout�İ󶨣���һ���ӿ�ִ��Ч�ʡ�
	dfs(6,0);
=======
ll isPrime(ll n)
{	//����1��ʾ�ж�Ϊ������0Ϊ���������ڴ�û�н��������쳣���
	double n_sqrt;
	if(n==2 || n==3) return 1;
	if(n%6!=1 && n%6!=5) return 0;
	n_sqrt=floor(sqrt((double)n));
	for(ll i=5;i<=n_sqrt;i+=6)
	{
	    if(n%(i)==0 | n%(i+2)==0) return 0;
	}
        return 1;
} 
int main()
{
	int flag;
	flag=isPrime(998244351);
	cout<<flag<<endl;
	return 0;
>>>>>>> 759470e9e9563b742d424ad3fe2d9609fee73d14
}
