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

bool present(ll ans, vl &v){
    for(ll i = 0; i<v.size(); i++){
        if(v[i] == ans) return true;
    }
    return false;
}

void solve(){
    ll n, m;
    cin>>n>>m;
    vvl v(m);
    mll mp;
    for(ll i = 0; i<m; i++){
        ll k;
        cin>>k;
        vl temp(k);
        for(ll j = 0; j<k; j++){
            cin>>temp[j];
            mp[temp[j]]++;
        }
        v[i] = temp;
    }
    ll mx = 0, maxi = -INF;
    for(auto &&i:mp){
        if(i.second > maxi){
            maxi = i.second;
            mx = i.first;
        }
    }
    mll count;
    vl ans(m, -1);
    ll cnt = 0;
    for(ll i = 0; i<m; i++){
        if(v[i].size() == 1 && v[i][0] == mx){
            ans[i] = mx;
            cnt++;
            count[mx]++;
        }
    }
    if(cnt > (m + 1)/2){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    for(ll i = 0; i<m; i++){
        if(ans[i] == -1){
            if(count[mx] < (m + 1)/2  && present(mx, v[i])){
                ans[i] = mx;
                count[mx]++;
            }
            else{
                for(ll j = 0; j<v[i].size(); j++){
                    if(v[i][j] != mx  && count[v[i][j]] < (m + 1)/2){
                        ans[i] = v[i][j];
                        count[v[i][j]]++;
                        break;
                    }
                }
            }
        }
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