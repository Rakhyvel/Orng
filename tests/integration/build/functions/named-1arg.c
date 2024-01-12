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
int64_t _982_main(void);
int64_t _984_id(int64_t _984_x);

/* Function definitions */
int64_t _982_main(void){
    function0 _982_t0;
    int64_t _982_t2;
    int64_t _982_t1;
    int64_t _982_$retval;
    _982_t0 = _984_id;
    _982_t2 = 52;
    $lines[$line_idx++] = "tests/integration/functions/named-1arg.orng:3:8:\n    id(.x = 52)\n      ^";
    _982_t1 = _982_t0(_982_t2);
    $line_idx--;
    _982_$retval = _982_t1;
    return _982_$retval;
}

int64_t _984_id(int64_t _984_x){
    int64_t _984_$retval;
    _984_$retval = _984_x;
    return _984_$retval;
}

int main(void) {
  printf("%ld",_982_main());
  return 0;
}
