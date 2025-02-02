#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // super brute force TC O(n*3n)===O(n^2) SC O(n)
    bool check(vector<int>& nums) {
        int n=nums.size();
        vector<int> sorted(n);
        for(int r=0;r<=n;r++){
            int idx=0;
            for(int i=r;i<n;i++){
                sorted[idx]=nums[i];
                idx++;
            }
            for(int i=0;i<r;i++){
                sorted[idx]=nums[i];
                idx++;
            }

            //is it sorted;
            bool isSorted=true;
            for(int i=0;i<=n-2;i++){
                if(sorted[i]>sorted[i+1]){
                    isSorted=false;
                    break;
                }
            }

            if(isSorted) return true;
        }
        return false;
    }
};

// ____________________________________________________________

class Solution {
public:
    // better brute O(n^2) SC O(n)
    bool check(vector<int>& nums) {
        int n=nums.size();
        vector<int> sorted=nums;
        sort(sorted.begin(),sorted.end());

        for(int r=0;r<=n;r++){
            bool isSorted=true;
            for(int i=0;i<n;i++){
                if(sorted[i]!=nums[(i+r)%n]){
                    isSorted=false;
                    break;
                }
            }
            if(isSorted) return true;
            
        }
        return false;
    }
};

// ____________________________________________________________
class Solution {
public:
    // Otimal O(n) SC O(1)
    bool check(vector<int>& nums) {
        int n=nums.size();
        int peak=0;
        for(int i=0;i<n;i++){
            if(nums[i]>nums[(i+1)%n]){
                peak++;
            }
        }
        return peak<=1;
    }
};