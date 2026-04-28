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
        ListNode* dummyNode = new ListNode(0, head);
        ListNode* fast = dummyNode;
        ListNode* slow = dummyNode;

        while(n != 0){
            fast = fast->next;
            n--;
        }

        fast = fast->next;
        while(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* temp = slow->next;
        slow->next = slow -> next -> next;
        delete temp;

        return dummyNode->next;
    }
};
