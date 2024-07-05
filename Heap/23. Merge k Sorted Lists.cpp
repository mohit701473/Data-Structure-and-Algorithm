// LeetCode -> 23. Merge k Sorted Lists
https://leetcode.com/problems/merge-k-sorted-lists/description/


/*
Approch -> 1: using the concept of the merge two sorted list
similiar to merge K sorted array approch here u are also processing same nodes so many time and ur time complexcity incresed
*/

// T.C. = O()
class Solution {
public:

    ListNode* mergeTwoList(ListNode* head1, ListNode* head2) {
        ListNode* head = new ListNode(-1);
        ListNode* curr = head;
        
        while(head1 != NULL && head2 != NULL) {
            if(head1 -> val < head2 -> val) {
                curr -> next = head1;
                head1 = head1 -> next;
            } else {
                curr -> next = head2;
                head2 = head2 -> next;
            }
            curr = curr -> next;
        }

        curr -> next = head1 == NULL ? head2 : head1;
        return head -> next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return NULL;
        
        ListNode* head = lists[0];

        for(int i = 1; i < lists.size(); i++) {
            head = mergeTwoList(head, lists[i]);
        }
        
        return head;
    }
};




// T.C. = O(N*K*log(K))
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode(-1);
        ListNode* curr = head;
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;

        for(int i = 0; i < lists.size(); i++) {
            ListNode* node = lists[i];
            if(node != NULL)
                pq.push({node -> val, node});
        }

        while(!pq.empty()) {
            auto p = pq.top();
            pq.pop();

            curr -> next = p.second;

            if(p.second -> next != NULL) {
                pq.push({p.second -> next -> val, p.second -> next});
            }

            curr = curr -> next;
        }

        return head -> next;
    }
};