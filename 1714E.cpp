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
void solve(){
    ll n;
    cin>>n;
    vl v(n);
    cin>>v;
    ll flag = 0, flag1 = 0;
    ll dum = -1, dum1 = -1;
    for(ll i = 0; i<n; i++){
        if(v[i]%10 == 5){ flag = 1; dum = v[i]; }
        if(v[i] % 10 == 0){ flag1 = 1; dum1 = v[i]; }
    }
    if(flag1 == 1){
        for(ll i = 0; i<n; i++){
            if(v[i] == dum1) continue;
            else if(v[i] % 10 == 5 && v[i] + 5 == dum1) continue;
            else{
                cout<<"No\n";
                return;
            }
        }
        cout<<"YES\n";
        return;
    }
    if(flag == 1){
        for(ll i = 0; i<n; i++){
            if(v[i] == v[0]) continue;
            else{
                cout<<"no\n";
                return;
            }
        }
        cout<<"YES\n";
        return;
    }
    else{
        vl w(n, -1);
        for(ll i = 0; i<n; i++){
            if((v[i]%10) == 1  || (v[i]%10) == 2  ||(v[i]%10) == 4 ||(v[i]%10) == 8){
                w[i] = ((v[i]/10)%10 + 1)%2;
            }
            else{
                w[i] = ((v[i]/10)%10)%2;
            }
        }
        for(ll i = 1; i<n; i++){
            if(w[i] != w[i-1]){
                cout<<"NO\n";
                return;
            }
        }
        cout<<"YES\n";
        return;
    }
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