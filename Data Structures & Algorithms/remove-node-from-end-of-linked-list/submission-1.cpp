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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        head = reverse(head);
        if ( n == 1 ){
            return reverse(head->next);
        }
        ListNode* prev = head;
        ListNode* curr = head;
        while (n > 1 ) {
            prev = curr;
            curr = curr->next;
            n--;
        }

        prev->next = curr->next; 
        return reverse(head);
    }

    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        while ( head != nullptr ) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }
};
