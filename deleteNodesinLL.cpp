//approach-1 using stack
ListNode* removeNodes(ListNode* head) {
        stack<ListNode*>st;
        ListNode* temp = head;
        while(temp!=NULL){
            st.push(temp);
            temp = temp->next;
        }
        int maxi  = st.top()->val;
        st.pop();
        ListNode * newL = new ListNode(maxi);
        while(!st.empty()){
           int curr = st.top()->val;
           st.pop();
           if(curr>=maxi){
             ListNode * newnode = new ListNode(curr);
             newnode->next = newL;
             newL = newnode;
             maxi = curr;
           }
        }
        return newL;
    }
//approach-2 using recursion

  ListNode* removeNodes(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        ListNode* nextNode = removeNodes(head->next);
        if(head->val<nextNode->val){
            delete head;
            return nextNode;
        }else{
            head->next = nextNode;
        }
        return head;
    }

//approach-3 using reverse LL and then updating LL

class Solution {
public:
    ListNode* reverse(ListNode*head){
      if(head==NULL || head->next==NULL){
        return head;
      }
      ListNode * smallhead = reverse(head->next);
      // 1 2 3 4
                //head->next
      // 4  3   2

      //head
      // 1
      head->next->next = head;
      head->next = NULL;
      return smallhead;
    }
    ListNode* removeNodes(ListNode* head) {
        // if(head==NULL || head->next==NULL)return head;
        head = reverse(head);
        ListNode* curr = head;
        ListNode* prev = NULL;
        int maxi = -1;
        while(curr!=NULL){
            if(curr->val>=maxi){
               maxi = curr->val;
               prev = curr;
               curr = curr->next;
            }else{
                prev->next = curr->next;
                ListNode* temp = curr;
                curr = curr->next;
                temp->next= NULL;
            }
        }
        head = reverse(head);

        return head;

    }
};
