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

#define MAXN 10000010
 
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

ll ans[(ll)1e7+10];
ll dp[MAXN];
void first_solve(){
    for(ll i = 0; i<1e7+10; i++) ans[i] = -1;
   for (ll n = 1; n <= 10000000; n++){    
        for (ll i = n; i <= 10000000; i += n){
            dp[i] += n;
        }
    }
    for (ll i = 0; i <= 10000000; i++)
    {
        if(dp[i] > 1e7) continue;
        if (ans[dp[i]] == -1) ans[dp[i]] = i;
    }
}
void solve(){
    ll n;
    cin>>n;
    cout<<ans[n]<<'\n';
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin);
       freopen("output.txt", "w", stdout);
    #endif
    sieve();
    first_solve();
    ll t; cin>>t;
    while(t--) solve();
    return 0;
}