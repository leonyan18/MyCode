#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1000005;
string s;
int main(){
	//���ز���
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//ȡ��ͬ��
	std::cin.tie(0);//���cin��cout�İ󶨣���һ���ӿ�ִ��Ч�ʡ�
	string temp="";
	string one="a";
	rep(i,0,200){
		one="a";
		one[0]=one[0]+i%26;
		temp=temp+one;
		s+=temp;
	}
//	cout<<s<<endl;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		n=n-1;
		cout<<s[n]<<endl;
	} 
}
