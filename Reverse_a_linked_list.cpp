//REVERSE A LINKED LIST
//https://leetcode.com/problems/reverse-linked-list/

//MY SOLUTION
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
        ListNode* prev = NULL;
        ListNode* forw = NULL;
        
        while(head!=NULL){
            forw = head->next;
            head->next = prev;
            prev=head;
            head=forw;
        }
        
        return prev;
    }
};