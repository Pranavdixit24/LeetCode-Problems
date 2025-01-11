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
};

// Next Smaller Element (NSE): For each element in the histogram (i.e., each bar), the Next Smaller Element is the index of the next bar with a height smaller than the current bar. If no smaller element exists, the NSE for that element is the length of the array, indicating that the bar can extend until the end.

// Previous Smaller Element (PSE): For each element in the histogram, the Previous Smaller Element is the index of the previous bar with a height smaller than the current bar. If no smaller element exists, the PSE for that element is -1, meaning the bar can extend from the beginning.

// Calculating the Maximum Area: Once we know the NSE and PSE for each bar, the width of the largest rectangle that can be formed with a specific bar as the shortest bar is calculated as:

// width=nse[i]-pse[i]-1

// And the area is:
// area=heights[i]×width




// Time Complexity:
// Finding NSE: O(n) because we traverse the list once and use the stack to manage indices.
// Finding PSE: O(n) for the same reason.
// Calculating Maximum Area: O(n), as we just traverse the list once to compute the area for each bar.
// Thus, the overall time complexity of the algorithm is O(n).

// Space Complexity:
// We use three additional arrays: nse, pse, and a stack, each of size n.
// Space Complexity: O(n).