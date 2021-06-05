#include<stdio.h>
#include<stdlib.h>

void input(int l[50],int h[50],int n);
#function to get the input values for the program

void print(int matrix[50][50],int n);
#function to print the matrix elements

void init(int matrix[50][50],int n);
#function to initialise the matrix

int check(int matrix[50][50],int i,int j,int l[50],int h[50],int n);

int max(int a,int b,int c);
#function to get the maximum element

void comp(int matrix[50][50],int n);
#function to perform the computation

void main()
{
  int h[50],l[50],matrix[50][50],n,i,j,k,s,x;
  printf("Enter the number of weeks\n");
  scanf("%d",&n);
  input(l,h,n);
  init(matrix,n);

  for(i=1;i<=n+1;i++)
  {    
       for(j=1;j<=n+1;j++)
      {
       if(h[i+1]>l[i]+l[i+1]) 
        {
         s=matrix[i-1][j]+h[i+1];
         for(k=1;k<=n;k++)
         {
            matrix[i][k]=matrix[i-1][k];
            matrix[i+1][k+1]=s;
           
         }
         i=i+2;
        }
       x=check(matrix,i,j,l,h,n);
       if(i==j)
       {
       matrix[i][j]=max(matrix[i-1][j],x,matrix[i][j-1]);
       }
       else
       {
        matrix[i][j]=max(matrix[i-1][j],matrix[i][j-1],0);
       }
      }
       
  }
  print(matrix,n);
}

void input(int l[50],int h[50],int n)
{
 int i;
 printf("Enter the value of low stress work\n");
 for(i=1;i<=n;i++)
 {
  scanf("%d",&l[i]);
 }
 printf("Enter the value of high stress work\n");
 for(i=1;i<=n;i++)
 {
  scanf("%d",&h[i]);
 }
}
void print(int matrix[50][50],int n)
{
 int i,j;
 printf("The matrix is\n");
 for(i=0;i<=n;i++)
 {
  for(j=0;j<=n;j++)
  {
  printf("%d ",matrix[i][j]);
  }
  printf("\n");
 }
 printf("Optimal solution is %d\n",matrix[n][n]);
 printf("Composition is ");
 comp(matrix,n);
}
void init(int matrix[50][50],int n)
{
int i;
for(i=0;i<=n;i++)
 {
  matrix[0][i]=0;
  matrix[i][0]=0;
 }
}
int check(int matrix[50][50],int i,int j,int l[50],int h[50],int n)
{

 //if(h[i+1]>l[i]+l[i+1])
   //     {
     //    for(j=1;j<=n;j++)
       //  {
         //  matrix[i][j]=matrix[i-1][j];
         //  matrix[i+1][j]=matrix[i-1][j];
       //  }
       //  i=i+2;
       //  return matrix[i][j]+h[i+1];
         
       // }
      
 //else
   //     {
          return matrix[i-1][j]+l[i];
          i++;
     //   }
}
int max(int a,int b,int c)
{
 if(a>b&&a>c)
 {
  return a;
 }
 else if(b>a&&b>c)
 {
  return b;
 }
 else
 {
  return c;
 }
}
void comp(int matrix[50][50],int n)
{
  int a;
  if(matrix[n][n]>matrix[n][n-1]&&n!=0)
  {
   a=matrix[n][n]-matrix[n][n-1];
   printf("%d ",a);
   n--;
   comp(matrix,n);
  }
}
