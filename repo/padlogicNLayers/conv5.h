#ifndef CONV_H
#define CONV_H

#include <cstddef>

// XXX Should this be sorta "fixed-point"? If positive, the convolution arithmetics (more specifically the product) should be changed accordingly?
typedef unsigned type_t;

// ZFNet 6
// (see https://arxiv.org/pdf/1902.01492.pdf and https://arxiv.org/pdf/1311.2901v3.pdf)


// Number of input feature maps (N. channels in)
const size_t C1 = 256;
const size_t C2 = 256;
const size_t C3 = 256;
const size_t C4 = 256;
const size_t C5 = 256;

// Number of output features maps (N. channels out)
const size_t M1 = 256;
const size_t M2 = 256;
const size_t M3 = 256;
const size_t M4 = 256;
const size_t M5 = 256;

// Input feature map size (H x H) 
const size_t H1 = 6;
const size_t H2 = 6;
const size_t H3 = 6;
const size_t H4 = 6;
const size_t H5 = 6;

// Convolution kernel size (R x R)
const size_t R1 = 5;
const size_t R2 = 5;
const size_t R3 = 5;
const size_t R4 = 5;
const size_t R5 = 5;

// Convolution kernel stride
const size_t S1 = 1;
const size_t S2 = 1;
const size_t S3 = 1;
const size_t S4 = 1;
const size_t S5 = 1;

// Output feature map size (E x E)
const size_t E1 = 6;
const size_t E2 = 6;
const size_t E3 = 6;
const size_t E4 = 6;
const size_t E5 = 6;

// Input feature map size with padding (F x F)
const size_t F1 = ((E1 * S1 + R1 - 1) < H1)? H1 : (E1 * S1 + R1 - 1);
const size_t F2 = ((E2 * S2 + R2 - 1) < H2)? H2 : (E2 * S2 + R2 - 1);
const size_t F3 = ((E3 * S3 + R3 - 1) < H3)? H3 : (E3 * S3 + R3 - 1);
const size_t F4 = ((E4 * S4 + R4 - 1) < H4)? H4 : (E4 * S4 + R4 - 1);
const size_t F5 = ((E5 * S5 + R5 - 1) < H5)? H5 : (E5 * S5 + R5 - 1);

// Padding size
const size_t P1 = (F1 - H1) / 2;
const size_t P2 = (F2 - H2) / 2;
const size_t P3 = (F3 - H3) / 2;
const size_t P4 = (F4 - H4) / 2;
const size_t P5 = (F5 - H5) / 2;

void conv1(type_t I1[C1 * H1 * H1], type_t W1[M1 * C1 * R1 * R1], type_t O1[M1 * E1 * E1]);
void conv2(type_t I2[C2 * H2 * H2], type_t W2[M2 * C2 * R2 * R2], type_t O2[M2 * E2 * E2]);
void conv3(type_t I3[C3 * H3 * H3], type_t W3[M3 * C3 * R3 * R3], type_t O3[M3 * E3 * E3]);
void conv4(type_t I4[C4 * H4 * H4], type_t W4[M4 * C4 * R4 * R4], type_t O4[M4 * E4 * E4]);
void conv5(type_t I5[C5 * H5 * H5], type_t W5[M5 * C5 * R5 * R5], type_t O5[M5 * E5 * E5]);

#endif
