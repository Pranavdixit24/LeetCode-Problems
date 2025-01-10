class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        vector<int> st;
        for(int i=0;i<n;i++){  //O(n)
            if(asteroids[i]>0){
                st.push_back(asteroids[i]);
            }
            else{
                while(!st.empty() && st.back()>0 && st.back()<abs(asteroids[i])){
                    st.pop_back();  //at max n elements stored we pop n O(n)
                }
                if(!st.empty() && st.back()==abs(asteroids[i])){
                    st.pop_back();
                }
                else if(st.empty() || st.back()<0){
                    st.push_back(asteroids[i]);
                }
            }
        }
        return st;
    }
};

// Iterate over all asteroids in the input list:

// If the asteroid is moving to the right (asteroids[i] > 0), simply add it to the stack (st).
// If the asteroid is moving to the left (asteroids[i] < 0):
// Collision loop: Check the stack of right-moving asteroids for potential collisions.
// If the magnitude of the left-moving asteroid is larger than the right-moving one on top of the stack, pop the top of the stack (right asteroid is destroyed).
// If they are equal in magnitude, both asteroids are destroyed (pop the stack).
// If the left-moving asteroid is smaller, stop checking, as it is destroyed.
// After the collision checks, if the stack is empty or contains a left-moving asteroid at the top, push the current left-moving asteroid onto the stack.
// Return the resulting stack after all asteroids have been processed.

// TC O(2n) its not nested n*n at max we can delete in nested every time we do nested iteration
// SC O(n) vector st

