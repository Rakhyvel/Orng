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
int64_t _976_main(void);
int64_t _978_return53(int64_t _978_x);


/* Function definitions */
int64_t _976_main(void){
    function0 _976_t0;
    int64_t _976_t2;
    int64_t _976_t1;
    int64_t _976_$retval;
    _976_t0 = (function0) _978_return53;
    _976_t2 = 53;
    $lines[$line_idx++] = "tests/integration/functions/default-1arg.orng:3:14:\n    return53()\n            ^";
    _976_t1 = _976_t0(_976_t2);
    $line_idx--;
    _976_$retval = _976_t1;
    return _976_$retval;
}

int64_t _978_return53(int64_t _978_x){
    int64_t _978_$retval;
    goto BB1155;
BB1155:
    _978_$retval = _978_x;
    return _978_$retval;
}


int main(void) {
  printf("%ld",_976_main());
  return 0;
}
