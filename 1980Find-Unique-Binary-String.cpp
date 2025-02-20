#include<bits/stdc++.h>
using namespace std;


//approach 1
class Solution {
    public:
        string findDifferentBinaryString(vector<string>& nums) {
            unordered_set<int> st;
            int n=nums.size();
            string str="";
            for(auto num:nums){
                st.insert(stoi(num,0,2));
            }
    
            for(int num=0;num<=n;num++){
                if(st.find(num)==st.end()){
                    str=bitset<16> (num).to_string();
                    return str.substr(16-n,n);
                }
            }
            return str;
    
        }
    };

//approach 2
class Solution {
    public:
        string findDifferentBinaryString(vector<string>& nums) {
            int n=nums.size();
            string str="";
            
            for(int i=0;i<n;i++){
                char ch=nums[i][i];
    
                str+=ch=='0'?'1':'0';
            }
            return str;
    
        }
    };