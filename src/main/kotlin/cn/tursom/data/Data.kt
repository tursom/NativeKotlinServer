package cn.tursom.data

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

private fun loadNativeLibrary(): Boolean {
    return try {
        System.load("${System.getProperty("user.dir")}/jni/libNativeKotlinServer.so")
        true
    } catch (e: UnsatisfiedLinkError) {
        System.err.println("无法加载动态链接库，请先编译")
        false
    }
}

val libraryNativeDataLoaded = loadNativeLibrary()

fun main() {
    println("hello 海星！".toCharArray().toByteArray().toCharArray().toList())
    1.toShort()
    println(1.ntoh())
}