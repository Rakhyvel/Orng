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
int64_t _1846_main(void);
int64_t _1848_f(struct struct1 _1848_a);


/* Function definitions */
int64_t _1846_main(void){
    int64_t _1846_t2;
    int64_t _1846_t3;
    struct struct0 _1846_t1;
    int64_t _1846_t4;
    struct struct1 _1847_x;
    function2 _1846_t6;
    int64_t _1846_t7;
    int64_t _1846_$retval;
    _1846_t2 = 50;
    _1846_t3 = 150;
    _1846_t1 = (struct struct0) {_1846_t2, _1846_t3};
    _1846_t4 = 300;
    _1847_x = (struct struct1) {_1846_t1, _1846_t4};
    _1846_t6 = (function2) _1848_f;
    $lines[$line_idx++] = "tests/integration/tuples/select2.orng:4:7:\n    f(x)\n     ^";
    _1846_t7 = _1846_t6(_1847_x);
    $line_idx--;
    _1846_$retval = _1846_t7;
    return _1846_$retval;
}

int64_t _1848_f(struct struct1 _1848_a){
    int64_t _1848_$retval;
    goto BB2029;
BB2029:
    _1848_$retval = _1848_a._1;
    return _1848_$retval;
}


int main(void) {
  printf("%ld",_1846_main());
  return 0;
}
