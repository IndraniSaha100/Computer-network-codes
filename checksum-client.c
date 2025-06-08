#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
    char data[100];
    int sum[100];
    printf("Enter data:");
    scanf("%s",data);
    int dl=strlen(data);
    int seglen,j=0;
    while(1){
        printf("Enter segment length:");
        scanf("%d",&seglen);
        for(int i=1;i<=(seglen/2);i++){
            if(pow(2,i)==seglen){
                j=1;break;
            }
        }
        if(j==1){
            break;
        }
        else printf("Enter the segment length of power of 2");
    }
    int c,k,t;
    for(int i=0;i<seglen;i++){
        sum[i]=0;
    }

    for(int i=dl;i>0;i=i-seglen){
        c=0;
        k=seglen-1;
        for(int j=i-1;j>=(i-seglen);j--){
            t=sum[k]+(data[j]-48)+c;
            sum[k]=t%2;
            c=t/2;
            k--;
        }
        if(c==1){
            for(int j=(seglen-1);j>=0;j--){
                t=sum[j]+c;
                sum[j]=t%2;
                c=t/2;
            }
        }
    }
    j=0;
    for (int i=0;i<seglen;i++){
        printf("%d ",sum[i]);
    }
    printf("\n");
    //check that sum[] values are all 1 or not, as we take added 1's complete of summation
    for(int i=0;i<seglen;i++){
        if(sum[i]!=1){
            j=1;break;
        }
    }
    if(j==0){
        
         printf("Data receive ok ");
        printf("\nActual data:");
        for(int i=0;i<(dl-seglen);i++)
            printf("%c ",data[i]);
    }
    else{
        printf("\n Wrong data received...");
    }
    return 0;
}