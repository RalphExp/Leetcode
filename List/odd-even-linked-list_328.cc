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
    ListNode* oddEvenList(ListNode* head) {
        ListNode  odd; // dummy node
        ListNode* odd_ptr = &odd;
        ListNode  even; // dummy node
        ListNode* even_ptr = &even;
        
        int flip = 1;
        while (head) {
            if (flip)
                odd_ptr = odd_ptr->next = head;
            else
                even_ptr = even_ptr->next = head;
            head = head->next;
            flip = !flip;
        }
        odd_ptr->next = even.next;
        even_ptr->next = nullptr;
        return odd.next;
    }
};
