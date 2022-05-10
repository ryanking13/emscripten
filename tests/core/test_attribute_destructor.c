#include <stdio.h>

// In Wasm destructors get lowered to constructors
// that call `__cxa_atexit`.
//
// Because it gets lowered to this during compilation this
// symbol cannot itself be LTO.  We has a bug where this symbol
// was itself LTO which can cause link failures.
//
// See: https://github.com/emscripten-core/emscripten/issues/16836
void my_dtor() __attribute__((destructor));

void my_dtor() {
  printf("my_dtor\n");
}

int main() {
  printf("main done\n");
  return 0;
}
