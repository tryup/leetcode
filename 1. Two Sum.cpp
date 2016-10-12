class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> hashtable;
        int nmaxlen = nums.size();
        for( int i = 0 ; i < nmaxlen ;++i )
        {
            auto iter = hashtable.find(target-nums[i]);
            if(  iter != hashtable.end() )
            {
                return { iter->second , i};
            }
            hashtable[nums[i]] = i;
        }
        return {0,0};
    }
};
