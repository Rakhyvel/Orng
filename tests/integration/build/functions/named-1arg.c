/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _990_main(void);
int64_t _992_id(int64_t _992_x);

/* Function definitions */
int64_t _990_main(void){
    function0 _990_t0;
    int64_t _990_t2;
    int64_t _990_t1;
    int64_t _990_$retval;
    _990_t0 = _992_id;
    _990_t2 = 52;
    $lines[$line_idx++] = "tests/integration/functions/named-1arg.orng:3:8:\n    id(.x = 52)\n      ^";
    _990_t1 = _990_t0(_990_t2);
    $line_idx--;
    _990_$retval = _990_t1;
    return _990_$retval;
}

int64_t _992_id(int64_t _992_x){
    int64_t _992_$retval;
    _992_$retval = _992_x;
    return _992_$retval;
}

int main(void) {
  printf("%ld",_990_main());
  return 0;
}
