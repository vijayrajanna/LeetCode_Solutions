/*
 * [66] Plus One
 *
 * https://leetcode.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (39.99%)
 * Total Accepted:    294.4K
 * Total Submissions: 736.1K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty array of digits representing a non-negative integer, plus
 * one to the integer.
 * 
 * The digits are stored such that the most significant digit is at the head of
 * the list, and each element in the array contain a single digit.
 * 
 * You may assume the integer does not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3]
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,3,2,1]
 * Output: [4,3,2,2]
 * Explanation: The array represents the integer 4321.
 * 
 * 
 */
class Solution {
public:
vector<int> plusOne(vector<int>& digits) {

	vector<int> answer;
	int sum = 0;
	int carry = 0;
	bool first = true;

	for (int i = (digits.size()-1); i > -1; i--)
	{
		if (first)
		{
			sum = digits[i] + carry + 1;
			first = false;
		}
        else
        {
		    sum = digits[i] + carry;
        }
		carry = sum / 10;
		answer.push_back(sum % 10);
	}
    if(carry)
    answer.push_back(carry);
    
	reverse(answer.begin(), answer.end());
	return answer;
}
    
};
