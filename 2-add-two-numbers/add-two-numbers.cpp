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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        int s=0;
        int t=0;
        ListNode* l3=nullptr;
        ListNode* tail=nullptr;
        while (l1!=nullptr||l2!=nullptr) {
            int x=0;
            int y=0;
            if (l1!=nullptr)
                x=l1->val;
            if (l2!=nullptr)
                y=l2->val;
            s=x+y+carry;
            t=s%10;
            carry=s/10;
            ListNode* newNode=new ListNode(t);
            if (l3==nullptr) {
                l3=newNode;
                tail=newNode;
            }
            else {
                tail->next=newNode;
                tail=newNode;
            }
            if (l1!=nullptr)
                l1=l1->next;
            if (l2!=nullptr)
                l2=l2->next;
        }
        if (carry!=0) {
            ListNode* newNode=new ListNode(carry);
            if (l3==nullptr) {
                l3=newNode;
            }
            else {
                tail->next=newNode;
            }
        }
        return l3;
    }
};