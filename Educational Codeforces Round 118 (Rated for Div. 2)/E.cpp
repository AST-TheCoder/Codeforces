#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define Max 100000000000000
#define min_heap priority_queue <pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>> >

template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main()
{   

    ll t;
    scanf("%lli",&t);

    while(t--){
        ll n,m;
        pair<ll,ll> pos;
        scanf("%lli %lli",&n,&m);

        string s[n+2];
        ll vis[n+2][m+2];
        memset(vis,0,sizeof(vis));

        for(ll i=1;i<=n;i++){
            cin>>s[i];
            s[i]="#"+s[i]+"#";
            for(ll j=1;j<=m;j++){
                if(s[i][j]=='L')
                    pos={i,j};
            }
        }
        for(ll i=0;i<=m+1;i++){
            s[0]+='#';
            s[n+1]+='#';
        }
        ll x[]={-1,1,0,0};
        ll y[]={0,0,-1,1};
        queue<pair<ll,ll>> q;

        for(ll i=0;i<4;i++){
            if(s[pos.first+x[i]][pos.second+y[i]]!='#')
                q.push({pos.first+x[i],pos.second+y[i]});
        }
        vis[pos.first][pos.second]=1;

        while(!q.empty()){
            pos=q.front();
            q.pop();
            ll cnt=0;
            for(ll i=0;i<4;i++){
                if(s[pos.first+x[i]][pos.second+y[i]]=='.')
                    cnt++;
            }
            if(cnt<=1){
                for(ll i=0;i<4;i++){
                    if(s[pos.first+x[i]][pos.second+y[i]]!='#' && !vis[pos.first+x[i]][pos.second+y[i]])
                        q.push({pos.first+x[i],pos.second+y[i]});
                }
                vis[pos.first][pos.second]=1;
                s[pos.first][pos.second]='+';
            }
        }
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=m;j++){
                printf("%c",s[i][j]);
            }printf("\n");
        }
    }

    return 0;
}