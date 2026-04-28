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
    void reorderList(ListNode* head) {
        ListNode* fast = findMid(head);
        fast = reverseLL(fast);


        ListNode* slow = head;
        ListNode* prevfast = fast;
        ListNode* temp = head;

        while(fast != NULL && fast->next != NULL){
            temp = slow;
            slow = slow->next;
            temp->next = fast;
            prevfast = fast;
            fast = fast->next;
            prevfast->next = slow;
        }

    }

    ListNode* reverseLL(ListNode* head){
        ListNode* front = head;
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL){
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        return prev;
    }

    ListNode* findMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};
