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
int64_t _606_main(void);
int64_t _608_add_fields(int64_t _608_scale,struct2 _608_mt);

/* Function definitions */
int64_t _606_main(void){
    function0 _606_t0;
    int64_t _606_t2;
    int64_t _606_t4;
    int64_t _606_t5;
    struct2 _606_t3;
    int64_t _606_t1;
    int64_t _606_$retval;
    _606_t0 = _608_add_fields;
    _606_t2 = 2;
    _606_t4 = 450;
    _606_t5 = 50;
    _606_t3 = (struct2) {_606_t4, _606_t5};
    $lines[$line_idx++] = "tests/integration/default/default-keyword.orng:8:16:\n    add_fields(2)\n              ^";
    _606_t1 = _606_t0(_606_t2, _606_t3);
    $line_idx--;
    _606_$retval = _606_t1;
    return _606_$retval;
}

int64_t _608_add_fields(int64_t _608_scale,struct2 _608_mt){
    int64_t _608_t0;
    int64_t _608_$retval;
    _608_t0 = $add_int64_t(_608_mt._0, _608_mt._1, "tests/integration/default/default-keyword.orng:14:12:\n    (mt.x + mt.y) / scale\n          ^");
    _608_$retval = $div_int64_t(_608_t0, _608_scale, "tests/integration/default/default-keyword.orng:14:20:\n    (mt.x + mt.y) / scale\n                  ^");
    return _608_$retval;
}

int main(void) {
  printf("%ld",_606_main());
  return 0;
}
