/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _756_main(void);
int64_t _758_f(int64_t _758_x);

/* Function definitions */
int64_t _756_main(void){
    function0 _756_t0;
    int64_t _756_t2;
    int64_t _756_t1;
    int64_t _756_$retval;
    _756_t0 = _758_f;
    _756_t2 = 1;
    $lines[$line_idx++] = "tests/integration/expressions/neq-0-lhs.orng:3:7:\n    f(1)\n     ^";
    _756_t1 = _756_t0(_756_t2);
    $line_idx--;
    _756_$retval = _756_t1;
    return _756_$retval;
}

int64_t _758_f(int64_t _758_x){
    int64_t _758_t1;
    uint8_t _758_t2;
    int64_t _758_t0;
    int64_t _758_$retval;
    _758_t1 = 0;
    _758_t2 = _758_t1 != _758_x;
    if (_758_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _758_t0 = 174;
    goto BB4;
BB5:
    _758_t0 = 3;
    goto BB4;
BB4:
    _758_$retval = _758_t0;
    return _758_$retval;
}

int main(void) {
  printf("%ld",_756_main());
  return 0;
}
