#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
    char string[100];
    printf("Enter a string\n");
    gets(string);
    printf("The inpiut string is:");
    puts(string);
    int dl=strlen(string);
    int count=0;
    for(int i=0;i<dl;i++)
    {
        if(string[i]==1)
            count++;
    }
    printf("Enter the mode of parity: even('e'),odd('o')");
    char ch;
    count=count%2;
    scanf("%c",&ch);
    switch(ch){
        case 'e'://even
        if(count==0)
            printf("No error");
        else printf("Error exist");
        break;
        case 'o'://odd
        if(count==1)
        printf("No error");
        else printf("Error exist");
        break;
        default:
            printf("Enter valid parity mode..");
    }
    return 0;
}