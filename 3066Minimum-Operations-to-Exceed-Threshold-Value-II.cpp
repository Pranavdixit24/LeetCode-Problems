class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            priority_queue<long,vector<long>,greater<long>> pq(nums.begin(),nums.end()); //O(logn)
    
            int count=0;
            //O(n * logn)
            while(!pq.empty() && pq.top()<k){ //O(n)
                long long first=pq.top();
                pq.pop();//O(logn)
    
                long long second=pq.top();
                pq.pop();//O(logn)
    
                pq.push(min(first,second)*2+max(first,second));//O(logn)
                count++;
            }
            return count;
        }
    };