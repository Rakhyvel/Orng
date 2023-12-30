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
int64_t _524_main(void);
int64_t _526_add_fields(int64_t _526_scale, struct2 _526_mt);

/* Function definitions */
int64_t _524_main(void){
    function0 _524_t0;
    int64_t _524_t2;
    int64_t _524_t4;
    int64_t _524_t5;
    struct2 _524_t3;
    int64_t _524_t1;
    int64_t _524_$retval;
    _524_t0 = _526_add_fields;
    _524_t2 = 2;
    _524_t4 = 450;
    _524_t5 = 50;
    _524_t3 = (struct2) {_524_t4, _524_t5};
    $lines[$line_idx++] = "tests/integration/default/default-keyword.orng:8:16:\n    add_fields(2)\n              ^";
    _524_t1 = _524_t0(_524_t2, _524_t3);
    $line_idx--;
    _524_$retval = _524_t1;
    return _524_$retval;
}

int64_t _526_add_fields(int64_t _526_scale, struct2 _526_mt){
    int64_t _526_t0;
    int64_t _526_$retval;
    _526_t0 = $add_int64_t(_526_mt._0, _526_mt._1, "tests/integration/default/default-keyword.orng:14:12:\n    (mt.x + mt.y) / scale\n          ^");
    _526_$retval = $div_int64_t(_526_t0, _526_scale, "tests/integration/default/default-keyword.orng:14:20:\n    (mt.x + mt.y) / scale\n                  ^");
    return _526_$retval;
}

int main(void) {
  printf("%ld",_524_main());
  return 0;
}
