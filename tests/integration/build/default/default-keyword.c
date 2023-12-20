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
int64_t _515_main(void);
int64_t _517_add_fields(int64_t _517_scale,struct2 _517_mt);

/* Function definitions */
int64_t _515_main(void){
    function0 _515_t0;
    int64_t _515_t2;
    int64_t _515_t4;
    int64_t _515_t5;
    struct2 _515_t3;
    int64_t _515_t1;
    int64_t _515_$retval;
    _515_t0 = _517_add_fields;
    _515_t2 = 2;
    _515_t4 = 450;
    _515_t5 = 50;
    _515_t3 = (struct2) {_515_t4, _515_t5};
    $lines[$line_idx++] = "tests/integration/default/default-keyword.orng:8:16:\n    add_fields(2)\n              ^";
    _515_t1 = _515_t0(_515_t2, _515_t3);
    $line_idx--;
    _515_$retval = _515_t1;
    return _515_$retval;
}

int64_t _517_add_fields(int64_t _517_scale,struct2 _517_mt){
    int64_t _517_t0;
    int64_t _517_$retval;
    _517_t0 = $add_int64_t(_517_mt._0, _517_mt._1, "tests/integration/default/default-keyword.orng:14:12:\n    (mt.x + mt.y) / scale\n          ^");
    _517_$retval = $div_int64_t(_517_t0, _517_scale, "tests/integration/default/default-keyword.orng:14:20:\n    (mt.x + mt.y) / scale\n                  ^");
    return _517_$retval;
}

int main(void) {
  printf("%ld",_515_main());
  return 0;
}
