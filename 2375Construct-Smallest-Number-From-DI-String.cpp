#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        //TC O(n+1!*n)==> O(permutation of n+1 size*for each we r checking pattern of size n)
        
        bool MatchesPattern(string num,string pattern){
            for(int i=0;i<pattern.size();i++){
                if(pattern[i]=='I' && num[i]>num[i+1] || pattern[i]=='D' && num[i]<num[i+1]){
                    return false;
                }
            }
            return true;
        }
        string smallestNumber(string pattern) {
            int n=pattern.size();
            string num="";
    
            for(int i=1;i<=n+1;i++){
                num.push_back(i+'0');
            }
    
            while(!MatchesPattern(num,pattern)){
                next_permutation(num.begin(),num.end());
            }
    
            return num;
            
            
        }
    };

// __________________________________________________________________

class Solution {
    public:
        string smallestNumber(string pattern) {
            int n=pattern.size();
            string num="";
    
            int counter=1;
            stack<char> st;
    
            for(int i=0;i<=n;i++){
                st.push(counter+'0');
                counter++;
    
                if(i==n || pattern[i]=='I' ){
                    while(!st.empty()){
                        num+=st.top();
                        st.pop();
                    }
    
                }
            }
            return num;
        }
    };