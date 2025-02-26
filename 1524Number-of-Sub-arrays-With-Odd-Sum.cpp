#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int numOfSubarrays(vector<int>& arr) {
            int n = arr.size();
            vector<int> prefix(n, 0);
            int M = 1e9 + 7;
    
            prefix[0] = arr[0];
            for (int i = 1; i < n; i++) {
                prefix[i] = prefix[i - 1] + arr[i];
            }
    
            int count = 0;
            int even = 1;
            int odd = 0;
    
            for (int i = 0; i < n; i++) {
                if (prefix[i] % 2 == 0) {
                    count = (count + odd) % M; // even + odd = odd
                    even++;
                } else {
                    count = (count + even) % M; // odd + even =odd
                    odd++;
                }
            }
            return count;
        }
    };