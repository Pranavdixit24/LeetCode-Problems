class Solution {
public:
    int countPalindromicSubsequence(string s) {
        //TC O(26*n)=>O(n)
        //SC O(26)
        int n=s.size();
        unordered_set<char> letters;
        int result=0;
        for(auto ch:s){
            letters.insert(ch);
        }

        for(auto letter:letters){ //O(26) worst case
            
            int left_idx=-1;
            int right_idx=-1;

            for(int i=0;i<n;i++){ //O(n)
                if(s[i]==letter){
                    if(left_idx==-1){
                        left_idx=i;
                    }
                    right_idx=i;
                }
            }
            unordered_set<char> st;
            for(int middle=left_idx+1;middle<=right_idx-1;middle++){
                st.insert(s[middle]);
            }
            result+=st.size();
        }

        return result;
    }
};