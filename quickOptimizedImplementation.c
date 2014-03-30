#define BLOCK_SIZE 64
#define NUMBER_OF_DOULBES_IN_ONE_BLOCK BLOCK_SIZE/sizeof(double)

int block_i, block_j, block_k;
int i, j, k;
int addressMatA, addressMatB, addressMatC;
for (block_i = 0 ; block_i < N ; block_i = block_i + NUMBER_OF_DOULBES_IN_ONE_BLOCK) {
	for (block_j = 0 ; block_i < N ; block_j = block_j + NUMBER_OF_DOULBES_IN_ONE_BLOCK) {
		for (block_k = 0 ; block_k < N ; block_k = block_k + NUMBER_OF_DOULBES_IN_ONE_BLOCK) {

			addressMatA = &addressMatA[block_i*N + block_k];
			addressMatC = &addressMatC[block_i*N + block_j];
			for (i = 0 ; i < NUMBER_OF_DOULBES_IN_ONE_BLOCK ; ++i) {

				addressMatB = &addressMatB[block_k*N + block_j];
				for (k = 0 ; k < NUMBER_OF_DOULBES_IN_ONE_BLOCK ; ++k) {

					for (j = 0 ; j < NUMBER_OF_DOULBES_IN_ONE_BLOCK ; ++j) {

						addressMatC[j] += addressMatA[k] + addressMatB[i];

					}

					addressMatB += N;
				}

				addressMatA += N;
				addressMatC += N;
			}

		}
	}
}