class Solution {
public:
    //TC O(5N) SC O(5N)
    #define ll long long 
    vector<int> findNSE(vector<int>& arr){
        int n=arr.size();
        stack<int> st; 
        vector<int> nse(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }

            nse[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> findPSEE(vector<int>& arr){
        int n=arr.size();
        stack<int> st;
        vector<int> psee(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){ //prev smaller or equal element
                st.pop();
            }
            psee[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return psee;
    }
    int sumSubarrayMins(vector<int>& arr) {
        ll n=arr.size();
        vector<int> nse=findNSE(arr); //O(2N),O(2N)
        vector<int> pse=findPSEE(arr); //O(2N),O(2N)
        ll total=0;
        ll mod=1e9+7;
        for(int i=0;i<n;i++){ //O(N)
            ll left=i-pse[i];
            ll right=nse[i]-i;

            total=(total+(right*left*arr[i])%mod)%mod;
        }
        return ((int)total%mod);
    }
};