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
    struct cmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if ( lists.empty() ) return nullptr;
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for ( int i = 0; i < lists.size(); i++ ) pq.push(lists[i]);

        ListNode node(0);
        ListNode* curr = &node;

        while ( !pq.empty() ) {
            ListNode* temp = pq.top(); pq.pop();
            curr->next = temp;
            curr = curr->next;

            if ( curr->next ){
                pq.push(curr->next);
            }
        }

        return node.next;
    }
};
