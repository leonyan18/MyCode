
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    int x,y;
    while(scanf("%d",&n)!=EOF)
    {
    vector <pair<int,int> >mm;
    int i,j,k;
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        mm.push_back(make_pair(x,y));
    }
    sort(mm.begin(),mm.end());                      //���� 
    mm.erase(unique(mm.begin(),mm.end()),mm.end());//ɾȥһ��Ԫ�ر���������ͬ��Ԫ�� 
    for(i=0;i<mm.size();i++)
    printf("%d %d\n",mm[i].first,mm[i].second);
    }
    return 0;
}
