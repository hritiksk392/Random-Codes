
void update(vector<int> &nums,int i ,int w ,int last, unordered_map <int,int> &mp){ 
     int n = nums.size();
    int total = min(w-1,min(i,n-1-i)) +1;
    mp[nums[i]] += total - max(0,(last - (i-w+1)+1));


}


vector<int> solve(vector<int>& nums, vector<int>& queries, int w) {
    unordered_map <int,int> mp,last;
    vector<int> ans;
    int n= nums.size();

    for(int i=0;i<n;i++){
        last[nums[i]] = INT_MIN;
        mp[nums[i]] = 0;
    }
    for(int i=0;i<n;i++){
        update(nums,i,w,last[nums[i]],mp);
        last[nums[i]]=i;
    }
    for(int j=0;j<queries.size();j++){
        ans.push_back(mp[queries[j]]);
    }

    return ans;



}