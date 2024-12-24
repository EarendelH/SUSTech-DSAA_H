#include <iostream>
using namespace std;

bool onek(string arr,int l,int r)
{
    int count=0;
    for(int i=l;i<=r;i++)
    {
        if(arr[i]=='K')
        {
            count+=1;
        }
    }
    if(count==1)
    {
        return true;
    }
    return false;
}
long long find(string arr, int left, int right) {
    long long inv_count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        cout<<left<<" "<<mid<<" "<<right<<" "<<onek(arr,left,mid)<<" "<<onek(arr,mid+1,right)<<endl;
        if(onek(arr,left,mid)&&onek(arr,mid+1,right))
        {
            return min(mid-left+1,right-mid);
        }
        else if(onek(arr,left,mid))
        {
            return find(arr,mid+1,right);
        }
        else if(onek(arr,mid+1,right))
        {
            return find(arr,left,mid);
        }
    }
    return 0;
}

int main() {
    string s;
    cin>>s;
    int inv_count = find(s, 0, s.size() - 1);
    cout << inv_count << endl;
    return 0;
}