class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> vec;
        if( nums.size() == 0 || k == 0)
            return vec;
        int nmax = nums[0];
        int nearestpos = 0;
        for(int i = 1; i < k ; ++i )
        {
            if( nmax < nums[i])
            {
                nmax = nums[i];
                nearestpos = i;
            }
        }
        vec.push_back(nmax);

        for(int i = k ; i < nums.size() && i - k >=0; ++i )
        {
            if( nmax > nums[i] && nearestpos + k >i )
            {

            }
            else if( nmax == nums[i ] )
            {
                nearestpos = i;
            }
            else
            {
                nmax = nums[i];
                for(int j = i;j> i-k ; --j)
                {
                    if( nmax < nums[j])
                    {
                        nmax = nums[j];
                        nearestpos = j;
                    }
                }
            }
            vec.push_back(nmax);

        }
        return vec;
    }
};
//标记最近的最大值位置进行优化，由原先300MS=>80MS，说明没有卡数据。