#include <stdio.h>
#include <math.h>
#include <string.h>

#define N 10
#define MAX_ITER 5

float b(int k,float a)
<<<<<<< HEAD
{	
	float temp;
	if (k == 0)
		return(0.0);
	temp = b(k-1,a);
	return(a - temp*temp);
=======
{
        float temp;
        if (k == 0)
                return(0.0);
        temp = b(k-1,a);
        return(a - temp*temp);
>>>>>>> a94d233e62a2649ce02cade3d3867ad5a0bf42a7
}

float bp(int k,float a)
{
<<<<<<< HEAD
	if (k == 1)
		return(0.0);

	return(1.0 - 2.0 * bp(k-1,a) * b(k-1,a));
=======
        if (k == 1)
                return(0.0);

        return(1.0 - 2.0 * bp(k-1,a) * b(k-1,a));
>>>>>>> a94d233e62a2649ce02cade3d3867ad5a0bf42a7
}

int main()
{
<<<<<<< HEAD
	int i, j;
	float a[N], anext[N];
	float delta[N];
	
	a[0] = anext[0] = 0.0;
	a[1] = anext[1] = 1.0;
	delta[1] = 3.2;
	
	for(i=2;i<N;i++)
		{
			a[i] = a[i-1] + (a[i-1] - a[i-2])/(delta[i-1]);
			delta[i] = (a[i-1] - a[i-2])/(a[i]-a[i-1]);
		}
		
	for(j=1;j<=MAX_ITER;j++)
		{
			printf("Interation %d\n",j);
			for(i=2;i<N;i++)
				{
					anext[i] = a[i] - b(1<<i,a[i])/bp(1<<i,a[i]);
				}
			memmove(a,anext,sizeof(float) * N);
		}
			
		
		
	for(i=2;i<N;i++)
		{
			delta[i] = (a[i-1] - a[i-2])/(a[i]-a[i-1]);
		}
	
	for(i=0;i<N;i++)
		printf("a[%d]=%f, delta[%d]=%f\n",i,a[i],i,delta[i]);
}
	
=======
        int i, j;
        float a[N], anext[N];
        float delta[N];

        a[0] = anext[0] = 0.0;
        a[1] = anext[1] = 1.0;
        delta[1] = 3.2;

        for(i=2;i<N;i++)
                {
                        a[i] = a[i-1] + (a[i-1] - a[i-2])/(delta[i-1]);
                        delta[i] = (a[i-1] - a[i-2])/(a[i]-a[i-1]);
                }

        for(j=1;j<=MAX_ITER;j++)
                {
                        printf("Interation %d\n",j);
                        for(i=2;i<N;i++)
                                {
                                        anext[i] = a[i] - b(1<<i,a[i])/bp(1<<i,a[i]);
                                }
                        memmove(a,anext,sizeof(float) * N);
                }                                                               



        for(i=2;i<N;i++)
                {
                        delta[i] = (a[i-1] - a[i-2])/(a[i]-a[i-1]);
                }

        for(i=0;i<N;i++)
                printf("a[%d]=%f, delta[%d]=%f\n",i,a[i],i,delta[i]);
}
>>>>>>> a94d233e62a2649ce02cade3d3867ad5a0bf42a7
