/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _957_main(void);
int64_t _959_id(int64_t _959_x);

/* Function definitions */
int64_t _957_main(void){
    function0 _957_t0;
    int64_t _957_t2;
    int64_t _957_t1;
    int64_t _957_$retval;
    _957_t0 = _959_id;
    _957_t2 = 52;
    $lines[$line_idx++] = "tests/integration/functions/named-1arg.orng:3:8:\n    id(.x = 52)\n      ^";
    _957_t1 = _957_t0(_957_t2);
    $line_idx--;
    _957_$retval = _957_t1;
    return _957_$retval;
}

int64_t _959_id(int64_t _959_x){
    int64_t _959_$retval;
    _959_$retval = _959_x;
    return _959_$retval;
}

int main(void) {
  printf("%ld",_957_main());
  return 0;
}
