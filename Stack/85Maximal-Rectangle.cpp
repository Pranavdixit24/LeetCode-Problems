#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    vector<int> findNSE(vector<int>& heights){
        int n=heights.size();
        vector<int> nse(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            nse[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> findPSE(vector<int>& heights){
        int n=heights.size();
        vector<int> pse(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            pse[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return pse;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> nse=findNSE(heights);
        vector<int> pse=findPSE(heights);
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,heights[i]*(nse[i]-pse[i]-1));
        }
        return maxi;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<vector<int>> pfsum(row,vector<int>(col,0));

        for(int j=0;j<col;j++){
            int sum=0;
            for(int i=0;i<row;i++){
                if(matrix[i][j]=='1'){
                    sum+=1;
                }
                else{
                    sum=0;
                }
                pfsum[i][j]=sum;
            }
        }
        int maxArea=0;
        for(int i=0;i<row;i++){
            maxArea=max(maxArea,largestRectangleArea(pfsum[i]));
        }
        return maxArea;
    }
};


// The key steps are:

// Prefix Sum Matrix (pfsum) Construction:

// You treat each column of the matrix as the height of a bar in a histogram. The height of the bar is calculated by accumulating the number of consecutive 1s in each column (starting from the top).
// If you encounter a 0 in the matrix, the height for that column is reset to 0.
// Using the largestRectangleArea Function:

// For each row in the pfsum matrix, you treat that row as the histogram of heights and find the largest rectangle that can be formed using a histogram.
// This problem is efficiently solved using a stack to find the Previous Smaller Element (PSE) and Next Smaller Element (NSE) for each histogram bar. basically largest rectangle that can be formed using a histogram