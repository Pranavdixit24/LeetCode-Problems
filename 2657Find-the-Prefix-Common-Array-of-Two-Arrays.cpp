#include<bits/stdc++.h>

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        //brute O(n^3)
        int n=A.size();
        vector<int> result(n);

        for(int i=0;i<n;i++){
            int count=0;
            for(int A_i=0;A_i<=i;A_i++){
                for(int B_i=0;B_i<=i;B_i++){
                    if(B[B_i]==A[A_i]){
                        count++;
                        break;
                    }
                }

            }
            result[i]=count;
        }
        return  result;
    }
};

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        //better O(n^2)
        int n=A.size();
        vector<int> result(n);
        vector<char> isPresentA(n+1,'F');
        vector<char> isPresentB(n+1,'F');

        for(int i=0;i<n;i++){
            int count=0;
            isPresentA[A[i]]='T';
            isPresentB[B[i]]='T';

            for(int i=1;i<=n;i++){
                if(isPresentA[i]=='T' && isPresentB[i]=='T'){
                    count++;
                }
            }
            result[i]=count;

        }
        return  result;
    }
};

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        //optimal O(n)
        int n=A.size();
        vector<int> result(n);
        unordered_map<int,int> mpp;
        int count=0;
        for(int i=0;i<n;i++){
            mpp[A[i]]++;
            if(mpp[A[i]]==2){
                count++;
            }
            mpp[B[i]]++;
            if(mpp[B[i]]==2){
                count++;
            }
            result[i]=count;

        }
        return result;
    }
};