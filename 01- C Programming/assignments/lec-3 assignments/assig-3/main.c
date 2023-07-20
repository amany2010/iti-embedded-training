#include <stdio.h>
#include <stdlib.h>

int main()
{
    int h;
    printf("Enter hight:");
    scanf("%d",&h);
    for(int i=h-1;i>=0;i--)
    {
        for(int j=0;j<2*h-1;j++)
        {
            (i<=j&&j<2*h-1-i)?printf("*"):printf(" ");
        }
        printf("\n");
    }
//    for(int i=1;i<h;i++)
//    {
//        for(int j=2*h-1;j>0;j--)
//        {
//            (i<j&&j<=2*h-1-i)?printf(" "):printf("*");
//        }
//        printf("\n");
//    }
}
