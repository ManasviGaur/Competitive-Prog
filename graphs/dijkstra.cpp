class graph{
    private:
        int n;
        vector<vector<pair<int, int>>> g;
    public:
        graph(int n1){
            n = n1;
            g.resize(n);
        }
        void addEdge(int u, int v, int w){
            g[u].push_back({v, w});
        }
        vector<int> dijkstra(int s){ // Calculates dist, number of paths, parent(to backtrack path)
            vector<int> dist(n, 1e18+5), cntpaths(n, 0), par(n, -1);
            priority_queue<pair<int, int>> pq;
            dist[s] = 0;
            cntpaths[s] = 1;
            pq.push({-dist[s], s});
            while (pq.size()){
                pair<int, int> p = pq.top();
                pq.pop();
                int u = p.second;
                if(dist[u] != -p.first)
                    continue;
                for (auto [v, w] : g[u]){
                    if(dist[v] > dist[u] + w){
                        dist[v] = dist[u] + w;
                        pq.push({-dist[v], v});
                        par[v] = u;
                        cntpaths[v] = cntpaths[u];
                    }
                    else if(dist[v] == dist[u] + v){
                        cntpaths[v] = (cntpaths[v] + cntpaths[u]) % M;
                    }
                }
            }
            return dist;
        }
};