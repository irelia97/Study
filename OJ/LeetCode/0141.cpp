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
    bool hasCycle(ListNode *head) {
        ListNode *lp = head;
        ListNode *fp = head;
        while( fp && fp->next ){
            lp = lp->next;
            fp = fp->next->next;
            if( lp == fp )
                return true;
        }
        return false;
    }
};
