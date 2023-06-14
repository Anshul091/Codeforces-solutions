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



void dfs(ll node, ll ans, vvl &adj, vl &par, vl &s){
    s.pb(node);
	if (ll(s.size()) >= ans)
		par[node] = s[s.size() - ans];
	for (auto u : adj[node])
		dfs(u, ans, adj, par, s);
	s.pop_back();
}



void dfs2(ll node, vvl &adj, vb &visited){
    visited[node] = true;
    for(auto &it: adj[node]){
        if(!visited[it])
        dfs2(it, adj, visited);
    }
}




bool good(ll ans, ll k, vvl &adj){
    ll n = adj.size();
    vl par(n, -1);
    vl s;
	dfs(0, ans, adj, par, s);
	vl dum, h(n);
	queue<ll> q;
	q.push(0);
	while (!q.empty()){
		ll node = q.front();
		dum.push_back(node);
		q.pop();
		for (auto i: adj[node]){
			q.push(i);
			h[i] = h[node] + 1;
		}
	}
	reverse(dum.begin(), dum.end());
    vb visited(n, false);
	ll check = 0;
	for (ll node : dum){
        if (!visited[node] && h[node] > ans){
		    check++;
		    dfs2(par[node], adj, visited);
        }
	}
	
	return check <= k;
}

void solve(){
    ll n, k;
    cin>>n>>k;
    vvl adj(n);
    for(ll i = 1; i<n; i++){
        ll dum;
        cin>>dum;
        adj[dum-1].pb(i);
    }
    ll st = 1, h = n-1;
    ll ans = -1;
    while (st <= h){
        ll mid = (st+h)/2;
        if(good(mid, k, adj)){
            ans = mid;
            h = mid-1;
        }
        else st = mid+1;
        // debug(mid);
    }
    cout<<ans<<"\n";
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