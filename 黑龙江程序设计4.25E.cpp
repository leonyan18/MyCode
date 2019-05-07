#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=5005;
char s[maxn]; 
int LagPalindrome(char *str, int n)
{
	int count = 0;
	int max = 0;//最长回文子串的长度
	if (str == NULL || n<1)
	{
		return 0;
	}
	for (int i = 0; i < n; i++)
	{		
		//子串为奇数时
		for (int j = 0; (i-j)>=0&&(i+j)<n; j++)
		{
			int temp='a'-'A';
			if(str[i-j]>='a'&&str[i-j]<='z'){
				temp='A'-'a';
			}
			if (str[i - j] != str[i + j]+temp)
			{
				break;
			}
			count = 2 * j + 1;
		}
		if (count > max)
		{
			max = count;
		}
		//子串为偶数时
		for (int k = 0; (i - k)>=0 && (i + k + 1) < n; k++)
		{
			int temp='A'-'a';
			if(str[i-k]>='a'&&str[i-k]<='z'){
				temp='a'-'A';
			}
			if (str[i - k] != str[i + k+1]+temp)
			{
				break;
			}
			count=2*k + 2;
		}
		if (count > max)
		{
			max =count ;
		}
	}
	
	return max;
}
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	cin>>s;
	cout<<LagPalindrome(s,strlen(s));
}



