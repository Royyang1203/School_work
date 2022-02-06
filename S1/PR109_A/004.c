#include <stdio.h>
#include <assert.h>

int main(void)
{
    FILE *fptr1 = fopen("testdata.txt", "r"), *fptr2 = fopen("test", "a");
    assert(fptr1 != NULL);
    assert(fptr2 != NULL);
    int c;
    char arr[100];
    fgets(arr, 10, fptr1);
    fprintf(stdout, "%s", arr);
    printf("%s\n", arr);
    //int n = atoi(arr);
    //printf("!%d!", n);
    //c = fgetc(fptr1);
    //printf("%c", c);
    //fputc('a', fptr1);
    return 0;
}
