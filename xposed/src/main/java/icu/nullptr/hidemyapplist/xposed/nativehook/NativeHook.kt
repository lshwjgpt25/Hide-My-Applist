package icu.nullptr.hidemyapplist.xposed.nativehook

import icu.nullptr.hidemyapplist.xposed.logE

object NativeHookLoader {
    init {
        runCatching { System.loadLibrary("hma_native") }
            .onFailure { logE("NativeHook", "Failed to load native library", it) }
    }
}
