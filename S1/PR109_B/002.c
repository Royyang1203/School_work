#include <stdio.h>

int main(void)
{
    const int n = 3, m = 5, d = 9;
    int *ptr = &n;
    //ptr = &n;
    printf("%p\n", &n);
    //n ++;
    (*ptr) ++;
    printf("%p\n%d", ptr, *ptr);
    return 0;
}
