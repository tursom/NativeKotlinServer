//
// Created by tursom on 19-7-3.
//

#ifndef JNI_NET_H
#define JNI_NET_H


#include "jni.h"

void htonll(jlong *l);

inline long ntohll(jlong l) {
	htonll(&l);
	return l;
}

extern jboolean True;
extern jboolean False;

#endif //JNI_NET_H
