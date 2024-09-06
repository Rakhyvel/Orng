/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct1;
struct struct2;

/* Struct, union, and function definitions */
struct struct2 {
    int64_t _0;
    int64_t _1;
};

struct struct1 {
    int64_t _0;
    struct struct2 _1;
};

typedef int64_t(*function0)(int64_t, struct struct2);

/* Function forward definitions */
int64_t _558_main(void);
int64_t _560_add_fields(int64_t _560_scale, struct struct2 _560_mt);


/* Function definitions */
int64_t _558_main(void){
    function0 _558_t0;
    int64_t _558_t2;
    int64_t _558_t4;
    int64_t _558_t5;
    struct struct2 _558_t3;
    int64_t _558_t1;
    int64_t _558_$retval;
    _558_t0 = (function0) _560_add_fields;
    _558_t2 = 2;
    _558_t4 = 450;
    _558_t5 = 50;
    _558_t3 = (struct struct2) {_558_t4, _558_t5};
    $lines[$line_idx++] = "tests/integration/default/default-keyword.orng:8:16:\n    add_fields(2)\n              ^";
    _558_t1 = _558_t0(_558_t2, _558_t3);
    $line_idx--;
    _558_$retval = _558_t1;
    return _558_$retval;
}

int64_t _560_add_fields(int64_t _560_scale, struct struct2 _560_mt){
    int64_t _560_t0;
    int64_t _560_$retval;
    _560_t0 = $add_int64_t(_560_mt._0, _560_mt._1, "tests/integration/default/default-keyword.orng:14:12:\n    (mt.x + mt.y) / scale\n          ^");
    _560_$retval = $div_int64_t(_560_t0, _560_scale, "tests/integration/default/default-keyword.orng:14:20:\n    (mt.x + mt.y) / scale\n                  ^");
    return _560_$retval;
}


int main(void) {
  printf("%ld",_558_main());
  return 0;
}
