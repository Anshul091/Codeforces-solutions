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
vl fibo(50);
void fun(){
    fibo[0] = 1;
    fibo[1] = 1;
    for(ll i = 2; i<50; i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
}
bool checker2(ll x, ll y, ll n){
    if(n & 1){
        if(x == 1){
            if(y == 2 || y == fibo[n+1] - 1 || y == 1 || y == fibo[n+1]) return true;
        }
        else if(x == fibo[n]){
            if(y == 2 || y == fibo[n+1] - 1 || y == 1 || y == fibo[n+1]) return true;
        }
    }
    else{
        if(y == 1){
            if(x == 1 || x== 2 || x == fibo[n] || x == fibo[n] - 1) return true;
        }
        if(y == fibo[n+1]){
            if(x == 1 || x== 2 || x == fibo[n] || x == fibo[n] - 1) return true;
        }
    }
    return false;
}
void solve(){
    ll n, x, y;
    cin>>n>>x>>y;
    ll flag = 0;
    if(checker2(5, 6, 4)) cerr<<"HEOJEO\n";
    if(n <= 1){
        cout<<"YES\n";
        return;
    }
    while(n != 1){
        if(checker2(x, y, n)){
            cout<<"YES\n";
            return;
        }
        if(y <= fibo[n] && y > fibo[n-1]){
            cout<<"NO\n";
            return;
        }
        if(y > fibo[n]) y-= fibo[n];
        swap(x, y);
        n--;
    }
    cout<<"NO\n";
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    // #ifndef ONLINE_JUDGE
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);
    // #endif
    fun();
    ll t; cin>>t;
    while(t--) solve();
    return 0;
}