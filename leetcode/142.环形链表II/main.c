#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *pq, *pl;
    pq = head;
    pl = head;
    while (1) {
        if (pq == NULL || pq->next == NULL) {
            return NULL;
        }
        pq = pq->next->next;
        pl = pl->next;
        if(pq == pl){
            break;
        }
    }
    pq = head;
    while (pq != pl){
        pl = pl->next;
        pq = pq->next;
    }
    return pq;
}