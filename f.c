#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define N 19
#define MAX_ITER 5

long double b(unsigned long long int k, const long double &a);
long double bp(unsigned long long int k, const long double &a);
void saver(long double delta,int i, time_t time);

int main()
{
	int i, j;
	int  M = MAX_ITER;

//	time_t start, finish, runtime;
	time_t runtime;

	long double aa[N][MAX_ITER+1] = {{0}};
	long double delta[N];

	printf("\e[4;91mBeginning of Run\e[0m\n");

	for(j=0;j<=M;j++)
	{
		aa[0][j] = 0.0;
		aa[1][j] = 1.0;
	}
	
	delta[1] = 3.20;

	aa[2][0] = aa[1][M] + (aa[1][M] - aa[0][M])/(delta[1]);

	printf("\n\n");
	printf("aa[0][M] = %3.30Lf \n",aa[0][M]);
	printf("aa[1][M] = %3.30Lf \n",aa[1][M]);
	printf("aa[2][0] = %3.30Lf \n\n",aa[2][0]);
	printf("delta(1)=%3.30Lf\n",delta[1]);

	for(i=2;i<N-1;i++)
	{
		runtime = time(NULL);
		printf("\e[1;34mIteration (%d)  \e[0m\n",i);
	
		for(j=0;j<M;j++)
			aa[i][j+1] = aa[i][j] - ( b(1<<i,aa[i][j]) / bp(1<<i,aa[i][j]) );		

		delta[i] = (aa[i-1][M] - aa[i-2][M])/(aa[i][M]-aa[i-1][M]);

		aa[i+1][0] = aa[i][M] + (aa[i][M] - aa[i-1][M])/(delta[i]);
//		finish = time(NULL);
		runtime = time(NULL) - runtime;

		printf("*** delta[%d-1] = %3.30Lf \n",i,delta[i-1]);
		printf("***   delta[%d] = %3.30Lf \n",i,delta[i]);
		printf("\n*** aa[%d-1][0] = %3.30Lf \n",i+1,aa[i][0]);	
		printf("***   aa[%d][0] = %3.30Lf \n",i+1,aa[i+1][0]);	
		printf("***   Time to finish %dth loop: %lu seconds\n\n",i,(unsigned long)runtime);

		saver(delta[i],i,runtime);
	}		
		
	for(i=1;i<N-1;i++)
		printf("aa[%d][M]=%3.30Lf, delta[%d]=%3.30Lf\n",i,aa[i][M],i,delta[i]);
	printf("\n");

//	printf("Segmentation fault.\n");
	return 0;
}

long double b(unsigned long long int k, const long double &a)
{	
        long double val = 0;
        while(k > 0) {
            val = a - val*val;
            k--;
        }
        return val;
//	if (k == 0)
//		return(0.0);
//	return( a - pow(b(k-1,a),2) );
}

long double bp(unsigned long long int k, const long double &a)
{
	if (k == 0)
		return(0.0);
	return(1.0 - 2.0 * bp(k-1,a) * b(k-1,a));
//	long double temp = 0;
//	while(k>0)
//	{
//		temp = 1.0 - 2.0 * temp*b(k-1,a);
//		k--;
//	}
//	return temp;
}

void saver(long double delta, int i, time_t time)
{
	FILE *file;
	file = fopen("output.txt","a");
	fprintf(file,"\nAfter %d iterations (in %llu seconds):\n%3.30Lf\n",i,(unsigned long long int)time,delta);
	fclose(file);
	
	return;
}
