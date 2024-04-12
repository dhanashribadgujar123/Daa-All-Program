#include<iostream>
using namespace std;
void knapsack(int n,float weight[],float profit[],float capacity)
{
float x[20],tp=0;
int i,j,u;
u= capacity;
for(i=0;i<n;i++)
x[i]= 0.0;
for(i=0;i<n;i++)
{
if(weight[i]>u)
break;
else
{
x[i]=1.0;
tp= tp + profit[i];
u= u - weight[i];
}
}
if(i<n)
x[i]= u/weight[i];
tp= tp + (x[i]*profit[i]);
cout<<"the result vector is\n:";

for(i=0;i<n;i++)
cout<<""<<x[i];
cout<<"maximum profit is:"<<tp ;
}
int main()
{
float weight[20],profit[20],capacity;
int num,i,j;
float ratio[20],temp;
cout<<"enter the number of objects \n:";
cin>>num;
cout<<"enter the wts and profit of each object:";
for(i=0;i<num;i++)
{
cin>>weight[i]>>profit[i];
}
cout<<"enter the capacity of knapsack:";
cin>>capacity;
for(i=0;i<num;i++)
{
ratio[i] =profit[i]/weight[i];
}
for(i=0;i<num;i++)
{
for(j=i+1;j<num;j++)
{
if(ratio[i]<ratio[j])
{
temp=ratio[j];
ratio[j]=ratio[i];
ratio[i]=temp;

temp=weight[j];
weight[j]=weight[i];
weight[i]=temp;

temp=profit[j];
profit[j]=profit[i];
profit[i]=temp;
}
}
}
knapsack(num,weight,profit,capacity);
return (0);
}

/*Output*/

/* enter the number of objects 
:7
enter the wts and profit of each object:
2 10
3 5
5 15
7 7
1 6
4 18
1 3
enter the capacity of knapsack:15
the result vector is
:111110.6666670maximum profit is:55.3333

=== Code Execution Successful === */