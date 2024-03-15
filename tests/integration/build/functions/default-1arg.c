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
int64_t _942_main(void);
int64_t _944_return53(int64_t _944_x);


/* Function definitions */
int64_t _942_main(void){
    function0 _942_t0;
    int64_t _942_t2;
    int64_t _942_t1;
    int64_t _942_$retval;
    _942_t0 = (function0) _944_return53;
    _942_t2 = 53;
    $lines[$line_idx++] = "tests/integration/functions/default-1arg.orng:3:14:\n    return53()\n            ^";
    _942_t1 = _942_t0(_942_t2);
    $line_idx--;
    _942_$retval = _942_t1;
    return _942_$retval;
}

int64_t _944_return53(int64_t _944_x){
    int64_t _944_$retval;
    _944_$retval = _944_x;
    return _944_$retval;
}


int main(void) {
  printf("%ld",_942_main());
  return 0;
}
