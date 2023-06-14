#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        int a, k, flag;
        cin>>n;
        vector<int> v;
        for(int i = 0; i<n; i++){
            cin>>a;
            v.push_back(a);
        }
        sort(v.begin(), v.end());
        v.insert(v.begin(), 0);
        // for(auto i:v){
        //     cout<<i<<' ';
        // }
        // cout<<'\n';
        k = n + 1 >> 1;
        while(k){
        int flag = 0;
        for(int i = 1; i<=k; i++){
            if(v[k+i-1]>i){
                k--;
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        break;
        }
        cout<<k<<endl;
    }
    return 0;
}