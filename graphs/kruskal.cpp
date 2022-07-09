class disjointSet{
private:
    vector<int> parent, rank, setSize;
    int numSets;
public:
    disjointSet(int n){
        setSize.assign(n, 1);
        numSets = n;
        for (int i = 0; i < n; i++)
            parent.push_back(i);
        rank.assign(n, 0);
    }
    int findParent(int node){
        if (parent[node] != node){
            parent[node] = findParent(parent[node]);
        }
        return parent[node];
    }
    void dsu(int i, int j){
        int id_i = findParent(i);
        int id_j = findParent(j);
        if (id_i == id_j)
            return;
        numSets--;
        if (rank[id_i] < rank[id_j]){
            parent[id_i] = id_j;
            setSize[id_j] += setSize[id_i];
        }
        else{
            parent[id_j] = id_i;
            setSize[id_i] += setSize[id_j];
            if (rank[id_i] == rank[id_j])
                rank[id_i]++;
        }
        return;
    }
    int countDisjointSets(){
        return numSets;
    }
    int sizeOfSet(int node){
        return setSize[findParent(node)];
    }
};

class graph{
public:
    vector<pair<int, pair<int, int>>> edg;
    int m, n;
    graph(int n1, int m1){
        m = m1;
        n = n1;
    }
    void addEdge(int u, int v, int w){
        edg.push_back({w, {u, v}});
    }
    vector<pair<int, pair<int, int>>> kruskal(){
        disjointSet ds(n);
        sort(all(edg));
        int size = 0;
        vector<pair<int, pair<int, int>>> res;
        for (int i = 0; i < m; i++){
            int u = edg[i].second.first, v = edg[i].second.second;
            if (ds.findParent(u) != ds.findParent(v)){
                ds.dsu(u, v);
                res.push_back(edg[i]);
                size++;
            }
            if (size == n - 1)
                break;
        }
        return res;
    }
};