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
    ll q;
    cin>>q;
    ll low = -1, high = 1e18;
    while(q--){
        ll event;
        cin>>event;
        ll a, b, n;
        if(event == 1){
            cin>>a>>b>>n;
            ll high1 = (a-b)*(n-1);
            high1 += a;
            ll low1 = (a-b)*(n-1);
            if(n == 1)    low1 = 1;
            else low1 = high1-(a-b)+1;
            if(low1 > high || low > high1){
                cout<<"0 ";
            }
            else{
                low = max(low, low1);
                high = min(high, high1);
                cout<<"1 ";
            }
            // cout<<"*############\n";
            // cout<<low<<' '<<high<<'\n';
        }
        else{
            cin>>a>>b;
            if(low < 0){
                cout<<"-1 ";
                continue;
            }
            ll ans1 = 1, ans2 = 1;
            ll h1 = low - a;
            ll h2 = high - a;
            if(h1 > 0)
            ans1 += (h1+a-b-1)/(a-b);
            if(h2 > 0)
            ans2 += (h2+a-b-1)/(a-b);
            if(ans1 == ans2)        cout<<ans1<<' ';
            else cout<<"-1 ";
            // cout<<ans2<<' ';
        }
    }
    cout<<'\n';
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