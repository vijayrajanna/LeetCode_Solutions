/*
 * [673] Number of Longest Increasing Subsequence
 *
 * https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (32.29%)
 * Total Accepted:    22.7K
 * Total Submissions: 70.3K
 * Testcase Example:  '[1,3,5,4,7]'
 *
 * 
 * Given an unsorted array of integers, find the number of longest increasing
 * subsequence.
 * 
 * 
 * Example 1:
 * 
 * Input: [1,3,5,4,7]
 * Output: 2
 * Explanation: The two longest increasing subsequence are [1, 3, 4, 7] and [1,
 * 3, 5, 7].
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [2,2,2,2,2]
 * Output: 5
 * Explanation: The length of longest continuous increasing subsequence is 1,
 * and there are 5 subsequences' length is 1, so output 5.
 * 
 * 
 * 
 * Note:
 * Length of the given array will be not exceed 2000 and the answer is
 * guaranteed to be fit in 32-bit signed int.
 * 
 */
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) 
    {
        if(!nums.size()) return 0;
        vector<int> dp(nums.size(), 1);
        vector<int> ct(nums.size(), 1);
        int maximum = 1;
        int ans = 0;

        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if ((nums[i] > nums[j]))
                {
                    if((dp[j] + 1) > dp[i])
                    {
                        dp[i] = dp[j] + 1;
                        maximum = max(maximum, dp[i]);
                        ct[i] = ct[j];
                    }
                    else if((dp[j]+1) == dp[i])
                    {
                        ct[i] += ct[j];
                    }

                }

            }
        }
        
        for (int i = 0; i < ct.size(); i++)
        {
            if(dp[i] == maximum) ans += ct[i];
        }
        
        return ans;
    }
};
