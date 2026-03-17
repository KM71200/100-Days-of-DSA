/**/

#include <stdio.h>
#include <stdbool.h>

bool isPowerOfTwo(int n) {
    if (n <= 0) return false;
    return (n & (n - 1)) == 0;
}

int main() {
    printf("n=1  → %s\n", isPowerOfTwo(1)  ? "true" : "false");  /* true  */
    printf("n=16 → %s\n", isPowerOfTwo(16) ? "true" : "false");  /* true  */
    printf("n=3  → %s\n", isPowerOfTwo(3)  ? "true" : "false");  /* false */
    printf("n=0  → %s\n", isPowerOfTwo(0)  ? "true" : "false");  /* false */
    printf("n=-4 → %s\n", isPowerOfTwo(-4) ? "true" : "false");  /* false */
    return 0;
}
