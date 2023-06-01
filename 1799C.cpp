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
    string s;
    cin>>s;
    ll n = s.size();
    vl v(26);
    for(ll i = 0; i<s.size(); i++){
        ll ind = s[i] - 97;
        v[ind]++;
    }
    ll flag = 0, flag1 = 0;
    ll start = 0, end = n-1;
    string ans = s;
    ll left = -1;
    for(ll i = 0; i<26; i++){
        if(v[i] & 1){
            left = i;
            break;
        }
    }
    if(left != -1){
        for(ll i = left+1; i<26; i++){
            if(v[i] != 0) flag1++;
        }
    }
    if(flag1 != 1){
    for(ll i = 0; i<26; i++){
        if(flag == 1){
            for(ll j = 0; j<v[i]; j++){
                ans[end] = i+97;
                end--;
            }
        }
        else{
            for(ll j = 0; j<v[i]/2; j++){
                ans[end] = i+97;
                end--;
            }
            for(ll j = 0; j<v[i]/2; j++){
                ans[start] = i+97;
                start++;
            }
            if((v[i] & 1)){
                flag = 1;
                ans[start] = i+97;
                start++;
            }
        }
    }
    }
    else{
        for(ll i = 0; i<26; i++){
            for(ll j = 0; j<v[i]/2; j++){
                ans[end] = i+97;
                end--;
            }
            for(ll j = 0; j<v[i]/2; j++){
                ans[start] = i+97;
                start++;
            }
        }
        for(ll i = 0; i<26; i++){
            if(v[i] & 1){
                ans[end] = i+97;
                end--;
            }
        }
    }
    string ans2 = ans;
    reverse(ans2.begin(), ans2.end());
    ans = max(ans, ans2);
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