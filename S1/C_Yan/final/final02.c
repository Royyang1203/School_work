#include <stdio.h>

int main(void)
{
    int n, m = 0;
    int arr[20];
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) {
        scanf("%d", &arr[i]);
        if(arr[i] > m)
            m = arr[i];
    }
    //printf("%d\n", m);
    while(1) {
        int b = 0;
        for(int i = 0; i < n; i ++) {
            //printf("!%d ", m % arr[i]);
            if(m % arr[i] != 0)
                b = 1;
        }
        if(b == 0) {
            printf("%d", m);
            return 0;
        }
        m ++;
    }
    return 0;
}
