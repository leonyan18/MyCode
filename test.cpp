#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
int main(){
	//���ز���
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","w",stdout);
	#endif
	ios::sync_with_stdio(false);//ȡ��ͬ��
	std::cin.tie(0);//���cin��cout�İ󶨣���һ���ӿ�ִ��Ч�ʡ�
	srand((unsigned)time(NULL));
	cout<<"1000 1000"<<endl;
	rep(i,0,1000){
		rep(j,0,1000){
			char c;
			if(rand()%2==0){
				c='A'+rand()%26;
				cout<<c;
			}
			else{
				c='a'+rand()%26;
				cout<<c;
			}
		}
		cout<<endl;
	} 
}


