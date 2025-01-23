class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        //TC O(m*n)+O(m*n)
        //SC O(m+n)
        int m=grid.size();
        int n=grid[0].size();

        vector<int> rowServerCnt(m,0);
        vector<int> colServerCnt(n,0);

        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1){
                    rowServerCnt[row]++;
                    colServerCnt[col]++;
                }
                    
            }
        }
        int result=0;
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1 && (rowServerCnt[row]>1 || colServerCnt[col]>1) ){
                    result++;
                }
            }
        }
        return result;
    }
};