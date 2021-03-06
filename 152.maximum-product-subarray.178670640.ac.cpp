/*
 * [152] Maximum Product Subarray
 *
 * https://leetcode.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (27.55%)
 * Total Accepted:    163.2K
 * Total Submissions: 592.3K
 * Testcase Example:  '[2,3,-2,4]'
 *
 * Given an integer array nums, find the contiguous subarray within an array
 * (containing at least one number) which has the largest product.
 * 
 * Example 1:
 * 
 * 
 * Input: [2,3,-2,4]
 * Output: 6
 * Explanation: [2,3] has the largest product 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-2,0,-1]
 * Output: 0
 * Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 * 
 */
class Solution {
public:
int maxProduct(vector<int>& nums) 
{
	if (!nums.size()) return 0;
	int maxProd = nums[0];
	int minProd = nums[0];
	int ans = nums[0];

	for (int i = 1; i < nums.size(); i++)
	{
		int a = maxProd * nums[i];
        int b = minProd * nums[i];
    
        maxProd = max(nums[i], max(a,b));
        
		minProd = min(nums[i], min(a,b));
		
        ans = max(ans, maxProd);
	}
	return ans;
}
    
};
