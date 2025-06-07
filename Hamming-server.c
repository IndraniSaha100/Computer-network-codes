#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
	char data[100];
	int data1[100],data2[100];
	int r,i=0,j=0,k=0,z,c,dl;
	printf("Enter the data: ");
	scanf("%s",data);
	dl=strlen(data);
	//finding number of parity bits
	while(1){
		if(pow(2,i)>= dl+i+1)
			break;
		i++;
	}
	r=i;
	//converting character dataset to number
	for(i=0;i<dl;i++){
		data1[i]=data[i]-48;
	}

	
	//for filling up parity bit position
	for(i=0;i<r;i++)
	{
		z=pow(2,i);
		data2[z]=999;
	}
	
	//filling the data2 with actual data in reverse order except parity bits
	for(i=dl+r;i>0;i--){
		if(data2[i]!=999){
			data2[i]=data1[j];
			j++;
		}
	}
	
	//finding out parity bit
	for(int i=0;i<r;i++){
		z=pow(2,i); //for z=2
		c=0;
		//calculating parity bit
		for(k=z;k<=dl+r;k=z+j){ //for k=2 k=2+4=6  k=2+8=10
			for(j=k;j<z+k;j++){  //for j=2, j=3, j=4\/  j=6,j=7,j=8\/
				if(j<=dl+r){
					if(data2[j]!=999){
							c=c+data2[j];
						}
				}
			}
		}
		data2[z]=c%2;
	}
	
	for(i=dl+r;i>0;i--){
		printf("%d ",data2[i]);
	}
	
	return 0;
}