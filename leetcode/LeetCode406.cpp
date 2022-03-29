#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1000005;
class Solution {
    static bool compare1(pair<int,int> a,pair<int,int> b){
        if(a.second==b.second){
            return a.first<b.first;
        }
        return a.second<b.second;
    }
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people)     {
        sort(people.begin(),people.end(),compare1);
        vector<pair<int, int>> ans;
        ans.push_back(people[0]);
        for(int i=1;i<people.size();i++){
            pair<int, int> t=people[i];
            int sum=0;
            for(int j=0;j<ans.size();j++){
                if(ans[j].first>=t.first){
                    sum++;
                }
                if(sum==t.second){
                	j++;
                	while(j<ans.size()&&ans[j].first<=t.first){
                		j++;
					}
					if(j>=ans.size()){
						ans.push_back(t);
					}else
                    	ans.insert(ans.begin()+j,t);
                    break;
                }
            }
        }
        return ans;
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
	vector<pair<int, int>> test={{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}}; 
	Solution s;
	vector<pair<int, int>> ans=s.reconstructQueue(test);
	rep(i,0,ans.size()){
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}
}



