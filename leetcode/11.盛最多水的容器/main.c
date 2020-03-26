#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <math.h>

int maxArea(int *height, int heightSize) {

    int head = 0;
    int tail = heightSize - 1;
    int max = 0;
    while (head != tail) {
        int area;
//
//        if (height[head] < height[tail]) {
//            area = height[head] * (tail - head);
//            head++;
//        } else {
//            area = height[tail] * (tail - head);
//            tail--;
//        }


        area = height[head] < height[tail] ? height[head++] * (tail - head + 1) : height[tail--] * (tail - head + 1);
        max = area > max ? area : max;

    }

    return max;
}

int main() {
//    int a[9] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int a[2] = {1, 2};
    int m;
    m = maxArea(a, 2);
    printf("%d", m);
}
