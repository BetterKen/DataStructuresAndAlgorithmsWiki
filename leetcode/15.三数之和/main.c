/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int comp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), comp);

    int **returnArray = (int **) malloc(sizeof(int *) * (numsSize) * (numsSize));
    *returnColumnSizes = (int *) malloc(sizeof(int) * (numsSize) * (numsSize));//记住这个写法!
    *returnSize = 0;


    for (int i = 0; i < numsSize - 2; i++) {
        int head = i + 1;
        int tail = numsSize - 1;
        while (head < tail) {
            if (nums[i] + nums[head] + nums[tail] == 0) {
                returnArray[*returnSize] = (int *) malloc(sizeof(int) * 3);
                (*returnColumnSizes)[*returnSize] = 3;
                returnArray[*returnSize][0] = nums[i];
                returnArray[*returnSize][1] = nums[head];
                returnArray[*returnSize][2] = nums[tail];
                (*returnSize)++;
                while (nums[head] == nums[++head] && head < tail);
                while (nums[tail] == nums[--tail] && head < tail);
            } else if (nums[i] + nums[head] + nums[tail] < 0) {
                head++;
            } else {
                tail--;
            }
        }
        while ((nums[i] == nums[i + 1]) && (i < numsSize - 2)) {
            i = i + 1;
        }
    }

    return returnArray;
}