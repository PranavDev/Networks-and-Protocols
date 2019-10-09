#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int flag1 = 0,flag2 = 1;
void Sender(int crc_g[100],int data[100],int crc_g_bits,int data_bits);
void Divide(int crc_g_bits,int data_bits,int crc_g[100],int data[100],int append_bits,int Original_Data[100]);
void Receiver(int BackUp_Data[100],int data[100],int data_bits,int len,int crc_g[100],int crc_g_bits,int append_bits,int Original_Data[100]);

int XOR(int a,int b)
{
	if(a==0 && b==0)
	{
		return 0;
	}
	else if(a==0 && b==1)
	{
		return 1;
	}
	else if(a==1 && b==0)
	{
		return 1;
	}
	else if(a==0 && b==0)
	{
		return 0;
	}
	else
	{
		return 0;
	}
}


void Sender(int crc_g[100],int data[100],int crc_g_bits,int data_bits)
{
	int append_bits,i,Original_Data[100],j=0;
	
	printf("\n\n-----------------------------------------------\n\n******Inside Sender...*******");
	
	append_bits = crc_g_bits - 1;
	
	for(i=0;i<data_bits;i++)
	{
		Original_Data[i] = data[i];
	}
	
	printf("\n\nOriginal Data (without Appended digits) is : ");
	for(i=0;i<data_bits;i++)
	{
		printf("%d",Original_Data[i]);
	}
	
	for(i=1;i<=append_bits;i++)
	{
		data[data_bits + i] = 0;
	}
	
	data_bits = data_bits + append_bits;
	
	printf("\n\nAfter Appending Data : ");
	for(i=0;i<data_bits;i++)
	{
		printf("%d",data[i]);
	}
	
	Divide(crc_g_bits,data_bits,crc_g,data,append_bits,Original_Data);
	
}


void Divide(int crc_g_bits,int data_bits,int crc_g[100],int data[100],int append_bits,int Original_Data[100])
{
	int i=0,j=0,m=0,k=0,val,checkVal,BackUp_Data[100],New_Data[100],len;
	
	int backup_data_bits;
	
	if(flag2==0)
	{
		for(i=0;i<data_bits;i++)
		{
			data[i] = Original_Data[i];
		}
	}
	
	flag2 = 0;
	
	backup_data_bits = data_bits;
	
	for(i=0;i<data_bits;i++)
	{
		BackUp_Data[i] = data[i];
	}
	
	i = 0;
	
	while(data_bits >= crc_g_bits)
	{
		while(data[j]!=1)
		{
			j++;
		}
	
		while(j<data_bits)
		{
			New_Data[i] = data[j];
			j++;
			i++;
		}
		
		while(k<i)
		{
			data[k] = New_Data[k];
			k++;
		}
		
		len = k;
		data_bits = len;
		
		if(data_bits >= crc_g_bits)
		{
			for(m=0;m<crc_g_bits;m++)
			{
				val = XOR(New_Data[m],crc_g[m]);
				
				data[m] = val;
			}
		}
		
		j = 0;
		i = 0;
		k = 0;
	}
	
	data_bits = backup_data_bits;
	
	printf("\n\nOriginal Data (with Appended digits) is : ");
	for(i=0;i<data_bits;i++)
	{
		printf("%d",BackUp_Data[i]);
	}
	
	printf("\n\nThe Data to be Appended to Receiver End is : ");
	for(i=0;i<len;i++)
	{
		printf("%d",data[i]);
	}
	
	i = 0;
	
	while(data[i]==0 && i<len)
	{
		i++;
	}
	
	if(i==len)
	{
		printf("\n\n\n\nRESULT : CRC Complete !! No Error in the Data Sent...!\n\n");
	}
	
	if(flag1==0)
	{
		flag1 = 1;
		Receiver(BackUp_Data,data,data_bits,len,crc_g,crc_g_bits,append_bits,Original_Data);
	}
}


void Receiver(int BackUp_Data[100],int data[100],int data_bits,int len,int crc_g[100],int crc_g_bits,int append_bits,int Original_Data[100])
{
	int i,j,no;
	
	printf("\n\n-----------------------------------------------\n\n******Inside Receiver...*******");
	
	data_bits = data_bits - append_bits;
	
	printf("\n\nOriginal Number of Data-Bits : %d",data_bits);
	
	printf("\nOriginal Data (without Appended digits) is : ");
	for(i=0;i<data_bits;i++)
	{
		printf("%d",Original_Data[i]);
	}
	
	if(len < append_bits)
	{
		no = append_bits - len;
		
		for(i=0;i<no;i++)
		{
			Original_Data[data_bits + i] = 0;
		}
		
		data_bits+=no;
		
		for(i=0;i<len;i++)
		{
			Original_Data[data_bits + i] = data[i];
		}
		
		data_bits+=len;
	}
	
	printf("\n\nSize of Data-Bits After Appending : %d",data_bits);
	
	printf("\n\nReceiver Data after Appending is : ");
	for(i=0;i<data_bits;i++)
	{
		printf("%d",Original_Data[i]);
	}
	
	Divide(crc_g_bits,data_bits,crc_g,data,append_bits,Original_Data);
}



int main()
{
	printf("**Cyclic Redundant Check**\n\n");
	
	int i=0,crc_g_bits,data_bits,crc_g[100],data[100];
	
	printf("Enter the Bits for CRC-G : ");
	scanf("%d",&crc_g_bits);
	
	printf("\nEnter the Bits for Data : ");
	scanf("%d",&data_bits);
	
	printf("\n\nEnter the CRC-G : ");
	for(i=0;i<crc_g_bits;i++)
	{
		printf("\nBit %d : ",i);
		scanf("%d",&crc_g[i]);
	}
	
	printf("\n\nEntered CRC-G is : ");
	for(i=0;i<crc_g_bits;i++)
	{
		printf("%d",crc_g[i]);
	}
	
	printf("\n\nEnter the Data : ");
	for(i=0;i<data_bits;i++)
	{
		printf("\nBit %d : ",i);
		scanf("%d",&data[i]);
	}
	
	printf("\nEntered Data is : ");
	for(i=0;i<data_bits;i++)
	{
		printf("%d",data[i]);
	}
	
	
	Sender(crc_g,data,crc_g_bits,data_bits);
	
	return 0;
}
