/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    uint8_t* _0;
    int64_t _1;
} struct0;

/* Interned Strings */
char* string_0 = "\x48\x65\x6C\x6C\x6F\x2C\x20\x4F\x72\x6E\x67\x21\x20\xF0\x9F\x8D\x8A";

/* Function forward definitions */
struct0 _979_main(void);

/* Function definitions */
struct0 _979_main(void) {
    struct0 _979_$retval;
    _979_$retval = (struct0) {(uint8_t*)string_0, 17};
    return _979_$retval;
}

int main(void) {
  printf("%s",_979_main()._0);
  return 0;
}
