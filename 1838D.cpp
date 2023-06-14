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
void solve(){
    ll n, q;
    cin>>n>>q;
    string s;
    cin>>s;
    ll num1 = 0, num2 = 0, flag = 0;
    for(ll i = 0; i<n; i++){
        if(s[i] == '(') num1++;
        else num2++;
    }
    // debug(num1, num2);
    if((abs(num2 - num1) & 1)    || (n == 1)){
        for(ll i = 0; i<q; i++){
            ll dum;
            cin>>dum;
            cout<<"NO\n";
        }
        return;
    }
    num2 = 0, num1 = 0;
    set<ll> open, close;
    for(ll i = 0; i<n - 1; i++){
        if(s[i] == s[i+1]){
            if(s[i] == '(') open.insert(i);
            else close.insert(i);
        }
    }
    while(q--){
        ll dum;
        cin>>dum;
        dum--;
        s[dum] = '(' + ')' - s[dum];
        if(n == 2){
            if(s == "()") cout<<"YES\n";
            else cout<<"NO\n";
            continue;
        }
        if(dum > 0){
            open.erase(dum -1);
            close.erase(dum -1);
            if(s[dum] == s[dum-1]){
                if(s[dum] == '(')open.insert(dum -1);
                else close.insert(dum -1);
            }
        }
        if(dum < n-1){
            open.erase(dum);
            close.erase(dum);
            if(s[dum] == s[dum + 1]){
                if(s[dum] == '(')open.insert(dum);
                else close.insert(dum);
            }
        }

        if(s[0] != '('    || s[n-1] != ')'){
            cout<<"NO\n";
            continue;
        }
        // debug(s);
        // debug(open, close);
        // debug(q, open.size(), close.size());
        if(open.size() == 0 && close.size() == 0) cout<<"YES\n";
        else if(open.size() != 0 && close.size() != 0){
            if(*open.begin() < *close.begin()  && *open.rbegin() < *close.rbegin()) cout<<"YES\n";
            else cout<<"NO\n";
        }
        else {
            cout<<"NO\n";
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    // #ifndef ONLINE_JUDGE
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);
    // #endif
    ll t; t = 1;
    while(t--) solve();
    return 0;
}