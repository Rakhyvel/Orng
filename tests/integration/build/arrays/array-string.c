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
struct0 _1_main(void);

/* Function definitions */
struct0 _1_main(void) {
    struct1 _2_x;
    struct0 _1_$retval;
    _2_x = (struct1) {(struct0) {(uint8_t*)string_0, 6}, (struct0) {(uint8_t*)string_1, 2}, (struct0) {(uint8_t*)string_2, 5}};
    _1_$retval = *((struct0*)&_2_x + 1);
    return _1_$retval;
}

int main(void)
{
  printf("%s",_1_main()._0);
  return 0;
}
