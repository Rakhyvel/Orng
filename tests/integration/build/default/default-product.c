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
    int64_t _531_t5;
    uint8_t _531_t7;
    int64_t _531_t3;
    int64_t _531_$retval;
    double _531_t8;
    uint8_t _531_t10;
    _531_t1 = 0;
    _531_t2 = 0.0e+00;
    _532_x = (struct0) {_531_t1, _531_t2};
    _531_t5 = 0;
    _531_t7 = _532_x._0 == _531_t5;
    if (_531_t7) {
        goto BB655;
    } else {
        goto BB663;
    }
BB655:
    _531_t8 = 0.0e+00;
    _531_t10 = _532_x._1 == _531_t8;
    if (_531_t10) {
        goto BB659;
    } else {
        goto BB663;
    }
BB663:
    _531_t3 = 0;
    goto BB662;
BB659:
    _531_t3 = 135;
    goto BB662;
BB662:
    _531_$retval = _531_t3;
    return _531_$retval;
}

int main(void) {
  printf("%ld",_531_main());
  return 0;
}
