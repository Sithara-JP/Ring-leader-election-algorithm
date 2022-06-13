#include<stdio.h>
#include<conio.h>
#include<process.h>
struct proc
{
int active;
int p_id;
}
process[10];
int n,cordinator=1;

void display()
{
int i;
printf("\n\nThe Processes are \n");
printf("\nProcesses ");
for(i=1;i<=n;i++)
printf("P%d\t",i);

printf("\nActive ");
for(i=1;i<=n;i++)
printf("%d\t",process[i].active);

printf("\nProcess id ");
for(i=1;i<=n;i++)
printf("%d\t",process[i].p_id);
printf("\n");
}

void ring()
{
int ch,c,id,i=0,init,max=-99,last;
for(i=1;i<=n;i++)
{
if(process[cordinator].p_id < process[i].p_id && process[i].active == 1)
cordinator=i;
}
printf("\nThe current CO-ORDINATOR is P%d",cordinator);
printf("\n\nRING ALGORITHM");
while(ch!=4)
{
printf("\n\n1.Crash a Process\n2.Activate a Process\n3.Display\n4.Exit\n");
printf("\nEnter your choice : ");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("\nEnter the process id to crash : ");
scanf("%d",&id);
if(process[id].active==0)
printf("\nProcess P%d is already crashed");
else
{
process[id].active=0;
printf("\nProcess P%d is crashed",id);
if(id==cordinator)
{
while(1)
{
printf("\n\nEnter the process id who wants to initiates the election process : ");
scanf("%d",&init);
if(process[init].active==0)
printf("\nThe selected Process P%d is crashed");
else
{
last=init;
printf("\nElection message sent from = %d",last);
for(i=init+1;i<=n;i++)
{
if(i!=init)
printf(" ->%d",i);
}
for(i=1;i<init;i++)
{
if(i!=init)
printf("->%d",i);
last=i;
}
for(i=init+1;i<=n;i++)
{
if(max < process[i].p_id && process[i].active==1)
{
cordinator=i;
max=process[i].p_id;
}
}
for(i=1;i<=init;i++)
{if(max<process[i].p_id && process[i].active==1)
{
cordinator=i;
max=process[i].p_id;
}
}
printf("\n\nThe new CO-ORDINATOR is P%d",cordinator);
break;
}
}
}
}
break;
case 2:
printf("\nEnter process id to be activated : ");
scanf("%d",&id);
if(process[id].active==1)
printf("\nProcess %d is already active",id);
else
{
process[id].active=1;
printf("\nProcess %d is activated",id);
if(process[id].p_id > process[cordinator].p_id)
{
printf("\n\nThe new CO-ORDINATOR is P%d\n",id);
cordinator=id;
}
}
break;
case 3:
display();
break;
case 4:
break;
}
}
}
void main()
{
int ch,i,c;
printf("\nEnter the number of processes : ");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
printf("\nEnter the process id of the process P%d : ",i);
scanf("%d",&process[i].p_id);
printf("\nEnter whether the process id P%d is active or not (0/1) : ",i);
scanf("%d",&process[i].active);
}
display();
while(1)
{
printf("\n1.RING ALGORITHM \n2.EXIT");
printf("\n\nEnter your choice : ");
scanf("%d",&ch);
switch(ch)
{
case 1:
ring();
break;
case 2:
exit(0);
}
}
}
