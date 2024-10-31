#include <cstdio>
#include <cstdlib>

#include "conv_tb3.h"
#include "conv3.h"

int main(void) {
    type_t *I1 = (type_t *) malloc(C1 * H1 * H1 * sizeof(type_t));
    type_t *W1 = (type_t *) malloc(M1 * C1 * R1 * R1 * sizeof(type_t));
    type_t *OL1 = (type_t *) calloc(M1 * E1 * E1, sizeof(type_t));
    type_t *I2 = (type_t *) malloc(C2 * H2 * H2 * sizeof(type_t));
    type_t *W2 = (type_t *) malloc(M2 * C2 * R2 * R2 * sizeof(type_t));
    type_t *OL2 = (type_t *) calloc(M2 * E2 * E2, sizeof(type_t));
    type_t *I3 = (type_t *) malloc(C3 * H3 * H3 * sizeof(type_t));
    type_t *W3 = (type_t *) malloc(M3 * C3 * R3 * R3 * sizeof(type_t));
    type_t *OL3 = (type_t *) calloc(M3 * E3 * E3, sizeof(type_t));

    srand(1);
    for(unsigned j = 0; j < C1 * H1 * H1; j++)
        I1[j] = rand() % RANDROOF;
    for(unsigned j = 0; j < C2 * H2 * H2; j++)
        I2[j] = rand() % RANDROOF;
    for(unsigned j = 0; j < C3 * H3 * H3; j++)
        I3[j] = rand() % RANDROOF;
    for(unsigned j = 0; j < M1 * C1 * R1 * R1; j++)
        W1[j] = rand() % RANDROOF;
    for(unsigned j = 0; j < M2 * C2 * R2 * R2; j++)
        W2[j] = rand() % RANDROOF;
    for(unsigned j = 0; j < M3 * C3 * R3 * R3; j++)
        W3[j] = rand() % RANDROOF;

    // Perform convolutions
    conv1(I1, W1, OL1);
    conv2(I2, W2, OL2);
    conv3(I3, W3, OL3);

    // Output results
    for(int j = 0; j < M3 * E3 * E3; j++) {
        printf("%x ", OL3[j]);
    }

    // Write output to files
    FILE *opf1 = fopen("output1.bin", "wb");
    fwrite(OL1, sizeof(type_t), M1 * E1 * E1, opf1);
    fclose(opf1);
    FILE *opf2 = fopen("output2.bin", "wb");
    fwrite(OL2, sizeof(type_t), M2 * E2 * E2, opf2);
    fclose(opf2);
    FILE *opf3 = fopen("output3.bin", "wb");
    fwrite(OL3, sizeof(type_t), M3 * E3 * E3, opf3);
    fclose(opf3);

    // Free allocated memory
    if(I1) free(I1);
    if(W1) free(W1);
    if(OL1) free(OL1);
    if(I2) free(I2);
    if(W2) free(W2);
    if(OL2) free(OL2);
    if(I3) free(I3);
    if(W3) free(W3);
    if(OL3) free(OL3);

    return EXIT_SUCCESS;
}