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
void solve(ll t, ll &flag){
    // if(t == 9999) flag = 1;
    ll n;
    cin>>n;
    string s;
    cin>>s;
    // if(flag == 1){
    //     if(t == 10000 - 178){
    //         cout<<s<<'\n';
    //     }
    //     else return;
    // }
    if(n & 1){
        cout<<"-1\n";
        return;
    }
    assert(n == s.size());
    map<char, ll> m;
    ll maxi = 0;
    for(ll i = 0; i<n; i++){
        m[s[i]]++;
        maxi = max(maxi, m[s[i]]);
    }
    if(maxi > n/2){
        cout<<"-1\n";
        return;
    }
    
    string s1 = s.substr(0, n/2), s2 = s.substr(n/2, n/2);
    reverse(s2.begin(), s2.end());
    map<char, ll> m1;
    ll mx = -INF, sm = 0;
    for(ll i = 0; i<n/2; i++){
        if(s1[i] == s2[i]){
            m1[s1[i]]++;
            mx = max(mx, m1[s1[i]]);
        }
    }
    for(char i = 'a'; i<='z'; i++)   sm += m1[i];
    if(sm - mx < mx)  cout<<mx<<'\n';
    else cout<<(sm+1)/2<<'\n';
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    // #ifndef ONLINE_JUDGE
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);
    // #endif
    ll flag = 0;
    ll t; cin>>t;
    while(t--) solve(t, flag);
    return 0;
}