/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _946_main(void);
int64_t _948_return53(int64_t _948_x);

/* Function definitions */
int64_t _946_main(void){
    function0 _946_t0;
    int64_t _946_t2;
    int64_t _946_t1;
    int64_t _946_$retval;
    _946_t0 = _948_return53;
    _946_t2 = 53;
    $lines[$line_idx++] = "tests/integration/functions/default-1arg.orng:3:14:\n    return53()\n            ^";
    _946_t1 = _946_t0(_946_t2);
    $line_idx--;
    _946_$retval = _946_t1;
    return _946_$retval;
}

int64_t _948_return53(int64_t _948_x){
    int64_t _948_$retval;
    _948_$retval = _948_x;
    return _948_$retval;
}

int main(void) {
  printf("%ld",_946_main());
  return 0;
}
