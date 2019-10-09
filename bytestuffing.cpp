#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void MakeFrame(int Flag[100],int Flag_len,int Data[100],int data_bits,int ESC[8],int value);
void DisplayFrame(int Frame[100],int j,int val,int data_len);


void MakeFrame(int Flag[100],int Flag_len,int Data[100],int data_bits,int ESC[8],int value)
{
	int Frame[100];
	int i,frame_len = 0;
	
	//data and flag same then frame_len is with ESC characters
	if(value==1)
	{
		frame_len = Flag_len + data_bits + 8 + Flag_len;
		
		for(i=0;i<Flag_len;i++)
		{
			Frame[i] = Flag[i];
		}
		
		int j = 0;
		for(i=Flag_len;i<Flag_len+8;i++)
		{
			Frame[i] = ESC[j];
			j++;
		}
		
		j = 0;
		for(i=Flag_len+8;i<Flag_len+8+data_bits;i++)
		{
			Frame[i] = Data[j];
			j++;
		}
		
		j = 0;
		for(i=Flag_len+8+data_bits;i<Flag_len+8+data_bits+8;i++)
		{
			Frame[i] = ESC[j];
			j++;
		}
		
		j = 0;
		for(i=Flag_len+8+data_bits+8;i<frame_len;i++)
		{
			Frame[i] = Flag[j];
			j++;
		}
	}
	else
	{
		frame_len = Flag_len + data_bits + Flag_len;
		
		for(i=0;i<Flag_len;i++)
		{
			Frame[i] = Flag[i];
		}
		
		int j = 0;
		for(i=Flag_len;i<Flag_len+data_bits;i++)
		{
			Frame[i] = Data[j];
			j++;
		}
		
		j = 0;
		for(i=Flag_len+data_bits;i<frame_len;i++)
		{
			Frame[i] = Flag[j];
			j++;
		}
	}
	
	DisplayFrame(Frame,frame_len,value,data_bits);
	
	return;
}



void DisplayFrame(int Frame[100],int j,int val,int data_len)
{
	int i;
	
	printf("\n\n----FRAME----\n\n");
	if(val==1)
	{
		printf("FLAG\t\t\t\tESC-DATA-ESC\t\t\tFLAG\n\n");
		
		for(i=0;i<j;i++)
		{
			//Flag
			if(i<7)
			{
				printf("%d ",Frame[i]);
			}
			//End-Of Flag : Flag's Last Bit
			else if(i==7)
			{
				printf("%d__",Frame[i]);
			}
			//ESC
			else if(i>7 && i<15)
			{
				printf("%d ",Frame[i]);
			}
			//ESC Last Bit
			else if(i==15)
			{
				printf("%d__",Frame[i]);
			}
			//Data Bits
			else if(i>15 && i<15+data_len)
			{
				printf("%d ",Frame[i]);
			}
			else if(i==15+data_len)
			{
				printf("%d__",Frame[i]);
			}
			//ESC
			else if(i>15+data_len && i<15+data_len+8)
			{
				printf("%d ",Frame[i]);
			}
			//ESC Last Bit
			else if(i==15+data_len+8)
			{
				printf("%d__",Frame[i]);
			}
			else if(i>15+data_len+8 && i<j)
			{
				printf("%d ",Frame[i]);
			}
		}
	}
	
	else if(val==0)
	{
		printf("FLAG\t\t\t\tDATA\t\t\tFLAG\n\n");
		
		for(i=0;i<j;i++)
		{
			//Flag
			if(i<7)
			{
				printf("%d ",Frame[i]);
			}
			//End-Of Flag : Flag's Last Bit
			else if(i==7)
			{
				printf("%d__",Frame[i]);
			}
			//Data Bits
			else if(i>7 && i<7+data_len)
			{
				printf("%d ",Frame[i]);
			}
			else if(i==7+data_len)
			{
				printf("%d__",Frame[i]);
			}
			else if(i>7+data_len && i<j)
			{
				printf("%d ",Frame[i]);
			}
		}
	}
	
	return;
}


int main()
{
	int i,Data[100],Flag[100],Store[100],Flag_len = 0,Data_len = 0,match = 0;
	int ESC[] = {0,0,0,1,1,1,0,0};
	int data_bits;
	
	printf("\n\t\t\t---BYTE STUFFING---\n\n");
	printf("******************************************************************\n\n");
	
	printf("---MAKING A FRAME---\n\n");
	
	printf("> Enter 8 Bit Flag : \n");
	for(i=0;i<8;i++)
	{
		printf("\nFlag[%d] = ",i);
		scanf("%d",&Flag[i]);
		Flag_len++;
	}
	
	printf("\n\n> We Enter the Flag At The Start And End!\n\n");
	
	printf("\nEnter Bits for Data : ");
	scanf("%d",&data_bits);
	
	printf("\n> Enter 8 Bit Data : \n");
	for(i=0;i<data_bits;i++)
	{
		printf("\nData[%d] = ",i);
		scanf("%d",&Data[i]);
		Data_len++;
	}
	
	//checking if Flag and Data are Same
	if(Data_len >= Flag_len)
	{
		for(i=0;i<Flag_len;i++)
		{
			if(Data[i] == Flag[i])
			{
				match++;
			}
		}
		
		if(match==Flag_len)
		{
			printf("\n\n-----Data And Flag are Same-----");
			
			printf("\n\nAdding ESC character to Data..\n\n");
		
			printf("ESC is: ");
		
			for(i=0;i<8;i++)
			{
				printf("%d ",ESC[i]);
			}
			printf("\n\n");
			
			//creates the entire frame by appending the Header and Footer to the ESC_DATA_ESC sequence
			MakeFrame(Flag,Flag_len,Data,data_bits,ESC,1);
		}
		else
		{
			printf("\n\nData and Flag not same..");
			//creates the entire frame by appending the Header and Footer to the DATA sequence..No ESC Added 
			MakeFrame(Flag,Flag_len,Data,data_bits,ESC,0);
		}
	}
	
	return 0;
}
