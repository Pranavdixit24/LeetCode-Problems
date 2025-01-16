// approach 1
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {

        int n1=nums1.size();
        int n2=nums2.size();
        unordered_map<int,long> mpp;

        for(auto num:nums1){
            mpp[num]+=n2;
        }

        for(auto num:nums2){
            mpp[num]+=n1;
        }

        int ans=0;
        for(auto it:mpp){
            int num=it.first;
            int freq=it.second;

            if(freq%2!=0){
                ans=ans^num;
            }
        }
        return ans;
    }
};

// approach 2
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        int ans=0;

        if(n1 % 2 !=0){
            for(auto num:nums2){
                ans^=num;
            }
        }
        if(n2 % 2 !=0){
            for(auto num:nums1){
                ans^=num;
            }
        }
        return ans;

    }
};