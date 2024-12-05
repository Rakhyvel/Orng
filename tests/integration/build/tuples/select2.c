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
int64_t _1899_main(void);
int64_t _1901_f(struct struct1 _1901_a);


/* Function definitions */
int64_t _1899_main(void){
    int64_t _1899_t2;
    int64_t _1899_t3;
    struct struct0 _1899_t1;
    int64_t _1899_t4;
    struct struct1 _1900_x;
    function2 _1899_t6;
    int64_t _1899_t7;
    int64_t _1899_$retval;
    _1899_t2 = 50;
    _1899_t3 = 150;
    _1899_t1 = (struct struct0) {_1899_t2, _1899_t3};
    _1899_t4 = 300;
    _1900_x = (struct struct1) {_1899_t1, _1899_t4};
    _1899_t6 = (function2) _1901_f;
    $lines[$line_idx++] = "tests/integration/tuples/select2.orng:4:7:\n    f(x)\n     ^";
    _1899_t7 = _1899_t6(_1900_x);
    $line_idx--;
    _1899_$retval = _1899_t7;
    return _1899_$retval;
}

int64_t _1901_f(struct struct1 _1901_a){
    int64_t _1901_$retval;
    goto BB2048;
BB2048:
    _1901_$retval = _1901_a._1;
    return _1901_$retval;
}


int main(void) {
  printf("%ld",_1899_main());
  return 0;
}
