/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */

/* Struct, union, and function definitions */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _747_main(void);
uint8_t _752_f(int64_t _752_x);


/* Function definitions */
int64_t _747_main(void){
    function0 _747_t1;
    int64_t _747_t3;
    uint8_t _747_t2;
    int64_t _747_t0;
    int64_t _747_$retval;
    _747_t1 = _752_f;
    _747_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mod-0.orng:3:10:\n    if f(4) {\n        ^";
    _747_t2 = _747_t1(_747_t3);
    $line_idx--;
    if (_747_t2) {
        goto BB902;
    } else {
        goto BB906;
    }
BB902:
    _747_t0 = 191;
    goto BB905;
BB906:
    _747_t0 = 4;
    goto BB905;
BB905:
    _747_$retval = _747_t0;
    return _747_$retval;
}

uint8_t _752_f(int64_t _752_x){
    uint8_t _752_$retval;
    (void)_752_x;
    _752_$retval = 1;
    return _752_$retval;
}


int main(void) {
  printf("%ld",_747_main());
  return 0;
}
