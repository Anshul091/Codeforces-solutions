#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> pll;
typedef map<ll, ll> mll;
typedef vector<pll> vpl;
const double PI = 3.141592653589793;
const int MOD = 1e9+7;
const int mod = 998244353;
const int inf = INT_MAX;
const ll INF = LLONG_MAX;
 
#define pb push_back
#define mp make_pair
 
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
bool dfs(ll par, ll node, vvl &adj, vl &visited){
    // cout<<"NODE - "<<node<<'\n';
    if(visited[node] == -1){
    if(par != -1)
    visited[node] = 1-visited[par];
    else visited[node] = 0;
    }
    // cout<<visited<<'\n';
    for(auto i:adj[node]){
        // cout<<"children - "<<i<<' '<<visited[i]<<'\n';
        if((visited[i] == -1)){
            if(!dfs(node, i, adj, visited)) return false;
        }
        else if(visited[node] == visited[i]) return false;
    }
    // cout<<"ABRAKADABRA\n";
    return true;
}
void solve(){
    ll n;
    cin>>n;
    vvl adj(n);
    for(ll i = 0; i<n; i++){
        ll dum, dum1;
        cin>>dum>>dum1;
        adj[dum-1].pb(dum1-1);
        adj[dum1-1].pb(dum-1);
    }
    vl visited(n, -1);
    mll m;
    for(auto i: adj){
        for(auto j:i) m[j]++;
    }
    for(auto &i:m){
        if(i.second != 2){
            cout<<"NO\n";
            return;
        }
    }
    for(ll i = 0; i<n; i++){
        if(!dfs(-1, i, adj, visited)){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    // #ifndef ONLINE_JUDGE
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);
    // #endif
    ll t; cin>>t;
    while(t--) solve();
    return 0;
}