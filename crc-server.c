#include<stdio.h>
#include<string.h>
int main(){
    char data[100],divisor[100];
    printf("Enter dataword:");
    scanf("%s",data);
    printf("Enter divisor:");
    scanf("%s",divisor);

    int dl=strlen(data);
    int divl=strlen(divisor);
    //printf("%d %d",dl,divl);

    //add divisor.length-1 0 values
    for(int i=0;i<divl-1;i++){
        data[dl+i]='0';
    }
    //find out the codeword
    char data1[100];
    strcpy(data1,data);
    for(int i=0;i<dl;i++){
        if(data1[i]=='1'){
            for(int j=0;j<divl;j++){
                if(data1[i+j]==divisor[j])
                    data1[i+j]='0';
                else    data1[i+j]='1';
            }
        }
    }
    for(int i=dl;i<dl+divl-1;i++)
        data[i]=data1[i];
    for(int i=0;i<(dl+divl-1);i++)
        printf("%c ",data[i]);
    
    return 0;
}