#include <bits/stdc++.h>
using namespace std;

class Graph{
private:
    int n, timer;
    vector<vector<int>> g, SCCs;
    stack<int> s;
    vector<int> disc, low;
    vector<bool> stackMember;
public:
    Graph(int n1){
        n = n1;
        g.resize(n);
    }
    void addEdge(int u, int v){
        u--, v--;
        g[u].push_back(v);
    }
    void dfs(int node){
        disc[node] = low[node] = ++timer;
        s.push(node);
        stackMember[node] = true;
        
        for(int i: g[node]){
            if(disc[i] == -1){
                dfs(i);
                low[node] = min(low[node], low[i]);
            }else if(stackMember[i]){
                low[node] = min(low[node], disc[i]);
            }
        }
        vector<int> v;
        if(disc[node] == low[node]){
            while(s.top() != node){
                int tmp = s.top();
                v.push_back(tmp);
                stackMember[tmp] = false;
                s.pop();
            }
            int tmp = s.top();
            s.pop();
            stackMember[tmp] = false;
            v.push_back(tmp);
            SCCs.push_back(v);
        }
    }

    vector<vector<int>> scc(){
        timer = 0;
        disc.assign(n, -1);
        low.assign(n, -1);
        stackMember.assign(n, false);
        
        for(int i = 0; i < n; i++){
            if(disc[i] == -1) dfs(i);
        }
        return SCCs;
    }
};