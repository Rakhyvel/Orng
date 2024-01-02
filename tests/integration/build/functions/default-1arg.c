/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _949_main(void);
int64_t _951_return53(int64_t _951_x);

/* Function definitions */
int64_t _949_main(void){
    function0 _949_t0;
    int64_t _949_t2;
    int64_t _949_t1;
    int64_t _949_$retval;
    _949_t0 = _951_return53;
    _949_t2 = 53;
    $lines[$line_idx++] = "tests/integration/functions/default-1arg.orng:3:14:\n    return53()\n            ^";
    _949_t1 = _949_t0(_949_t2);
    $line_idx--;
    _949_$retval = _949_t1;
    return _949_$retval;
}

int64_t _951_return53(int64_t _951_x){
    int64_t _951_$retval;
    _951_$retval = _951_x;
    return _951_$retval;
}

int main(void) {
  printf("%ld",_949_main());
  return 0;
}
