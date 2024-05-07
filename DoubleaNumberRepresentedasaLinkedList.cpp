//Approach - 1 Recursion

class Solution {
public:
    int doubleAll(ListNode*&head){
        if(head==NULL)return 0;
        int carry  = doubleAll(head->next);
        int newVal = (head->val)*2 + carry;
        head->val = newVal%10;
        return newVal/10;
    }
    ListNode* doubleIt(ListNode* head) {
     int lastCarry = doubleAll(head);
     if(lastCarry>0){
        ListNode*newHead = new ListNode(lastCarry);
        newHead-> next = head;
        return newHead;
     }
     return head;
    }
};
//Approach - 2 Reversing LL twice
class Solution {
public:
    ListNode*rev(ListNode*head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode * nexthead = rev(head->next);
        head->next->next = head;
        head->next = NULL;
        return nexthead;
    }
    ListNode* doubleIt(ListNode* head) {
        head = rev(head);
        ListNode* curr = head;
        ListNode* prev = NULL;
        int carry = 0;
        while(curr!=NULL){
            int value = curr->val*2 + carry;
            curr->val = value%10;
            carry = value/10;

            prev = curr;
            curr = curr->next;
        }
        if(carry>0){
            ListNode*newNode = new ListNode(carry);
            prev->next = newNode;
        }
        return rev(head);
    }
};
