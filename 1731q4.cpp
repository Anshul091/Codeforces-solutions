#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> pll;
typedef map<ll, ll> mll;
 
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
    ll n, m;
    cin>>n>>m;
    vvl v(n, vl(m));
    cin>>v;
    ll l;
    //Binary search on l
    ll start = 1, end = 1000, ans = 1;
    while(start <= end){
        ll mid = (start + end)/2;
        vvl pref(n, vl(m));
        for(ll i = 0; i<n; i++){
            for(ll j = 0; j<m; j++){
                if(v[i][j] >= mid)
                pref[i][j] = 1;
            }
        }
        // if(start == 2){
        // for(ll i = 0; i<n; i++)
        // cout<<pref[i]<<'\n';
        // }
        for(ll i = 0; i<n; i++){
            for(ll j = 0; j<m; j++){
                if(i>0 && j>0)
                pref[i][j] += pref[i-1][j]-pref[i-1][j-1]+pref[i][j-1];
                else if(i == 0 && j>0)
                pref[i][j] += pref[i][j-1];
                else if(j == 0 && i>0)
                pref[i][j] += pref[i-1][j];
            }
        }
        // if(start == 2){
        // for(ll i = 0; i<n; i++)
        // cout<<pref[i]<<'\n';
        // }
        ll flag = 0;
        for(ll i = mid-1; i<n; i++){
            for(ll j = mid-1; j<m; j++){
                ll checker = pref[i][j];
                if(i >= mid)
                checker -= pref[i-mid][j];
                if(j>=mid)
                checker -= pref[i][j-mid];
                if(i>=mid && j>=mid)
                checker += pref[i-mid][j-mid];
                // if(start == 2) {
                //     cout<<mid<<'\n';
                //     cout<<i<<' '<<j<<'\n';
                //     cout<<checker<<'\n';
                // }
                if(checker == mid*mid){
                    ans = mid;
                    flag = 1;
                    start = mid+1;
                    // cout<<"start- "<<start<<'\n'; 
                    break;
                }
            }
            if(flag == 1) break;
        }
        if(flag == 0) {end = mid-1;
        }
    }
    int a = __gcd(n, m);
    cout<<ans<<'\n';
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while(t--) solve();
    return 0;
}