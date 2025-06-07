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

    //actual data = dl-divl+1
    //check that we get the remainder as all 0 or not
    char data1[100];
    strcpy(data1,data);
    for(int i=0;i<dl-divl+1;i++){
        if(data1[i]=='1'){
            for(int j=0;j<divl;j++){
                if(data1[i+j]==divisor[j])
                    data1[i+j]='0';
                else
                    data1[i+j]='1';
            }
        }
    }
    //our data word after division
    // for(int i=0;i<dl;i++){
    //     printf("%c ",data1[i]);
    // }

    //checking that we have remainder 0 or ot
    int check=0;
    for(int i=dl-divl+1;i<dl;i++){
        if(data1[i]=='1')
        {
            check=1;
            break;
        }
    }
    if(check==0){
        printf("\nThe data is having no error");
    }
    else{
        printf("Wrong codeword is:");
        for(int i=dl-divl+1;i<dl;i++){
            printf("%c ",data1[i]);
        }
    }
    return 0;
}