#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

int Store[100],New_Store[100],K4[100],K1_K2[100],Complement_Of_Sum[100];

void GetSum(int K1[100],int K2[100],int K3[100]);
int ADD_for_carry(int a,int b,int carry);
int ADD_for_value(int a,int b,int carry);
int Complement(int x);


int Complement(int x)
{
	if(x==1)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int ADD_for_carry(int a,int b,int carry)
{
	if(a==0 && b==0 && carry==1)
	{
		//printf("\na==0 b==0 carry==1");
		carry = 0;
		return carry;
	}
	else if(a==0 && b==1 && carry==0)
	{
		//printf("\na==0 b==1 carry==0");
		carry = 0;
		return carry;
	}
	else if(a==1 && b==0 && carry==0)
	{
		//printf("\na==1 b==0 carry==0");
		carry = 0;
		return carry;
	}
	else if(a==1 && b==1 && carry==0)
	{
		//printf("\na==1 b==1 carry==0");
		carry = 1;
		return carry;
	}
	else if(a==1 && b==1 && carry==1)
	{
		//printf("\na==1 b==1 carry==1");
		carry = 1;
		return carry;
	}
	else if(a==1 && b==0 && carry==1)
	{
		//printf("\na==1 b==0 carry==1");
		carry = 1;
		return carry;
	}
	else
	{
		//printf("\na==0 b==0 carry==0");
		carry = 0;
		return carry;
	}
}


int ADD_for_value(int a,int b,int carry)
{
	if(a==0 && b==0 && carry==1)
	{
		//printf("\na==0 b==0 carry==1");
		//carry = 0;
		return 1;
	}
	else if(a==0 && b==1 && carry==0)
	{
		//printf("\na==0 b==1 carry==0");
		//carry = 0;
		return 1;
	}
	else if(a==1 && b==0 && carry==0)
	{
		//printf("\na==1 b==0 carry==0");
		//carry = 0;
		return 1;
	}
	else if(a==1 && b==1 && carry==0)
	{
		//printf("\na==1 b==1 carry==0");
		//carry = 1;
		return 0;
	}
	else if(a==1 && b==1 && carry==1)
	{
		//printf("\na==1 b==1 carry==1");
		//carry = 1;
		return 1;
	}
	else if(a==1 && b==0 && carry==1)
	{
		//printf("\na==1 b==1 carry==1");
		//carry = 1;
		return 0;
	}
	else
	{
		//printf("\na==0 b==0 carry==0");
		//carry = 0;
		return 0;
	}
}

int Add_for_carry(int a,int carry)
{
	if(a==0 && carry==1)
	{
		carry = 0;
		return carry;
	}
	else if(a==1 && carry==1)
	{
		carry = 1;
		return carry;
	}
}

int Add_for_value(int a,int b)
{
	if(a==0 && b==1)
	{
		return 1;
	}
	else if(a==1 && b==1)
	{
		return 0;
	}
}



int main()
{
	int K1[100],K2[100],K3[100];
	int i;
	
	printf("---CHECKSUM---\n\n\n");
	
	printf("**********************************\n\n");
	
	printf("\nEnter the Values for K1 :- \n");
	for(i=0;i<8;i++)
	{
		printf("\nK1[%d] = ",i);
		scanf("%d",&K1[i]);
	}
	
	printf("\nEnter the Values for K2 :- \n");
	for(i=0;i<8;i++)
	{
		printf("\nK2[%d] = ",i);
		scanf("%d",&K2[i]);
	}
	
	printf("\nEnter the Values for K3 :- \n");
	for(i=0;i<8;i++)
	{
		printf("\nK3[%d] = ",i);
		scanf("%d",&K3[i]);
	}
	
	printf("\n**********************************\n\n");
	printf("\n\n---Entered Values of K---\n\n");
	
	printf("\n\nK1 Values : ");
	for(i=0;i<8;i++)
	{
		printf("%d ",K1[i]);
	}

	printf("\n\nK2 Values : ");
	for(i=0;i<8;i++)
	{
		printf("%d ",K2[i]);
	}
	
	printf("\n\nK3 Values : ");
	for(i=0;i<8;i++)
	{
		printf("%d ",K3[i]);
	}
	
	printf("\n\n**********************************\n\n");
	
	
	//now perfroming addition of K1,K2,K3
	GetSum(K1,K2,K3);

	printf("\n\n---DONE---\n");
	
	return 0;
}


//function GetSum()
void GetSum(int K1[100],int K2[100],int K3[100])
{
	int i,j=0,carry=0,setCarry;
	
	printf("\n---INSIDE GetSum---\n\n");
	
	//addition of K1 and K2
	for(j=7;j>=0;j--)
	{
		if(j==7)
		{
			Store[j] = ADD_for_value(K1[j],K2[j],carry);
			setCarry = ADD_for_carry(K1[j],K2[j],carry);
			printf("\nCarry = %d",setCarry);
		}
		else
		{
			Store[j] = ADD_for_value(K1[j],K2[j],setCarry);
			setCarry = ADD_for_carry(K1[j],K2[j],setCarry);
			printf("\nCarry = %d",setCarry);
			
		}	
	}
	
	printf("\nCarry : %d",setCarry);
	
	if(setCarry==1)
	{
		int k;
	
		for(k=7;k>=0;k--)
		{
			if(setCarry==1)
			{
				K1_K2[k] = Add_for_value(Store[k],setCarry);
				setCarry = Add_for_carry(Store[k],setCarry);
			}
			else
			{
				K1_K2[k] = Store[k];
			}
		}
		
		
		printf("\n\nK1_K2 After Adding Carry : ");
		for(i=0;i<8;i++)
		{
			printf("%d ",K1_K2[i]);
		}
	}
	else
	{
		printf("\n\n K1_K2 Without Carry : ");
		for(i=0;i<8;i++)
		{
			printf("%d ",K1_K2[i]);
		}
	}
	printf("\n\n");
	
	//adding K3 to the K1_K2
	carry=0,setCarry=0;

	for(j=7;j>=0;j--)
	{
		if(j==7)
		{
			New_Store[j] = ADD_for_value(K1_K2[j],K3[j],carry);
			setCarry = ADD_for_carry(K1_K2[j],K3[j],carry);
			printf("\nCarry = %d",setCarry);
		}
		else
		{
			New_Store[j] = ADD_for_value(K1_K2[j],K3[j],setCarry);
			setCarry = ADD_for_carry(K1_K2[j],K3[j],setCarry);
			printf("\nCarry = %d",setCarry);
			
		}	
	}
	
	if(setCarry==1)
	{
		int k;
	
		for(k=7;k>=0;k--)
		{
			if(setCarry==1)
			{
				K4[k] = Add_for_value(New_Store[k],setCarry);
				setCarry = Add_for_carry(New_Store[k],setCarry);
			}
			else
			{
				K4[k] = New_Store[k];
			}
		}
		
		
		printf("\n\nK4 After Adding Carry : ");
		for(i=0;i<8;i++)
		{
			printf("%d ",K4[i]);
		}
	}
	else
	{
		printf("\n\nK4 Values : ");
		for(i=0;i<8;i++)
		{
			printf("%d ",New_Store[i]);
		}
	}
	
	
	//Taking Complement of the Sum
	for(i=0;i<8;i++)
	{
		Complement_Of_Sum[i] = Complement(New_Store[i]);
	}
	
	printf("\n\nComplement of K4 : ");
	for(i=0;i<8;i++)
	{
		printf("%d ",Complement_Of_Sum[i]);
	}
	
	return;
}







