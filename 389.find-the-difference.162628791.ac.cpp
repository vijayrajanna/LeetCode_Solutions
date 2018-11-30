/*
 * [389] Find the Difference
 *
 * https://leetcode.com/problems/find-the-difference/description/
 *
 * algorithms
 * Easy (51.88%)
 * Total Accepted:    120.6K
 * Total Submissions: 232.5K
 * Testcase Example:  '"abcd"\n"abcde"'
 *
 * 
 * Given two strings s and t which consist of only lowercase letters.
 * 
 * String t is generated by random shuffling string s and then add one more
 * letter at a random position.
 * 
 * Find the letter that was added in t.
 * 
 * Example:
 * 
 * Input:
 * s = "abcd"
 * t = "abcde"
 * 
 * Output:
 * e
 * 
 * Explanation:
 * 'e' is the letter that was added.
 * 
 */
class Solution {
public:
char findTheDifference(string s, string t) 
{
	int indx[256] = {0};
	int i = 0;
	while (i < s.size())
	{
		indx[s[i]]++;
		indx[t[i]]--;
		i++;
	}
	indx[t[i]]--;

	for (int i = 0; i < 256; i++)
	{
		if (indx[i] < 0) return char(i);
	}
}
};
