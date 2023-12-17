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
int64_t _599_main(void);
int64_t _601_add_fields(int64_t _601_scale,struct2 _601_mt);

/* Function definitions */
int64_t _599_main(void){
    function0 _599_t0;
    int64_t _599_t2;
    int64_t _599_t4;
    int64_t _599_t5;
    struct2 _599_t3;
    int64_t _599_t1;
    int64_t _599_$retval;
    _599_t0 = _601_add_fields;
    _599_t2 = 2;
    _599_t4 = 450;
    _599_t5 = 50;
    _599_t3 = (struct2) {_599_t4, _599_t5};
    $lines[$line_idx++] = "tests/integration/default/default-keyword.orng:8:16:\n    add_fields(2)\n              ^";
    _599_t1 = _599_t0(_599_t2, _599_t3);
    $line_idx--;
    _599_$retval = _599_t1;
    return _599_$retval;
}

int64_t _601_add_fields(int64_t _601_scale,struct2 _601_mt){
    int64_t _601_t0;
    int64_t _601_$retval;
    _601_t0 = $add_int64_t(_601_mt._0, _601_mt._1, "tests/integration/default/default-keyword.orng:14:12:\n    (mt.x + mt.y) / scale\n          ^");
    _601_$retval = $div_int64_t(_601_t0, _601_scale, "tests/integration/default/default-keyword.orng:14:20:\n    (mt.x + mt.y) / scale\n                  ^");
    return _601_$retval;
}

int main(void) {
  printf("%ld",_599_main());
  return 0;
}
