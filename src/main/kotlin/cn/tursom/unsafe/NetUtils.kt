@file:Suppress("NOTHING_TO_INLINE")

package cn.tursom.unsafe

object NetUtils {
    init {
        try {
            System.load("${System.getProperty("user.dir")}/jni/libNativeKotlinServer.so")

        } catch (e: UnsatisfiedLinkError) {
            System.err.println("无法加载动态链接库，请先编译")
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

    inline fun <T> use(action: NetUtils.() -> T): T {
        return this.action()
    }
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
