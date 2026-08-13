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
        ListNode *prev = nullptr, *next;
        while ( head ) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }

    void reorderList(ListNode* head) {
        if ( head == nullptr || head->next == nullptr ) return;
        ListNode *slow = head, *fast = head->next->next, *left, *right, *leftNext, *rightNext;

        while ( fast && fast->next ) {
            slow = slow->next;
            fast = fast->next->next;
        }

        left = head;
        right = reverse(slow->next);
        slow->next = nullptr;

        while ( left && left->next ) {
            leftNext = left->next;
            rightNext = right->next;
            right->next = nullptr;
            left->next = right;
            right->next = leftNext;
            left = leftNext;
            right = rightNext;
        }

        left->next = right;
    }
};
