#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        int first,second, i, j, flag=0;
        for(i=0; i<nums.size()-1; i++)
        {
            first = nums[i];
            for(j=i+1; j<nums.size(); j++)
            {
                second = nums[j];
                if(first + second == target)
                {
                    flag=1;
                    break;
                }
            }
            if(flag == 1)
            {
                break;
            }
        }

        vector<int> answer = {i,j};
        return answer;
    }
};

int main(void)
{
    vector<int> sample= {2,7,11,15};
    int target = 9;

    Solution solution_ka_object;

    vector<int> answer = solution_ka_object.twoSum(sample, target);
    cout<<answer[0]<<endl<<answer[1];

    return 0;
}
