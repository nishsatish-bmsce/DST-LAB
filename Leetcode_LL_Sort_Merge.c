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

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    //Merge
    struct ListNode* last;    
    struct ListNode* temp1;
    struct ListNode* whatToReturn;
    if(list1 == NULL && list2 == NULL) {
        return list1;
    } else if(list1 == NULL && list2 != NULL) {
        return sortIt(list2);
    } else if(list1 != NULL && list2 == NULL) {
        return sortIt(list1);
    } else {
        last = list1;
        while(last->next != NULL) {
            last = last->next;
        }
        last->next = list2;
        return sortIt(list1);
    }
}
