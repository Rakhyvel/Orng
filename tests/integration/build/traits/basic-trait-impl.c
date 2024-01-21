/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct0;

/* Typedefs */
struct struct0 {
    int64_t _0;
    int64_t _1;
};

/* Function forward definitions */
int64_t _12_main(void);

/* Function definitions */
int64_t _12_main(void){
    int64_t _12_t1;
    int64_t _12_t2;
    struct struct0 _13_my_val;
    int64_t _12_t4;
    int64_t _12_t3;
    int64_t _12_$retval;
    _12_t1 = 200;
    _12_t2 = 45;
    _13_my_val = (struct struct0) {_12_t1, _12_t2};
    _12_t4 = 2;
    $lines[$line_idx++] = "tests/integration/traits/basic-trait-impl.orng:30:13:\n    my_val.>a(2)\n           ^";
    _12_t3 = _13_my_val(_13_my_val, _12_t4);
    $line_idx--;
    _12_$retval = _12_t3;
    return _12_$retval;
}

int main(void) {
  printf("%ld",_12_main());
  return 0;
}
