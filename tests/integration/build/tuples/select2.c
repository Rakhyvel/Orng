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
int64_t _1885_main(void);
int64_t _1887_f(struct struct1 _1887_a);


/* Function definitions */
int64_t _1885_main(void){
    int64_t _1885_t2;
    int64_t _1885_t3;
    struct struct0 _1885_t1;
    int64_t _1885_t4;
    struct struct1 _1886_x;
    function2 _1885_t6;
    int64_t _1885_t7;
    int64_t _1885_$retval;
    _1885_t2 = 50;
    _1885_t3 = 150;
    _1885_t1 = (struct struct0) {_1885_t2, _1885_t3};
    _1885_t4 = 300;
    _1886_x = (struct struct1) {_1885_t1, _1885_t4};
    _1885_t6 = (function2) _1887_f;
    $lines[$line_idx++] = "tests/integration/tuples/select2.orng:4:7:\n    f(x)\n     ^";
    _1885_t7 = _1885_t6(_1886_x);
    $line_idx--;
    _1885_$retval = _1885_t7;
    return _1885_$retval;
}

int64_t _1887_f(struct struct1 _1887_a){
    int64_t _1887_$retval;
    goto BB2039;
BB2039:
    _1887_$retval = _1887_a._1;
    return _1887_$retval;
}


int main(void) {
  printf("%ld",_1885_main());
  return 0;
}
