/*
 * [776] N-ary Tree Postorder Traversal
 *
 * https://leetcode.com/problems/n-ary-tree-postorder-traversal/description/
 *
 * algorithms
 * Easy (61.89%)
 * Total Accepted:    10.7K
 * Total Submissions: 17.3K
 * Testcase Example:  '{"$id":"1","children":[{"$id":"2","children":[{"$id":"5","children":[],"val":5},{"$id":"6","children":[],"val":6}],"val":3},{"$id":"3","children":[],"val":2},{"$id":"4","children":[],"val":4}],"val":1}'
 *
 * Given an n-ary tree, return the postorder traversal of its nodes' values.
 * 
 * 
 * For example, given a 3-ary tree:
 * 
 * 
 * 
 * 
 * Return its postorder traversal as: [5,6,3,2,4,1].
 * 
 * 
 * Note: Recursive solution is trivial, could you do it iteratively?
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    
    
vector<int> postorder(Node* root) {

	stack<Node*> holder;
	vector<int> ans;

	if (root)
	{
		holder.push(root);

		while (!holder.empty())
		{
			Node* temp = holder.top();
			holder.pop();
			int size = temp->children.size();
			int i = 0;

			while (i < size)
			{
				holder.push(temp->children[i]);
				i++;
			}

			ans.push_back(temp->val);
		}
	}

	reverse(ans.begin(), ans.end());
	return ans;
}
    
};
