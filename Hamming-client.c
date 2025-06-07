#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
    char data[100];
    printf("Enter dataword:");
    scanf("%s",data);

    int dl=strlen(data);
    int data1[100];
    for(int i=0,j=dl;i<dl;i++,j--){
        data1[j]=data[i]-48;
       //printf("%d ",data1[j]);
    }

    int r=0;
    while(1){
        if(pow(2,r)>dl)
            break;
        r++;
    }
    int z,c,j,count=0,l=1;
    int data2[r];
    for(int i=0;i<r;i++){
        z=pow(2,i);
        c=0;

        for(int k=z;k<=dl;k=z+j){
            for(j=k;j<k+z;j++){
                if(j<=dl){
                        c+=data1[j];
                }
            }
        }
        data2[l]=c%2;
        count+=c%2;
        l++;        
    }
    if(count==0) printf("Actual data received");
    else
    {
        printf("Wrong data received");
        int position=0;
        for(int i=r;i>0;i--){
            if(data2[i]==1)
                position=position+pow(2,i-1);
        }
        printf("\n Error at posotion %d\n",position);
        if(data1[position]==0)   data1[position]=1;
        else    data1[position]=0;
        printf("corrected codeword is: ");
        for(int i=dl;i>=1;i--)
            printf("%d ",data1[i]);
        printf("\n");
    }

    return 0;

}