#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
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
// void __print(ll x) {cerr << x;}
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

 
void combinationUtil(vector<char> arr, ll data[],
                    ll start, ll end,
                    ll index, ll r, vector<vector<char>> &ans);
 
// The main function that prints
// all combinations of size r
// in arr[] of size n. This function
// mainly uses combinationUtil()
vector<vector<char>> printCombination(vector<char> arr, ll n, ll r)
{
    // A temporary array to store
    // all combination one by one
    ll data[r];
    vector<vector<char>> ans;
    // Print all combination using
    // temporary array 'data[]'
    combinationUtil(arr, data, 0, n-1, 0, r, ans);
    return ans;
}
 
/* arr[] ---> Input Array
data[] ---> Temporary array to
store current combination
start & end ---> Starting and
Ending indexes in arr[]
index ---> Current index in data[]
r ---> Size of a combination to be printed */
void combinationUtil(vector<char> arr, ll data[],
                    ll start, ll end,
                    ll index, ll r, vector<vector<char>> &ans)
{
    // Current combination is ready
    // to be printed, print it
    if (index == r)
    {
        vector<char> dum(r);
        for (ll j = 0; j < r; j++)
            dum[j] = data[j];
        ans.pb(dum);
        return;
    }
 
    // replace index with all possible
    // elements. The condition "end-i+1 >= r-index"
    // makes sure that including one element
    // at index will make a combination with
    // remaining elements at remaining positions
    for (ll i = start; i <= end &&
        end - i + 1 >= r - index; i++)
    {
        data[index] = arr[i];
        combinationUtil(arr, data, i+1,
                        end, index+1, r, ans);
    }
}
void solve(){
    ll n, k;
    cin>>n>>k;
    string a, b;
    cin>>a>>b;
    map<char, ll> m;
    vector<char> v;
    for(ll i = 0; i < n; i++){
        if(a[i] != b[i]){
            if(m[a[i]] == 0){
                v.pb(a[i]);
            }
            m[a[i]]++;
        }
    }
    vector<vector<char>> per = printCombination(v, v.size(), min(k, (ll)v.size()));
    // for(ll i = 0; i < per.size(); i++){
    //     cout<<per[i].size()<<"\n"; for(ll j = 0; j<per[i].size(); j++) cout<<per[i][j]<<' ';
    //     cout<<'\n';
    // }
    ll ans = 0;
    // cout<<per.size()<<'\n';
    for(ll i = 0; i<per.size(); i++){
        ll ans2 = 0;
        unordered_map<char, ll> m1;
        for(ll j = 0; j<per[i].size(); j++){
            m1[per[i][j]]++;
            // cout<<per[i][j];
        }
        ll trail = 0;
        for(ll j = 0; j<n; j++){
            if(a[j] == b[j] || m1.find(a[j]) != m1.end()){
                trail++;
                ans2 += trail;
            }
            else trail = 0;
        }
        ans = max(ans, ans2);
    }
    cout<<ans<<'\n';
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