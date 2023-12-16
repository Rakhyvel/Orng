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
int64_t _435_main(void);
int64_t _437_add_fields(int64_t _437_scale,struct2 _437_mt);

/* Function definitions */
int64_t _435_main(void) {
    function0 _435_t0;
    int64_t _435_t2;
    int64_t _435_t4;
    int64_t _435_t5;
    struct2 _435_t3;
    int64_t _435_t1;
    int64_t _435_$retval;
    _435_t0 = _437_add_fields;
    _435_t2 = 2;
    _435_t4 = 450;
    _435_t5 = 50;
    _435_t3 = (struct2) {_435_t4, _435_t5};
    $lines[$line_idx++] = "tests/integration/default/default-keyword.orng:8:16:\n    add_fields(2)\n              ^";
    _435_t1 = _435_t0(_435_t2, _435_t3);
    $line_idx--;
    _435_$retval = _435_t1;
    return _435_$retval;
}

int64_t _437_add_fields(int64_t _437_scale,struct2 _437_mt) {
    int64_t _437_t0;
    int64_t _437_$retval;
    _437_t0 = $add_int64_t(_437_mt._0, _437_mt._1, "tests/integration/default/default-keyword.orng:14:12:\n    (mt.x + mt.y) / scale\n          ^");
    _437_$retval = $div_int64_t(_437_t0, _437_scale, "tests/integration/default/default-keyword.orng:14:20:\n    (mt.x + mt.y) / scale\n                  ^");
    return _437_$retval;
}

int main(void) {
  printf("%ld",_435_main());
  return 0;
}
