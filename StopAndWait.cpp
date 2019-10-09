#include<stdio.h>
#include<conio.h>

struct Frame
{
	int seq_no;
	int ack;
	int data[100];
}*fr,*head;

int main()
{
	int i=0,fnum;
	
	printf("\t\t***STOP AND WAIT***\n\n");
	printf("**********************************************************");
	
	printf("\nEnter the No. of Frames : ");
	scanf("%d",&fnum);
	
	head = (struct Frame*)malloc(sizeof(struct Frame));
	printf("Enter Head Frame-Data[%d] : ",i+1);
	scanf("%d",&head->data[i]);
	head->seq_no = i;
	head->ack = 0;
	
	printf("\n\nEnter the Data in frame : ");
	for(i=1;i<fnum;i++)
	{
		fr = (struct Frame*)malloc(sizeof(struct Frame));
		printf("Enter Frame-Data[%d] : ",i+1);
		scanf("%d",&fr->data[i]);
		fr->seq_no = i;
		fr->ack = 0;
	}
	
	printf("\n\nThe Data Entered in Frame is : ");
	for(i=0;i<fsize;i++)
	{
		printf("%d ",frame->)
	}
}
