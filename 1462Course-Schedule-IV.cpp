#include<bits/stdc++.h>
using namespace std;

//approach 1
class Solution {
public:
    bool dfs(unordered_map<int,vector<int>>& adj,int src,int dest,vector<bool>& visited){
        visited[src]=true;
        if(src==dest) return true;

        bool isReachable=false;
        for(auto adjNode : adj[src]){
            if(!visited[adjNode]){
                isReachable = isReachable || dfs(adj,adjNode,dest,visited);
            }
        }
        return isReachable;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>> adj; // SC: O(V+E)

        for(auto edge : prerequisites){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v); //u-->v
        }

        int Q=queries.size();
        vector<bool> result(Q);
        // O(Q*(V+E))
        for(int i=0;i<Q;i++){ //TC: O(Q)
            int u = queries[i][0]; //src
            int v = queries[i][1]; //dest

            vector<bool> visited(numCourses,false);
            result[i]=dfs(adj,u,v,visited); //O(V+E)

        }
        return result;


    }
};


//________________________________________________________________ 
//approach 2
class Solution {
public:
    bool dfs(unordered_map<int,vector<int>>& adj,int src,int dest,vector<bool>& visited){
        visited[src]=true;
        if(src==dest) return true;

        bool isReachable=false;
        for(auto adjNode : adj[src]){
            if(!visited[adjNode]){
                isReachable = isReachable || dfs(adj,adjNode,dest,visited);
            }
        }
        return isReachable;
    }
    void preprocess(int n,unordered_map<int,vector<int>>& adj,vector<vector<bool>>&grid){
        for(int u=0;u<n;u++){
            for(int v=0;v<n;v++){
                if(u!=v){
                    vector<bool> visited(n,false);
                    if(dfs(adj,u,v,visited)){
                        grid[u][v]=true;
                    }
                }
            }
        }
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>> adj;

        for(auto edge : prerequisites){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v); //u-->v
        }

        int Q=queries.size();
        vector<bool> result(Q);
        vector<vector<bool>> grid(numCourses,vector<bool>(numCourses,false));
        preprocess(numCourses,adj,grid);
        //TC O(Q *(V+E))
        for(int i=0;i<Q;i++){ 
            int u = queries[i][0]; //src
            int v = queries[i][1]; //dest

            vector<bool> visited(numCourses,false);
            result[i]=grid[u][v]; 

        }
        return result;


    }
};