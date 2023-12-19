/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(uint8_t);

/* Function forward definitions */
int64_t _1888_main(void);
int64_t _1890_f(uint8_t _1890_b);

/* Function definitions */
int64_t _1888_main(void){
    int64_t _1889_x;
    int64_t* _1889_y;
    function0 _1888_t2;
    int64_t _1888_t4;
    uint8_t _1888_t6;
    uint8_t _1888_t5;
    uint8_t _1888_t7;
    int64_t _1888_t3;
    int64_t _1888_$retval;
    _1889_x = 0;
    _1889_y = &_1889_x;
    _1888_t2 = _1890_f;
    _1888_t4 = 1;
    _1888_t6 = *_1889_y == _1888_t4;
    if (_1888_t6) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _1888_t5 = 1;
    goto BB2;
BB4:
    _1888_t5 = 0;
    goto BB2;
BB2:
    _1888_t7 = !_1888_t5;
    $lines[$line_idx++] = "tests/integration/whitebox/not.orng:5:7:\n    f(not (y^ == 1))\n     ^";
    _1888_t3 = _1888_t2(_1888_t7);
    $line_idx--;
    _1888_$retval = _1888_t3;
    return _1888_$retval;
}

int64_t _1890_f(uint8_t _1890_b){
    uint8_t _1890_t0;
    uint8_t _1890_t1;
    int64_t _1890_t2;
    int64_t _1890_$retval;
    _1890_t0 = !_1890_b;
    _1890_b = _1890_t0;
    _1890_t1 = !_1890_t0;
    _1890_b = _1890_t1;
    if (_1890_t0) {
        goto BB5;
    } else {
        goto BB1;
    }
BB5:
    _1890_t2 = 10;
    goto BB4;
BB1:
    _1890_t2 = 31;
    goto BB4;
BB4:
    _1890_$retval = _1890_t2;
    return _1890_$retval;
}

int main(void) {
  printf("%ld",_1888_main());
  return 0;
}
