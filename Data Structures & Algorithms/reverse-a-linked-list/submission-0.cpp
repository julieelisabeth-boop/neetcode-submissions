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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr; //skal være den nye start og dens next skal pege på en nullpt, så vi sætter den her så vi kan sætte den gamle hoved til at pege på den
        ListNode* curr = head; // current er det smame som head
        ListNode* next;

        while (curr!=nullptr) //køre inditl vi er på den nullptr som tail peger på
        {
            next=curr->next; //det næste node er den current nu peger på
            curr->next=prev; // det current skal pege på er prev, altså vende rentingen fra -> til <-
            prev = curr;  //den nuværende current bliver den næste previous (fordi vi itterer ligersom videre)
            curr = next;  //den nuværende next bliver vores current
        }

        return prev; //fordi vi her allerede er ude over vores noder, da curr er gået for langt (er nullptr), så prev — ét skridt bagved — er den sidste rigtige node, som nu er den nye head."
    }
};
