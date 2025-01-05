class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //TC O(4N)
        //SC O(2N)
        int n=nums.size();
        vector<int> nge(n);
        stack<int> st;
        for(int i=2*n-1;i>=0;i--){ //O(2N)
            while(!st.empty() && st.top()<=nums[i%n]){ //O(2N)
                st.pop();
            }
            if(i<n){
                nge[i]=st.empty()?-1:st.top();
            }
            st.push(nums[i%n]); //O(2N)
        }
        return nge;
    }
};