/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _0;
    int64_t _1;
} struct0;

/* Function forward definitions */
int64_t _46_add(int64_t _46_a,int64_t _46_b);
int64_t _36_main(void);

/* Function definitions */
int64_t _46_add(int64_t _46_a,int64_t _46_b){
    int64_t _46_$retval;
    _46_$retval = $add_int64_t(_46_a, _46_b, "tests/integration/comptime/default-init.orng:7:36:\nfn add(a: Int, b: Int) -> Int { a + b }\n                                  ^");
    return _46_$retval;
}

int64_t _36_main(void){
    int64_t _36_t1;
    int64_t _36_t2;
    struct0 _37_x;
    int64_t _36_$retval;
    _36_t1 = 240;
    _36_t2 = 5;
    _37_x = (struct0) {_36_t1, _36_t2};
    _36_$retval = $add_int64_t(_37_x._0, _37_x._1, "tests/integration/comptime/default-init.orng:4:10:\n    x.a + x.b\n        ^");
    return _36_$retval;
}

int main(void) {
  printf("%ld",_36_main());
  return 0;
}
