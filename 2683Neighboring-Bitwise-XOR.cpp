// My method 
class Solution {
public:
    bool check(vector<int>& derived,vector<int>& original){
        int n=derived.size();
        for(int i=0;i<n-1;i++){
            if((original[i]^original[i+1])!=derived[i]){
                return false;
            }
            if((original[n-1]^original[0])!=derived[n-1]){
                return false;
            }
        }
        return true;
    }
    bool doesValidArrayExist(vector<int>& derived) {
        int n=derived.size();
        vector<int> original(n,0);

        if(derived.size()==1 && derived[0]==1) return false;
        if(derived.size()==1 && derived[0]==0) return true;

        for(int i=0;i<n-1;i++){
            original[i+1]=original[i]^derived[i];
        }

        if(check(derived,original)){
            return true;
        }

        original={1};
        for(int i=0;i<n-1;i++){
            original[i+1]=original[i]^derived[i];
        }

        if(check(derived,original)){
            return true;
        }
        return false;


        
    }
};

// Their method
//Approach 1
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {     //property (x^y)=z 
        int n=derived.size();                                    //  (y^z)=x
        vector<int> original(n);                                //   (z^x)=y
        original[0]=0;

        for(int i=0;i<n-1;i++){
            original[i+1]=original[i]^derived[i];
        }

        if(original[0]^original[n-1]==derived[n-1]) return true;

        original[0]=1;
        for(int i=0;i<n-1;i++){
            original[i+1]=original[i]^derived[i];
        }

        if(original[0]^original[n-1]==derived[n-1]) return true;

        return false;
        
    }
};

//Approach 2
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int XOR=0;
        for(int x:derived){
            XOR^=x;
        }
        return XOR==0;
    }
};
// approach
// derived = [1,1,0]
// original={a,b,c}
// {a^b,b^c,c^a} if we xor all  we get 0 so goes with derived it should also be 0 then true 