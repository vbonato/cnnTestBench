#include <cstdio>
#include <cstdlib>

#include "conv_tb.h"
#include "conv.h"

int main(void) {
	type_t *I = (type_t *) malloc(C * H * H * sizeof(type_t));
	type_t *W = (type_t *) malloc(M * C * R * R * sizeof(type_t));
	type_t *OL1 = (type_t *) calloc(M * E * E, sizeof(type_t));
	type_t *OL2 = (type_t *) calloc(M * E * E, sizeof(type_t));

	srand(1);
	for(unsigned i = 0; i < C * H * H; i++)
		I[i] = rand() % RANDROOF;
	for(unsigned i = 0; i < M * C * R * R; i++)
		W[i] = rand() % RANDROOF;

	conv(I, W, OL1);
	//conv(OL1, W, OL2);
	for(int i=0; i< M * E * E; i++)
	{
		printf("%x ",OL1[i]);
	}
	

	FILE *opf = fopen("output.bin", "wb");
	fwrite(OL1, sizeof(type_t), M * E * E, opf);
	fclose(opf);

	if(I) free(I);
	if(W) free(W);
	if(OL1) free(OL1);
	if(OL2) free(OL2);

	return EXIT_SUCCESS;
}
