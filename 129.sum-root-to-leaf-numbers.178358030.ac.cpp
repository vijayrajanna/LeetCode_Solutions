/*
 * [129] Sum Root to Leaf Numbers
 *
 * https://leetcode.com/problems/sum-root-to-leaf-numbers/description/
 *
 * algorithms
 * Medium (39.56%)
 * Total Accepted:    152.8K
 * Total Submissions: 386.2K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf path
 * could represent a number.
 * 
 * An example is the root-to-leaf path 1->2->3 which represents the number
 * 123.
 * 
 * Find the total sum of all root-to-leaf numbers.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * Output: 25
 * Explanation:
 * The root-to-leaf path 1->2 represents the number 12.
 * The root-to-leaf path 1->3 represents the number 13.
 * Therefore, sum = 12 + 13 = 25.
 * 
 * Example 2:
 * 
 * 
 * Input: [4,9,0,5,1]
 * ⁠   4
 * ⁠  / \
 * ⁠ 9   0
 * / \
 * 5   1
 * Output: 1026
 * Explanation:
 * The root-to-leaf path 4->9->5 represents the number 495.
 * The root-to-leaf path 4->9->1 represents the number 491.
 * The root-to-leaf path 4->0 represents the number 40.
 * Therefore, sum = 495 + 491 + 40 = 1026.
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// class Solution {
// public:
    
// int reverse(int n)
// {
//     int sum = 0;
//     while(n)
//     {
//         sum *= 10;
//         sum += n%10;
//         n /= 10;
//     }
    
//     return sum;
// }
// void sumNumbers2(TreeNode* root, int& ans, int curSum, int mult)
// {
// 	if (root)
// 	{
// 		curSum += root->val * mult;

// 		if (!root->left && !root->right) 
//         {
// 		    cout << curSum<< endl;
            
//             int temp = reverse(curSum);
            
//             if(!root->val) temp *= mult;
                
//             ans += temp;
// 			return;
// 		}
// 		sumNumbers2(root->left, ans, curSum, mult*10);
// 		sumNumbers2(root->right, ans, curSum, mult*10);
// 	}
// }

// int sumNumbers(TreeNode* root) 
// {
// 	int ans = 0;
// 	int curSum = 0;
// 	int mult = 1;
// 	sumNumbers2(root, ans, curSum, mult);
// 	return ans;
// }
// };


class Solution {
public:
    int sumNumbers(TreeNode *root) {
        if(!root)
            return 0;
        sum=0;
        DFS(root, 0);
        return sum;
    }
    
    void DFS(TreeNode *&node, int currentSum)
    {
        currentSum=currentSum*10+node->val;
        if(!node->left&&!node->right)
            sum+=currentSum;
        if(node->left)
            DFS(node->left, currentSum);
        if(node->right)
            DFS(node->right, currentSum);
    }
private:
    int sum;
};
