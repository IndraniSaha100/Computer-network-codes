#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
    char data[100],data1[100];
    printf("Enter data:");
    scanf("%s",data);
    int dl=strlen(data);
    //check seglen is power of 2 or not
    int seglen,j;
    while(1){
        printf("Enter segment length:");
        scanf("%d",&seglen);
        for(int i=1;i<=seglen/2;i++){
            if(pow(2,i)==seglen){
                j=1;break;
            }
        }
        if(j==1)    break;
        else    printf("Segment length must be power of 2");
    }

    //check that data length is divisible by segment length otherwise ad 0's in front of the data
    int i;
    if((dl%seglen)!=0){
        i=seglen-(dl%seglen);
        for(int j=0;j<i;j++)
            data1[j]='0';
        strcat(data1,data);
        strcpy(data,data1);
        dl=dl+i;
    }
    //Taking the array as for storing checksum value
    int sum[100];
    for(int i=0;i<seglen;i++){
        sum[i]=0;
    }
   
    //calculating the binary addition with 2 data values
    int c,k,t;
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
            for(int j=seglen-1;j>=0;j--){
                t=sum[j]+c;
                sum[j]=t%2;
                c=t/2;
            }
        }
    }
    sum[seglen]='\0';
  
    //Complement the result of sum and add as checksum
    j=0;
    for(i=dl;i<(dl+seglen);i++){
        data[i]=(sum[j]==0)?'1':'0';
        j++;
    }
    data[dl+seglen]='\0';
    printf("data: %s",data);

    return  0;
}