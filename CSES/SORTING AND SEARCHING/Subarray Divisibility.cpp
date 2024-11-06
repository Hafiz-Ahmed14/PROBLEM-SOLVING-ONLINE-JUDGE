#include<bits/stdc++.h>
using namespace std;
 
//Define start and end marco
#define BISMILLAH ios_base::sync_with_stdio(0);cin.tie(0);
#define ALHAMDULILLAH return 0
#define ll long long
#define pb push_back
#define nl '\n'
 
struct Hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static
        const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
 
 
 
int32_t main()
{
    BISMILLAH
        
    int n; cin >> n;
    vector<int> a(n + 1) , prefix(n + 1);
 
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        prefix[i] = prefix[i - 1] + a[i];
        prefix[i] = prefix[i] % n;
        prefix[i] = (prefix[i] + n) % n;
    } 
 
    ll ans = 0;
 
    unordered_map<int,int,Hash>mp;
    mp[0]++;
    for(int i = 1; i <= n; i++) {
        ans += mp[prefix[i]];
        mp[prefix[i]]++;
    }
 
    cout << ans << nl;
            
    ALHAMDULILLAH;
}