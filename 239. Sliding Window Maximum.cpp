class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> vec;
        if( nums.size() == 0 || k == 0)
            return vec;
        int nmax = nums[0];

        for(int i = 1; i < k ; ++i )
        {
            if( nmax < nums[i])
            {
                nmax = nums[i];
            }
        }
        vec.push_back(nmax);

        for(int i = k ; i < nums.size() && i - k >=0; ++i )
        {
            nmax = nums[i];
            for(int j = i;j> i-k ; --j)
            {
                if( nmax < nums[j])
                {
                    nmax = nums[j];
                }
            }
            vec.push_back(nmax);
        }
        return vec;
    }
};
