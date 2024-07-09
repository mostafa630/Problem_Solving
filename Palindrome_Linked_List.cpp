//----------------------------------> بسم الله <------------------------------------------//
//problem link : https://leetcode.com/problems/palindrome-linked-list/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode*left ;
    bool solve(ListNode* head)
    {
        if(head==nullptr)
            return true;
        bool result = solve(head->next) && (left->val == head->val);
        left = left->next;
        return result;
    }
public:
    bool isPalindrome(ListNode* head) {
        left=head;
        return solve(head);
        
    }
};