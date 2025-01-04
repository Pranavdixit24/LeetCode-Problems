class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //TC O(n+m) n is the length of nums2 and m is the length of nums1. 
        stack<int> st;
        unordered_map<int,int> mp;
        vector<int> result;
        for(int i=nums2.size()-1;i>=0;i--){
            int current=nums2[i];

            while(!st.empty() && st.top()<=current){
                st.pop();
            }
            if(!st.empty()){
                mp[current]=st.top();
            }
            else{
                mp[current]=-1;
            }
            st.push(current);
        }
        for(auto num:nums1){
            result.push_back(mp[num]);
        }
        return result;
    }
};