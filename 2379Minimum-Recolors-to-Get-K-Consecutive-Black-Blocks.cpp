#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            //brute O(n*k)
            int n=blocks.size();
            int result=INT_MAX;
            for(int i=0;i<=n-k;i++){
                int w=0;
                for(int j=i;j-i+1<=k;j++){
                    if(blocks[j]=='W'){
                        w++;
                    }
                }
                result=min(result,w);
            }
            return result;
        }
    };

// ____________________________________________________________
class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            //optimal sliding window O(n)
            int n=blocks.size();
            int result=INT_MAX;
            int w=0;
            int i=0;
            int j=0;
            while(j<n){
                if(blocks[j]=='W'){
                    w++;
                }
                if(j-i+1==k){
                    result=min(result,w);
                    if(blocks[i]=='W'){
                        w--;
                    }
                    i++;
                }
                j++;
            }
            return result;
        }
    };