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
        vector<ListNode*> kopi;

        ListNode* curr = head;
        while (curr != nullptr)
        {
            kopi.push_back(curr);
            curr = curr->next;
        }

        int len = kopi.size();

        if (n == len)            // head skal fjernes
            return head->next;

        kopi[len-n-1]->next = kopi[len-n]->next; // noden før peger forbi den fjernede

        return head;
    }
};
