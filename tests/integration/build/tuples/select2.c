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
int64_t _1918_main(void);
int64_t _1920_f(struct struct1 _1920_a);


/* Function definitions */
int64_t _1918_main(void){
    int64_t _1918_t2;
    int64_t _1918_t3;
    struct struct0 _1918_t1;
    int64_t _1918_t4;
    struct struct1 _1919_x;
    function2 _1918_t6;
    int64_t _1918_t7;
    int64_t _1918_$retval;
    _1918_t2 = 50;
    _1918_t3 = 150;
    _1918_t1 = (struct struct0) {_1918_t2, _1918_t3};
    _1918_t4 = 300;
    _1919_x = (struct struct1) {_1918_t1, _1918_t4};
    _1918_t6 = (function2) _1920_f;
    $lines[$line_idx++] = "tests/integration/tuples/select2.orng:4:7:\n    f(x)\n     ^";
    _1918_t7 = _1918_t6(_1919_x);
    $line_idx--;
    _1918_$retval = _1918_t7;
    return _1918_$retval;
}

int64_t _1920_f(struct struct1 _1920_a){
    int64_t _1920_$retval;
    goto BB2070;
BB2070:
    _1920_$retval = _1920_a._1;
    return _1920_$retval;
}


int main(void) {
  printf("%ld",_1918_main());
  return 0;
}
