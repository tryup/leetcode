class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        auto cnt = nums.size();
        if( cnt <=1)
            return false;
        sort(nums.begin(),nums.end());
        for( int i =  1; i< cnt ; ++i )
        {
            if( nums[i] == nums[i-1])
                return true;
        }
        return false;
    }
};