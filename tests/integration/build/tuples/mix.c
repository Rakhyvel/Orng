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
} struct1;

typedef struct {
    int64_t _0;
    int64_t _1;
    int64_t _2;
    int64_t _3;
} struct2;

typedef struct2(*function0)(int64_t, int64_t);

typedef struct {
    int64_t _0;
    int64_t* _1;
} struct3;

/* Function forward definitions */
int64_t _1147_main(void);
struct2 _1149_get_array(int64_t _1149_a,int64_t _1149_b);

/* Function definitions */
int64_t _1147_main(void) {
    function0 _1147_t0;
    int64_t _1147_t2;
    int64_t _1147_t3;
    struct2 _1147_t1;
    int64_t _1148_z;
    int64_t* _1147_t7;
    struct3 _1148_y;
    int64_t _1147_$retval;
    _1147_t0 = _1149_get_array;
    _1147_t2 = 15;
    _1147_t3 = 16;
    $lines[$line_idx++] = "tests/integration/tuples/mix.orng:3:31:\n    let x: [4]Int = get_array(15, 16)\n                             ^";
    _1147_t1 = _1147_t0(_1147_t2, _1147_t3);
    $line_idx--;
    (void)_1147_t1;
    _1148_z = 64;
    _1147_t7 = &_1148_z;
    _1148_y = (struct3) {_1148_z, _1147_t7};
    _1147_$retval = _1148_y._0;
    return _1147_$retval;
}

struct2 _1149_get_array(int64_t _1149_a,int64_t _1149_b) {
    struct2 _1149_$retval;
    _1149_$retval = (struct2) {_1149_a, _1149_b, _1149_a, _1149_b};
    return _1149_$retval;
}

int main(void) {
  printf("%ld",_1147_main());
  return 0;
}
