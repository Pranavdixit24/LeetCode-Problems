class Solution {
public:
    //brute
    int maxScore(string s) {
        int n=s.size();
        int result=INT_MIN;
        for(int i=0;i<=n-2;i++){

            // 0 to i cnt 0??
            int cnt0=0;
            for(int j=0;j<=i;j++){
                if(s[j]=='0'){
                    cnt0++;
                }
            }
            // i+1 to n-1 cnt 1??
            int cnt1=0;
            for(int j=i+1;j<n;j++){
                if(s[j]=='1'){
                    cnt1++;
                }
            }
            result=max(result,cnt0+cnt1);


        }
        return result;
    }
};

//better
class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        int result=INT_MIN;
        int total_one=count(s.begin(),s.end(),'1');
        int left_zero=0;
        int left_one=0;
        for(int i=0;i<=n-2;i++){
            if(s[i]=='0'){
                left_zero++;
            }
            else{
                left_one++;
            }

            int right_one=total_one-left_one;
            result=max(result,left_zero+right_one);
            
        }
        return result;
    }
};

//better/optimal

class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        int score=INT_MIN;
        int zero=0;                                         
        int one=0;
        for(int i=0;i<=n-2;i++){
            if(s[i]=='1'){
                one++;
            }
            else{
                zero++;
            }

            score=max(score,zero-one);     
            
        }
        if(s[n-1]=='1') one++; //since we were iterating till n-2
      
        return score+one;
    }
};

//observation of above 
// score=l_zero+r_one 
// t_one=l_one+r_one
// reaaranging, r_one=t_one-l_one

//score=l_zero+(t_one-l_one)
// score=(l_zer0-l_one)+t_one 
//we need to maximize (l_zer0-l_one)

