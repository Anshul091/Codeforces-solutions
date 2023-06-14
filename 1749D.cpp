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
ll lcm(ll a, ll b){
    ll g = __gcd(a, b);
    return (a * b) / g;
}

ll modpower(ll x, ll y, ll m){
    x %= m;
    ll ans = 1;
    while (y > 0) {
        if (y % 2 == 1) ans = (ans*x) % m;
        x = (x*x) % m;
        y /= 2;
    }
    return ans;
}
#define MAXN 10000001
 
ll spf[MAXN];
 
void sieve(){
    spf[1] = 1;
    for (ll i = 2; i<MAXN; i++) spf[i] = i;
    for (ll i = 4; i<MAXN; i+=2) spf[i] = 2;
    for (ll i = 3; i*i<MAXN; i++) if (spf[i] == i) for (ll j=i*i; j<MAXN; j+=i) if (spf[j]==j) spf[j] = i;
}
 
vl getFactorization(ll x) {
    vl ret;
    while (x != 1){
        ret.push_back(spf[x]);
        x /= spf[x];
    }
    return ret;
}
void solve(){
    ll n, m;
    cin>>n>>m;
    vl dp(n+1);
    dp[1] = 1;
    for(ll i = 2; i<=n; i++){
        dp[i] = dp[i-1];
        if(spf[i] == i){
            dp[i] *= i;
        }
        if(dp[i] > m) dp[i] = m + 100;
    }
    ll ans = 1;
    ll ans2 = 0;
    ll dum = 1;
    for(ll i = 1; i<=n; i++){
        ll dum2 = m/dp[i];
        dum2 %= mod;
        ans *= dum2;
        ans%= mod;
        // debug(ans);
        dum *= (m % mod);
        dum %= mod;
        ans2 += (dum - ans + mod) % mod;
        ans2 %= mod;
    }
    cout<<ans2<<'\n';
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    // #ifndef ONLINE_JUDGE
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);
    // #endif
    sieve();
    ll t = 1;
    // cin>>t;
    while(t--) solve();
    return 0;
}