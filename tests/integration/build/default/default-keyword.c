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
int64_t _572_main(void);
int64_t _574_add_fields(int64_t _574_scale, struct struct2 _574_mt);


/* Function definitions */
int64_t _572_main(void){
    function0 _572_t0;
    int64_t _572_t2;
    int64_t _572_t4;
    int64_t _572_t5;
    struct struct2 _572_t3;
    int64_t _572_t1;
    int64_t _572_$retval;
    _572_t0 = (function0) _574_add_fields;
    _572_t2 = 2;
    _572_t4 = 450;
    _572_t5 = 50;
    _572_t3 = (struct struct2) {_572_t4, _572_t5};
    $lines[$line_idx++] = "tests/integration/default/default-keyword.orng:8:16:\n    add_fields(2)\n              ^";
    _572_t1 = _572_t0(_572_t2, _572_t3);
    $line_idx--;
    _572_$retval = _572_t1;
    return _572_$retval;
}

int64_t _574_add_fields(int64_t _574_scale, struct struct2 _574_mt){
    int64_t _574_t0;
    int64_t _574_$retval;
    _574_t0 = $add_int64_t(_574_mt._0, _574_mt._1, "tests/integration/default/default-keyword.orng:14:12:\n    (mt.x + mt.y) / scale\n          ^");
    _574_$retval = $div_int64_t(_574_t0, _574_scale, "tests/integration/default/default-keyword.orng:14:20:\n    (mt.x + mt.y) / scale\n                  ^");
    return _574_$retval;
}


int main(void) {
  printf("%ld",_572_main());
  return 0;
}
