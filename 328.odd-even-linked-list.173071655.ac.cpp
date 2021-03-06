/*
 * [328] Odd Even Linked List
 *
 * https://leetcode.com/problems/odd-even-linked-list/description/
 *
 * algorithms
 * Medium (46.51%)
 * Total Accepted:    114K
 * Total Submissions: 245.1K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given a singly linked list, group all odd nodes together followed by the
 * even nodes. Please note here we are talking about the node number and not
 * the value in the nodes.
 * 
 * You should try to do it in place. The program should run in O(1) space
 * complexity and O(nodes) time complexity.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2->3->4->5->NULL
 * Output: 1->3->5->2->4->NULL
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 2->1->3->5->6->4->7->NULL
 * Output: 2->3->6->7->1->5->4->NULL
 * 
 * 
 * Note:
 * 
 * 
 * The relative order inside both the even and odd groups should remain as it
 * was in the input.
 * The first node is considered odd, the second node even and so on ...
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

ListNode* oddEvenList(ListNode* head) 
{
	
    if (head)
	{
		ListNode* odd = new ListNode(-1);
		ListNode* even = new ListNode(-1);
        
		ListNode* evenref = even;
		ListNode* oddref = odd;

		bool oddnumber = true;

		while (head != NULL)
		{
			if (oddnumber == true)
			{
				odd->next = head;
			    odd = head;
				oddnumber = false;
			}
			else
			{
				    even->next = head;
			        even = head;
				    oddnumber = true;
			}
            
            head = head->next;
		}
        
		// cout << odd->val << endl;
		// cout << even->val << endl;
		// cout << evenref->next->val << endl;
		// cout << oddref->next->val << endl;


        
         odd->next = evenref->next;
         even->next = NULL;
         return oddref->next;
        
        while(head != NULL)
        {
            cout << head->val <<"\t";
            head = head->next;
        }
		
	}
    
	return head;
}
};
