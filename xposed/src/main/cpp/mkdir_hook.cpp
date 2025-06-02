#include <cstring>
#include <cerrno>
#include <sys/stat.h>
#include <android/log.h>
#include <nativehook/nativehook.h>

static int (*orig_mkdir)(const char *, mode_t) = nullptr;

static int hooked_mkdir(const char *pathname, mode_t mode) {
    if (pathname && strncmp(pathname, "/storage/emulated/0/Android/data/", 32) == 0) {
        errno = EACCES; // Permission denied
        return -1;
    }
    return orig_mkdir(pathname, mode);
}

static void __attribute__((constructor)) init() {
    nativehook::HookSymbol("libc.so", "mkdir", (void *)hooked_mkdir, (void **)&orig_mkdir);
}
