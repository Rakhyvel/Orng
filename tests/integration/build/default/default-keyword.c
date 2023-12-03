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
int64_t _277_main(void);
int64_t _279_add_fields(int64_t _279_scale,struct2 _279_mt);

/* Function definitions */
int64_t _277_main(void) {
    function0 _277_t0;
    int64_t _277_t2;
    int64_t _277_t4;
    int64_t _277_t5;
    struct2 _277_t3;
    int64_t _277_t1;
    int64_t _277_$retval;
    _277_t0 = _279_add_fields;
    _277_t2 = 2;
    _277_t4 = 450;
    _277_t5 = 50;
    _277_t3 = (struct2) {_277_t4, _277_t5};
    $lines[$line_idx++] = "tests/integration/default/default-keyword.orng:8:16:\n    add_fields(2)\n              ^";
    _277_t1 = _277_t0(_277_t2, _277_t3);
    $line_idx--;
    _277_$retval = _277_t1;
    return _277_$retval;
}

int64_t _279_add_fields(int64_t _279_scale,struct2 _279_mt) {
    int64_t _279_t0;
    int64_t _279_$retval;
    _279_t0 = $add_int64_t(_279_mt._0, _279_mt._1, "tests/integration/default/default-keyword.orng:14:12:\n    (mt.x + mt.y) / scale\n          ^");
    _279_$retval = $div_int64_t(_279_t0, _279_scale, "tests/integration/default/default-keyword.orng:14:20:\n    (mt.x + mt.y) / scale\n                  ^");
    return _279_$retval;
}

int main(void) {
  printf("%ld",_277_main());
  return 0;
}
