//
// Created by tursom on 19-7-3.
//

#include <netinet/in.h>
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
	auto c = env->GetCharArrayElements(jcharArray1, &True);
	jint size = env->GetArrayLength(jcharArray1);
	for (int i = 0; i < size; ++i) {
		c[i] = htons(c[i]);
	}
	auto byteArray = env->NewByteArray(size * 2);
	env->SetByteArrayRegion(byteArray, 0, size * 2, (jbyte *) c);
	return byteArray;
}


/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toByteArray
 * Signature: ([S)[B
 */
JNIEXPORT jbyteArray JNICALL Java_cn_tursom_unsafe_NetUtils_toByteArray___3S
		(JNIEnv *env, jobject, jshortArray jshortArray1) {
	auto shortArray = env->GetShortArrayElements(jshortArray1, &True);
	jint size = env->GetArrayLength(jshortArray1);
	for (int i = 0; i < size; ++i) {
		shortArray[i] = htons(shortArray[i]);
	}
	auto byteArray = env->NewByteArray(size * 2);
	env->SetByteArrayRegion(byteArray, 0, size * 2, (jbyte *) shortArray);
	return byteArray;
}

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toByteArray
 * Signature: ([I)[B
 */
JNIEXPORT jbyteArray JNICALL Java_cn_tursom_unsafe_NetUtils_toByteArray___3I
		(JNIEnv *env, jobject, jintArray jintArray1) {
	auto intArray = env->GetIntArrayElements(jintArray1, &True);
	jint size = env->GetArrayLength(jintArray1);
	for (int i = 0; i < size; ++i) {
		intArray[i] = htonl(intArray[i]);
	}
	auto byteArray = env->NewByteArray(size * 4);
	env->SetByteArrayRegion(byteArray, 0, size * 4, (jbyte *) intArray);
	return byteArray;
}

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toByteArray
 * Signature: ([J)[B
 */
JNIEXPORT jbyteArray JNICALL Java_cn_tursom_unsafe_NetUtils_toByteArray___3J
		(JNIEnv *env, jobject, jlongArray jlongArray1) {
	auto longArray = env->GetLongArrayElements(jlongArray1, &True);
	jint size = env->GetArrayLength(jlongArray1);
	for (int i = 0; i < size; ++i) {
		htonll(&longArray[i]);
	}
	auto byteArray = env->NewByteArray(size * 8);
	env->SetByteArrayRegion(byteArray, 0, size, (jbyte *) longArray);
	return byteArray;
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
	auto c = env->GetCharArrayElements(jcharArray1, &True);
	for (int i = 0; i < size; ++i) {
		c[i] = ntohs(c[i]);
	}
	env->SetByteArrayRegion(jbyteArray1, offset, size * 2, (jbyte *) c);
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
	auto shortArray = env->GetShortArrayElements(jshortArray1, &True);
	for (int i = 0; i < size; ++i) {
		shortArray[i] = htons(shortArray[i]);
	}
	env->SetByteArrayRegion(jbyteArray1, offset, size * 2, (jbyte *) shortArray);
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
	auto shortArray = env->GetIntArrayElements(jintArray1, &True);
	for (int i = 0; i < size; ++i) {
		shortArray[i] = htonl(shortArray[i]);
	}
	env->SetByteArrayRegion(jbyteArray1, offset, size * 4, (jbyte *) shortArray);
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
	auto shortArray = env->GetLongArrayElements(jlongArray1, &True);
	for (int i = 0; i < size; ++i) {
		htonll(&shortArray[i]);
	}
	env->SetByteArrayRegion(jbyteArray1, offset, size * 8, (jbyte *) shortArray);
	return true;
}

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toCharArray
 * Signature: ([B)[C
 */
JNIEXPORT jcharArray JNICALL Java_cn_tursom_unsafe_NetUtils_toCharArray
		(JNIEnv *env, jobject, jbyteArray jbyteArray1) {
	auto byteArray = (jchar *) env->GetByteArrayElements(jbyteArray1, &False);
	jint size = env->GetArrayLength(jbyteArray1) / 2;
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
	auto byteArray = (jshort *) env->GetByteArrayElements(jbyteArray1, &False);
	jint size = env->GetArrayLength(jbyteArray1) / 2;
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
	auto byteArray = (jint *) env->GetByteArrayElements(jbyteArray1, &False);
	jint size = env->GetArrayLength(jbyteArray1) / 4;
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
	auto byteArray = (jlong *) env->GetByteArrayElements(jbyteArray1, &False);
	jint size = env->GetArrayLength(jbyteArray1) / 8;
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

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toNativeEndianByteArray
 * Signature: ([C)[B
 */
JNIEXPORT jbyteArray JNICALL Java_cn_tursom_unsafe_NetUtils_toNativeEndianByteArray___3C
		(JNIEnv *env, jobject, jcharArray array) {
	auto size = env->GetArrayLength(array) * 2;
	auto newByteArray = env->NewByteArray(size);
	env->SetByteArrayRegion(newByteArray, 0, size, (const jbyte *) env->GetCharArrayElements(array, &False));
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
	env->SetByteArrayRegion(newByteArray, 0, size, (const jbyte *) env->GetShortArrayElements(array, &False));
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
	env->SetByteArrayRegion(newByteArray, 0, size, (const jbyte *) env->GetIntArrayElements(array, &False));
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
	env->SetByteArrayRegion(newByteArray, 0, size, (const jbyte *) env->GetLongArrayElements(array, &False));
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
	env->SetByteArrayRegion(target, offset, size, (const jbyte *) env->GetCharArrayElements(from, &False));
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
	env->SetByteArrayRegion(target, offset, size, (const jbyte *) env->GetShortArrayElements(from, &False));
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
	env->SetByteArrayRegion(target, offset, size, (const jbyte *) env->GetIntArrayElements(from, &False));
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
	env->SetByteArrayRegion(target, offset, size, (const jbyte *) env->GetLongArrayElements(from, &False));
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
	auto byteArray = env->GetByteArrayElements(array, &False);
	auto newArray = env->NewCharArray(size);
	env->SetCharArrayRegion(newArray, 0, size, (const jchar *) byteArray);
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
	auto byteArray = env->GetByteArrayElements(array, &False);
	auto newArray = env->NewShortArray(size);
	env->SetShortArrayRegion(newArray, 0, size, (const jshort *) byteArray);
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
	auto byteArray = env->GetByteArrayElements(array, &False);
	auto newArray = env->NewIntArray(size);
	env->SetIntArrayRegion(newArray, 0, size, (const jint *) byteArray);
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
	auto byteArray = env->GetByteArrayElements(array, &False);
	auto newArray = env->NewLongArray(size);
	env->SetLongArrayRegion(newArray, 0, size, (const jlong *) byteArray);
	return newArray;
}

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toNativeEndianChar
 * Signature: ([BI)C
 */
JNIEXPORT jchar JNICALL Java_cn_tursom_unsafe_NetUtils_toNativeEndianChar
		(JNIEnv *env, jobject, jbyteArray array, jint offset) {
	return *(jchar *) (env->GetByteArrayElements(array, &False) + offset);
}

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toNativeEndianShort
 * Signature: ([BI)S
 */
JNIEXPORT jshort JNICALL Java_cn_tursom_unsafe_NetUtils_toNativeEndianShort
		(JNIEnv *env, jobject, jbyteArray array, jint offset) {
	return *(jshort *) (env->GetByteArrayElements(array, &False) + offset);
}

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toNativeEndianInt
 * Signature: ([BI)I
 */
JNIEXPORT jint JNICALL Java_cn_tursom_unsafe_NetUtils_toNativeEndianInt
		(JNIEnv *env, jobject, jbyteArray array, jint offset) {
	return *(jint *) (env->GetByteArrayElements(array, &False) + offset);
}

/*
 * Class:     cn_tursom_unsafe_NetUtils
 * Method:    toNativeEndianLong
 * Signature: ([BI)J
 */
JNIEXPORT jlong JNICALL Java_cn_tursom_unsafe_NetUtils_toNativeEndianLong
		(JNIEnv *env, jobject, jbyteArray array, jint offset) {
	return *(jlong *) (env->GetByteArrayElements(array, &False) + offset);
}

#pragma clang diagnostic pop