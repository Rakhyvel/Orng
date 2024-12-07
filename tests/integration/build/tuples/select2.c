/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;
struct struct1;

/* Struct, union, and function definitions */
struct struct0 {
    int64_t _0;
    int64_t _1;
};

struct struct1 {
    struct struct0 _0;
    int64_t _1;
};

typedef int64_t(*function2)(struct struct1);

/* Function forward definitions */
int64_t _1913_main(void);
int64_t _1915_f(struct struct1 _1915_a);


/* Function definitions */
int64_t _1913_main(void){
    int64_t _1913_t2;
    int64_t _1913_t3;
    struct struct0 _1913_t1;
    int64_t _1913_t4;
    struct struct1 _1914_x;
    function2 _1913_t6;
    int64_t _1913_t7;
    int64_t _1913_$retval;
    _1913_t2 = 50;
    _1913_t3 = 150;
    _1913_t1 = (struct struct0) {_1913_t2, _1913_t3};
    _1913_t4 = 300;
    _1914_x = (struct struct1) {_1913_t1, _1913_t4};
    _1913_t6 = (function2) _1915_f;
    $lines[$line_idx++] = "tests/integration/tuples/select2.orng:4:7:\n    f(x)\n     ^";
    _1913_t7 = _1913_t6(_1914_x);
    $line_idx--;
    _1913_$retval = _1913_t7;
    return _1913_$retval;
}

int64_t _1915_f(struct struct1 _1915_a){
    int64_t _1915_$retval;
    goto BB2067;
BB2067:
    _1915_$retval = _1915_a._1;
    return _1915_$retval;
}


int main(void) {
  printf("%ld",_1913_main());
  return 0;
}
