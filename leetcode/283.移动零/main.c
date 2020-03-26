#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <math.h>


void moveZeroes(int *nums, int numsSize) {
    int j = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] != 0) {
            nums[j] = nums[i];
            if (i != j) nums[i] = 0;
            j++;
        }
    }
}

int main() {
    int a[9] = {1, 8, 6, 0, 5, 4, 0, 3, 7};

    int m;
    moveZeroes(a, 9);
    for (int i = 0; i < 9; ++i) {
        printf("%d\t", a[i]);
    }
}
