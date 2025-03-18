#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:
        bool isNice(int i, int j, vector<int> nums) {
            int mask = 0;
            for (int k = i; k <= j; k++) {
                if ((mask & nums[k]) != 0) {
                    return false;
                }
                mask |= nums[k];
            }
            return true;
        }
        int longestNiceSubarray(vector<int>& nums) {
            // brute O(n^3)
            int n = nums.size();
            int maxLen = 0;
            for (int i = 0; i < n; i++) {
                for (int j = i; j < n; j++) {
                    if (isNice(i, j, nums)) {
                        maxLen = max(maxLen, j - i + 1);
                    } else {
                        break;
                    }
                }
            }
            return maxLen;
        }
    };

    // _____________________________________

    class Solution {
        public:
            int longestNiceSubarray(vector<int>& nums) {
                // brute better O(n^2)
                int n = nums.size();
                int maxLen = 0;
                for (int i = 0; i < n; i++) {
                    int mask = 0;
                    for (int j = i; j < n; j++) {
                        if ((mask & nums[j]) != 0) {
                            break;
                        }
        
                        maxLen = max(maxLen, j - i + 1);
                        mask |= nums[j];
                    }
                }
                return maxLen;
            }
        };

        // _____________________________________________

        class Solution {
            public:
                int longestNiceSubarray(vector<int>& nums) {
                    // optimal sliding window O(n)
                    int n = nums.size();
                    int maxLen = 0;
                    int i = 0;
                    int j = 0;
                    int mask = 0;
                    while (j < n) {
                        while ((mask & nums[j]) != 0) { // keep shrinking window
                            mask = mask ^ nums[i];
                            i++;
                        }
            
                        maxLen = max(maxLen, j - i + 1);
                        mask = mask | nums[j];
                        j++;
                    }
                    return maxLen;
                }
            };