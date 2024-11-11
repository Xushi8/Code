#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using pii = pair<int, int>;

void solve()
{
    int n;
    cin>>n;
    int ans[32];
    if(n==0)
    {
        cout<<"NO"<<'\n';
        return;
    }
    if(n&1)
    {
        cout<<"YES"<<'\n';
        int tt=((n-1)>>1);
        for(int i=0;i<31;i++)
        {
            if(tt&1)
            {
                ans[i]=1;
            }
            else 
            {
                ans[i]=-1;
            }
            tt>>=1;
        }
        ans[31]=1;
        int size=0;
        for(int i=0;i<4;i++)
        {
            size+=8;
            for(int j=size-8;j<size;j++)
            {
                cout<<ans[j]<<" ";
            }
            cout<<'\n';
        }
        
    }
    else
    {
        int tt=((n-2)>>1);
        for(int i=0;i<31;i++)
        {
            if(tt&1)
            {
                ans[i]=1;
            }
            else 
            {
                ans[i]=-1;
            }
            tt>>=1;
        }
        
        ans[31]=1;

        if(ans[0]==1)
        {
            cout<<"NO\n";
            return;
        }
        else
        {
            cout<<"YES"<<'\n';
            ans[0]=0;
        }

        int size=0;
        for(int i=0;i<4;i++)
        {
            size+=8;
            for(int j=size-8;j<size;j++)
            {
                cout<<ans[j]<<" ";
            }
            cout<<'\n';
        }
    }
}   
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}