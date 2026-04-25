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
        ListNode* kthnode = NULL;
        ListNode* temp = head;
        ListNode* nextnode = NULL;
        ListNode* prevnode = NULL;
        while(temp != NULL){
            kthnode = findKthnode(temp, k);
            if(kthnode == NULL){
                if(prevnode) prevnode->next = temp;
                break;
            }
            nextnode = kthnode->next;
            kthnode->next = NULL;
            ListNode* newhead = reverse(temp);
            if(temp == head){
                head = newhead;
            }
            else{
                prevnode->next = newhead;
            }
            prevnode = temp;
            temp = nextnode;
        }
        return head;
    }
    ListNode* findKthnode(ListNode* head, int k){
        int cnt = 1;
        ListNode* temp = head;
        while(temp != NULL){
            if(cnt == k){
                return temp;
            }
            cnt++;
            temp = temp->next;
        }
        return NULL;
    }

    ListNode* reverse(ListNode* head){
        ListNode* temp = head;
        ListNode* prevnode = NULL;
        ListNode* front = NULL;
        while(temp != NULL){
            front = temp->next;
            temp->next = prevnode;
            prevnode = temp;
            temp = front;
        }
        return prevnode;
    }
};
