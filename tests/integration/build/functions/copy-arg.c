/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _939_main(void);
int64_t _941_g(int64_t _941_x);
int64_t _943_f(int64_t _943_x);

/* Function definitions */
int64_t _939_main(void){
    function0 _939_t0;
    int64_t _939_t2;
    int64_t _939_t1;
    int64_t _939_$retval;
    _939_t0 = _941_g;
    _939_t2 = 194;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:3:7:\n    g(194)\n     ^";
    _939_t1 = _939_t0(_939_t2);
    $line_idx--;
    _939_$retval = _939_t1;
    return _939_$retval;
}

int64_t _941_g(int64_t _941_x){
    int64_t _942_z;
    function0 _941_t0;
    int64_t _941_t1;
    int64_t _941_$retval;
    _942_z = _941_x;
    _941_t0 = _943_f;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:8:7:\n    f(z)\n     ^";
    _941_t1 = _941_t0(_942_z);
    $line_idx--;
    _941_$retval = _941_t1;
    return _941_$retval;
}

int64_t _943_f(int64_t _943_x){
    int64_t _943_$retval;
    _943_$retval = _943_x;
    return _943_$retval;
}

int main(void) {
  printf("%ld",_939_main());
  return 0;
}
