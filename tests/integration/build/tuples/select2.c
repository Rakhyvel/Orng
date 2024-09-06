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
int64_t _1888_main(void);
int64_t _1890_f(struct struct1 _1890_a);


/* Function definitions */
int64_t _1888_main(void){
    int64_t _1888_t2;
    int64_t _1888_t3;
    struct struct0 _1888_t1;
    int64_t _1888_t4;
    struct struct1 _1889_x;
    function2 _1888_t6;
    int64_t _1888_t7;
    int64_t _1888_$retval;
    _1888_t2 = 50;
    _1888_t3 = 150;
    _1888_t1 = (struct struct0) {_1888_t2, _1888_t3};
    _1888_t4 = 300;
    _1889_x = (struct struct1) {_1888_t1, _1888_t4};
    _1888_t6 = (function2) _1890_f;
    $lines[$line_idx++] = "tests/integration/tuples/select2.orng:4:7:\n    f(x)\n     ^";
    _1888_t7 = _1888_t6(_1889_x);
    $line_idx--;
    _1888_$retval = _1888_t7;
    return _1888_$retval;
}

int64_t _1890_f(struct struct1 _1890_a){
    int64_t _1890_$retval;
    goto BB2041;
BB2041:
    _1890_$retval = _1890_a._1;
    return _1890_$retval;
}


int main(void) {
  printf("%ld",_1888_main());
  return 0;
}
