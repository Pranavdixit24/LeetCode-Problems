class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(auto op:s){
            if(op=='(' || op=='[' || op=='{'){
                st.push(op);
            }
            else{
                if(st.empty()){
                    return false;
                }
                char top=st.top();
                st.pop();
                if((op==')' && top!='(') || (op==']' && top!='[') || (op=='}' && top!='{')){
                    return false;
                }
            }
        }
        return st.empty();
    }
};