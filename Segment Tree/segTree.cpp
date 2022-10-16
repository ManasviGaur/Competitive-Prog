#include <bits/stdc++.h>
using namespace std;

class segTree{ // 0-based indexing, 2n space
    vector<int> tree;
    int val, n;
public:
    segTree(int _n, int _val){n = _n; val = _val; tree.assign(2*n, val);}
    segTree(vector<int> a, int _val){
        n = a.size(); val = _val; tree.resize(2*n);
        for(int i = 0; i < n; i++) tree[i+n] = a[i];
        for(int i = n-1; i > 0; i--)
            tree[i] = todo(tree[2*i], tree[2*i + 1]);
    }
    int todo(int x, int y){ return (x + y);}
    void update(int i, int newVal){
        i += n; tree[i] = newVal; int curr;
        while(i > 0){
            i /= 2, curr = todo(tree[2*i], tree[2*i+1]);
            if(curr != tree[i]) tree[i] = curr; else return;
        }
    }
    int query(int from, int to){  // from is inclusive, to is exclusive
        from += n, to += n;
        int curr = val;
        while(from < to){
            if(from & 1) curr = todo(curr, tree[from++]);
            if(to&1) curr = todo(curr, tree[--to]);
            from /= 2, to /= 2;
        }
        return curr;
    }
};

class segTree { //1-based indexing
    int n, VAL;
    vector<int> tree;
    public:
    segTree(int _n, int val) {
        n = _n;
        VAL = val;
        tree.assign(2*n+2, VAL);
    }
    int todo(int a, int b) { return max(a, b); }
    void update(int i, int x) {
        for(tree[i += n] = x; i > 1; i >>= 1)
            tree[i >> 1] = todo(tree[i], tree[i^1]);
    }
    int query(int l, int r) { // both l and r are inclusive
        int res = VAL;
        for(l += n, r += n+1; l<r; l >>= 1, r >>= 1) {
            if(l & 1) res = todo(res, tree[l++]);
            if(r & 1) res = todo(res, tree[--r]);
        }
        return res;
    }
};

template <typename T, class F = function<T(const T&, const T&)>>
class SegTree {
	int n;
	T VAL;
	vector<T> tree;
	F todo;
public:
	SegTree(int n, int VAL, const F& todo) {
		this->n = n;
		this->VAL = VAL;
		tree.assign(2 * n + 2, VAL);
		this->todo = todo;
	}
	void update(int i, T x) {
		for (tree[i += n] = x; i > 1; i >>= 1)
			tree[i >> 1] = todo(tree[i], tree[i ^ 1]);
	}
	T get(int l, int r) {
		T res = VAL;
		for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
			if (l & 1) res = todo(res, tree[l++]);
			if (r & 1) res = todo(res, tree[--r]);
		}
		return res;
	}
};
