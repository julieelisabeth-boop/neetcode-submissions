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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy;           // midlertidig kladde-node, aldrig en del af det endelige svar
        ListNode* tail = &dummy;  // dummy er en node så for at få den til at pege på den node skal vi bruge &okay 

    while (list1 != nullptr && list2 != nullptr)   // kør så længe begge lister har noder tilbage
    {
        if ( list1->val <= list2->val)
        {
            tail->next=list1; //hægt list1's nuværende node på enden af resultatet
            list1=list1->next; //ryk list1 videre til dens næste node
        }
        else 
        {
            tail->next=list2;
            list2=list2->next;
        }
        tail = tail->next; ////ryk tail frem, så den igen peger på den sidste (nyeste) node i resultatet
    }
    if (list1 != nullptr)
    {
        tail->next= list1; // det næste halen skal pege på er list 1 fordi her er stadigvæk værdier
    }
    else
    {
        tail->next= list2;
    }
        return dummy.next; //dummy objektet derfor . for at få dens next pointer
    }

    
    /*
    Så når du skriver tail->next = list1;, hægter du ikke kun en node på 
    du hægter hele resten af kæden på i ét hug, fordi den første af de 5 noder allerede peger videre til den næste, 
    som peger videre til den næste, og så videre, helt ud til den sidste
    */
};















