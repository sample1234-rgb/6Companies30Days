int f(vector<int> nums, int i,int n){
    int sum = 0;
    for(int num: nums){
        sum += num*i;
        i = (i+1)%n;
    }
    return sum;
}

int maxRotateFunction(vector<int>& nums) {
    int max_num = -INT_MAX;
    int n = nums.size();
    for(int i=0;i<n;i++){
        max_num = max(max_num,f(nums,i,n));
    }
    return max_num;
}
