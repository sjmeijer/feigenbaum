#include <stdio.h>
#include <math.h>
#include <string.h>
#include <gmp.h>

#define N 10
#define MAX_ITER 500

mpf_t b(int k, mpg double a)
{	
	long double temp;
	if (k == 0)
		return(0.0);
	temp = b(k-1,a);

	return( a - (temp*temp) );
}

float bp(int k, long double a)
{
	if (k == 0)
		return(0.0);

	return(1.0 - 2.0 * bp(k-1,a) * b(k-1,a));
}

int main()
{
	int i, j, p;
	int  M = MAX_ITER;

	long double aa[N][MAX_ITER+1] = {0};
	long double delta[N];
	
	long double test;

	printf("\e[4;91mBeginning of Run\e[0m\n");

	for(j=0;j<=M;j++)
	{
		aa[0][j] = 0.0;
		aa[1][j] = 1.0;
	}
	
//	aa[1][M] = 1.0;
//	aa[1][0] = 1.0;
//	aa[0][M] = 0.0;
	delta[1] = 3.20;

	aa[2][0] = aa[1][M] + (aa[1][M] - aa[0][M])/(delta[1]);
	aa[2][0] = 1.0 + (1.0-0.0)/3.2;
//	printf("Test = %3.20Lf \n",test);
//	aa[2][0]=test;

	printf("\n\n");
	printf("aa[0][M] = %3.20Lf \n",aa[0][M]);
	printf("aa[1][M] = %3.20Lf \n",aa[1][M]);
	printf("aa[2][0] = %3.20Lf \n\n",aa[2][0]);
	printf("delta(1)=%3.20Lf\n",delta[1]);
	for(i=2;i<N;i++)
	{
		printf("\e[1;34mIteration (i) %d\e[0m\n",i);
	
		for(j=0;j<=M;j++)
		{
			aa[i][j+1] = aa[i][j] - ( b(pow(2,i),aa[i][j]) / bp(pow(2,i),aa[i][j]) );
	//		printf("aa[%d][%d+1]=%3.10f \n ",i,j,aa[i][j]);
		}
		printf("*****\n aa[i-2]=%Lf, aa[i-2]=%Lf, aa[i]=%Lf \n\n",aa[i-2][M],aa[i-2][M],aa[i-0][M]);
	//	printf("      delta = (\n%3.15Lf - \n%3.15Lf)\n/(\n%3.15Lf - \n%3.15Lf)\n",aa[i-1][M],aa[i-2][M],aa[i][M],aa[i-1][M]);
		printf("      delta = \n(%3.20Lf)\n / \n(%3.20Lf)\n\n",aa[i-1][M]-aa[i-2][M],aa[i][M]-aa[i-1][M]);
	//	for(p=0;p<=i;p++)
	//		printf("aa[%d][M]=%Lf, aa[%d][M-1]=%Lf \n",p,aa[p][M],p,aa[p][M-1]);

		delta[i] = (aa[i-1][M] - aa[i-2][M])/(aa[i][M]-aa[i-1][M]);

		aa[i+1][0] = aa[i][M] + (aa[i][M] - aa[i-1][M])/(delta[i]);
		printf("***** delta[%d] = %3.15Lf \n",i,delta[i]);
		printf("aa[%d][0] = %Lf \n",i+1,aa[i+1][0]);	
	}		
		
	for(i=1;i<N;i++)
		printf("aa[%d][M]=%3.20Lf, delta[%d]=%3.20Lf\n",i,aa[i][M],i,delta[i]);
}

