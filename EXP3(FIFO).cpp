#include<stdio.h>
int p[30],a[30],m;
int fifo(int);
main()
{
int i,n1,n2,pf1,pf2;
printf("***FIFO***");
printf("enter number of pages\n");
scanf("%d",&m);
printf("enter first number of frames\n");
scanf("%d",&n1);
printf("enter second number of frames\n");
scanf("%d",&n2);
printf("enter pages inorder to be loaded\n");
for(i=0;i<m;i++)
scanf("%d",&p[i]);
printf("\nthe pagefaults for %d pageframe is \n",n1);
pf1=fifo(n1);
printf("\nthe pagefaults for %d pageframe is \n",n2);
pf2=fifo(n2);
if(pf1<pf2)
printf("\nbeladys anamoly exists\n");
else
printf("\nbeladys anamoly doesnot exists\n");
}
int fifo(int n)
{
int i,j,flag,pfault=0;
for(i=0;i<n;i++)
a[i]=-1;
for(i=0;i<m;i++)
{
flag=0;
for(j=0;j<n;j++)
if(a[j]==p[i])
{
flag=1;
break;
}
if(flag==1)
continue;
else
{
for(j=0;j<n-1;j++)
{
a[j]=a[j+1];
}
a[j]=p[i];
pfault++;
}
printf("\na= ");
for(j=0;j<n;j++)
printf("%3d",a[j]);
}
printf("\n number of pagefaults are %d",pfault);
return(pfault);
}
