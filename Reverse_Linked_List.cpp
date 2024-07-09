//----------------------------------> بسم الله <------------------------------------------//
//problem link : https://leetcode.com/problems/reverse-linked-list/
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
public:
    ListNode* reverseList(ListNode* head) {
        if( head==nullptr || head->next ==nullptr )
            return head;
        ListNode* currentNode = head;
        ListNode*nextNode = head->next;
        ListNode*targetNode = reverseList(head->next);
        nextNode->next =currentNode;
        currentNode->next = nullptr;
        return targetNode;
    }
};