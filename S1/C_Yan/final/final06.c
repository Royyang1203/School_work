#include <stdio.h>
#include <stdlib.h>

struct PData

{

char name[50];

char phoneNumber[50];

char address[100];

};


char *getPhoneNumber1(struct PData *data, int n, char *name)
{
    for(int i = 0; i < n; i ++) {
        if(strcmp((data+i)->name, name) == 0)
            return (data+i)->phoneNumber;
    }
    return NULL;
}
char *getPhoneNumber2(struct PData **data, int n, char *name)
{
    for(int i = 0; i < n; i ++) {
        if(strcmp((*data + i)->name, name) == 0 )
            return (*data + i)->phoneNumber;
    }
    return NULL;

}


int main(void)
{
    int n;
    char arr[] = "eee";
    struct PData *ptr;
    struct PData a[] = {{"roy", "123", "eee"}, {"rrr", "321", "eee"}, {"eee", "1111", "eee"}, {"qqq", "2222", "eee"}, {"www", "3333", "eee"}};
    ptr = a;
    printf("%s", getPhoneNumber2(&ptr, 5, arr));
    printf("%s", getPhoneNumber1(a, 5, arr));
    return 0;
}
