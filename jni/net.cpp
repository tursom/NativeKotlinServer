//
// Created by tursom on 19-7-3.
//

#include "net.h"

jboolean True = true;
jboolean False = false;

void htonll(jlong *l) {
	auto *c = (unsigned char *) l;
	for (int i = 0; i < 4; ++i) {
		c[i] ^= c[7 - i];
		c[7 - i] ^= c[i];
		c[i] ^= c[7 - i];
	}
}