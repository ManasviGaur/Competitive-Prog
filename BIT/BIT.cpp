class BIT{ //1-based indexing
    int n, val;
    //if todo = multiply, val should be 1, if todo = min(), val should be inf, if todo = add or max, val = 0
    vector<int> bit;
public:
    BIT(int _n, int _val){
        n = _n;
        val = _val;
        bit.assign(n + 1, val);
    }
    BIT(vector<int> a, int _val){ // a should be in 1-based indexing
        n = a.size() - 1;
        val = _val;
        bit = a;
        for (int i = 1; i <= n; i++){
            int p = i + (i & -i); //index to parent
            if (p <= n)
                bit[p] = todo(bit[p], bit[i]);
        }
    }
    int todo(int a, int b) { return (a + b); }
    void update(int i, int delta){ //if todo is addition, delta = new val - old val
        for (; i <= n; i += (i & -i))
            bit[i] = todo(bit[i], delta);
    }
    int get(int i){
        int res = val;
        for (; i; i -= (i & -i))
            res = todo(res, bit[i]);
        return res;
    }
};