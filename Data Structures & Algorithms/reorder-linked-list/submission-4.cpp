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
        
     // 1) tæl noderne
    int n = 0;
    ListNode* curr = head;
    while (curr != nullptr)
    {
        n++;
        curr = curr->next;
    }

    // 2) gå til sidste node i første halvdel (med en ekstra pointer)
    ListNode* mid = head;
    for (int i = 0; i < (n - 1) / 2; i++)
    {
        mid = mid->next;
    }

    // 3) skær listen over
    ListNode* second = mid->next;   // starten af anden halvdel
    mid->next = nullptr;            // første halvdel slutter her
    

    ListNode* prev = nullptr;
    curr = second;

    while (curr != nullptr)
    {
        ListNode* next=curr->next; //gem det næste tal listen peger på
        curr->next=prev; //det current skal pege på er den forige
        prev=curr; //den nye prev bliver nu vores current
        curr=next; //den nye current bliver vores next

    }

    second = prev;  // prev er nu starten på den vendte liste

    while (second != nullptr)
    {
        ListNode* temp1 = head->next;     // gem næste i første liste
        ListNode* temp2 = second->next;   // gem næste i anden liste

        head->next = second;              // head peger på second
        second->next = temp1;             // second peger på head's gamle næste

        head = temp1;                     // ryk begge frem
        second = temp2;
    }



    }
};
