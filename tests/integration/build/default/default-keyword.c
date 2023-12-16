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
int64_t _454_main(void);
int64_t _456_add_fields(int64_t _456_scale,struct2 _456_mt);

/* Function definitions */
int64_t _454_main(void){
    function0 _454_t0;
    int64_t _454_t2;
    int64_t _454_t4;
    int64_t _454_t5;
    struct2 _454_t3;
    int64_t _454_t1;
    int64_t _454_$retval;
    _454_t0 = _456_add_fields;
    _454_t2 = 2;
    _454_t4 = 450;
    _454_t5 = 50;
    _454_t3 = (struct2) {_454_t4, _454_t5};
    $lines[$line_idx++] = "tests/integration/default/default-keyword.orng:8:16:\n    add_fields(2)\n              ^";
    _454_t1 = _454_t0(_454_t2, _454_t3);
    $line_idx--;
    _454_$retval = _454_t1;
    return _454_$retval;
}

int64_t _456_add_fields(int64_t _456_scale,struct2 _456_mt){
    int64_t _456_t0;
    int64_t _456_$retval;
    _456_t0 = $add_int64_t(_456_mt._0, _456_mt._1, "tests/integration/default/default-keyword.orng:14:12:\n    (mt.x + mt.y) / scale\n          ^");
    _456_$retval = $div_int64_t(_456_t0, _456_scale, "tests/integration/default/default-keyword.orng:14:20:\n    (mt.x + mt.y) / scale\n                  ^");
    return _456_$retval;
}

int main(void) {
  printf("%ld",_454_main());
  return 0;
}
