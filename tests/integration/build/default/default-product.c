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
int64_t _632_main(void);

/* Function definitions */
int64_t _632_main(void){
    int64_t _632_t1;
    double _632_t2;
    struct0 _633_x;
    int64_t _632_t5;
    uint8_t _632_t7;
    int64_t _632_t3;
    int64_t _632_$retval;
    double _632_t8;
    uint8_t _632_t10;
    _632_t1 = 0;
    _632_t2 = 0.0e+00;
    _633_x = (struct0) {_632_t1, _632_t2};
    _632_t5 = 0;
    _632_t7 = _633_x._0 == _632_t5;
    if (_632_t7) {
        goto BB3;
    } else {
        goto BB11;
    }
BB3:
    _632_t8 = 0.0e+00;
    _632_t10 = _633_x._1 == _632_t8;
    if (_632_t10) {
        goto BB7;
    } else {
        goto BB11;
    }
BB11:
    _632_t3 = 0;
    goto BB10;
BB7:
    _632_t3 = 135;
    goto BB10;
BB10:
    _632_$retval = _632_t3;
    return _632_$retval;
}

int main(void) {
  printf("%ld",_632_main());
  return 0;
}
