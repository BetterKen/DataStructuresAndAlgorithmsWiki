#include <stdlib.h>


void rotate2(int *nums, int numsSize, int k) {
    for (int j = 1; j <= k; ++j) {
        int tmp = nums[numsSize - 1];
        for (int i = numsSize - 1; i > 0; --i) {
            nums[i] = nums[i - 1];
        }
        nums[0] = tmp;
    }
}


void rotate(int *nums, int numsSize, int k) {
    k = k % numsSize;
    reverse(nums,0, numsSize - 1);
    reverse(nums, 0, k - 1);
    reverse(nums,k, numsSize - 1);
}

void reverse(int *nums, int i, int j) {
    int tmp = 0;
    while (i < j) {
        tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
        i++;
        j--;
    }
}

int main() {
    int a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    rotate2(a, 9, 3);
    for (int i = 0; i < 9; ++i) {
        printf("%d->", a[i]);
    }
}
