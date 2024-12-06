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
int64_t _1905_main(void);
int64_t _1907_f(struct struct1 _1907_a);


/* Function definitions */
int64_t _1905_main(void){
    int64_t _1905_t2;
    int64_t _1905_t3;
    struct struct0 _1905_t1;
    int64_t _1905_t4;
    struct struct1 _1906_x;
    function2 _1905_t6;
    int64_t _1905_t7;
    int64_t _1905_$retval;
    _1905_t2 = 50;
    _1905_t3 = 150;
    _1905_t1 = (struct struct0) {_1905_t2, _1905_t3};
    _1905_t4 = 300;
    _1906_x = (struct struct1) {_1905_t1, _1905_t4};
    _1905_t6 = (function2) _1907_f;
    $lines[$line_idx++] = "tests/integration/tuples/select2.orng:4:7:\n    f(x)\n     ^";
    _1905_t7 = _1905_t6(_1906_x);
    $line_idx--;
    _1905_$retval = _1905_t7;
    return _1905_$retval;
}

int64_t _1907_f(struct struct1 _1907_a){
    int64_t _1907_$retval;
    goto BB2057;
BB2057:
    _1907_$retval = _1907_a._1;
    return _1907_$retval;
}


int main(void) {
  printf("%ld",_1905_main());
  return 0;
}
