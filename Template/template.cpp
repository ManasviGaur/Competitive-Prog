#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <iomanip>
#include <tuple>
#include <list>
#include <bitset>
#include <queue>
#include <deque>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <chrono>
#include <stack>
#include <functional>
#include <utility>
#include <numeric>

using namespace std;
 
/******************************MACROS******************************/
 
#define int long long
#define ld long double
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define vt vector
#define pb push_back
#define F first
#define S second
#define u_s unordered_set
#define u_m unordered_map
#define p_q priority_queue
#define all0(x) memset((x), 0, sizeof((x)))

/*****************************DEBUGGING*TEMPLATE******************************/
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifndef ONLINE_JUDGE
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define deb(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

/******************************ALGORITHMS******************************/
int __pow(int x, int y, int m) {int res = 1;while(y>0){if(y&1) res = (res*x)%m; y>>=1; x = (x*x)%m;}return res%m;}
int __pow(int x, int y) {int res = 1;while(y>0){if(y&1) res = (res*x); y>>=1; x = (x*x);}return res;}
int gcd(int a, int b) {if(b==0) return a; return gcd(b, a % b);}
int mi(int x, int M) { return __pow(x,M-2, M);}
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b){return (a.second < b.second);}

/******************************main*code******************************/
 
const int N = 2e5+1, inf = 1e17, M = 1e9 + 7;
int test, n, m, k, query;
void solve(){
    
}

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    test = 1;
    cin >> test;
    for(int i = 1; i <= test; i++){
        //cout << "Case #" << i << ": ";
        solve();
    }
    // #ifndef ONLINE_JUDGE
    //     cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
    // #endif
    return 0;
}
