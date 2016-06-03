#include<stdio.h>
int main()
{
int start,end,key,mid;
int a[10]={1,2,5,6,7,9,10,56,60,80};
printf("\nenter the integer:\n");
scanf(" %d",&key);
start=0;
end=9;
while(start<=end)
{
mid=(start+end)/2;
if(a[mid]==key)
{
printf("\nfound\n");
exit(1);
}
else if(a[mid]>key)
end=mid-1;
else
start=mid+1;
}
printf("\nnot found\n");
return 0;
}
