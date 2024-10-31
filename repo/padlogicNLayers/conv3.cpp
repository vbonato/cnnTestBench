#include "conv3.h"

void conv1(type_t I1[C1 * H1 * H1], type_t W1[M1 * C1 * R1 * R1], type_t O1[M1 * E1 * E1]) {
    // LOF
    for(int m = 0; m < M1; m++) {
        // LIF
        for(int c = 0; c < C1; c++) {
            // LSY
            for(int y = 0; y < E1; y++) {
                // LSX
                for(int x = 0; x < E1; x++) {
                    // LFY
                    for(int k = 0; k < R1; k++) {
                        // LFX
                        for(int l = 0; l < R1; l++) {
                            int h1 = y * S1 - P1 + k;
                            int h2 = x * S1 - P1 + l;
                            type_t i = (h1 < 0 || h1 >= H1 || h2 < 0 || h2 >= H1) ? 0 : I1[h2 + (h1 + (c * H1)) * H1];
                            O1[x + (y + (m * E1)) * E1] += i * W1[l + (k + (c + (m * C1)) * R1) * R1];
                        }
                    }
                }
            }
        }
    }
}

void conv2(type_t I2[C2 * H2 * H2], type_t W2[M2 * C2 * R2 * R2], type_t O2[M2 * E2 * E2]) {
    // LOF
    for(int m = 0; m < M2; m++) {
        // LIF
        for(int c = 0; c < C2; c++) {
            // LSY
            for(int y = 0; y < E2; y++) {
                // LSX
                for(int x = 0; x < E2; x++) {
                    // LFY
                    for(int k = 0; k < R2; k++) {
                        // LFX
                        for(int l = 0; l < R2; l++) {
                            int h1 = y * S2 - P2 + k;
                            int h2 = x * S2 - P2 + l;
                            type_t i = (h1 < 0 || h1 >= H2 || h2 < 0 || h2 >= H2) ? 0 : I2[h2 + (h1 + (c * H2)) * H2];
                            O2[x + (y + (m * E2)) * E2] += i * W2[l + (k + (c + (m * C2)) * R2) * R2];
                        }
                    }
                }
            }
        }
    }
}

void conv3(type_t I3[C3 * H3 * H3], type_t W3[M3 * C3 * R3 * R3], type_t O3[M3 * E3 * E3]) {
    // LOF
    for(int m = 0; m < M3; m++) {
        // LIF
        for(int c = 0; c < C3; c++) {
            // LSY
            for(int y = 0; y < E3; y++) {
                // LSX
                for(int x = 0; x < E3; x++) {
                    // LFY
                    for(int k = 0; k < R3; k++) {
                        // LFX
                        for(int l = 0; l < R3; l++) {
                            int h1 = y * S3 - P3 + k;
                            int h2 = x * S3 - P3 + l;
                            type_t i = (h1 < 0 || h1 >= H3 || h2 < 0 || h2 >= H3) ? 0 : I3[h2 + (h1 + (c * H3)) * H3];
                            O3[x + (y + (m * E3)) * E3] += i * W3[l + (k + (c + (m * C3)) * R3) * R3];
                        }
                    }
                }
            }
        }
    }
}

