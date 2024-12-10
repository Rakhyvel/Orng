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
int64_t _570_main(void);
int64_t _572_add_fields(int64_t _572_scale, struct struct2 _572_mt);


/* Function definitions */
int64_t _570_main(void){
    function0 _570_t0;
    int64_t _570_t2;
    int64_t _570_t4;
    int64_t _570_t5;
    struct struct2 _570_t3;
    int64_t _570_t1;
    int64_t _570_$retval;
    _570_t0 = (function0) _572_add_fields;
    _570_t2 = 2;
    _570_t4 = 450;
    _570_t5 = 50;
    _570_t3 = (struct struct2) {_570_t4, _570_t5};
    $lines[$line_idx++] = "tests/integration/default/default-keyword.orng:8:16:\n    add_fields(2)\n              ^";
    _570_t1 = _570_t0(_570_t2, _570_t3);
    $line_idx--;
    _570_$retval = _570_t1;
    return _570_$retval;
}

int64_t _572_add_fields(int64_t _572_scale, struct struct2 _572_mt){
    int64_t _572_t0;
    int64_t _572_$retval;
    _572_t0 = $add_int64_t(_572_mt._0, _572_mt._1, "tests/integration/default/default-keyword.orng:14:12:\n    (mt.x + mt.y) / scale\n          ^");
    _572_$retval = $div_int64_t(_572_t0, _572_scale, "tests/integration/default/default-keyword.orng:14:20:\n    (mt.x + mt.y) / scale\n                  ^");
    return _572_$retval;
}


int main(void) {
  printf("%ld",_570_main());
  return 0;
}
