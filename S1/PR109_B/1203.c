#include<stdio.h>

int h(int x);
int g(int x);

int f(int x)
{
    //printf("##%d\n", x);
    int t = h(x);
    if (x > t)
        return f(x - 1) - t;
    if (x < t) {
        //printf("!!\n");
        int gx = g(x);
        //printf("@@%d", gx);
        return f(gx) - gx;
    }
    else
        return 1;
}
int h(int x)
{
    x %= 6;
    if (x < 2)
        return -1;

    else
        return 2 + h(x - 1) - h(x - 2);

}
int g(int x)
{
    if (x <= 2)
        return x * x - 1;
    else
    return 2;
}
int main(void)
{
    int n;
    scanf("%d", &n);
    printf("%d\n", f(n));
    return 0;
}
