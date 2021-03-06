/*
 * [108] Convert Sorted Array to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (46.75%)
 * Total Accepted:    203.5K
 * Total Submissions: 435.4K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * Given an array where elements are sorted in ascending order, convert it to a
 * height balanced BST.
 * 
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
 * 
 * Example:
 * 
 * 
 * Given the sorted array: [-10,-3,0,5,9],
 * 
 * One possible answer is: [0,-3,9,-10,null,5], which represents the following
 * height balanced BST:
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
 * 
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
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        if(!nums.size()) return NULL;
    
        return convertBST(nums, 0, nums.size()-1);
        
    }
    
    TreeNode* convertBST(vector<int> nums, int low, int high)
    {
        if(low <= high)
        {
            int mid = low + (high-low)/2;
            
            TreeNode* root = new TreeNode(nums[mid]);
            
            root->left = convertBST(nums, low, mid-1);
            
            root->right = convertBST(nums, mid+1, high);
            
            return root;
        }
        return NULL;
        
       
    }
};
