#include<iostream>
#include <algorithm>
using namespace std;
int r[1002],p[1002],s[1002];
int memoized_cut(int n, int p[], int r[],int s[])
{
    int q;
    if (r[n] >= 0)
    {
        return r[n];
    }
    if (n == 0)
    {
        q = 0;
    }
    else
    {
        q = -1;
        for (int i = 1; i <= n; i++)
        {
            int tmp= p[i] + memoized_cut(n - i, p, r,s);
            if (q < tmp)
            {
                q = tmp;
                s[n] = i;
            }
        }
    }
    r[n] = q;

    return q;
}
int memoized_cut_rod(int n, int p[], int r[],int s[])
{
    for (int i = 0; i <= n; i++)
    {
        r[i]=-1;
        s[i]=0;
    }
    return memoized_cut(n, p, r,s);
}
void get_cut_rod_solution(int n, int s[])
{
    int b[1002];
    int i = 0;
    while (n > 0)
    {
        b[i] = s[n];
        n = n - s[n];
        i++;
    }
    cout<<i<<endl;
    for (int j = 0; j < i; j++)
    {
        cout<<b[j]<<" ";
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    cout << memoized_cut_rod(n, p, r,s) << endl;
    get_cut_rod_solution(n, s);
}