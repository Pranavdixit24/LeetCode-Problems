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

/*Key Observations:
Subarray Minimum Contribution: The idea is to compute how much each element contributes to the sum of minimums for all subarrays in which it is the minimum.
The element arr[i] is the minimum in the subarrays that extend from the previous smaller element to the next smaller element.
For each element arr[i], we need to determine:
PSE[i]: The index of the closest element to the left of arr[i] that is smaller than arr[i].
NSE[i]: The index of the closest element to the right of arr[i] that is smaller than arr[i].
With this, we can compute how many subarrays have arr[i] as their minimum.

Explanation of Code:
Helper Function findNSE:

This function computes the index of the Next Smaller Element for each element in the array.
It uses a monotonic stack to traverse the array from right to left.
For each element, if the stack is not empty and the element at the top of the stack is greater than or equal to the current element, it pops the stack.
After this, the top of the stack will contain the index of the next smaller element.
If no smaller element exists, the index is set to n (out of bounds).
Helper Function findPSEE:

This function computes the index of the Previous Smaller or Equal Element for each element.
It uses a monotonic stack to traverse the array from left to right.
For each element, if the stack is not empty and the element at the top of the stack is greater than the current element, it pops the stack.
After this, the top of the stack will contain the index of the previous smaller or equal element.
If no such element exists, it is set to -1.
Main Function sumSubarrayMins:

Once we have the arrays for PSE and NSE, we calculate the total sum of the minimum values for all subarrays.
For each element arr[i], it contributes to subarrays formed by the left range (pse[i] to i) and right range (i to nse[i]).
The contribution of arr[i] to the total sum is arr[i] * (i - pse[i]) * (nse[i] - i), where:
(i - pse[i]) represents the number of subarrays where arr[i] is the minimum element on the left side.
(nse[i] - i) represents the number of subarrays where arr[i] is the minimum element on the right side.
The result is taken modulo 10^9 + 7.
Time Complexity:
findNSE: O(N) because each element is pushed and popped from the stack at most once.
findPSEE: O(N) because each element is pushed and popped from the stack at most once.
sumSubarrayMins: O(N) because it processes each element once.
Thus, the overall time complexity is O(N).

Space Complexity:
We use two additional arrays (nse and pse) of size N, and a stack for each helper function. Thus, the space complexity is O(N).
*/