stack<int> st;
unordered_map<int,bool> mp;

unordered_map<int,bool> create_map(vector<int> temp){
    unordered_map<int,bool> mp1;
    for(int num: temp)
        mp1[num] = true;
    return mp1;
}

bool check(vector<int> temp, vector<vector<int>> store){
    unordered_map<int,bool> p1 = create_map(temp);
    int sz = p1.size();
    for(vector<int> i: store){
        int cnt = 0;
        for(int j: i){
            if(p1.find(j) != p1.end())
                cnt++;
        }
        if(cnt == sz)
            return false;
    }
    return true;
}

void solve(vector<vector<int>>& store, int n, int k, int i){
    if(n < 0 || k < 0)
        return;
    else if(n == 0){
        if(k != 0)
            return;
        else{
            // do Stuff
            vector<int> temp2;
            stack<int> temp;
            while(!st.empty()){
                int t = st.top();
                temp2.push_back(t);
                temp.push(t);
                st.pop();
            }
            // check fn
            if(check(temp2, store))
                store.push_back(temp2);
            while(!temp.empty()){
                int t = temp.top();
                st.push(t);
                temp.pop();
            }
            return;
        }
    }
    else{
        for(int j = 1; j <= 9; j++){
            if(j != i && !mp[j]){
                // up (j)
                mp[j] = true;
                st.push(j);

                solve(store, n-j, k--, j);

                // down (j)
                st.pop();
                mp[j] = false;
            }
        }
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    for(int i=1; i <= 9; i++)
        mp[i] = false;
    vector<vector<int>> store;
    for(int j = 1; j <= 9; j++){
        // up (j)
        mp[j] = true;
        st.push(j);

        solve(store, n-j, k--, j);

        // down (j)
        st.pop();
        mp[j] = false;
    }
    return store;
}
