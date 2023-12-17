/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _909_main(void);
int64_t _911_f(int64_t _911_x);

/* Function definitions */
int64_t _909_main(void){
    function0 _909_t0;
    int64_t _909_t2;
    int64_t _909_t1;
    int64_t _909_$retval;
    _909_t0 = _911_f;
    _909_t2 = 1;
    $lines[$line_idx++] = "tests/integration/expressions/neq-0-rhs.orng:3:7:\n    f(1)\n     ^";
    _909_t1 = _909_t0(_909_t2);
    $line_idx--;
    _909_$retval = _909_t1;
    return _909_$retval;
}

int64_t _911_f(int64_t _911_x){
    int64_t _911_t1;
    uint8_t _911_t2;
    int64_t _911_t0;
    int64_t _911_$retval;
    _911_t1 = 0;
    _911_t2 = _911_x != _911_t1;
    if (_911_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _911_t0 = 173;
    goto BB4;
BB5:
    _911_t0 = 3;
    goto BB4;
BB4:
    _911_$retval = _911_t0;
    return _911_$retval;
}

int main(void) {
  printf("%ld",_909_main());
  return 0;
}
