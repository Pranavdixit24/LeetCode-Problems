class MinStack {
public:

    stack<long long> st;
    long long mini = LLONG_MAX;

    MinStack() {}
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            mini=val;
        }
        else{
            if(val<mini){
                st.push(2*(long long)val-(long long)mini); //to avoid overflow
                mini=val;
            }
            else{
                st.push(val);
            }

        }
        
    }
    
    void pop() {
        if(st.empty()) return;

        long long top_val=st.top();
        st.pop();

        if(top_val<mini){
            mini=2*(long long)mini-(long long)top_val;//to avoid overflow
        }
    }
    
    int top() {
        if(st.empty()) return -1;
        long long top_val=st.top();
        if(top_val<mini){
            return (int)mini;
        }
        return (int)top_val;//return type int so cast to int
    }
    
    int getMin() {
        return (int)mini;//return type int so cast to int
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */