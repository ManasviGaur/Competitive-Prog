class disjointSet {
    private:
        vector<int> parent, rank, setSize;
        //parent: path toward root of disjoint_set OR parent of every element in disjoint set
        //rank: upper bound of the actual height of the tree; not reliable as actual measure
        //setSize = size of each disjoint set
        int numSets;
    public:
        disjointSet(int n){
            setSize.assign(n, 1);
            numSets = n;
            for(int i=0; i<n; i++) parent.push_back(i);
            rank.assign(n, 0);
        }

        int findParent(int node){
            if(parent[node] != node){
                parent[node] = findParent(parent[node]);
            }
            return parent[node];
        }

        void dsu(int i, int j){
            int id_i = findParent(i);
            int id_j = findParent(j);
            if(id_i == id_j) return;
            numSets--;
            if(rank[id_i] < rank[id_j]){
                parent[id_i] = id_j;
                setSize[id_j] += setSize[id_i];
            }
            else{
                parent[id_j] = id_i;
                setSize[id_i] += setSize[id_j];
                if(rank[id_i] == rank[id_j])
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
