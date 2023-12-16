/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _0;
    int64_t _1;
} struct2;

typedef struct {
    int64_t _0;
    struct2 _1;
} struct1;

typedef int64_t(*function0)(int64_t, struct2);

/* Function forward definitions */
int64_t _514_main(void);
int64_t _516_add_fields(int64_t _516_scale,struct2 _516_mt);

/* Function definitions */
int64_t _514_main(void){
    function0 _514_t0;
    int64_t _514_t2;
    int64_t _514_t4;
    int64_t _514_t5;
    struct2 _514_t3;
    int64_t _514_t1;
    int64_t _514_$retval;
    _514_t0 = _516_add_fields;
    _514_t2 = 2;
    _514_t4 = 450;
    _514_t5 = 50;
    _514_t3 = (struct2) {_514_t4, _514_t5};
    $lines[$line_idx++] = "tests/integration/default/default-keyword.orng:8:16:\n    add_fields(2)\n              ^";
    _514_t1 = _514_t0(_514_t2, _514_t3);
    $line_idx--;
    _514_$retval = _514_t1;
    return _514_$retval;
}

int64_t _516_add_fields(int64_t _516_scale,struct2 _516_mt){
    int64_t _516_t0;
    int64_t _516_$retval;
    _516_t0 = $add_int64_t(_516_mt._0, _516_mt._1, "tests/integration/default/default-keyword.orng:14:12:\n    (mt.x + mt.y) / scale\n          ^");
    _516_$retval = $div_int64_t(_516_t0, _516_scale, "tests/integration/default/default-keyword.orng:14:20:\n    (mt.x + mt.y) / scale\n                  ^");
    return _516_$retval;
}

int main(void) {
  printf("%ld",_514_main());
  return 0;
}
