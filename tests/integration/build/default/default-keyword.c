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
int64_t _551_main(void);
int64_t _553_add_fields(int64_t _553_scale, struct struct2 _553_mt);


/* Function definitions */
int64_t _551_main(void){
    function0 _551_t0;
    int64_t _551_t2;
    int64_t _551_t4;
    int64_t _551_t5;
    struct struct2 _551_t3;
    int64_t _551_t1;
    int64_t _551_$retval;
    _551_t0 = _553_add_fields;
    _551_t2 = 2;
    _551_t4 = 450;
    _551_t5 = 50;
    _551_t3 = (struct struct2) {_551_t4, _551_t5};
    $lines[$line_idx++] = "tests/integration/default/default-keyword.orng:8:16:\n    add_fields(2)\n              ^";
    _551_t1 = _551_t0(_551_t2, _551_t3);
    $line_idx--;
    _551_$retval = _551_t1;
    return _551_$retval;
}

int64_t _553_add_fields(int64_t _553_scale, struct struct2 _553_mt){
    int64_t _553_t0;
    int64_t _553_$retval;
    _553_t0 = $add_int64_t(_553_mt._0, _553_mt._1, "tests/integration/default/default-keyword.orng:14:12:\n    (mt.x + mt.y) / scale\n          ^");
    _553_$retval = $div_int64_t(_553_t0, _553_scale, "tests/integration/default/default-keyword.orng:14:20:\n    (mt.x + mt.y) / scale\n                  ^");
    return _553_$retval;
}


int main(void) {
  printf("%ld",_551_main());
  return 0;
}
