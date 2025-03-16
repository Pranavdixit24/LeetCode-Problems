class Solution {
    public:
        typedef long long ll;
        bool isPossible(vector<int>& ranks, int cars, ll mid) {
            ll carsFixed = 0;
            for (int i = 0; i < ranks.size(); i++) {
                carsFixed += sqrt(mid / ranks[i]); // ignoring tc of sqrt
            }
            return carsFixed >= cars;
        }
        long long repairCars(vector<int>& ranks, int cars) {
            // TC O(n * log(maxR * cars * cars))
            ll l = 1;       //min in range of search space /least time
            ll maxR = *max_element(ranks.begin(), ranks.end());
            ll r = maxR * cars * cars;  //max in range of search space /max time
            ll result = -1;
            while (l <= r) { // O(maxR * cars * cars)
                ll mid = l + (r - l) / 2;
    
                if (isPossible(ranks, cars, mid) == true) { // O(n)
                    result = mid;
                    r = mid - 1; //try to minimize more by  reducing search space by moving r to mid-1
                } else {
                    l = mid + 1;
                }
            }
            return result;
        }
    };