
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        // Min heap to store the smallest node first
        priority_queue<ListNode*, vector<ListNode*>,
        function<bool(ListNode*, ListNode*)>> pq(
            [](ListNode* a, ListNode* b) {
                return a->val > b->val;
            }
        );

        // Insert the head of each non-empty list
        for (ListNode* node : lists) {
            if (node != nullptr) {
                pq.push(node);
            }
        }

        // Dummy node simplifies result list construction
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!pq.empty()) {

            // Get the node with the smallest value
            ListNode* smallest = pq.top();
            pq.pop();

            // Attach it to the result list
            tail->next = smallest;
            tail = tail->next;

            // Insert the next node from the same list
            if (smallest->next != nullptr) {
                pq.push(smallest->next);
            }
        }

        return dummy.next;
    }
};

