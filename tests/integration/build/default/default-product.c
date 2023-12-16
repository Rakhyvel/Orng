/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _0;
    double _1;
} struct0;

/* Function forward definitions */
int64_t _469_main(void);

/* Function definitions */
int64_t _469_main(void){
    int64_t _469_t1;
    double _469_t2;
    struct0 _470_x;
    int64_t _469_t5;
    uint8_t _469_t7;
    int64_t _469_t3;
    int64_t _469_$retval;
    double _469_t8;
    uint8_t _469_t10;
    _469_t1 = 0;
    _469_t2 = 0.0e+00;
    _470_x = (struct0) {_469_t1, _469_t2};
    _469_t5 = 0;
    _469_t7 = _470_x._0 == _469_t5;
    if (_469_t7) {
        goto BB3;
    } else {
        goto BB11;
    }
BB3:
    _469_t8 = 0.0e+00;
    _469_t10 = _470_x._1 == _469_t8;
    if (_469_t10) {
        goto BB7;
    } else {
        goto BB11;
    }
BB11:
    _469_t3 = 0;
    goto BB10;
BB7:
    _469_t3 = 135;
    goto BB10;
BB10:
    _469_$retval = _469_t3;
    return _469_$retval;
}

int main(void) {
  printf("%ld",_469_main());
  return 0;
}
