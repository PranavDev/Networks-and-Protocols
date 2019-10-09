#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct FrameNode
{
	int data;
	struct FrameNode* prev;
	struct FrameNode* Nxt;
}*head,*p,*q;


void DisplayFrame(int Frame[100],int j,int val,int data_len);
void MakeFrame(int Flag[100],int Flag_len,int Data[100],int data_bits,int ESC[100],int value);
void DecodeFrame(int Data[100],int data_bits);

void DecodeFrame(int Data[100],int data_bits)
{
	int i;
	
	printf("\n****************************************************************************\n");
	printf("\n\nDecoded Frame : ");
		
	for(i=0;i<data_bits;i++)
	{
		printf("%d ",Data[i]);
	}
}

void MakeFrame(int Flag[100],int Flag_len,int Data[100],int data_bits,int ESC[100],int value)
{
	int Frame[100];
	int i,frame_len = 0;
	
	//data and flag same then frame_len is with ESC characters
	if(value==1)
	{
		frame_len = Flag_len + 8 + data_bits + Flag_len;
		
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
		for(i=Flag_len+8+data_bits;i<frame_len;i++)
		{
			Frame[i] = Flag[j];
			j++;
		}
	}
	else if(value==0)
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
	
	else if(value==2)
	{
		frame_len = Flag_len + 8 + data_bits + Flag_len;
		
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
		for(i=Flag_len+8+data_bits;i<frame_len;i++)
		{
			Frame[i] = Flag[j];
			j++;
		}
	}
	
	else if(value==3)
	{
		frame_len = Flag_len + 8 + data_bits + 8 + Flag_len;
		
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
		for(i=Flag_len+8;i<Flag_len+8+(data_bits/2);i++)
		{
			Frame[i] = Data[j];
			j++;
		}
		
		j = 0;
		for(i=Flag_len+8+(data_bits/2);i<Flag_len+8+data_bits;i++)
		{
			Frame[i] = ESC[j];
			j++;
		}
		
		j = 0;
		for(i=Flag_len+8+data_bits;i<Flag_len+8+data_bits+data_bits;i++)
		{
			Frame[i] = Data[j];
			j++;
		}
		
		j = 0;
		for(i=Flag_len+8+data_bits+data_bits;i<frame_len;i++)
		{
			Frame[i] = Flag[j];
			j++;
		}
	}
	
	
	DisplayFrame(Frame,frame_len,value,data_bits);
}



void DisplayFrame(int Frame[100],int j,int val,int data_len)
{
	int i;
	
	printf("\n\n----FRAME----\n\n");
	if(val==1)
	{
		printf("FLAG\t\t\t\tESC-DATA\t\t\tFLAG\n\n");
		
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
			//Flag
			else if(i>15+data_len && i<j)
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
	else if(val==2)
	{
		printf("FLAG\t\t\t\tESC-DATA\t\t\tFLAG\n\n");
		
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
			//Flag
			else if(i>15+data_len && i<j)
			{
				printf("%d ",Frame[i]);
			}
		}
	}
	
	else if(val==3)
	{
		printf("FLAG\t\t\t\tESC-DATA/2-ESC-DATA/2\t\t\tFLAG\n\n");
		
		for(i=0;i<j;i++)
		{
			printf("%d ",Frame[i]);	
		}
	}
	
	return;
}


int main()
{
	int i,Data[100],Flag[100],Store[100],Flag_len = 0,Data_len = 0,Flagmatch = 0,ESCmatch = 0;
	int ESC[] = {0,0,0,1,1,1,0,0},data;
	int data_bits;
	
	head = (struct FrameNode*)malloc(sizeof(struct FrameNode));
	head->data = data;
	head->Nxt = NULL;
	head->prev = NULL;
	
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
	
	int j = 0;
	
	if(Data_len >= Flag_len)
	{
		for(i=0;i<Flag_len;i++)
		{
			if(Data[i] == Flag[i])
			{
				Flagmatch++;
			}
		}
		
		for(j=0;j<8;j++)
		{
			if(Data[j] == ESC[j])
			{
				ESCmatch++;
			}
		}
		
		if(i<Data_len)
		{
		while(i<Data_len)
		{
			if(Data[i] == ESC[j])
			{
				ESCmatch++;
			}
			
			j++;
			i++;
		}
		}
		
		if(Flagmatch==Flag_len && ESCmatch==8)
		{
			printf("\n\n-----Data is combination of Flag And ESC-----");
			
			//creates frame 
			MakeFrame(Flag,Flag_len,Data,data_bits,ESC,3);
			DecodeFrame(Data,data_bits);
			
			ESCmatch = 0;
		}
		
		else if(Flagmatch==Flag_len)
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
			DecodeFrame(Data,data_bits);
			
			Flagmatch = 0;
		}
		else if(ESCmatch==8)
		{
			printf("\n\nData Entered is ESC..");
			
			
			MakeFrame(Flag,Flag_len,Data,data_bits,ESC,2);
			DecodeFrame(Data,data_bits);
			
			ESCmatch = 0;
		}
		
		else
		{
			printf("\n\nData,Flag and ESC not same..");
			//creates the entire frame by appending the Header and Footer to the DATA sequence..No ESC Added 
			MakeFrame(Flag,Flag_len,Data,data_bits,ESC,0);
			DecodeFrame(Data,data_bits);
		}
		
		ESCmatch = 0;
		Flagmatch = 0;
	}
	
	return 0;
}
