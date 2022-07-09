
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

/******************************FAST*I/P*O/P******************************/
struct _ENDLINE {	
} _ENDL;

struct FastIO {
	private:
	#ifdef _WIN32
      inline char gcu() {return _getchar_nolock();}
      inline void pcu(char x) {_putchar_nolock(x);}
  #else
      inline char gcu() {return getchar_unlocked();}
      inline void pcu(char x) {putchar_unlocked(x);}
  #endif
	char *bufferi, *bufferll, *bufferLL;
	short imax, llmax, LLmax;
	inline bool valid(char x) {return !isspace(x) && x != EOF;}
	public:
	FastIO(const int32_t a = 11, const int32_t b = 21, const int32_t c = 41): imax(a), llmax(b), LLmax(c) 
		{bufferi = new char[a];bufferll = new char[b];bufferLL = new char[c];}
	void read(int64_t &x) {x = 0;char c;bool neg = false;
		while (true) {c = gcu();if (c == '-') {neg = true;break;} 
		if (c >= '0' && c <= '9') {x = c - '0';	break;}
		}
		while (isdigit(c = gcu())) {x = x * 10 + (c - '0');}
		if (neg) x = -x;
	}
	void read(int32_t &x) {
		x = 0; char c; bool neg = false;
		while (true) {c = gcu();if (c == '-') {neg = true;break;} 
			if (c >= '0' && c <= '9') {x = c - '0';	break;}
		}
		while (isdigit(c = gcu())) {x = x * 10 + (c - '0');}
		if (neg) x = -x;
	}
	void read(__int128 &x) {
		x = 0;char c;bool neg = false;
		while (true) {c = gcu();if (c == '-') {neg = true;break;}
			if (c >= '0' && c <= '9') {x = c - '0';	break;}	}
		while (isdigit(c = gcu())) {x = x * 10 + (c - '0');}
		if (neg) x = -x;
	}
	
	void read(char &x) {while (!valid(x = gcu()));}
	void read(string &s) {
		s.clear();char c;while (!valid(c = gcu())) ;
		s += c;	while (valid(c = gcu())) s += c;
	} 
	template<typename A, typename B> void read(pair<A, B> &p) {read(p.first);read(p.second);}
	template<typename T> FastIO& operator >> (T &x) {read(x);return *this;}
	void print(int64_t n) {int64_t i = llmax;bool neg = false;
		if (n < 0) {neg = true;	n = -n;	}
		do {bufferll[--i] = (n % 10) + '0';n /= 10;}while (n);
		if (neg) bufferll[--i] = '-';
		do {pcu(bufferll[i]);} while (++i < llmax);
	}
	void print(int32_t n) {
		int32_t i = imax;bool neg = false;
		if (n < 0) {neg = true;	n = -n;}
		do {bufferi[--i] = (n % 10) + '0';n /= 10;} while (n);
		if (neg) bufferi[--i] = '-';
		do {pcu(bufferi[i]);} while (++i < imax);
	}
	void print(__int128 n) {int32_t i = LLmax;bool neg = false;
		if (n < 0) {neg = true;	n = -n;}
		do {bufferLL[--i] = (n % 10) + '0';n /= 10;} while (n);
		if (neg) bufferLL[--i] = '-';
		do {pcu(bufferLL[i]);} while (++i < LLmax);
	}
	void print(char c) {pcu(c);}
	void print(const string &s) {for (char i : s) pcu(i);}
	template<typename T> FastIO& operator << (const T &x) {
		print(x);return *this;}
	FastIO& operator << (const _ENDLINE &x) {
		pcu('\n');fflush(stdout);return *this;}
};
FastIO _FR;
#define cin _FR
#define cout _FR
#define endl _ENDL

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
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
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
