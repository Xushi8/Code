#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using pii = pair<int, int>;

void solve() {
    int n=0;
    cin>>n;
    vector<int> a(n);
    int maxx=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        maxx=max(maxx,a[i]);
    }
    priority_queue<pii,vector<pii>,greater<pii> > A;
    map<int,int > ll;
    map<int,int > rr;
    map<int,set<pii> > bb;
    for(int x=0;x<n;x++)
    {int j=0;
        for(int j=x+1;j<n;j++)
        {if(a[x]!=a[j])
            {break;}
        }
        int l=x;
        int r=j;
        ll[l]=a[x];
        rr[a[x]]=r;
        bb[a[x]].emplace(l,r);
        A.emplace(a[x],l);
    }
    while(A.size()>1)
    {
        pii tt=A.top();
        A.pop();
        if(tt.second==0)
        {
        }
        else if(rr[ll[tt.second]]==n-1)
        {
            
        }
        else
        {
            int forward=tt.second-1;
            int  last=rr[ll[tt.second+1]];
            if(rr[forward]>=ll[last])
            {

            }
            else
            {

            }
        }


    }



}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}