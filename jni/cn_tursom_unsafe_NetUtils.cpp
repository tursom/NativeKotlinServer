//
// Created by tursom on 19-7-3.
//

#include <netinet/in.h>
#include <zconf.h>
#include "cn_tursom_unsafe_NetUtils.h"
#include "net.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toByteArray
 * Signature: ([C)[B
 */
JNIEXPORT jbyteArray JNICALL Java_cn_tursom_unsafe_NetUtils_toByteArray___3C
		(JNIEnv *env, jobject, jcharArray jcharArray1) {
	jint size = env->GetArrayLength(jcharArray1);
	auto newByteArray = env->NewByteArray(size * 2);
	auto fromArray = (jchar *) env->GetPrimitiveArrayCritical(jcharArray1, nullptr);
	auto byteArray = (jchar *) env->GetPrimitiveArrayCritical(newByteArray, nullptr);
	for (int i = 0; i < size; ++i) {
		byteArray[i] = htons(fromArray[i]);
	}
	env->ReleasePrimitiveArrayCritical(jcharArray1, fromArray, 0);
	env->ReleasePrimitiveArrayCritical(newByteArray, byteArray, 0);
	return newByteArray;
}


/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toByteArray
 * Signature: ([S)[B
 */
JNIEXPORT jbyteArray JNICALL Java_cn_tursom_unsafe_NetUtils_toByteArray___3S
		(JNIEnv *env, jobject, jshortArray jshortArray1) {
	jint size = env->GetArrayLength(jshortArray1);
	auto newByteArray = env->NewByteArray(size * 2);
	auto fromArray = (jshort *) env->GetPrimitiveArrayCritical(jshortArray1, nullptr);
	auto byteArray = (jshort *) env->GetPrimitiveArrayCritical(newByteArray, nullptr);
	for (int i = 0; i < size; ++i) {
		byteArray[i] = htons(fromArray[i]);
	}
	env->ReleasePrimitiveArrayCritical(jshortArray1, fromArray, 0);
	env->ReleasePrimitiveArrayCritical(newByteArray, byteArray, 0);
	return newByteArray;
}

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toByteArray
 * Signature: ([I)[B
 */
JNIEXPORT jbyteArray JNICALL Java_cn_tursom_unsafe_NetUtils_toByteArray___3I
		(JNIEnv *env, jobject, jintArray jintArray1) {
	jint size = env->GetArrayLength(jintArray1);
	auto newByteArray = env->NewByteArray(size * 4);
	auto fromArray = (jint *) env->GetPrimitiveArrayCritical(jintArray1, nullptr);
	auto byteArray = (jint *) env->GetPrimitiveArrayCritical(newByteArray, nullptr);
	for (int i = 0; i < size; ++i) {
		byteArray[i] = htonl(fromArray[i]);
	}
	env->ReleasePrimitiveArrayCritical(jintArray1, fromArray, 0);
	env->ReleasePrimitiveArrayCritical(newByteArray, byteArray, 0);
	return newByteArray;
}

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toByteArray
 * Signature: ([J)[B
 */
JNIEXPORT jbyteArray JNICALL Java_cn_tursom_unsafe_NetUtils_toByteArray___3J
		(JNIEnv *env, jobject, jlongArray jlongArray1) {
	jint size = env->GetArrayLength(jlongArray1);
	auto newByteArray = env->NewByteArray(size * 8);
	auto fromArray = (jlong *) env->GetPrimitiveArrayCritical(jlongArray1, nullptr);
	auto byteArray = (jlong *) env->GetPrimitiveArrayCritical(newByteArray, nullptr);
	for (int i = 0; i < size; ++i) {
		byteArray[i] = ntohll(fromArray[i]);
	}
	env->ReleasePrimitiveArrayCritical(jlongArray1, fromArray, 0);
	env->ReleasePrimitiveArrayCritical(newByteArray, byteArray, 0);
	return newByteArray;
}

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toByteArray
 * Signature: ([C[BI)Z
 */
JNIEXPORT jboolean JNICALL Java_cn_tursom_unsafe_NetUtils_toByteArray___3C_3BI
		(JNIEnv *env, jobject, jcharArray jcharArray1, jbyteArray jbyteArray1, jint offset) {
	jint size = env->GetArrayLength(jcharArray1);
	if (offset < 0 || size * 2 > env->GetArrayLength(jbyteArray1) - offset) return false;
	auto byteArray = (jchar *) env->GetPrimitiveArrayCritical(jbyteArray1, nullptr);
	auto fromArray = (jchar *) env->GetPrimitiveArrayCritical(jcharArray1, nullptr);
	for (int i = 0; i < size; ++i) {
		byteArray[i + offset] = ntohs(fromArray[i]);
	}
	env->ReleasePrimitiveArrayCritical(jcharArray1, fromArray, 0);
	env->ReleasePrimitiveArrayCritical(jbyteArray1, byteArray, 0);
	return true;
}

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toByteArray
 * Signature: ([S[BI)Z
 */
JNIEXPORT jboolean JNICALL Java_cn_tursom_unsafe_NetUtils_toByteArray___3S_3BI
		(JNIEnv *env, jobject, jshortArray jshortArray1, jbyteArray jbyteArray1, jint offset) {
	jint size = env->GetArrayLength(jshortArray1);
	if (offset < 0 || size * 2 > env->GetArrayLength(jbyteArray1) - offset) return false;
	auto byteArray = (jshort *) env->GetPrimitiveArrayCritical(jbyteArray1, nullptr);
	auto fromArray = (jshort *) env->GetPrimitiveArrayCritical(jshortArray1, nullptr);
	for (int i = 0; i < size; ++i) {
		byteArray[i] = htons(fromArray[i]);
	}
	env->ReleasePrimitiveArrayCritical(jshortArray1, fromArray, 0);
	env->ReleasePrimitiveArrayCritical(jbyteArray1, byteArray, 0);
	return true;
}

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toByteArray
 * Signature: ([I[BI)Z
 */
JNIEXPORT jboolean JNICALL Java_cn_tursom_unsafe_NetUtils_toByteArray___3I_3BI
		(JNIEnv *env, jobject, jintArray jintArray1, jbyteArray jbyteArray1, jint offset) {
	jint size = env->GetArrayLength(jintArray1);
	if (offset < 0 || size * 4 > env->GetArrayLength(jbyteArray1) - offset) return false;
	auto byteArray = (jint *) env->GetPrimitiveArrayCritical(jbyteArray1, nullptr);
	auto fromArray = (jint *) env->GetPrimitiveArrayCritical(jintArray1, nullptr);
	for (int i = 0; i < size; ++i) {
		byteArray[i] = htonl(fromArray[i]);
	}
	env->ReleasePrimitiveArrayCritical(jintArray1, fromArray, 0);
	env->ReleasePrimitiveArrayCritical(jbyteArray1, byteArray, 0);
	return true;
}

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toByteArray
 * Signature: ([J[BI)Z
 */
JNIEXPORT jboolean JNICALL Java_cn_tursom_unsafe_NetUtils_toByteArray___3J_3BI
		(JNIEnv *env, jobject, jlongArray jlongArray1, jbyteArray jbyteArray1, jint offset) {
	jint size = env->GetArrayLength(jlongArray1);
	if (offset < 0 || size * 8 > env->GetArrayLength(jbyteArray1) - offset) return false;
	auto byteArray = (jlong *) env->GetPrimitiveArrayCritical(jbyteArray1, nullptr);
	auto fromArray = (jlong *) env->GetPrimitiveArrayCritical(jlongArray1, nullptr);
	for (int i = 0; i < size; ++i) {
		byteArray[i] = ntohll(fromArray[i]);
	}
	env->ReleasePrimitiveArrayCritical(jlongArray1, fromArray, 0);
	env->ReleasePrimitiveArrayCritical(jbyteArray1, byteArray, 0);
	return true;
}

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toCharArray
 * Signature: ([B)[C
 */
JNIEXPORT jcharArray JNICALL Java_cn_tursom_unsafe_NetUtils_toCharArray
		(JNIEnv *env, jobject, jbyteArray jbyteArray1) {
	jint size = env->GetArrayLength(jbyteArray1) / 2;
	jcharArray newArray = env->NewCharArray(size);
	auto byteArray = (jchar *) env->GetPrimitiveArrayCritical(jbyteArray1, nullptr);
	auto toArray = (jchar *) env->GetPrimitiveArrayCritical(newArray, nullptr);
	for (int i = 0; i < size; ++i) {
		toArray[i] = ntohs(byteArray[i]);
	}
	env->ReleasePrimitiveArrayCritical(newArray, toArray, 0);
	env->ReleasePrimitiveArrayCritical(jbyteArray1, byteArray, 0);
	return newArray;
}

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toShortArray
 * Signature: ([B)[S
 */
JNIEXPORT jshortArray JNICALL Java_cn_tursom_unsafe_NetUtils_toShortArray
		(JNIEnv *env, jobject, jbyteArray jbyteArray1) {
	jint size = env->GetArrayLength(jbyteArray1) / 2;
	auto newArray = env->NewShortArray(size);
	auto byteArray = (jshort *) env->GetPrimitiveArrayCritical(jbyteArray1, nullptr);
	auto toArray = (jshort *) env->GetPrimitiveArrayCritical(newArray, nullptr);
	for (int i = 0; i < size; ++i) {
		toArray[i] = ntohs(byteArray[i]);
	}
	env->ReleasePrimitiveArrayCritical(newArray, toArray, 0);
	env->ReleasePrimitiveArrayCritical(jbyteArray1, byteArray, 0);
	return newArray;
}


/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toIntArray
 * Signature: ([B)[I
 */
JNIEXPORT jintArray JNICALL Java_cn_tursom_unsafe_NetUtils_toIntArray
		(JNIEnv *env, jobject, jbyteArray jbyteArray1) {
	jint size = env->GetArrayLength(jbyteArray1) / 4;
	auto newArray = env->NewIntArray(size);
	auto byteArray = (jint *) env->GetPrimitiveArrayCritical(jbyteArray1, nullptr);
	auto toArray = (jint *) env->GetPrimitiveArrayCritical(newArray, nullptr);
	for (int i = 0; i < size; ++i) {
		toArray[i] = ntohl(byteArray[i]);
	}
	env->ReleasePrimitiveArrayCritical(newArray, toArray, 0);
	env->ReleasePrimitiveArrayCritical(jbyteArray1, byteArray, 0);
	return newArray;
}

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toLongArray
 * Signature: ([B)[J
 */
JNIEXPORT jlongArray JNICALL Java_cn_tursom_unsafe_NetUtils_toLongArray
		(JNIEnv *env, jobject, jbyteArray jbyteArray1) {
	jint size = env->GetArrayLength(jbyteArray1) / 8;
	auto newArray = env->NewLongArray(size);
	auto byteArray = (jlong *) env->GetPrimitiveArrayCritical(jbyteArray1, nullptr);
	auto toArray = (jlong *) env->GetPrimitiveArrayCritical(newArray, nullptr);
	for (int i = 0; i < size; ++i) {
		toArray[i] = ntohll(byteArray[i]);
	}
	env->ReleasePrimitiveArrayCritical(newArray, toArray, 0);
	env->ReleasePrimitiveArrayCritical(jbyteArray1, byteArray, 0);
	return newArray;
}

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toChar
 * Signature: ([BI)C
 */
JNIEXPORT jchar JNICALL Java_cn_tursom_unsafe_NetUtils_toChar
		(JNIEnv *env, jobject, jbyteArray jbyteArray1, jint offset) {
	auto byteArray = (jbyte *) env->GetPrimitiveArrayCritical(jbyteArray1, nullptr);
	auto ret = ntohs(*(jchar *) (byteArray + offset));
	env->ReleasePrimitiveArrayCritical(jbyteArray1, byteArray, 0);
	return ret;
}

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toShort
 * Signature: ([BI)S
 */
JNIEXPORT jshort JNICALL Java_cn_tursom_unsafe_NetUtils_toShort
		(JNIEnv *env, jobject, jbyteArray jbyteArray1, jint offset) {
	auto byteArray = (jbyte *) env->GetPrimitiveArrayCritical(jbyteArray1, nullptr);
	auto ret = ntohs(*(jshort *) (byteArray + offset));
	env->ReleasePrimitiveArrayCritical(jbyteArray1, byteArray, 0);
	return ret;
}

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toInt
 * Signature: ([BI)I
 */
JNIEXPORT jint JNICALL Java_cn_tursom_unsafe_NetUtils_toInt
		(JNIEnv *env, jobject, jbyteArray jbyteArray1, jint offset) {
	auto byteArray = (jbyte *) env->GetPrimitiveArrayCritical(jbyteArray1, nullptr);
	auto ret = ntohl(*(jint *) (byteArray + offset));
	env->ReleasePrimitiveArrayCritical(jbyteArray1, byteArray, 0);
	return ret;
}

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toLong
 * Signature: ([BI)J
 */
JNIEXPORT jlong JNICALL Java_cn_tursom_unsafe_NetUtils_toLong
		(JNIEnv *env, jobject, jbyteArray jbyteArray1, jint offset) {
	auto byteArray = (jbyte *) env->GetPrimitiveArrayCritical(jbyteArray1, nullptr);
	auto ret = ntohll(*(jlong *) (byteArray + offset));
	env->ReleasePrimitiveArrayCritical(jbyteArray1, byteArray, 0);
	return ret;
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

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toNativeEndianByteArray
 * Signature: ([C)[B
 */
JNIEXPORT jbyteArray JNICALL Java_cn_tursom_unsafe_NetUtils_toNativeEndianByteArray___3C
		(JNIEnv *env, jobject, jcharArray array) {
	auto size = env->GetArrayLength(array) * 2;
	auto newByteArray = env->NewByteArray(size);
	auto from = (jbyte *) env->GetPrimitiveArrayCritical(array, nullptr);
	env->SetByteArrayRegion(newByteArray, 0, size, from);
	env->ReleasePrimitiveArrayCritical(array, from, 0);
	return newByteArray;
}

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toNativeEndianByteArray
 * Signature: ([S)[B
 */
JNIEXPORT jbyteArray JNICALL Java_cn_tursom_unsafe_NetUtils_toNativeEndianByteArray___3S
		(JNIEnv *env, jobject, jshortArray array) {
	auto size = env->GetArrayLength(array) * 2;
	auto newByteArray = env->NewByteArray(size);
	auto from = (jbyte *) env->GetPrimitiveArrayCritical(array, nullptr);
	env->SetByteArrayRegion(newByteArray, 0, size, from);
	env->ReleasePrimitiveArrayCritical(array, from, 0);
	return newByteArray;
}

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toNativeEndianByteArray
 * Signature: ([I)[B
 */
JNIEXPORT jbyteArray JNICALL Java_cn_tursom_unsafe_NetUtils_toNativeEndianByteArray___3I
		(JNIEnv *env, jobject, jintArray array) {
	auto size = env->GetArrayLength(array) * 4;
	auto newByteArray = env->NewByteArray(size);
	auto from = (jbyte *) env->GetPrimitiveArrayCritical(array, nullptr);
	env->SetByteArrayRegion(newByteArray, 0, size, from);
	env->ReleasePrimitiveArrayCritical(array, from, 0);
	return newByteArray;
}

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toNativeEndianByteArray
 * Signature: ([J)[B
 */
JNIEXPORT jbyteArray JNICALL Java_cn_tursom_unsafe_NetUtils_toNativeEndianByteArray___3J
		(JNIEnv *env, jobject, jlongArray array) {
	auto size = env->GetArrayLength(array) * 8;
	auto newByteArray = env->NewByteArray(size);
	auto from = (jbyte *) env->GetPrimitiveArrayCritical(array, nullptr);
	env->SetByteArrayRegion(newByteArray, 0, size, from);
	env->ReleasePrimitiveArrayCritical(array, from, 0);
	return newByteArray;
}

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toNativeEndianByteArray
 * Signature: ([C[BI)Z
 */
JNIEXPORT jboolean JNICALL Java_cn_tursom_unsafe_NetUtils_toNativeEndianByteArray___3C_3BI
		(JNIEnv *env, jobject, jcharArray from, jbyteArray target, jint offset) {
	auto size = env->GetArrayLength(from) * 2;
	if (offset < 0 || size + offset > env->GetArrayLength(target))return false;
	auto fromArray = (jbyte *) env->GetPrimitiveArrayCritical(from, nullptr);
	env->SetByteArrayRegion(target, offset, size, (const jbyte *) fromArray);
	env->ReleasePrimitiveArrayCritical(from, fromArray, 0);
	return true;
}

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toNativeEndianByteArray
 * Signature: ([S[BI)Z
 */
JNIEXPORT jboolean JNICALL Java_cn_tursom_unsafe_NetUtils_toNativeEndianByteArray___3S_3BI
		(JNIEnv *env, jobject, jshortArray from, jbyteArray target, jint offset) {
	auto size = env->GetArrayLength(from) * 2;
	if (offset < 0 || size + offset > env->GetArrayLength(target))return false;
	auto fromArray = (jbyte *) env->GetPrimitiveArrayCritical(from, nullptr);
	env->SetByteArrayRegion(target, offset, size, (const jbyte *) fromArray);
	env->ReleasePrimitiveArrayCritical(from, fromArray, 0);
	return true;
}

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toNativeEndianByteArray
 * Signature: ([I[BI)Z
 */
JNIEXPORT jboolean JNICALL Java_cn_tursom_unsafe_NetUtils_toNativeEndianByteArray___3I_3BI
		(JNIEnv *env, jobject, jintArray from, jbyteArray target, jint offset) {
	auto size = env->GetArrayLength(from) * 4;
	if (offset < 0 || size + offset > env->GetArrayLength(target))return false;
	auto fromArray = (jbyte *) env->GetPrimitiveArrayCritical(from, nullptr);
	env->SetByteArrayRegion(target, offset, size, (const jbyte *) fromArray);
	env->ReleasePrimitiveArrayCritical(from, fromArray, 0);
	return true;
}

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toNativeEndianByteArray
 * Signature: ([J[BI)Z
 */
JNIEXPORT jboolean JNICALL Java_cn_tursom_unsafe_NetUtils_toNativeEndianByteArray___3J_3BI
		(JNIEnv *env, jobject, jlongArray from, jbyteArray target, jint offset) {
	auto size = env->GetArrayLength(from) * 8;
	if (offset < 0 || size + offset > env->GetArrayLength(target))return false;
	auto fromArray = (jbyte *) env->GetPrimitiveArrayCritical(from, nullptr);
	env->SetByteArrayRegion(target, offset, size, (const jbyte *) fromArray);
	env->ReleasePrimitiveArrayCritical(from, fromArray, 0);
	return true;
}

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toNativeEndianCharArray
 * Signature: ([B)[C
 */
JNIEXPORT jcharArray JNICALL Java_cn_tursom_unsafe_NetUtils_toNativeEndianCharArray
		(JNIEnv *env, jobject, jbyteArray array) {
	auto size = env->GetArrayLength(array) / 2;
	auto byteArray = env->GetPrimitiveArrayCritical(array, nullptr);
	auto newArray = env->NewCharArray(size);
	env->SetCharArrayRegion(newArray, 0, size, (const jchar *) byteArray);
	env->ReleasePrimitiveArrayCritical(array, byteArray, 0);
	return newArray;
}

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toNativeEndianShortArray
 * Signature: ([B)[S
 */
JNIEXPORT jshortArray JNICALL Java_cn_tursom_unsafe_NetUtils_toNativeEndianShortArray
		(JNIEnv *env, jobject, jbyteArray array) {
	auto size = env->GetArrayLength(array) / 2;
	auto byteArray = env->GetPrimitiveArrayCritical(array, nullptr);
	auto newArray = env->NewShortArray(size);
	env->SetShortArrayRegion(newArray, 0, size, (const jshort *) byteArray);
	env->ReleasePrimitiveArrayCritical(array, byteArray, 0);
	return newArray;
}

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toNativeEndianIntArray
 * Signature: ([B)[I
 */
JNIEXPORT jintArray JNICALL Java_cn_tursom_unsafe_NetUtils_toNativeEndianIntArray
		(JNIEnv *env, jobject, jbyteArray array) {
	auto size = env->GetArrayLength(array) / 4;
	auto byteArray = env->GetPrimitiveArrayCritical(array, nullptr);
	auto newArray = env->NewIntArray(size);
	env->SetIntArrayRegion(newArray, 0, size, (const jint *) byteArray);
	env->ReleasePrimitiveArrayCritical(array, byteArray, 0);
	return newArray;
}

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toNativeEndianLongArray
 * Signature: ([B)[J
 */
JNIEXPORT jlongArray JNICALL Java_cn_tursom_unsafe_NetUtils_toNativeEndianLongArray
		(JNIEnv *env, jobject, jbyteArray array) {
	auto size = env->GetArrayLength(array) / 8;
	auto byteArray = env->GetPrimitiveArrayCritical(array, nullptr);
	auto newArray = env->NewLongArray(size);
	env->SetLongArrayRegion(newArray, 0, size, (const jlong *) byteArray);
	env->ReleasePrimitiveArrayCritical(array, byteArray, 0);
	return newArray;
}

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toNativeEndianChar
 * Signature: ([BI)C
 */
JNIEXPORT jchar JNICALL Java_cn_tursom_unsafe_NetUtils_toNativeEndianChar
		(JNIEnv *env, jobject, jbyteArray array, jint offset) {
	auto byteArray = (jbyte *) env->GetPrimitiveArrayCritical(array, nullptr);
	auto ret = *(jchar *) (byteArray + offset);
	env->ReleasePrimitiveArrayCritical(array, byteArray, 0);
	return ret;
}

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toNativeEndianShort
 * Signature: ([BI)S
 */
JNIEXPORT jshort JNICALL Java_cn_tursom_unsafe_NetUtils_toNativeEndianShort
		(JNIEnv *env, jobject, jbyteArray array, jint offset) {
	auto byteArray = (jbyte *) env->GetPrimitiveArrayCritical(array, nullptr);
	auto ret = *(jshort *) (byteArray + offset);
	env->ReleasePrimitiveArrayCritical(array, byteArray, 0);
	return ret;
}

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toNativeEndianInt
 * Signature: ([BI)I
 */
JNIEXPORT jint JNICALL Java_cn_tursom_unsafe_NetUtils_toNativeEndianInt
		(JNIEnv *env, jobject, jbyteArray array, jint offset) {
	auto byteArray = (jbyte *) env->GetPrimitiveArrayCritical(array, nullptr);
	auto ret = *(jint *) (byteArray + offset);
	env->ReleasePrimitiveArrayCritical(array, byteArray, 0);
	return ret;
}

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toNativeEndianLong
 * Signature: ([BI)J
 */
JNIEXPORT jlong JNICALL Java_cn_tursom_unsafe_NetUtils_toNativeEndianLong
		(JNIEnv *env, jobject, jbyteArray array, jint offset) {
	auto byteArray = (jbyte *) env->GetPrimitiveArrayCritical(array, nullptr);
	auto ret = *(jlong *) (byteArray + offset);
	env->ReleasePrimitiveArrayCritical(array, byteArray, 0);
	return ret;
}

#pragma clang diagnostic pop