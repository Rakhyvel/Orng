/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _753_main(void);
int64_t _755_f(int64_t _755_x);

/* Function definitions */
int64_t _753_main(void){
    function0 _753_t0;
    int64_t _753_t2;
    int64_t _753_t1;
    int64_t _753_$retval;
    _753_t0 = _755_f;
    _753_t2 = 1;
    $lines[$line_idx++] = "tests/integration/expressions/neq-0-rhs.orng:3:7:\n    f(1)\n     ^";
    _753_t1 = _753_t0(_753_t2);
    $line_idx--;
    _753_$retval = _753_t1;
    return _753_$retval;
}

int64_t _755_f(int64_t _755_x){
    int64_t _755_t1;
    uint8_t _755_t2;
    int64_t _755_t0;
    int64_t _755_$retval;
    _755_t1 = 0;
    _755_t2 = _755_x != _755_t1;
    if (_755_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _755_t0 = 173;
    goto BB4;
BB5:
    _755_t0 = 3;
    goto BB4;
BB4:
    _755_$retval = _755_t0;
    return _755_$retval;
}

int main(void) {
  printf("%ld",_753_main());
  return 0;
}
