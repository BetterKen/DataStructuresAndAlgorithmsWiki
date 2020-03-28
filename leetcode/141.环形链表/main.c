#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
    struct ListNode *pq, *pl;
    pq = head;
    pl = head;

    while (pq != NULL) {
        if(pq->next == NULL||pl->next == NULL || pq->next->next == NULL){
            return false;
        }
        pq = pq->next->next;
        pl = pl->next;
        if (pq == pl) {
            return true;
        }
    }
    return false;
}
