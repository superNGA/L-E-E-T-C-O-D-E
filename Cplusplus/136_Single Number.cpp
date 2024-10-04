#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());

        if(nums.size() > 2)
        {
            for(int i=1; i<nums.size(); i+=2)
            {
                if(nums[i] != nums[i-1])
                {
                    return nums[i-1];
                }
            }
        }
        return nums[nums.size()-1];
    }
};

int main(void)
{
    Solution sol;
    vector<int> sample = {2,2,1};

    cout<<sol.singleNumber(sample);

    return 0;
}
