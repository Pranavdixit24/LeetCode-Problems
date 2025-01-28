#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //TC O(m*n) visiting each cell once 
    vector<vector<int>> directions={{-1,0},{1,0},{0,1},{0,-1}};
    int dfs(int i,int j,vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();

        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==0){
            return 0;
        }

        int fishCount=grid[i][j];
        grid[i][j]=0;

        for(auto dir:directions){
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            fishCount += dfs(i_,j_,grid);

        }
        return fishCount;

    }
    int findMaxFish(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int maxFish=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>0){
                    maxFish=max(maxFish,dfs(i,j,grid));
                }
            }
        }
        return maxFish;
    }
};

// ________________________________________

class Solution {
public:
    //TC O(m*n) visiting each cell once 
    //SC for bfs O(m*n) worst case
    vector<vector<int>> directions={{-1,0},{1,0},{0,1},{0,-1}};
    int bfs(int i,int j,vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();

        queue<pair<int,int>> q;
        q.push({i,j});
        int fishCount=grid[i][j];
        grid[i][j]=0;

        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();

            for(auto dir:directions){
                int i_ = i + dir[0];
                int j_ = j + dir[1];

                if(i_>=0 && j_>=0 && i_<m && j_<n && grid[i_][j_]>0){
                    q.push({i_,j_});
                    fishCount += grid[i_][j_];
                    grid[i_][j_]=0;

                }

            }
        }
        return fishCount;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int maxFish=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>0){
                    maxFish=max(maxFish,bfs(i,j,grid));
                }
            }
        }
        return maxFish;
    }
};