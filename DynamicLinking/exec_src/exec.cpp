#include <iostream>
#include <dlfcn.h>

typedef void (*Type)();

int main() {
    void *SharedObject = dlopen("./lib.so", RTLD_LAZY);
    Type function = (Type) dlsym(SharedObject, "_Z8functionv");

    function();

    dlclose(SharedObject);
}
