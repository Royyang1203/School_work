#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a, b;
    int A = 0;
    for (int i = 0; i < 5; i++)
    {
        scanf("\n%c%c", &a, &b);
        if (a == 'P' && b == 'R')
            A++;
        else if (a == 'S' && b == 'P')
            A++;
        else if (a == 'R' && b == 'S')
            A++;
        else if (a == 'R' && b == 'P')
            A--;
        else if (a == 'P' && b == 'S')
            A--;
        else if (a == 'S' && b == 'R')
            A--;
    }
    if (A > 0)
        printf("Alice");
    else if (A < 0)
        printf("Bob");
    else
        printf("Draw");
    return 0;
}

// _______________________________________________

// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>

// int main()
// {
//     char a, b;
//     int A = 0;
//     for (int i = 0; i < 5; i++){
//         scanf("\n%c%c", &a, &b);
//         if ((a == 'P' && b == 'R') || (a == 'S' && b == 'P') || (a == 'R' && b == 'S'))
//             A++;
//         else if ((a == 'R' && b == 'P') || (a == 'P' && b == 'S') || (a == 'S' && b == 'R'))
//             A--;
//     }
//     if (A > 0)
//         printf("Alice");
//     else if (A < 0)
//         printf("Bob");
//     else
//         printf("Draw");
//     return 0;
// }