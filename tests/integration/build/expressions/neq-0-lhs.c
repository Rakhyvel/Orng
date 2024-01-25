/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */

/* Struct, union, and function definitions */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _823_main(void);
int64_t _825_f(int64_t _825_x);


/* Function definitions */
int64_t _823_main(void){
    function0 _823_t0;
    int64_t _823_t2;
    int64_t _823_t1;
    int64_t _823_$retval;
    _823_t0 = _825_f;
    _823_t2 = 1;
    $lines[$line_idx++] = "tests/integration/expressions/neq-0-lhs.orng:3:7:\n    f(1)\n     ^";
    _823_t1 = _823_t0(_823_t2);
    $line_idx--;
    _823_$retval = _823_t1;
    return _823_$retval;
}

int64_t _825_f(int64_t _825_x){
    int64_t _825_t1;
    uint8_t _825_t3;
    int64_t _825_t0;
    int64_t _825_$retval;
    _825_t1 = 0;
    _825_t3 = _825_t1==_825_x;
    if (_825_t3) {
        goto BB1018;
    } else {
        goto BB1014;
    }
BB1018:
    _825_t0 = 3;
    goto BB1017;
BB1014:
    _825_t0 = 174;
    goto BB1017;
BB1017:
    _825_$retval = _825_t0;
    return _825_$retval;
}


int main(void) {
  printf("%ld",_823_main());
  return 0;
}
