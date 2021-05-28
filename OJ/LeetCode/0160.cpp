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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pa = headA, * pb = headB;
        while( pa != pb ){
            pa = (pa ? pa->next : headB);
            pb = (pb ? pb->next : headA);
        } 
        return pa;
    }
    
//    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//        if( !headA || !headB )
//            return nullptr;
//        unordered_set<ListNode*> s;
//        while( headA || headB ){
//            if( headA ){
//                if( s.insert(headA).second == false ) return headA;
//                headA = headA->next;
//            }
//            if( headB ){
//                if( s.insert(headB).second == false ) return headB;
//                headB = headB->next;
//            }
//        }
//        return nullptr;
//    }
};
