#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        //TC O(n*(n-1)*(n-2)) ====> O(n*n!)
        //SC O(n*n!)+ recursion stack space O(n) length of string is n
        void solve(string& s,string& curr,unordered_set<string>& result,vector<bool>& used){
            result.insert(curr);
    
            for(int i=0;i<s.size();i++){
                if(used[i]){
                    continue;
                }
    
                used[i]=true;
                curr.push_back(s[i]);
    
                solve(s,curr,result,used);
    
                used[i]=false;
                curr.pop_back();
            }
        }
        int numTilePossibilities(string tiles) {
            int n=tiles.size();
    
            unordered_set<string> result;
            vector<bool> used(n,false);
    
            string curr="";
    
            solve(tiles,curr,result,used);
    
            return result.size()-1;
        }
    };