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
int64_t _285_main(void);
int64_t _287_add_fields(int64_t _287_scale,struct2 _287_mt);

/* Function definitions */
int64_t _285_main(void) {
    function0 _285_t0;
    int64_t _285_t2;
    int64_t _285_t4;
    int64_t _285_t5;
    struct2 _285_t3;
    int64_t _285_t1;
    int64_t _285_$retval;
    _285_t0 = _287_add_fields;
    _285_t2 = 2;
    _285_t4 = 450;
    _285_t5 = 50;
    _285_t3 = (struct2) {_285_t4, _285_t5};
    $lines[$line_idx++] = "tests/integration/default/default-keyword.orng:8:16:\n    add_fields(2)\n              ^";
    _285_t1 = _285_t0(_285_t2, _285_t3);
    $line_idx--;
    _285_$retval = _285_t1;
    return _285_$retval;
}

int64_t _287_add_fields(int64_t _287_scale,struct2 _287_mt) {
    int64_t _287_t0;
    int64_t _287_$retval;
    _287_t0 = $add_int64_t(_287_mt._0, _287_mt._1, "tests/integration/default/default-keyword.orng:14:12:\n    (mt.x + mt.y) / scale\n          ^");
    _287_$retval = $div_int64_t(_287_t0, _287_scale, "tests/integration/default/default-keyword.orng:14:20:\n    (mt.x + mt.y) / scale\n                  ^");
    return _287_$retval;
}

int main(void) {
  printf("%ld",_285_main());
  return 0;
}
