#ifndef CONV_H
#define CONV_H

#include <cstddef>

// XXX Should this be sorta "fixed-point"? If positive, the convolution arithmetics (more specifically the product) should be changed accordingly?
typedef unsigned type_t;

// ZFNet 6
// (see https://arxiv.org/pdf/1902.01492.pdf and https://arxiv.org/pdf/1311.2901v3.pdf)

// Number of input feature maps (N. channels in)
const size_t C = 256;

// Number of output features maps (N. channels out)
const size_t M = 256;

// Input feature map size (H x H) 
const size_t H = 6;

// Convolution kernel size (R x R)
const size_t R = 3;

// Convolution kernel stride
const size_t S = 1;

// Output feature map size (E x E)
const size_t E = 6;

// Input feature map size with padding (F x F)
const size_t F = ((E * S + R - 1) < H)? H : (E * S + R - 1);
// Padding size
const size_t P = (F - H) / 2;

void conv(type_t I[C * H * H], type_t W[M * C * R * R], type_t O[M * E * E]);

#endif
