class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.size();
        if(k==n) return true;

        if(k>n) return false;

        vector<int> vec(26,0);
        for(auto ch:s){
            vec[ch-'a']++;
        }
        int oddFreqCount=0;
        for(int i=0;i<26;i++){
            if(vec[i]%2!=0){
                oddFreqCount++;
            }
        }
        return oddFreqCount<=k;
        
    }
};

// Steps of the Approach:

// Edge Case Handling:
// If k equals the size of the string n (k == n), then each character can be its own palindrome (since each will have a frequency of 1). In this case, the answer is true.
// If k is greater than the size of the string (k > n), it is impossible to divide the string into k parts. Hence, the answer is false.
// Frequency Count:
// Count the frequency of each character in the string using a vector vec of size 26 (since there are 26 lowercase English letters).
// Odd Frequency Count:
// Count how many characters have odd frequencies in the string. These odd frequencies are crucial because a valid palindromic arrangement requires at most one odd frequency character for palindromes of odd length.
// Check Feasibility:
// If the number of characters with odd frequencies is less than or equal to k, then it's possible to form k palindromic substrings. This is because each odd frequency can contribute to one palindrome (the middle character), and the rest of the characters can be arranged symmetrically.
// Otherwise, it's not possible to construct k palindromic substrings.
// Time Complexity:

// The time complexity is O(n), where n is the length of the string s, because the code iterates over the string to calculate frequencies and then over the frequency array (of fixed size 26).