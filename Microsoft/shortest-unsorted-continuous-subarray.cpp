int findUnsortedSubarray(vector<int>& nums) {
    int n = nums.size();
    if(n < 2)
        return 0;
    int i=0,max = INT_MIN,start=-1,end=-1;
    // since the array will be sorted in ascending order so the maximum element will always present
    // at the last position.
    while(i < n){
        if(max > nums[i]){
            // the error point
            if(start == -1)
                start = i-1;
            while(start-1 >= 0 && nums[start-1] > nums[i]){start--;} // second error point
            end = i+1;
        }
        else
            max = nums[i];
        i++;
    }
    return end-start;
}
