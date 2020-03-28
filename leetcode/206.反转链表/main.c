#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode *reverseList(struct ListNode *head) {
    struct ListNode *pos;
    if (head == NULL) {
        return head;
    }
    pos = head->next;
    head->next = NULL;
    while (pos) {
        struct ListNode *tmp = pos;
        int tmpVal = tmp->val;
        pos = pos->next;

        tmp->val = head->val;
        head->val = tmpVal;

        tmp->next = head->next;
        head->next = tmp;
    }
    return head;

}


struct ListNode *reverseList2(struct ListNode *head) {
    struct ListNode *pre = NULL;
    struct ListNode *tmp = NULL;
    struct ListNode *cur = head;
    while (cur) {
        tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    return pre;
}

struct ListNode *reverseList3(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode *cur = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return cur;
}
