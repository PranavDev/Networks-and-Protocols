#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int getVal(int Collect[100], int parity, int num);


int getVal(int Collect[100],int parity, int num)
{
	int i,val,count = 0;
	
	if(parity==1)
	{
		for(i=0;i<=num;i++)
		{
			val = Collect[i];
			
			if(val==1)
			{
				count++;
			}
		}
		
		if(count%2==0)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	else
	{
		for(i=0;i<=num;i++)
		{
			val = Collect[i];
			
			if(val==1)
			{
				count++;
			}
		}
		
		if(count%2==0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}

int main()
{
	int i,j,choice,parity,P1_val,P2_val,P3_val,P4_val;
	int Hamming_Code[100],Parity_Code[100],Collect[100];
	
	printf("---Hamming Code---\n\n");
	printf("Enter the Hamming Code : \n\n");
	for(i=0;i<11;i++)
	{
		printf("\nHammingCode[%d] = ",i);
		scanf("%d",&Hamming_Code[i]);
	}
	
	printf("\n\nHamming Code Entered : ");
	for(i=0;i<11;i++)
	{
		printf("%d ",Hamming_Code[i]);
	}
	
	j=0;
	
	printf("\n\n**Storing Hamming Code in Parity Code Array**\n");
	for(i=15;i>=0;i--)
	{
		if(i==0||i==1||i==3||i==7||i==15)
		{
			Parity_Code[i] = 9;
		}
		else
		{
			Parity_Code[i] = Hamming_Code[j];
			j++;
		}
	}
	
	printf("\nThe Parity Code : ");
	for(i=15;i>=0;i--)
	{
		printf("%d ",Parity_Code[i]);
	}
	
	
	printf("\n\n\n---Parities--- \n1. Even \n2. Odd\n\n");
	printf("Enter Your Choice : ");
	scanf("%d",&choice);
	
	printf("\n\n**********************************\n");
	
	switch(choice)
	{
		case 1: parity = 1; //1 says even parity
		
				printf("\n------EVEN PARITY------\n\n");
				
				printf("-> CALCULATING P1,P2,P3,P4..\n\n");
				
				//for P1
				
				j = 0;
				int num;
				
				for(i=0;i<16;i+=2)
				{
					if(i==0)
					{
						i+=2;
					}
					
					Collect[j] = Parity_Code[i];
					j++;
				}
				
				num = j - 1;
				j = 0;
				
				printf("\n> The Collected Data for P1 : ");
				for(i=0;i<=num;i++)
				{
					printf("%d ",Collect[i]);
				}
				
				P1_val = getVal(Collect,parity,num);
				
				printf("\n\n> The value of P1 : %d",P1_val);
				
				//for P2
				
				j = 0;
				
				for(i=1;i<16;i+=3)
				{
					if(i==1)
					{
						i++;
						Collect[j] = Parity_Code[i];
					}
					else
					{
						j++;
						Collect[j] = Parity_Code[i];
						j++;
						Collect[j] = Parity_Code[i+1];
						i++;
					}
				}
				
				num = j;
				j = 0;
				
				printf("\n\n> The Collected Data for P2 : ");
				for(i=0;i<=num;i++)
				{
					printf("%d ",Collect[i]);
				}
				
				P2_val = getVal(Collect,parity,num);
				
				printf("\n\n> The value of P2 : %d",P2_val);
				
				
				//for P3
				j = 0;
				
				for(i=3;i<15;i+=5)
				{
					if(i==3)
					{
						i++;
						Collect[j] = Parity_Code[i];
						i++;j++;
						Collect[j] = Parity_Code[i];
						i++;j++;
						Collect[j] = Parity_Code[i];
					}
					else
					{
						j++;
						Collect[j] = Parity_Code[i];
						i++;j++;
						Collect[j] = Parity_Code[i];
						i++;j++;
						Collect[j] = Parity_Code[i];
						i++;j++;
						Collect[j] = Parity_Code[i];
					}
				}
				
				num = j;
				j = 0;
				
				printf("\n\n> The Collected Data for P3 : ");
				for(i=0;i<=num;i++)
				{
					printf("%d ",Collect[i]);
				}
				
				P3_val = getVal(Collect,parity,num);
				
				printf("\n\n> The value of P3 : %d",P3_val);
				
				
				//for P4
				j = 0;
				
				for(i=8;i<15;i++)
				{
					Collect[j] = Parity_Code[i];
					j++;
				}
				
				num = j;
				j = 0;
				
				printf("\n\n> The Collected Data for P4 : ");
				for(i=0;i<num;i++)
				{
					printf("%d ",Collect[i]);
				}
				
				P4_val = getVal(Collect,parity,num);
				
				printf("\n\n> The value of P4 : %d",P4_val);
				
				//final Hamming Code
				
				for(i=0;i<16;i++)
				{
					if(Parity_Code[i]==9)
					{
						if(i==0)
						{
							Parity_Code[i] = P1_val;
						}
						else if(i==1)
						{
							Parity_Code[i] = P2_val;
						}
						else if(i==3)
						{
							Parity_Code[i] = P3_val;
						}
						else if(i==7)
						{
							Parity_Code[i] = P4_val;
						}
					}
				}
				
				printf("\n\n\nThe Final Hamming Code : ");
				for(i=15;i>=0;i--)
				{
					printf("%d ",Parity_Code[i]);
				}
				
				printf("\n\n*****************************************\n\n");
				
				break;
				
		case 2: parity = 2; //2 says odd parity
		
				printf("\n------ODD PARITY------\n\n");
				
				printf("-> CALCULATING P1,P2,P3,P4..\n\n");
				
				//for P1
				
				j = 0;
				num = 0;
				
				for(i=0;i<16;i+=2)
				{
					if(i==0)
					{
						i+=2;
					}
					
					Collect[j] = Parity_Code[i];
					j++;
				}
				
				num = j - 1;
				j = 0;
				
				printf("\n> The Collected Data for P1 : ");
				for(i=0;i<=num;i++)
				{
					printf("%d ",Collect[i]);
				}
				
				P1_val = getVal(Collect,parity,num);
				
				printf("\n\n> The value of P1 : %d",P1_val);
				
				//for P2
				
				j = 0;
				
				for(i=1;i<16;i+=3)
				{
					if(i==1)
					{
						i++;
						Collect[j] = Parity_Code[i];
					}
					else
					{
						j++;
						Collect[j] = Parity_Code[i];
						j++;
						Collect[j] = Parity_Code[i+1];
						i++;
					}
				}
				
				num = j;
				j = 0;
				
				printf("\n\n> The Collected Data for P2 : ");
				for(i=0;i<=num;i++)
				{
					printf("%d ",Collect[i]);
				}
				
				P2_val = getVal(Collect,parity,num);
				
				printf("\n\n> The value of P2 : %d",P2_val);
				
				
				//for P3
				j = 0;
				
				for(i=3;i<15;i+=5)
				{
					if(i==3)
					{
						i++;
						Collect[j] = Parity_Code[i];
						i++;j++;
						Collect[j] = Parity_Code[i];
						i++;j++;
						Collect[j] = Parity_Code[i];
					}
					else
					{
						j++;
						Collect[j] = Parity_Code[i];
						i++;j++;
						Collect[j] = Parity_Code[i];
						i++;j++;
						Collect[j] = Parity_Code[i];
						i++;j++;
						Collect[j] = Parity_Code[i];
					}
				}
				
				num = j;
				j = 0;
				
				printf("\n\n> The Collected Data for P3 : ");
				for(i=0;i<=num;i++)
				{
					printf("%d ",Collect[i]);
				}
				
				P3_val = getVal(Collect,parity,num);
				
				printf("\n\n> The value of P3 : %d",P3_val);
				
				
				//for P4
				j = 0;
				
				for(i=8;i<15;i++)
				{
					Collect[j] = Parity_Code[i];
					j++;
				}
				
				num = j;
				j = 0;
				
				printf("\n\n> The Collected Data for P4 : ");
				for(i=0;i<num;i++)
				{
					printf("%d ",Collect[i]);
				}
				
				P4_val = getVal(Collect,parity,num);
				
				printf("\n\n> The value of P4 : %d",P4_val);
				
				//final Hamming Code
				
				for(i=0;i<16;i++)
				{
					if(Parity_Code[i]==9)
					{
						if(i==0)
						{
							Parity_Code[i] = P1_val;
						}
						else if(i==1)
						{
							Parity_Code[i] = P2_val;
						}
						else if(i==3)
						{
							Parity_Code[i] = P3_val;
						}
						else if(i==7)
						{
							Parity_Code[i] = P4_val;
						}
					}
				}
				
				printf("\n\n\nThe Final Hamming Code : ");
				for(i=15;i>=0;i--)
				{
					printf("%d ",Parity_Code[i]);
				}
				
				printf("\n\n*****************************************\n\n");				
								
				break;
				
		default: printf("\n\nWRONG CHOICE...");
				 break;
	}

	return 0;
}
