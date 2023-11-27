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
char* string_0 = "\x5B";

/* Function forward definitions */
uint8_t _986_main(void);

/* Function definitions */
uint8_t _986_main(void) {
    struct0 _987_x;
    int64_t _986_t1;
    uint8_t _986_$retval;
    _987_x = (struct0) {(uint8_t*)string_0, 1};
    _986_t1 = 0;
    _986_$retval = *((uint8_t*)_987_x._0 + _986_t1);
    return _986_$retval;
}

int main(void) {
  printf("%d",_986_main());
  return 0;
}
