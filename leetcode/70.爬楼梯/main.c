#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <math.h>


int climbStairs(int n) {
    int f1 = 1;
    int f2 = 2;
    int f3 = 3;
    if (n == 1) return 1;
    if (n == 2) return 2;
    for (int i = 3; i <= n; ++i) {
        f3 = f2 + f1;
        f1 = f2;
        f2 = f3;
    }
    return f3;
}


int main() {
    int n = 4;
    printf("%d",climbStairs(4));
}
