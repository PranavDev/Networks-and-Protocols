#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void Display_Frame(int Data[100],int Flag[100],int length);


void Display_Frame(int Data[100],int Flag[100],int frame_len,int Data_len,int Flag_len)
{
	int i=0,j=0;
	
	printf("\n\t\t----FRAME----\n");
	printf("\n\n\tFLAG\t\tDATA\t\tFLAG\n\n");
	for(i=0;i<frame_len;i++)
	{
		if(i<=Flag_len-1)
		{
			printf("%d ",Flag[j]);
			j++;
		}
		if(i==Flag_len)
		{
			j = 0;
			printf("_ %d ",Data[j]);
			j++;
		}
		if(i>Flag_len && i<=(Flag_len + Data_len)-1)
		{
			printf("%d ",Data[j]);
			j++;
		}
		if(i==(Flag_len + Data_len))
		{
			j = 0;
			printf("_ %d ",Flag[j]);
			j++;
		}
		if(i>(Flag_len + Data_len) && i<=frame_len)
		{
			printf("%d ",Flag[j]);
			j++;
		}
	}
}

int main()
{
	int i,Data[100],Flag[100],Store[100],count = 0,Flag_len = 0,Data_len = 0,len_after_stuff = 0,frame_len = 0;
	
	printf("\n\t\t\t---BIT STUFFING---\n\n");
	printf("******************************************************************\n\n");
	
	printf("---MAKING A FRAME---\n\n");
	
	printf("> Enter Flag : \n");
	for(i=0;i<8;i++)
	{
		printf("\nFlag[%d] = ",i);
		scanf("%d",&Flag[i]);
		Flag_len++;
	}
	
	printf("\n\n> We Enter the Flag At The Start And End!\n\n");
	
	printf("\n> Enter 8 bit Data : \n");
	for(i=0;i<8;i++)
	{
		printf("\nData[%d] = ",i);
		scanf("%d",&Data[i]);
		Data_len++;
	}
	
	int j = 0;
	
	//length of entire frame
	frame_len = (2*Flag_len) + Data_len;
	
	Display_Frame(Data,Flag,frame_len,Data_len,Flag_len);
		
	printf("\n\n________________________________________________\n");
	
	j = 0;
	int bit;
	
	printf("\n\n---NOW WE STUFF BIT 0 AFTER EVERY 5 1's---\n");
	
	for(i=0;i<8;i++)
	{
		bit = Data[i];
		
		if(bit==1)
		{
			count++;
			
			if(count%5!=0)
			{
				Store[j] = bit;
				j++;
			}
			else
			{
				Store[j] = bit;
				j++;
				Store[j] = 0;
				j++;
				count = 0;
			}
		}
		else
		{
			Store[j] = bit;
			j++;
			count = 0;
		}
	}
	
	len_after_stuff = j;
	j = 0;
	
	//getting new frame length after stuffing
	frame_len = (2*Flag_len) + len_after_stuff;
	
	printf("\n\n");
	Display_Frame(Store,Flag,frame_len,len_after_stuff,Flag_len);
	
	printf("\n\n________________________________________________\n");
	
	return 0;
}
