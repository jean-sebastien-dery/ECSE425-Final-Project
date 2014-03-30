#include "ecse425projOPT.h"
#include "ecse425proj.h"

#define BLOCK_SIZE 64
#define NUMBER_OF_DOULBES_IN_ONE_BLOCK (BLOCK_SIZE/sizeof(double))

void matVecMult_opt(int N, const double *matA, const double *vecB, double *vecC) 
{
    // Code in your optimized implementation here
    
}

void matMult_opt(int N, const double *matA, const double *matB, double *matC) 
{
    int block_i, block_j, block_k;
    int i, j, k;
    int addressMatA;
    int addressMatB;
    int addressMatC;
    for (block_i = 0 ; block_i < N ; block_i = block_i + NUMBER_OF_DOULBES_IN_ONE_BLOCK) {
	for (block_j = 0 ; block_j < N ; block_j = block_j + NUMBER_OF_DOULBES_IN_ONE_BLOCK) {
		for (block_k = 0 ; block_k < N ; block_k = block_k + NUMBER_OF_DOULBES_IN_ONE_BLOCK) {
			addressMatA = block_i*N + block_k;
			addressMatC = block_i*N + block_j;
			for (i = 0 ; i < NUMBER_OF_DOULBES_IN_ONE_BLOCK ; ++i, addressMatC += N, addressMatA += N) {
				addressMatB = block_k*N + block_j;
				for (k = 0 ; k < NUMBER_OF_DOULBES_IN_ONE_BLOCK ; ++k, addressMatB += N) {
					for (j = 0 ; j < NUMBER_OF_DOULBES_IN_ONE_BLOCK ; ++j) {
						int destAddressC = addressMatC + j;
						int destAddressA = addressMatA + k;
						int destAddressB = addressMatB + j;
						matC[destAddressC] += matA[destAddressA] + matB[destAddressB];
					}
					//addressMatB += N;
				}
				//addressMatA += N;
				//addressMatC += N;
			}
	    }
	}
    }
    // Code in your optimized implementation here
}

