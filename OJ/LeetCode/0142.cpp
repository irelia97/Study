/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if( !head || !head->next  ) 
            return nullptr;

        ListNode* pl = head->next;
        ListNode* pf = head->next->next;
        while( pf && pf->next && pl!=pf ){
            pl = pl->next;
            pf = pf->next->next;
        }
        if( !pf || !pf->next )
            return nullptr;

        pl = head;
        while( pl != pf ){
            pl = pl->next;
            pf = pf->next;
        }
        return pl;
    }
};
