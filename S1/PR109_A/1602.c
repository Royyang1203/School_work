#include <stdio.h>

int main(void)
{
    char key[5], guess[5];
    int a = 0, b = 0;
    scanf("%s", &key);
    scanf("%s", &guess);
    for(int i = 0; i < 4; i ++) {
        //printf("%c %c\n", guess[i], key[i]);
        if(guess[i] == key[i]) {
            a ++;
            key[i] = '#';
        }
    }
    for (int i = 0; i < 4; i ++)
        for (int j = 0; j < 4; j ++)
            if (guess[i] == key[j]) {
                b ++;
                key[j] = '#';
            }
    printf("%d %d", a, b);
    return 0;
}
