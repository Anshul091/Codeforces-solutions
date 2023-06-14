#include <bits/stdc++.h>
using namespace std;
 
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
 
 
 
typedef long long int ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> pll;
typedef map<ll, ll> mll;
typedef vector<pll> vpl;
typedef vector<bool> vb;
 
 
 
 
 
const double PI = 3.141592653589793;
const int MOD = 1e9+7;
const int mod = 998244353;
const int inf = INT_MAX;
const ll INF = LLONG_MAX;
 
 
 
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
 
 
 
// Operator overloads <<, >> 
template<typename T1, typename T2> // cin >> pair
istream &operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template<typename T> // cin >> vector
istream &operator>>(istream &istream, vector<T> &v) { for (auto &it : v) { cin >> it; } return istream; }
template<typename T1, typename T2> // cout << pair
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
template<typename T> // cout << vector
ostream &operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) { cout << it << " "; } return ostream; }
 
// ================================== Template Ends ==================================
// ================================== Debug Starts ==================================
// void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
// ================================== Debug Ends ==================================

void bfs(ll node, vvl &adj, vl &dist){
    queue<ll> q;
    q.push(node);
    dist[node] = 0;
    while(!q.empty()){
        ll curr = q.front();
        q.pop();
        for(auto it: adj[curr]){
            if(dist[it] == -1){
                dist[it] = dist[curr] + 1;
                q.push(it);
            }
        }
    }
}


void solve(){
    ll n, m, k;
    cin>>n>>m>>k;
    vl spec(k);
    cin>>spec;
    for(ll i = 0; i<k; i++) spec[i]--;
    vl dis1(n, -1);
    vl dis2(n, -1);
    vvl adj(n);
    for(ll i = 0; i<m; i++){
        ll u, v; 
        cin>>u>>v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    bfs(0, adj, dis1);
    bfs(n-1, adj, dis2);
    vpl dist(k);
    for(ll i = 0; i<k; i++){
        dist[i] = {dis1[spec[i]] , dis2[spec[i]]};
    }
    sort(all(dist));
    ll ans = -INF;
    vl suf(k);
    for(ll i = k - 1; i>=0; i--){
        suf[i] = dist[i].second;
        if(i != k-1) suf[i] = max(suf[i], suf[i+1]);
    }
    for(ll i = 0; i<k - 1; i++){
        ans = max(ans, dist[i].first + 1 + suf[i+1]);
    }
    cout<<min(ans, dis1[n-1])<<'\n';
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    // #ifndef ONLINE_JUDGE
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);
    // #endif
    ll t; t = 1;
    while(t--) solve();
    return 0;
}