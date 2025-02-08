#include<bits/stdc++.h>
using namespace std;

class NumberContainers {
public:
    unordered_map<int,int> indToNum;
    unordered_map<int,set<int>> numToInd;

    NumberContainers() {
        //do nothing
    }
    
    void change(int index, int number) {
        if(indToNum.count(index)){//O(1)
            int prevNum=indToNum[index];
            numToInd[prevNum].erase(index);//O(logn)
            if(numToInd[prevNum].empty()){
                numToInd.erase(prevNum);//O(1)
            }
        }

        indToNum[index]=number;
        numToInd[number].insert(index);//O(logn)
    }
    
    int find(int number) {
        if(numToInd.count(number)){//O(1)
            return *numToInd[number].begin();//O(1)
        }
        return -1;
    }
};