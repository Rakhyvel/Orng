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
int64_t _1838_main(void);
int64_t _1840_f(struct struct1 _1840_a);


/* Function definitions */
int64_t _1838_main(void){
    int64_t _1838_t2;
    int64_t _1838_t3;
    struct struct0 _1838_t1;
    int64_t _1838_t4;
    struct struct1 _1839_x;
    function2 _1838_t6;
    int64_t _1838_t7;
    int64_t _1838_$retval;
    _1838_t2 = 50;
    _1838_t3 = 150;
    _1838_t1 = (struct struct0) {_1838_t2, _1838_t3};
    _1838_t4 = 300;
    _1839_x = (struct struct1) {_1838_t1, _1838_t4};
    _1838_t6 = (function2) _1840_f;
    $lines[$line_idx++] = "tests/integration/tuples/select2.orng:4:7:\n    f(x)\n     ^";
    _1838_t7 = _1838_t6(_1839_x);
    $line_idx--;
    _1838_$retval = _1838_t7;
    return _1838_$retval;
}

int64_t _1840_f(struct struct1 _1840_a){
    int64_t _1840_$retval;
    goto BB2023;
BB2023:
    _1840_$retval = _1840_a._1;
    return _1840_$retval;
}


int main(void) {
  printf("%ld",_1838_main());
  return 0;
}
