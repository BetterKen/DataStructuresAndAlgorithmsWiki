#include <malloc.h>
# include <string.h>

int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
    int *result = (int *) malloc(sizeof(int) * 2);

    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (*(nums + i) + *(nums + j) == target) {
                *(result) = i;
                *(result + 1) = j;
                *returnSize = 2;
                return result;
            }
        }
    }
    return result;
}

#define MAX 3000

int *twoSum2(int *nums, int numsSize, int target, int *returnSize) {
    int *result = (int *) malloc(sizeof(int) * 2);

    int hash[MAX];
    memset(hash, -1, sizeof(hash));
    for (int i = 0; i < numsSize; i++) {
        int r = target - nums[i];
        r = (r + MAX) % MAX;
        if (hash[r] != -1) {
            *returnSize = 2;
            *(result) = i;
            *(result + 1) = hash[r];
            return result;
        }
        hash[(nums[i] + MAX) % MAX] = i;
    }
    return result;
}

int main() {
    int a[4] = {2, 7, 11, 15};
    int *b;
    int n;
    int numSize = 4;
    int target = 18;
    b = twoSum2(a, numSize, target, &n);
    printf("%d\t%d", b[0], b[1]);
}
