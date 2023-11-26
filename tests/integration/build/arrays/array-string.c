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
struct0 _47_main(void);

/* Function definitions */
struct0 _47_main(void) {
    struct0 _47_t1;
    struct0 _47_t2;
    struct0 _47_t3;
    struct1 _48_x;
    int64_t _47_t4;
    struct0 _47_$retval;
    _47_t1 = (struct0) {(uint8_t*)string_0, 6};
    _47_t2 = (struct0) {(uint8_t*)string_1, 2};
    _47_t3 = (struct0) {(uint8_t*)string_2, 5};
    _48_x = (struct1) {_47_t1, _47_t2, _47_t3};
    _47_t4 = 1;
    _47_$retval = *((struct0*)&_48_x + _47_t4);
    return _47_$retval;
}

int main(void) {
  printf("%s",_47_main()._0);
  return 0;
}
