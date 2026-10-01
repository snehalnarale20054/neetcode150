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
        int len=0;
        ListNode*temp=head;
        

        //Find the length of the linked list
        while(temp!=NULL){
            len++;
            temp=temp->next;
            
        }
        //If the first node needs to be deleted
        if(len==n){
            return head->next;
        }

        //Find the position before the node to delete
        int pos=len-n;
        temp=head;

        // Move temp to the node just before the node that needs to be deleted
        // must start from i=1 and not from i=0
        for(int i=1;i<pos;i++){
            temp=temp->next;


        }
        //Delete the nth node from the end
        temp->next=temp->next->next;
        return head;
        
    }
    
};
