// LeetCode -> 1669. Merge In Between Linked Lists
https://leetcode.com/problems/merge-in-between-linked-lists/description/


class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {

        ListNode* dummy = new ListNode(-1) ;
        dummy -> next = list1 ;
        
        ListNode* removeSt = dummy ;
        ListNode* removeEnd = dummy ;

        int i=-1, j=-1 ;
        while(i<(a-1)){
            if(removeSt -> next) removeSt = removeSt -> next ; 
            if(removeEnd-> next) removeEnd = removeEnd-> next ;
            i++, j++ ;
        }

        while(j<b){
            if(removeEnd-> next) removeEnd = removeEnd-> next ;
            j++ ;
        }

        ListNode* tail2 = list2 ;
        while(tail2 -> next != NULL){
            tail2 = tail2 -> next ;
        }

        removeSt -> next = list2 ;
        tail2 -> next = removeEnd -> next ;
        removeEnd -> next = NULL ;

        return dummy -> next ;
    }
};