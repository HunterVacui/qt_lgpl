EXTRA_INCLUDEPATH += /home/qt/openssl/android/openssl-1.1.1d/include
host_build {
    QT_CPU_FEATURES.x86_64 = mmx sse sse2
} else {
    QT_CPU_FEATURES.i386 = mmx sse sse2 sse3 ssse3
}
QT.global_private.enabled_features = sse2 alloca_h alloca android-style-assets avx2 gui network reduce_exports reduce_relocations sql system-zlib testlib widgets xml
QT.global_private.disabled_features = alloca_malloc_h private_tests dbus dbus-linked gc_binaries libudev posix_fallocate release_tools stack-protector-strong
QT_COORD_TYPE = double
QMAKE_LIBS_ZLIB = -lz
CONFIG -= precompile_header
CONFIG += cross_compile sse2 aesni sse3 ssse3 sse4_1 sse4_2 avx avx2 avx512f avx512bw avx512cd avx512dq avx512er avx512ifma avx512pf avx512vbmi avx512vl compile_examples f16c rdrnd shani x86SimdAlways
QT_BUILD_PARTS += libs
