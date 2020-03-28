#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *reverse(struct ListNode *head) {
    struct ListNode *pre = NULL, *cur = head;
    struct ListNode *tmp = NULL;

    while (cur) {
        tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    return pre;
}

struct ListNode *reverseKGroup(struct ListNode *head, int k) {
    struct ListNode dummy;
    struct ListNode *pHead = &dummy, *pre, *end;
    pHead->next = head;
    pre = pHead;
    end = pHead;
    while (end->next != NULL) {
        for (int i = 0; i < k && end != NULL; ++i) {
            end = end->next;
        }
        if (end == NULL) {
            break;
        }

        struct ListNode *start = pre->next;
        struct ListNode *next = end->next;


        end->next = NULL;
        pre->next = reverse(start);
        start->next = next;
        pre = start;
        end = start;
    }

    return pHead->next;
}




