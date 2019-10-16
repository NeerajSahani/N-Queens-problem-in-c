#include<stdio.h>
#include<conio.h>
#include<math.h>
int x[20];

int place(int k, int i)
{
	for(int j=1; j<k; j++)
	{
		if(x[j] == i || abs(x[j]-i) == abs(j-k) )
			{
				return (0);	
			}
	}
	return 1;
}

void queen(int k, int n)
{
	for(int i=1; i<=n; i++)
	{
		if(place(k, i))
		{
			x[k]=i;
			if(k==n)
				{
					for(int z=1; z<=n; z++)
						printf("%5d", x[i]);
				}
			else
				queen(k+1, n);	
		}
	}
}

int main(){
	queen(1, 8);
	getch();
}
