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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        while ( head != nullptr ){
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if ( head == nullptr ) return head;

        ListNode* node = new ListNode(0, reverse(head));
        ListNode* curr = node;
        while ( n > 1 && curr != nullptr ) {
            curr = curr->next;
            n--;
        }
        
        curr->next = curr->next->next;
        return reverse(node->next);
    }
};
