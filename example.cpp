#include <emscripten/bind.h>
#include <cmath>

double my_pow(double b, double e)
{
  return pow(b, e);
}

EMSCRIPTEN_BINDINGS() {
  emscripten::function("call_wasm_pow", &my_pow);
}