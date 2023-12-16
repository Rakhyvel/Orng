/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _930_main(void);
int64_t _932_id(int64_t _932_x);

/* Function definitions */
int64_t _930_main(void){
    function0 _930_t0;
    int64_t _930_t2;
    int64_t _930_t1;
    int64_t _930_$retval;
    _930_t0 = _932_id;
    _930_t2 = 52;
    $lines[$line_idx++] = "tests/integration/functions/named-1arg.orng:3:8:\n    id(.x = 52)\n      ^";
    _930_t1 = _930_t0(_930_t2);
    $line_idx--;
    _930_$retval = _930_t1;
    return _930_$retval;
}

int64_t _932_id(int64_t _932_x){
    int64_t _932_$retval;
    _932_$retval = _932_x;
    return _932_$retval;
}

int main(void) {
  printf("%ld",_930_main());
  return 0;
}
