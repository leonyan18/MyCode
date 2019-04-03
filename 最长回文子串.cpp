#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1005;
class Solution {
int len[1005];
int a[150][1005];
bool ans[1005][1005];
struct node{
	int pos;
	int len;
	friend bool operator<(node n1,node n2){
		return n1.len>n2.len;
	}
        
};
public:
    string longestPalindrome(string s) {
    	if(s.length()==0){
    		return "";
		}
    	int maxlen=0;
    	int maxpos=0;
    	priority_queue<node> q;
        for(int i=0;i<s.length();i++){
        	if(len[s[i]]!=0){
        		node temp;
        		temp.pos=a[s[i]][len[s[i]]-1];
        		temp.len=i-temp.pos;
        		q.push(temp);
			}
        	a[s[i]][len[s[i]]++]=i;
		}
		while(!q.empty()){
			node temp=q.top();
			q.pop();
			if(temp.len==1||temp.len==2||ans[temp.pos+1][temp.len-2]){
				ans[temp.pos][temp.len]==true;
				if(temp.len>maxlen){
					maxlen=temp.len;
					maxpos=temp.pos;
				}
			}
		}
		return s.substr(maxpos,maxpos+maxlen+1);
    }
};
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	string s;
	cin>>s;
	Solution sl;
	cout<<sl.longestPalindrome(s)<<endl;
}



