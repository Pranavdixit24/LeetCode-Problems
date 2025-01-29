#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int u,int v,unordered_map<int,vector<int>> adj,vector<bool>&visited){
        visited[u]=true;

        if(u==v) return true;

        for(auto ngbr:adj[u]){
            if(visited[ngbr]) continue;

            if(dfs(ngbr,v,adj,visited)) return true;
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        //TC O(n^2) worst case O(n) for loop O(n) dfs wc will visit every node
        //SC O(n)
        int n=edges.size();
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<n;i++){ 
            int u=edges[i][0];
            int v=edges[i][1];

            vector<bool>visited(n,false);
            if(adj.find(u)!=adj.end() && adj.find(v)!=adj.end() && dfs(u,v,adj,visited)){
                return edges[i];
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }
};