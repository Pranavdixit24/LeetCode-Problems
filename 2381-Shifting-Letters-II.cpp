class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();
        vector<int> diff(n,0);
        // O(q)
        for(auto query:shifts){
            int L=query[0];
            int R=query[1];
            int dir=query[2];
            int x;

            if(dir==1){
                x=1;
            }
            else{
                x=-1;
            }
            //Difference Array Technique
            diff[L]+=x;

            if(R+1<n){
                diff[R+1]-=x;
            }
        }
        //cummulative sum to find shift in i
        // O(n)
        for(int i=1;i<n;i++){
            diff[i]+=diff[i-1];
        }
        //apply shift
        // O(n)
        for(int i=0;i<n;i++){
            int shift=diff[i] % 26;
            if(shift < 0){
                shift += 26;
            }
            s[i]=(((s[i]-'a') + shift) % 26)+'a';
        }
        return s;
    }
};