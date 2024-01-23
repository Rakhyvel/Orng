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
int64_t _944_g(int64_t _944_x);
int64_t _946_f(int64_t _946_x);


/* Function definitions */
int64_t _942_main(void){
    function0 _942_t0;
    int64_t _942_t2;
    int64_t _942_t1;
    int64_t _942_$retval;
    _942_t0 = _944_g;
    _942_t2 = 194;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:3:7:\n    g(194)\n     ^";
    _942_t1 = _942_t0(_942_t2);
    $line_idx--;
    _942_$retval = _942_t1;
    return _942_$retval;
}

int64_t _944_g(int64_t _944_x){
    int64_t _945_z;
    function0 _944_t0;
    int64_t _944_t1;
    int64_t _944_$retval;
    _945_z = _944_x;
    _944_t0 = _946_f;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:8:7:\n    f(z)\n     ^";
    _944_t1 = _944_t0(_945_z);
    $line_idx--;
    _944_$retval = _944_t1;
    return _944_$retval;
}

int64_t _946_f(int64_t _946_x){
    int64_t _946_$retval;
    _946_$retval = _946_x;
    return _946_$retval;
}


int main(void) {
  printf("%ld",_942_main());
  return 0;
}
