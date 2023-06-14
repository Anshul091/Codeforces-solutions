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


#define MAXN 1000005
 
ll spf[MAXN];
 
void sieve(){
    spf[1] = 1;
    for (ll i = 2; i<MAXN; i++) spf[i] = i;
    for (ll i = 4; i<MAXN; i+=2) spf[i] = 2;
    for (ll i = 3; i*i<MAXN; i++) if (spf[i] == i) for (ll j=i*i; j<MAXN; j+=i) if (spf[j]==j) spf[j] = i;
}

bool isprime(ll a){
    if(a == 1   ||   spf[a] != a) return false;
    return true;
}

ll fac[MAXN];

void factorial(){
    fac[0] = 1;
    fac[1] = 1;
    for(ll i = 2; i<MAXN; i++) fac[i] = fac[i-1]*i;
}

void solve(){
    ll n;cin>>n;
    vl v(2*n);
    map<ll,ll> m,comp;
    for (ll i=0;i<2*n;i++) {
        cin>>v[i];
        if (!isprime(v[i])) comp[v[i]]++;
        else m[v[i]]++;
    }
    ll distinct = m.size();
    vl cnt;
    for (auto x:m) cnt.pb(x.second);
    // for (auto x:comp) compcnt.pb(x.sec);
    if (distinct<n) {cout<<0;return;}
    ll dp [distinct][n+1];
    ll prod=1;
    for (ll i=0;i<distinct;i++){
        for (ll j=1;j<=n;j++) {
            if (i==0 && j==1) dp[i][j]=cnt[i];
            else if (i==0) dp[i][j]=0;
            else if (j==1) dp[i][j]=dp[i-1][j]+cnt[i];
            else dp[i][j]=(dp[i-1][j]+dp[i-1][j-1]*cnt[i])%mod;
            dp[i][j]%=mod;
        }
        prod*=fac[cnt[i]];
        prod%=mod;
    }
    // for (ll i=0;i<distinct;i++){
    //     for (ll j=1;j<=n;j++) cout<<dp[i][j]<<" ";
    //         cout<<"\n";
    // }
    ll compans = 1;
    for (auto x:comp) {
        compans*=fac[x.second];
        compans%=mod;
    }
    ll ans = fac[n];
    ans = (ans*modpower(prod,mod-2,mod))%mod;
    ans = (ans*dp[distinct-1][n])%mod;
    ans = (ans*modpower(compans,mod-2,mod))%mod;
    cout<<ans;



}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    // #ifndef ONLINE_JUDGE
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);
    // #endif
    sieve();
    factorial();
    ll t; t = 1;
    while(t--) solve();
    return 0;
}