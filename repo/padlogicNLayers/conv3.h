#ifndef CONV_H
#define CONV_H

#include <cstddef>

typedef unsigned type_t;

// Number of input feature maps (N. channels in)
const size_t C1 = 256;
const size_t C2 = 256;
const size_t C3 = 256;

// Number of output feature maps (N. channels out)
const size_t M1 = 256;
const size_t M2 = 256;
const size_t M3 = 256;

// Input feature map size (H x H)
const size_t H1 = 6;
const size_t H2 = 6;
const size_t H3 = 6;

// Convolution kernel size (R x R)
const size_t R1 = 5;
const size_t R2 = 5;
const size_t R3 = 5;

// Convolution kernel stride
const size_t S1 = 1;
const size_t S2 = 1;
const size_t S3 = 1;

// Output feature map size (E x E)
const size_t E1 = 6;
const size_t E2 = 6;
const size_t E3 = 6;

// Input feature map size with padding (F x F)
const size_t F1 = ((E1 * S1 + R1 - 1) < H1) ? H1 : (E1 * S1 + R1 - 1);
const size_t F2 = ((E2 * S2 + R2 - 1) < H2) ? H2 : (E2 * S2 + R2 - 1);
const size_t F3 = ((E3 * S3 + R3 - 1) < H3) ? H3 : (E3 * S3 + R3 - 1);

// Padding size
const size_t P1 = (F1 - H1) / 2;
const size_t P2 = (F2 - H2) / 2;
const size_t P3 = (F3 - H3) / 2;

void conv1(type_t I1[C1 * H1 * H1], type_t W1[M1 * C1 * R1 * R1], type_t O1[M1 * E1 * E1]);
void conv2(type_t I2[C2 * H2 * H2], type_t W2[M2 * C2 * R2 * R2], type_t O2[M2 * E2 * E2]);
void conv3(type_t I3[C3 * H3 * H3], type_t W3[M3 * C3 * R3 * R3], type_t O3[M3 * E3 * E3]);

#endif