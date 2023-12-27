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
int64_t _531_main(void);

/* Function definitions */
int64_t _531_main(void){
    int64_t _531_t1;
    double _531_t2;
    struct0 _532_x;
    int64_t _531_t4;
    uint8_t _531_t6;
    int64_t _531_t3;
    double _531_t7;
    uint8_t _531_t9;
    int64_t _531_$retval;
    _531_t1 = 0;
    _531_t2 = 0.0e+00;
    _532_x = (struct0) {_531_t1, _531_t2};
    _531_t4 = 0;
    _531_t6 = _532_x._0==_531_t4;
    if (_531_t6) {
        goto BB633;
    } else {
        goto BB640;
    }
BB633:
    _531_t7 = 0.0e+00;
    _531_t9 = _532_x._1==_531_t7;
    if (_531_t9) {
        goto BB636;
    } else {
        goto BB640;
    }
BB640:
    _531_t3 = 0;
    goto BB639;
BB636:
    _531_t3 = 135;
    goto BB639;
BB639:
    _531_$retval = _531_t3;
    return _531_$retval;
}

int main(void) {
  printf("%ld",_531_main());
  return 0;
}
