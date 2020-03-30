#include <stdlib.h>


int removeDuplicates(int *nums, int numsSize) {
    int *cur = nums;
    if (numsSize == 0) {
        return 0;
    }
    int k = 1;
    for (int i = 1; i < numsSize; ++i) {
        if (*(cur + i - 1) != *(cur + i)) {
            *(cur + k) = *(cur + i);
            k++;  // 隐式的在最后加一了
        }
    }
    return k;
}

int removeDuplicates2(int *nums, int numsSize) {
    int *cur = nums;
    if (numsSize == 0) {
        return 0;
    }
    int k = 0;
    for (int i = 1; i < numsSize; ++i) {
        if (nums[k] != nums[i]) {
            k++;
            nums[k] = nums[i];
        }
    }
    return k+1; //注意最后要加一
}


int main() {
    int a[9] = {1, 8, 6, 0, 5, 4, 0, 3, 7};

}
