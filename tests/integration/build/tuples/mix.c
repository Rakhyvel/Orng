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
int64_t _1123_main(void);
struct2 _1125_get_array(int64_t _1125_a,int64_t _1125_b);

/* Function definitions */
int64_t _1123_main(void) {
    function0 _1123_t0;
    int64_t _1123_t2;
    int64_t _1123_t3;
    struct2 _1123_t1;
    int64_t _1124_z;
    int64_t* _1123_t7;
    struct3 _1124_y;
    int64_t _1123_$retval;
    _1123_t0 = _1125_get_array;
    _1123_t2 = 15;
    _1123_t3 = 16;
    $lines[$line_idx++] = "tests/integration/tuples/mix.orng:3:31:\n    let x: [4]Int = get_array(15, 16)\n                             ^";
    _1123_t1 = _1123_t0(_1123_t2, _1123_t3);
    $line_idx--;
    (void)_1123_t1;
    _1124_z = 64;
    _1123_t7 = &_1124_z;
    _1124_y = (struct3) {_1124_z, _1123_t7};
    _1123_$retval = _1124_y._0;
    return _1123_$retval;
}

struct2 _1125_get_array(int64_t _1125_a,int64_t _1125_b) {
    struct2 _1125_$retval;
    _1125_$retval = (struct2) {_1125_a, _1125_b, _1125_a, _1125_b};
    return _1125_$retval;
}

int main(void) {
  printf("%ld",_1123_main());
  return 0;
}
