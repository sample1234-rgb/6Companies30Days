int evalRPN(vector<string>& tokens){
    stack<int> st;
    for(string t:tokens){
        if(t == "+" || t == "-" || t == "*"  || t == "/"){
            int t1 = st.top();
            st.pop();
            int t2 = st.top();
            st.pop();
            if(t == "+")
                st.push(t1+t2);
            else if(t == "-")
                st.push(t2-t1);
            else if(t == "*")
                st.push(t1*t2);
            else
                st.push(t2/t1);
        }
        else
            st.push(stoi(t));
    }
    return st.top();
}
