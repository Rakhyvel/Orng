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
int64_t _21_main(void);
struct2 _23_get_array(int64_t _23_a,int64_t _23_b);

/* Function definitions */
int64_t _21_main(void) {
    function0 _21_t0;
    int64_t _21_t2;
    int64_t _21_t3;
    struct2 _21_t1;
    int64_t _22_z;
    int64_t* _21_t7;
    struct3 _22_y;
    int64_t _21_$retval;
    _21_t0 = _23_get_array;
    _21_t2 = 15;
    _21_t3 = 16;
    $lines[$line_idx++] = "tests/integration/tuples/mix.orng:3:31:\n    let x: [4]Int = get_array(15, 16)\n                             ^";
    _21_t1 = _21_t0(_21_t2, _21_t3);
    $line_idx--;
    (void)_21_t1;
    _22_z = 64;
    _21_t7 = &_22_z;
    _22_y = (struct3) {_22_z, _21_t7};
    _21_$retval = _22_y._0;
    return _21_$retval;
}

struct2 _23_get_array(int64_t _23_a,int64_t _23_b) {
    struct2 _23_$retval;
    _23_$retval = (struct2) {_23_a, _23_b, _23_a, _23_b};
    return _23_$retval;
}

int main(void) {
  printf("%ld",_21_main());
  return 0;
}
