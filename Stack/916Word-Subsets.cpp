class Solution {
public:
    bool isSubset(vector<int>& temp,vector<int>& freq2){
        for(int i=0;i<26;i++){ //O(26)==> O(1)
            if(temp[i]<freq2[i]){
                return false;
            }
        }
        return true;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> result;
        vector<int> freq2(26);
        //O(n *l1)
        for(auto word:words2){ //O(n)
            vector<int> temp(26);

            for(auto ch:word){ //O(l1)
                temp[ch-'a']++;
                freq2[ch-'a']=max(freq2[ch-'a'],temp[ch-'a']);
            }
        }
        // O(m * l2)
        for(auto word:words1){ //O(m)
            vector<int> temp(26);

            for(auto ch:word){ //O(l2)
                temp[ch-'a']++;
            }

            if(isSubset(temp,freq2)==true){
                result.push_back(word);
            }
        }
        return result;
    }
    // TC O(n*l1 m*l2)
    //SC  O(26) ==> O(1)
};

// Step 1: Determine the Maximum Frequency for Each Character in words2

// We iterate through each word in words2 and for each character, update the frequency array freq2 to store the maximum frequency required by any word in words2.
// Step 2: Check if Words in words1 are Universally Matched

// For each word in words1, we check if it contains at least the required frequency of each character from freq2. This is done using a helper function isSubset, which compares the frequency of characters in a word from words1 against the required frequency in freq2.
// Step 3: Add Valid Words to Result

// If a word from words1 meets the conditions, it is added to the result list.