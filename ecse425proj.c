#include "ecse425proj.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Specify the data layout format */
const DLayout dlayout = RowMaj;

void randInitialize(int sz, double *vPtr)
{
    int i;
    for (i = 0; i < sz; i++)
        vPtr[i] = drand48();
}

void displayVec(int sz, const double *vPtr)
{
    if(dlayout == RowMaj)
    {
        int i;
        printf("[");
        for (i = 0; i < sz; i++)
        {
            printf("%e",vPtr[i]);
            if(i < sz-1)
                printf(",");
            else
                printf("]");
        }
    }
}

void displayMat(int rows, int cols, const double *vPtr)
{
    if(dlayout == RowMaj)
    {
        int i;
        printf("[\n");
        for (i = 0; i < rows; i++) {
            displayVec(cols, &vPtr[i*rows]);
            printf("\n");
        }
        printf("]");
    }
}

void matMult(int N, const double *matA, const double *matB, double *matC)
{
    if(dlayout == RowMaj)
    {
	int i;
    	for(i=0; i < N*N; i++)
    	{
    		int row = i/N;
    		int col = i%N;
    		int startingNum = row*N;
    		matC[i]=0;
		int j;
    		for (j=0; j<N; j++)
    		{
    			matC[i] += matA[startingNum+j]*matB[j*N+col];
    		}
    	}
    }

}

void matVecMult(int N, const double *matA, const double *vecB, double *vecC)
{
    if(dlayout == RowMaj)
    {
    	//printf("%i", N);
    	int i;
    	for(i = 0; i < N; i++)
    	{
    		int row = i;
    		int startingNum = row*N;
    		vecC[i] = 0;
		int j;
    		for(j=0; j < N; j++)
    		{
    			vecC[i] += matA[startingNum+j]*vecB[j];
    		}
    	}
    }
}

double compareVecs(int N, const double *src, const double *ref)
{
    double ds = 0., ss = 0.;
    int i;
    for(i = 0; i < N; i++)
    {
        ds += (src[i] - ref[i]) * (src[i] - ref[i]);
        ss += ref[i] * ref[i];
    }
    ss = ds/ss;
    printf("Error SQUARED is: %e\n",ss);
    return ss;
}
