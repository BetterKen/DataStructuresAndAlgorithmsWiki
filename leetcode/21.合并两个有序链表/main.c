#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

//迭代
struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode *cur, *p1, *p2, dummy;
    p1 = l1;
    p2 = l2;
    cur = &dummy;
    while (NULL != p1 && NULL != p2) {
        if (p1->val < p2->val) {
            cur->next = p1;
            cur = cur->next;
            p1 = p1->next;
        } else {
            cur->next = p2;
            cur = cur->next;
            p2 = p2->next;
        }
    }
    if (NULL == p1) {
        cur->next = p2;
    }
    if (NULL == p2) {
        cur->next = p1;
    }
    return dummy.next;
}

//递归
struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2) {
    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }

    if (l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l2->next, l1);
        return l2;
    }
}


int main() {
    int a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    rotate2(a, 9, 3);
    for (int i = 0; i < 9; ++i) {
        printf("%d->", a[i]);
    }
}
