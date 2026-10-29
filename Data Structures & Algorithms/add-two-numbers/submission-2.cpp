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
        ListNode* dummy = new ListNode(0);   // en falsk start-knude, værdien er ligegyldig
        ListNode* hale = dummy;              // hale peger på den sidste knude i listen
        int mente=0;

        while (l1!=nullptr || l2!=nullptr || mente!=0)
        {
            int sum=mente;
            if (l1!=nullptr) {sum+=l1->val; l1=l1->next;}
            if (l2!=nullptr) {sum+=l2->val; l2=l2->next;}


        ListNode* ny = new ListNode(sum % 10);
        mente=sum/10;
        hale->next = ny;   // den sidste peger på den nye
        hale = ny;         // den nye er nu den sidste  
        }

        return dummy->next;
    }
};
