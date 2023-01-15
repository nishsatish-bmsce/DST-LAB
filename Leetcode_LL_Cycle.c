/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* sortIt(struct ListNode* beg) {
    int x;
    struct ListNode* temp2;
    struct ListNode* temp1;
    // Check if single element
    if(beg->next == NULL || beg == NULL) {
        return beg;
    }
    temp1 = beg;
    while(temp1->next != NULL) {
        temp2 = temp1->next;
        while(temp2 != NULL) {
            if(temp1->val > temp2->val) {
                x = temp1->val;
                temp1->val = temp2->val;
                temp2->val = x;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return beg;
}

bool hasCycle(struct ListNode *head) {
    struct ListNode *beg;
    beg = sortIt(head);
    struct ListNode *first;
    struct ListNode *second;
    first = beg;
    second = beg->next;
    if(first == NULL || first->next == NULL){
        return false;
    }
    while(first != NULL) {
        first = first->next;
        second = second->next;
        if(first->val > second->val) {
            return true;
        }
    }

    return false;
}
