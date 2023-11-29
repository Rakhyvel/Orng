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
int64_t _1203_main(void);
struct2 _1206_get_array(int64_t _1206_a,int64_t _1206_b);

/* Function definitions */
int64_t _1203_main(void) {
    function0 _1203_t0;
    int64_t _1203_t2;
    int64_t _1203_t3;
    struct2 _1203_t1;
    int64_t _1204_z;
    int64_t* _1203_t7;
    struct3 _1204_y;
    int64_t _1203_$retval;
    _1203_t0 = _1206_get_array;
    _1203_t2 = 15;
    _1203_t3 = 16;
    $lines[$line_idx++] = "tests/integration/tuples/mix.orng:3:31:\n    let x: [4]Int = get_array(15, 16)\n                             ^";
    _1203_t1 = _1203_t0(_1203_t2, _1203_t3);
    $line_idx--;
    (void)_1203_t1;
    _1204_z = 64;
    _1203_t7 = &_1204_z;
    _1204_y = (struct3) {_1204_z, _1203_t7};
    _1203_$retval = _1204_y._0;
    return _1203_$retval;
}

struct2 _1206_get_array(int64_t _1206_a,int64_t _1206_b) {
    struct2 _1206_$retval;
    _1206_$retval = (struct2) {_1206_a, _1206_b, _1206_a, _1206_b};
    return _1206_$retval;
}

int main(void) {
  printf("%ld",_1203_main());
  return 0;
}
