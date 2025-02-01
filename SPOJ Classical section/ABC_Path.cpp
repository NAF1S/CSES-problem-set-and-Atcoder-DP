

/*
Problem Link: https://www.spoj.com/problems/ABC_PATH/
Idea : DSF+DP(memoization)
*/


#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define ll long long
#define pb push_back
#define pi acos(-1)
#define fi first
#define se second
#define lightSpeed() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
int dirx[] = {+0,+0,+1,-1,-1,+1,-1,+1};
int diry[] = {-1,+1,+0,+0,+1,+1,-1,-1};
using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using p = pair<int, int>;
const ll inf = 1e18;
const ll mod = 1e9 + 7;



int n,m;
char grid[51][51];
bool val(int x,int y){
    if((x<n && x>=0) && (y>=0 && y<m)){
        return 1;
    }
    return 0;
}
int dp[51][51];
int dfs(int x,int y){
    if(dp[x][y]!=-1)return dp[x][y];
    int ret=0,tem;
    for(int i=0;i<8;i++){
        int xx=x+dirx[i];
        int yy=y+diry[i];
        if(val(xx,yy) && (grid[xx][yy] == grid[x][y]+1)){
            tem = 1+dfs(xx,yy);
        }
        else{
            tem=1;
        }
        ret = max(tem,ret);
    }
    return dp[x][y] = ret;

}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif  
    int c=1;
    while(scanf("%d%d",&n,&m)!=EOF){ 
    cin>>n>>m;
    //char g[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    //int protibeshi[n][m] = {-1};
    for(int i=0;i<n;i++){

    }
    memset(dp,-1,sizeof(dp));
    int ans = 0;
    vector<pair<int,int>>st;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='A'){
                ans = max(ans,dfs(i,j));
            }
        }
    }
    //cout<<ans<<nl;
    printf("Case %d: %d\n",c++,ans);
}
return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define ll long long
#define pb push_back
#define pi acos(-1)
#define fi first
#define se second
#define lightSpeed() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
int dirx[] = {+0,+0,+1,-1,-1,+1,-1,+1};
int diry[] = {-1,+1,+0,+0,+1,+1,-1,-1};
using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using p = pair<int, int>;
const ll inf = 1e18;
const ll mod = 1e9 + 7;



int n,m;
char grid[51][51];
bool val(int x,int y){
    if((x<n && x>=0) && (y>=0 && y<m)){
        return 1;
    }
    return 0;
}
int dp[51][51];
int dfs(int x,int y){
    if(dp[x][y]!=-1)return dp[x][y];
    int ret=0,tem;
    for(int i=0;i<8;i++){
        int xx=x+dirx[i];
        int yy=y+diry[i];
        if(val(xx,yy) && (grid[xx][yy] == grid[x][y]+1)){
            tem = 1+dfs(xx,yy);
        }
        else{
            tem=1;
        }
        ret = max(tem,ret);
    }
    return dp[x][y] = ret;

}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif  
    int c=1;
    while(scanf("%d%d",&n,&m)!=EOF){ 
    cin>>n>>m;
    //char g[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    //int protibeshi[n][m] = {-1};
    for(int i=0;i<n;i++){

    }
    memset(dp,-1,sizeof(dp));
    int ans = 0;
    vector<pair<int,int>>st;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='A'){
                ans = max(ans,dfs(i,j));
            }
        }
    }
    //cout<<ans<<nl;
    printf("Case %d: %d\n",c++,ans);
}
return 0;
}
