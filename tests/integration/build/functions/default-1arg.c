/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _968_main(void);
int64_t _970_return53(int64_t _970_x);

/* Function definitions */
int64_t _968_main(void){
    function0 _968_t0;
    int64_t _968_t2;
    int64_t _968_t1;
    int64_t _968_$retval;
    _968_t0 = _970_return53;
    _968_t2 = 53;
    $lines[$line_idx++] = "tests/integration/functions/default-1arg.orng:3:14:\n    return53()\n            ^";
    _968_t1 = _968_t0(_968_t2);
    $line_idx--;
    _968_$retval = _968_t1;
    return _968_$retval;
}

int64_t _970_return53(int64_t _970_x){
    int64_t _970_$retval;
    _970_$retval = _970_x;
    return _970_$retval;
}

int main(void) {
  printf("%ld",_968_main());
  return 0;
}
