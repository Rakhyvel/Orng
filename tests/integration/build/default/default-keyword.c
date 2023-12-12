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
int64_t _304_main(void);
int64_t _306_add_fields(int64_t _306_scale,struct2 _306_mt);

/* Function definitions */
int64_t _304_main(void) {
    function0 _304_t0;
    int64_t _304_t2;
    int64_t _304_t4;
    int64_t _304_t5;
    struct2 _304_t3;
    int64_t _304_t1;
    int64_t _304_$retval;
    _304_t0 = _306_add_fields;
    _304_t2 = 2;
    _304_t4 = 450;
    _304_t5 = 50;
    _304_t3 = (struct2) {_304_t4, _304_t5};
    $lines[$line_idx++] = "tests/integration/default/default-keyword.orng:8:16:\n    add_fields(2)\n              ^";
    _304_t1 = _304_t0(_304_t2, _304_t3);
    $line_idx--;
    _304_$retval = _304_t1;
    return _304_$retval;
}

int64_t _306_add_fields(int64_t _306_scale,struct2 _306_mt) {
    int64_t _306_t0;
    int64_t _306_$retval;
    _306_t0 = $add_int64_t(_306_mt._0, _306_mt._1, "tests/integration/default/default-keyword.orng:14:12:\n    (mt.x + mt.y) / scale\n          ^");
    _306_$retval = $div_int64_t(_306_t0, _306_scale, "tests/integration/default/default-keyword.orng:14:20:\n    (mt.x + mt.y) / scale\n                  ^");
    return _306_$retval;
}

int main(void) {
  printf("%ld",_304_main());
  return 0;
}
