#include <stdio.h>  
#define max 100001  
long long a[max],b[max];  
long long count;  
void Merge(long long a[], int start, int mid , int end)   
{  
    int i = start,j = mid + 1,k = start;  
    while(i <= mid&&j <= end)  
    {  
        if(a[i] <= a[j])  
        {  
            b[k++] = a[i++];  
        }  
        else  
        {  
            count += j - k; 
            b[k++] = a[j++];  
        }  
    }  
    while(i <= mid)  
    {  
        b[k++] = a[i++];  
    }  
    while(j <= end)  
    {  
        b[k++] = a[j++];  
    }  
    for(int i = start; i <= end; i++)  
    {  
        a[i] = b[i];  
    }  
}  
  
void MergeSort(long long a[], int start, int end)  //¹é²¢ÅÅÐò  
{  
    if(start < end)  
    {  
        int mid = (start + end)/2;  
        MergeSort(a,start,mid);       
        MergeSort(a,mid+1,end);       
        Merge(a,start,mid,end);       
    }  
}  
int main(int argc, char const *argv[])  
{  
    int n,m;  
    while(~scanf("%d",&m))  
    {   
        count = 0;  
        for(int i = 0; i < m; i++)  
        {  
            scanf("%d",a+i);  
        }  
        MergeSort(a,0,m-1);  
        printf("%lld\n",count);  
    }  
    return 0;  
}  

