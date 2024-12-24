//counting sort
#include <iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<=m;i++)
    {
        b[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        b[a[i]]++;
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<b[i];j++)
        {
            cout<<i<<" ";
        }
    }
    
}