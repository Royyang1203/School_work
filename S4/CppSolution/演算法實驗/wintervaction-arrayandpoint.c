#include <stdio.h>
#include <stdlib.h> //用malloc()

int main()
{
    //****陣列:
    //int arr[5]={}///設定初始化把所有陣列裡所有空間放0 == int arr[5]={0}
    int arr[5]={1,2,3,4};
   //我們對arr設初始，但沒有設定arr[4]，他會是0，如果沒有初始化就會是殘留值
    
    int ar[6]={1};///這樣的意思並不是把所有陣列全部放1，而是把ar[0]變成1，其它為0
    int a[4]={};////這 等價於 a[4]={0}   => 所有值都為0
   // printf("%d",a[2]);
   /// %u = sizeof of type 
    
    printf("arr of size: %u \n",sizeof(arr)); ///一個arr所占大小 
    printf("arr[0] of size: %u\n\n",sizeof(arr[0])); ///一個arr[0]所占大小，這為一個int大小 4 bite
    for(int i=0; i<sizeof(arr)/sizeof(arr[0]);i++)
        printf("arr[%d]: %p\n",i, &arr[i]);
    
    printf("Important:\narr:%p\n",arr);
    printf("&arr[0]:%p\n", &arr[0]);
    printf("&arr:%p\n",&arr);
    ///arr == &arr[0] == &arr，所以陣列並不是一個指標，arr這個東西在記憶體不存在
    ///所以當我們需要取陣列的位址就從第一個位址開始(&arr[0])
    int s[3][3];
    printf("2D Array:\n%p %p %p %p\n", &s[0][0], &s, s, &s[0]);

    //****指標:
    int *p ; ///*(p+0) == p[0]
    p = &arr[0]; //不要這樣寫， p  = &arr or p = arr ，因為arr本身不存在，在編譯器中代表陣列第一個位址
    printf("\n%d %d\n\n",*(p+3),p[3]);

    int *pp,*ppp,temp;
   /* pp[0]=3;*****這樣的寫法有問題，因為沒有初始化指標，所以指標只為指向
   任意的記憶體位址，但編譯器通常會幫忙指向0xccccccc，因為這個記憶體未指是
   不能被程式存取，所以程式就會發生異常，除非改成以下方式:(指向一塊記憶體位址)*/
    temp = 3;
    pp = &temp;
    printf("pp:\n%p %p %d\n",&temp,pp,pp[0]);
    ///或者給ppp指向一塊記憶體 
    ppp = malloc(sizeof(int)*1);///我只要一塊存int大小的記憶體
    ppp[0]=3;
    printf("ppp:\n%p %d\n",&ppp,ppp[0]);

    ///2D陣列:
    printf("2D array:\n");
    int Arr[3][4]={},k=0;

    for(int i=0;i<3;i++)
        for(int j=0;j<4;j++)
            Arr[i][j]=++k;
    for(int i=0;i<3;i++,printf("\n"))
        for(int j=0;j<4;j++)
            printf("%3d ",Arr[i][j]);
    
    /*1.------2維陣列與雙重指標記憶分布是不一樣的，所以不能用
     雙重指標訪問2維陣列
    int **t;
    t = (int *) Arr;
    for(int i=0;i<3;i++)
        for(int j=0;j<4;j++)
            printf("%3d ",Arr[i][j]);*/

    /*用一維的方式訪問2維，從這裡可知int Arr[4*3] == int Arr[3][4]
    所以一維就等同於二維，所以Arr[4][3]為連續記憶體陣列
    int *te = (int*)Arr; ///把Arr轉成(int *)
    for(int i=0;i<12;i++)
        printf("%d ", *(te+i));or te[i]*/

    ///一個2維陣列的型態為指向陣列的指標，int (*)[4] 切記:[] >> *
    //與指標陣列不一樣

    int (*ptr)[4] = Arr;///將指向陣列的指標指在 &Arr[0]
    for(int i=0;i<3;i++,ptr++)
    {
        printf("%p %p\n", *ptr, Arr[i]);//*ptr == &Arr[0]
        //*(ptr+1) == &Arr[1]
        for(int j=0;j<4;j++)
            printf("%d\n", *((*ptr)+j));
    }

}