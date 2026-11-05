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
    ListNode* reverseKGroup(ListNode* head, int k) {
            ListNode* temp = head;

                    // Check if k nodes are available
                            for (int i = 0; i < k; i++) {
                                        if (temp == NULL) {
                                                        return head;
                                                                    }
                                                                                temp = temp->next;
                                                                                        }

                                                                                                // Reverse k nodes
                                                                                                        ListNode* prev = NULL;
                                                                                                                ListNode* curr = head;

                                                                                                                        for (int i = 0; i < k; i++) {
                                                                                                                                    ListNode* nextNode = curr->next;
                                                                                                                                                curr->next = prev;
                                                                                                                                                            prev = curr;
                                                                                                                                                                        curr = nextNode;
                                                                                                                                                                                }

                                                                                                                                                                                        // Recursively reverse the remaining groups
                                                                                                                                                                                                head->next = reverseKGroup(curr, k);

                                                                                                                                                                                                        return prev;
                                                                                                                                                                                                            }
                                                                                                                                                                                                            };
                                                                                                                                                                                                            
