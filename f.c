#include <stdio.h>
#include <math.h>
#include <string.h>

#define N 15
#define MAX_ITER 50

float b(int k,float a)
{	
	float temp;
	if (k == 0)
		return(0.0);
	temp = b(k-1,a);
	return(a - temp*temp);
}

float bp(int k,float a)
{
	if (k == 1)
		return(0.0);

	return(1.0 - 2.0 * bp(k-1,a) * b(k-1,a));
}

int main()
{
	int i, j;
	int  M = MAX_ITER;

	float aa[N][MAX_ITER] = {0};
	float delta[N];
	
//	aa[0][0] = 0.0;
//	aa[0][M] = 0.0;
	aa[1][0] = 1.0;
	aa[1][M] = 1.0;
//	for(j=0;j<=M;

	delta[1] = 3.2;
	
	for(i=2;i<N;i++)
		{
			aa[i][0] = aa[i-1][M] + (aa[i-1][M] - aa[i-2][M])/(delta[i-1]);
			delta[i] = (aa[i-1][M] - aa[i-2][M])/(aa[i][M]-aa[i-1][M]);
			printf("aa[%d][0] = %f \n",i,aa[i][0]);
		}
		
	for(j=1;j<=MAX_ITER;j++)
		{
			printf("Interation %d\n",j);
			for(i=2;i<N;i++)
				{
					aa[i][j+1] = aa[i][j] - b(1<<i,aa[i][j])/bp(1<<i,aa[i][j]);
					printf("aa[%d][%d+1]=%f \n",i,j,aa[i][j]);
				}
//			memmove(a0,a,sizeof(float) * N);
		}
			
		
		
	for(i=2;i<N;i++)
			{
			delta[i] = (aa[i-1][M] - aa[i-2][M])/(aa[i][M]-aa[i-1][M]);
		}
	
	for(i=0;i<N;i++)
		printf("aa[%d][END]=%f, delta[%d]=%f\n",i,aa[i][M],i,delta[i]);
}
	
