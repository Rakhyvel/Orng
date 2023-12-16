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
int64_t _443_main(void);
int64_t _445_add_fields(int64_t _445_scale,struct2 _445_mt);

/* Function definitions */
int64_t _443_main(void){
    function0 _443_t0;
    int64_t _443_t2;
    int64_t _443_t4;
    int64_t _443_t5;
    struct2 _443_t3;
    int64_t _443_t1;
    int64_t _443_$retval;
    _443_t0 = _445_add_fields;
    _443_t2 = 2;
    _443_t4 = 450;
    _443_t5 = 50;
    _443_t3 = (struct2) {_443_t4, _443_t5};
    $lines[$line_idx++] = "tests/integration/default/default-keyword.orng:8:16:\n    add_fields(2)\n              ^";
    _443_t1 = _443_t0(_443_t2, _443_t3);
    $line_idx--;
    _443_$retval = _443_t1;
    return _443_$retval;
}

int64_t _445_add_fields(int64_t _445_scale,struct2 _445_mt){
    int64_t _445_t0;
    int64_t _445_$retval;
    _445_t0 = $add_int64_t(_445_mt._0, _445_mt._1, "tests/integration/default/default-keyword.orng:14:12:\n    (mt.x + mt.y) / scale\n          ^");
    _445_$retval = $div_int64_t(_445_t0, _445_scale, "tests/integration/default/default-keyword.orng:14:20:\n    (mt.x + mt.y) / scale\n                  ^");
    return _445_$retval;
}

int main(void) {
  printf("%ld",_443_main());
  return 0;
}
