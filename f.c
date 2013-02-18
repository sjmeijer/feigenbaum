#include <stdio.h>
#include <math.h>
#include <string.h>
#include <gmp.h>

#define N 10
#define MAX_ITER 100

float b(int k,long double a)
{	
	long double temp;
	if(k == 0)
		return(0.0);
	temp = b(k-1,a);

	return( a - (temp*temp) );
}

float bp(int k,long double a)
{
	if(k == 1)
		return(0.0);

	return(1.0 - 2.0 * bp(k-1,a) * b(k-1,a));
}

int main()
{
	int i, j, p;
	int  M = MAX_ITER;

	mpf_t aa[N][MAX_ITER+1] = {0};
	for(i=0;i<=N;i++)
	{
		for(j=0;j<=M;j++)
			mpf_init(aa[i][j]);
	}

	mpf_t delta[N];
	mpf_init(delta[0]);
	
	for(j=0;j<=M;j++)
	{
		aa[0][j] = 0.0;
		aa[1][j] = 1.0;
	}
	aa[1][M] = 1.0;
	aa[1][0] = 1.0;
	aa[0][M] = 0.0;
	delta[1] = 3.2;

	aa[2][0] = aa[1][M] + (aa[1][M] - aa[0][M])/(delta[1]);

	printf("*****\n*****\n*****\n");
	gmp_fprintf("aa[0][M] = %Lf \n",aa[0][M]);
	gmp_fprintf("aa[1][M] = %Lf \n",aa[1][M]);
	gmp_fprintf("aa[2][0] = %Lf \n\n",aa[2][0]);
	gmp_fprintf("delta(1)=%Lf\n",delta[1]);
	for(i=2;i<N;i++)
	{
		for(j=0;j<=M;j++)
		{
			aa[i][j+1] = aa[i][j] - ( b(pow(2,i+0),aa[i][j]) / bp(pow(2,i+1),aa[i][j]) );
			gmp_fprintf("aa[%d][%d+1]=%Lf \n ",i,j,aa[i][j]);
		}

		gmp_fprintf("*****\n aa[i-2]=%Lf, aa[i-2]=%Lf, aa[i]=%Lf \n\n",aa[i-2][M],aa[i-2][M],aa[i-0][M]);
		gmp_fprintf("      delta = (%Lf - %Lf)/(%Lf - %Lf)\n",aa[i-1][M],aa[i-2][M],aa[i][M],aa[i-1][M]);
		gmp_fprintf("      delta = (%Lf) / (%Lf)\n\n",aa[i-1][M]-aa[i-2][M],aa[i][M]-aa[i-1][M]);
		for(p=0;p<=i;p++)
			gmp_fprintf("aa[%d][M]=%Lf, aa[%d][M-1]=%Lf \n",p,aa[p][M],p,aa[p][M-1]);

		delta[i] = (aa[i-1][M] - aa[i-2][M])/(aa[i][M]-aa[i-1][M]);

		aa[i+1][0] = aa[i][M] + (aa[i][M] - aa[i-1][M])/(delta[i]);
		gmp_fprintf("***** delta[%d] = %Lf \n",i,delta[i]);
		gmp_fprintf("aa[%d][0] = %Lf \n",i+1,aa[i+1][0]);	
	}		
		
	for(i=1;i<N;i++)
		gmp_fprintf("aa[%d][M]=%Lf, delta[%d]=%Lf\n",i,aa[i][M],i,delta[i]);
}
	
