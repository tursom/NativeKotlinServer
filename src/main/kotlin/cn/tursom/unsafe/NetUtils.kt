@file:Suppress("NOTHING_TO_INLINE", "unused")

package cn.tursom.unsafe

object NetUtils {
    init {
        try {
            System.load("${System.getProperty("user.dir")}/jni/libNativeKotlinServer.so")
        } catch (e: UnsatisfiedLinkError) {
            System.err.println("无法加载动态链接库 jni/libNativeKotlinServer.so")
        }
    }

    external fun CharArray.toByteArray(): ByteArray
    external fun ShortArray.toByteArray(): ByteArray
    external fun IntArray.toByteArray(): ByteArray
    external fun LongArray.toByteArray(): ByteArray

    external fun CharArray.toByteArray(buffer: ByteArray, offset: Int = 0): Boolean
    external fun ShortArray.toByteArray(buffer: ByteArray, offset: Int = 0): Boolean
    external fun IntArray.toByteArray(buffer: ByteArray, offset: Int = 0): Boolean
    external fun LongArray.toByteArray(buffer: ByteArray, offset: Int = 0): Boolean

    external fun ByteArray.toCharArray(): CharArray
    external fun ByteArray.toShortArray(): ShortArray
    external fun ByteArray.toIntArray(): IntArray
    external fun ByteArray.toLongArray(): LongArray

    external fun ByteArray.toChar(offset: Int = 0): Char
    external fun ByteArray.toShort(offset: Int = 0): Short
    external fun ByteArray.toInt(offset: Int = 0): Int
    external fun ByteArray.toLong(offset: Int = 0): Long

    external fun Short.ntoh(): Short
    external fun Short.hton(): Short

    external fun Int.ntoh(): Int
    external fun Int.hton(): Int

    external fun Long.ntoh(): Long
    external fun Long.hton(): Long

    external fun CharArray.toNativeEndianByteArray(): ByteArray
    external fun ShortArray.toNativeEndianByteArray(): ByteArray
    external fun IntArray.toNativeEndianByteArray(): ByteArray
    external fun LongArray.toNativeEndianByteArray(): ByteArray

    external fun CharArray.toNativeEndianByteArray(buffer: ByteArray, offset: Int = 0): Boolean
    external fun ShortArray.toNativeEndianByteArray(buffer: ByteArray, offset: Int = 0): Boolean
    external fun IntArray.toNativeEndianByteArray(buffer: ByteArray, offset: Int = 0): Boolean
    external fun LongArray.toNativeEndianByteArray(buffer: ByteArray, offset: Int = 0): Boolean

    external fun ByteArray.toNativeEndianCharArray(): CharArray
    external fun ByteArray.toNativeEndianShortArray(): ShortArray
    external fun ByteArray.toNativeEndianIntArray(): IntArray
    external fun ByteArray.toNativeEndianLongArray(): LongArray

    external fun ByteArray.toNativeEndianChar(offset: Int = 0): Char
    external fun ByteArray.toNativeEndianShort(offset: Int = 0): Short
    external fun ByteArray.toNativeEndianInt(offset: Int = 0): Int
    external fun ByteArray.toNativeEndianLong(offset: Int = 0): Long

    external fun Short.toNativeByteArray(): ByteArray
    external fun Int.toNativeByteArray(): ByteArray
    external fun Long.toNativeByteArray(): ByteArray

    external fun Short.toNativeByteArray(byteArray: ByteArray, offset: Int): ByteArray
    external fun Int.toNativeByteArray(byteArray: ByteArray, offset: Int): ByteArray
    external fun Long.toNativeByteArray(byteArray: ByteArray, offset: Int): ByteArray
}

inline fun <T> NetUtils.use(action: NetUtils.() -> T): T {
    return this.action()
}

inline fun CharArray.toByteArray(): ByteArray = NetUtils.use { toByteArray() }
inline fun ShortArray.toByteArray(): ByteArray = NetUtils.use { toByteArray() }
inline fun IntArray.toByteArray(): ByteArray = NetUtils.use { toByteArray() }
inline fun LongArray.toByteArray(): ByteArray = NetUtils.use { toByteArray() }

inline fun CharArray.toByteArray(buffer: ByteArray, offset: Int = 0): Boolean =
    NetUtils.use { toByteArray(buffer, offset) }

inline fun ShortArray.toByteArray(buffer: ByteArray, offset: Int = 0): Boolean =
    NetUtils.use { toByteArray(buffer, offset) }

inline fun IntArray.toByteArray(buffer: ByteArray, offset: Int = 0): Boolean =
    NetUtils.use { toByteArray(buffer, offset) }

inline fun LongArray.toByteArray(buffer: ByteArray, offset: Int = 0): Boolean =
    NetUtils.use { toByteArray(buffer, offset) }

inline fun ByteArray.toCharArray(): CharArray = NetUtils.use { toCharArray() }
inline fun ByteArray.toShortArray(): ShortArray = NetUtils.use { toShortArray() }
inline fun ByteArray.toIntArray(): IntArray = NetUtils.use { toIntArray() }
inline fun ByteArray.toLongArray(): LongArray = NetUtils.use { toLongArray() }

inline fun ByteArray.toChar(offset: Int = 0): Char = NetUtils.use { toChar(offset) }
inline fun ByteArray.toShort(offset: Int = 0): Short = NetUtils.use { toShort(offset) }
inline fun ByteArray.toInt(offset: Int = 0): Int = NetUtils.use { toInt(offset) }
inline fun ByteArray.toLong(offset: Int = 0): Long = NetUtils.use { toLong(offset) }

inline fun Short.ntoh(): Short = NetUtils.use { ntoh() }
inline fun Short.hton(): Short = NetUtils.use { hton() }

inline fun Int.ntoh(): Int = NetUtils.use { ntoh() }
inline fun Int.hton(): Int = NetUtils.use { hton() }

inline fun Long.ntoh(): Long = NetUtils.use { ntoh() }
inline fun Long.hton(): Long = NetUtils.use { hton() }

inline fun CharArray.toNativeEndianByteArray(): ByteArray = NetUtils.use { toNativeEndianByteArray() }
inline fun ShortArray.toNativeEndianByteArray(): ByteArray = NetUtils.use { toNativeEndianByteArray() }
inline fun IntArray.toNativeEndianByteArray(): ByteArray = NetUtils.use { toNativeEndianByteArray() }
inline fun LongArray.toNativeEndianByteArray(): ByteArray = NetUtils.use { toNativeEndianByteArray() }

inline fun CharArray.toNativeEndianByteArray(buffer: ByteArray, offset: Int = 0): Boolean =
    NetUtils.use { toNativeEndianByteArray(buffer, offset) }

inline fun ShortArray.toNativeEndianByteArray(buffer: ByteArray, offset: Int = 0): Boolean =
    NetUtils.use { toNativeEndianByteArray(buffer, offset) }

inline fun IntArray.toNativeEndianByteArray(buffer: ByteArray, offset: Int = 0): Boolean =
    NetUtils.use { toNativeEndianByteArray(buffer, offset) }

inline fun LongArray.toNativeEndianByteArray(buffer: ByteArray, offset: Int = 0): Boolean =
    NetUtils.use { toNativeEndianByteArray(buffer, offset) }

inline fun ByteArray.toNativeEndianCharArray(): CharArray = NetUtils.use { toNativeEndianCharArray() }
inline fun ByteArray.toNativeEndianShortArray(): ShortArray = NetUtils.use { toNativeEndianShortArray() }
inline fun ByteArray.toNativeEndianIntArray(): IntArray = NetUtils.use { toNativeEndianIntArray() }
inline fun ByteArray.toNativeEndianLongArray(): LongArray = NetUtils.use { toNativeEndianLongArray() }

inline fun ByteArray.toNativeEndianChar(offset: Int = 0): Char = NetUtils.use { toNativeEndianChar(offset) }
inline fun ByteArray.toNativeEndianShort(offset: Int = 0): Short = NetUtils.use { toNativeEndianShort(offset) }
inline fun ByteArray.toNativeEndianInt(offset: Int = 0): Int = NetUtils.use { toNativeEndianInt(offset) }
inline fun ByteArray.toNativeEndianLong(offset: Int = 0): Long = NetUtils.use { toNativeEndianLong(offset) }

inline fun Short.toNativeByteArray(): ByteArray = NetUtils.use { toNativeByteArray() }
inline fun Int.toNativeByteArray(): ByteArray = NetUtils.use { toNativeByteArray() }
inline fun Long.toNativeByteArray(): ByteArray = NetUtils.use { toNativeByteArray() }

inline fun Short.toNativeByteArray(byteArray: ByteArray, offset: Int): ByteArray =
    NetUtils.use { toNativeByteArray(byteArray, offset) }

inline fun Int.toNativeByteArray(byteArray: ByteArray, offset: Int): ByteArray =
    NetUtils.use { toNativeByteArray(byteArray, offset) }

inline fun Long.toNativeByteArray(byteArray: ByteArray, offset: Int): ByteArray =
    NetUtils.use { toNativeByteArray(byteArray, offset) }


fun main() {
    println(intArrayOf(1, 2, 3, 4, 5, 6, 7, 8, 9, 0).toByteArray().toIntArray().toList())
}