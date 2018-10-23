#include<stdio.h>
#include<conio.h>
#include<math.h>

int queen[]={0 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 , 1, 1, 1, 1, 1, 1, 1, 1};

int verify(int row, int column)
{
	for(int i=1; i<row; i++)
	 {
	 	/*verifying that the position is safe. Ist condition is for column and 2nd is for diagonal*/
		if(queen[i] == column || (abs(queen[i] - column) == abs(i-row) ) )
				return 0;
	 }
	 return 1;
}


void queenSolution(int number_of_queens)
{
	int row=1, flag;
	while(row <= number_of_queens)
	 {
			for(int i=queen[row]; i<=number_of_queens; i++)
			 {
				flag = 0;
				if(verify(row, i))			 // verify the place is safe for queen or not
				 {
					queen[row++]=i;	  		//set position and increase row by one
					flag=1;			 		//set flag to check whether need to backtrack or not
					break;
				 } 
			 }
			if(!flag)					   //backtracking required
			{
					queen[row]=1;	       //reset current queen's position
				    queen[--row]++;		   //backtrac to previous queen and increase it's position by one
			}
	 }		
}

void print(int n)
{
	printf("\n\nSolution is...\n\n \t\t ");
	for(int j=1; j<=n; j++)
		printf("   %3d   ",j);
	printf("\n\n");
	for(int i=1; i<=n; i++)
	{
		printf("\t\t%2d",i);
		for(int j=1; j<=n; j++)
		{
			if(queen[i] == j)
				printf("    Q    ");
			else
				printf("    -    ");
		}
		printf("\n\n\n");
	}
}
int main()
{
	int n;
	printf("Enter Number of queens :");
	scanf("%d", &n);
	queenSolution(n);
	print(n);
	printf("\n\n");
	for(int i=1; i<=n; i++)
		printf("%4d", queen[i]);
	getch();
	
}
