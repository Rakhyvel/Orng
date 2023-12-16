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

typedef struct {
    struct0 _0;
    struct0 _1;
    struct0 _2;
} struct1;

/* Interned Strings */
char* string_0 = "\x48\x65\x6C\x6C\x6F\x2C\x20";
char* string_1 = "\x32\x31\x37";
char* string_2 = "\x57\x6F\x72\x6C\x64\x21";

/* Function forward definitions */
struct0 _77_main(void);

/* Function definitions */
struct0 _77_main(void) {
    struct0 _77_t1;
    struct0 _77_t2;
    struct0 _77_t3;
    struct1 _78_x;
    int64_t _77_t4;
    struct0 _77_$retval;
    _77_t1 = (struct0) {(uint8_t*)string_0, 7};
    _77_t2 = (struct0) {(uint8_t*)string_1, 3};
    _77_t3 = (struct0) {(uint8_t*)string_2, 6};
    _78_x = (struct1) {_77_t1, _77_t2, _77_t3};
    _77_t4 = 1;
    _77_$retval = *((struct0*)&_78_x + _77_t4);
    return _77_$retval;
}

int main(void) {
  printf("%s",_77_main()._0);
  return 0;
}
