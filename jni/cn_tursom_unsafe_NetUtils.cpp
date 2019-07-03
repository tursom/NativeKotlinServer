//
// Created by tursom on 19-7-3.
//

#include <netinet/in.h>
#include "cn_tursom_unsafe_NetUtils.h"
#include "net.h"
/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toByteArray
 * Signature: ([C)[B
 */
JNIEXPORT jbyteArray JNICALL Java_cn_tursom_unsafe_NetUtils_toByteArray___3C
		(JNIEnv *env, jobject, jcharArray jcharArray1) {
	unsigned short *c = env->GetCharArrayElements(jcharArray1, &True);
	int size = env->GetArrayLength(jcharArray1);
	for (int i = 0; i < size; ++i) {
		c[i] = htons(c[i]);
	}
	auto byteArray = env->NewByteArray(size * 2);
	env->SetByteArrayRegion(byteArray, 0, size * 2, (signed char *) c);
	return byteArray;
}


/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toByteArray
 * Signature: ([S)[B
 */
JNIEXPORT jbyteArray JNICALL Java_cn_tursom_unsafe_NetUtils_toByteArray___3S
		(JNIEnv *env, jobject, jshortArray jshortArray1) {
	short *shortArray = env->GetShortArrayElements(jshortArray1, &True);
	int size = env->GetArrayLength(jshortArray1);
	for (int i = 0; i < size; ++i) {
		shortArray[i] = htons(shortArray[i]);
	}
	auto byteArray = env->NewByteArray(size * 2);
	env->SetByteArrayRegion(byteArray, 0, size * 2, (signed char *) shortArray);
	return byteArray;
}

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toByteArray
 * Signature: ([I)[B
 */
JNIEXPORT jbyteArray JNICALL Java_cn_tursom_unsafe_NetUtils_toByteArray___3I
		(JNIEnv *env, jobject, jintArray jintArray1) {
	int *shortArray = env->GetIntArrayElements(jintArray1, &True);
	int size = env->GetArrayLength(jintArray1);
	for (int i = 0; i < size; ++i) {
		shortArray[i] = htonl(shortArray[i]);
	}
	auto byteArray = env->NewByteArray(size * 4);
	env->SetByteArrayRegion(byteArray, 0, size * 4, (signed char *) shortArray);
	return byteArray;
}

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toByteArray
 * Signature: ([J)[B
 */
JNIEXPORT jbyteArray JNICALL Java_cn_tursom_unsafe_NetUtils_toByteArray___3J
		(JNIEnv *env, jobject, jlongArray jlongArray1) {
	long *shortArray = env->GetLongArrayElements(jlongArray1, &True);
	int size = env->GetArrayLength(jlongArray1);
	for (int i = 0; i < size; ++i) {
		htonll(&shortArray[i]);
	}
	auto byteArray = env->NewByteArray(size * 8);
	env->SetByteArrayRegion(byteArray, 0, size, (signed char *) shortArray);
	return byteArray;
}

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toByteArray
 * Signature: ([C[BI)Z
 */
JNIEXPORT jboolean JNICALL Java_cn_tursom_unsafe_NetUtils_toByteArray___3C_3BI
		(JNIEnv *env, jobject, jcharArray jcharArray1, jbyteArray jbyteArray1, jint offset) {
	unsigned short *c = env->GetCharArrayElements(jcharArray1, &True);
	int size = env->GetArrayLength(jcharArray1);
	for (int i = 0; i < size; ++i) {
		c[i] = ntohs(c[i]);
	}
	env->SetByteArrayRegion(jbyteArray1, offset, size * 2, (signed char *) c);
	return true;
}

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toByteArray
 * Signature: ([S[BI)Z
 */
JNIEXPORT jboolean JNICALL Java_cn_tursom_unsafe_NetUtils_toByteArray___3S_3BI
		(JNIEnv *env, jobject, jshortArray jshortArray1, jbyteArray jbyteArray1, jint offset) {
	short *shortArray = env->GetShortArrayElements(jshortArray1, &True);
	int size = env->GetArrayLength(jshortArray1);
	for (int i = 0; i < size; ++i) {
		shortArray[i] = htons(shortArray[i]);
	}
	env->SetByteArrayRegion(jbyteArray1, offset, size * 2, (signed char *) shortArray);
	return true;
}

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toByteArray
 * Signature: ([I[BI)Z
 */
JNIEXPORT jboolean JNICALL Java_cn_tursom_unsafe_NetUtils_toByteArray___3I_3BI
		(JNIEnv *env, jobject, jintArray jintArray1, jbyteArray jbyteArray1, jint offset) {
	int *shortArray = env->GetIntArrayElements(jintArray1, &True);
	int size = env->GetArrayLength(jintArray1);
	for (int i = 0; i < size; ++i) {
		shortArray[i] = htonl(shortArray[i]);
	}
	env->SetByteArrayRegion(jbyteArray1, offset, size * 4, (signed char *) shortArray);
	return true;
}

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toByteArray
 * Signature: ([J[BI)Z
 */
JNIEXPORT jboolean JNICALL Java_cn_tursom_unsafe_NetUtils_toByteArray___3J_3BI
		(JNIEnv *env, jobject, jlongArray jlongArray1, jbyteArray jbyteArray1, jint offset) {
	long *shortArray = env->GetLongArrayElements(jlongArray1, &True);
	int size = env->GetArrayLength(jlongArray1);
	for (int i = 0; i < size; ++i) {
		htonll(&shortArray[i]);
	}
	env->SetByteArrayRegion(jbyteArray1, offset, size * 8, (signed char *) shortArray);
	return true;
}

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toCharArray
 * Signature: ([B)[C
 */
JNIEXPORT jcharArray JNICALL Java_cn_tursom_unsafe_NetUtils_toCharArray
		(JNIEnv *env, jobject, jbyteArray jbyteArray1) {
	auto byteArray = (unsigned short *) env->GetByteArrayElements(jbyteArray1, &False);
	int size = env->GetArrayLength(jbyteArray1) / 2;
	for (int i = 0; i < size; ++i) {
		byteArray[i] = ntohs(byteArray[i]);
	}
	jcharArray newCharArray = env->NewCharArray(size);
	env->SetCharArrayRegion(newCharArray, 0, size, byteArray);
	return newCharArray;
}

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toShortArray
 * Signature: ([B)[S
 */
JNIEXPORT jshortArray JNICALL Java_cn_tursom_unsafe_NetUtils_toShortArray
		(JNIEnv *env, jobject, jbyteArray jbyteArray1) {
	auto byteArray = (short *) env->GetByteArrayElements(jbyteArray1, &False);
	int size = env->GetArrayLength(jbyteArray1) / 2;
	for (int i = 0; i < size; ++i) {
		byteArray[i] = ntohs(byteArray[i]);
	}
	auto newArray = env->NewShortArray(size);
	env->SetShortArrayRegion(newArray, 0, size, byteArray);
	return newArray;
}


/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toIntArray
 * Signature: ([B)[I
 */
JNIEXPORT jintArray JNICALL Java_cn_tursom_unsafe_NetUtils_toIntArray
		(JNIEnv *env, jobject, jbyteArray jbyteArray1) {
	auto byteArray = (int *) env->GetByteArrayElements(jbyteArray1, &False);
	int size = env->GetArrayLength(jbyteArray1) / 4;
	for (int i = 0; i < size; ++i) {
		byteArray[i] = ntohl(byteArray[i]);
	}
	auto newArray = env->NewIntArray(size);
	env->SetIntArrayRegion(newArray, 0, size, byteArray);
	return newArray;
}

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toLongArray
 * Signature: ([B)[J
 */
JNIEXPORT jlongArray JNICALL Java_cn_tursom_unsafe_NetUtils_toLongArray
		(JNIEnv *env, jobject, jbyteArray jbyteArray1) {
	auto byteArray = (long *) env->GetByteArrayElements(jbyteArray1, &False);
	int size = env->GetArrayLength(jbyteArray1) / 8;
	for (int i = 0; i < size; ++i) {
		byteArray[i] = ntohll(byteArray[i]);
	}
	auto newArray = env->NewLongArray(size);
	env->SetLongArrayRegion(newArray, 0, size, byteArray);
	return newArray;
}

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toChar
 * Signature: ([BI)C
 */
JNIEXPORT jchar JNICALL Java_cn_tursom_unsafe_NetUtils_toChar
		(JNIEnv *env, jobject, jbyteArray jbyteArray1, jint offset) {
	auto byteArray = env->GetByteArrayElements(jbyteArray1, &False);
	return ntohs(*(jchar *) (byteArray + offset));
}

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toShort
 * Signature: ([BI)S
 */
JNIEXPORT jshort JNICALL Java_cn_tursom_unsafe_NetUtils_toShort
		(JNIEnv *env, jobject, jbyteArray jbyteArray1, jint offset) {
	auto byteArray = env->GetByteArrayElements(jbyteArray1, &False);
	return ntohs(*(jshort *) (byteArray + offset));
}

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toInt
 * Signature: ([BI)I
 */
JNIEXPORT jint JNICALL Java_cn_tursom_unsafe_NetUtils_toInt
		(JNIEnv *env, jobject, jbyteArray jbyteArray1, jint offset) {
	auto byteArray = env->GetByteArrayElements(jbyteArray1, &False);
	return ntohl(*(jint *) (byteArray + offset));
}

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toLong
 * Signature: ([BI)J
 */
JNIEXPORT jlong JNICALL Java_cn_tursom_unsafe_NetUtils_toLong
		(JNIEnv *env, jobject, jbyteArray jbyteArray1, jint offset) {
	auto byteArray = env->GetByteArrayElements(jbyteArray1, &False);
	return ntohll(*(jlong *) (byteArray + offset));
}

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    ntoh
 * Signature: (S)S
 */
JNIEXPORT jshort JNICALL Java_cn_tursom_unsafe_NetUtils_ntoh__S
		(JNIEnv *, jobject, jshort jshort1) {
	return ntohs(jshort1);
}

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    hton
 * Signature: (S)S
 */
JNIEXPORT jshort JNICALL Java_cn_tursom_unsafe_NetUtils_hton__S
		(JNIEnv *, jobject, jshort jshort1) {
	return htons(jshort1);
}

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    ntoh
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_cn_tursom_unsafe_NetUtils_ntoh__I
		(JNIEnv *, jobject, jint jint1) {
	return ntohl(jint1);
}

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    hton
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_cn_tursom_unsafe_NetUtils_hton__I
		(JNIEnv *, jobject, jint jint1) {
	return htonl(jint1);
}

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    ntoh
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_cn_tursom_unsafe_NetUtils_ntoh__J
		(JNIEnv *, jobject, jlong jlong1) {
	return ntohll(jlong1);
}

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    hton
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_cn_tursom_unsafe_NetUtils_hton__J
		(JNIEnv *, jobject, jlong jlong1) {
	return ntohll(jlong1);
}