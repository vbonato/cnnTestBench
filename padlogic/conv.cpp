#include "conv.h"

void conv(type_t I[C * H * H], type_t W[M * C * R * R], type_t O[M * E * E]) {
	// LOF
	for(int m = 0; m < M; m++) {
		// LIF
		for(int c = 0; c < C ; c++) {
			// LSY
			for(int y = 0; y < E; y++) {
				// LSX
				for(int x = 0; x < E; x++) {
					// LFY
					for(int k = 0; k < R; k++) {
						// LFX
						for(int l = 0; l < R; l++) {
							int h1 = y * S - P + k;
							int h2 = x * S - P + l;
							// c * H * H + h1 * H + h2 = h2 + (h1 + (c * H)) * H
							type_t i = (h1 < 0 || h1 >= H || h2 < 0 || h2 >= H)? 0 : I[h2 + (h1 + (c * H)) * H];

							// m * E * E + y * E + x = x + (y + (m * E)) * E
							// m * C * R * R + c * R * R + k * R + l = l + (k + (c + (m * C)) * R) * R
							O[x + (y + (m * E)) * E] += i * W[l + (k + (c + (m * C)) * R) * R];
						}
					}
				}
			}
		}
	}
}
