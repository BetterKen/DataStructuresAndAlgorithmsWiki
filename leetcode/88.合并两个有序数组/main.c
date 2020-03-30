#include <stdlib.h>


void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n) {
    int p = m + n - 1, p1 = m - 1, p2 = n - 1;
    while (p1 >= 0 && p2 >= 0) {
        nums1[p--] = nums1[p1] < nums2[p2] ? nums2[p2--] : nums1[p1--];
    }
    while (p1 >= 0) {
        nums1[p--] = nums1[p1--];
    }
    while (p2 >= 0) {
        nums1[p--] = nums2[p2--];
    }
}


int comp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

void merge2(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n) {
    for (int i = 0; i < n; ++i) {
        nums1[m + i] = nums2[i];
    }
    qsort(nums1, n + m, sizeof(int), comp);
}

int main() {
    int a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    rotate2(a, 9, 3);
    for (int i = 0; i < 9; ++i) {
        printf("%d->", a[i]);
    }
}
