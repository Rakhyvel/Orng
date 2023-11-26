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
int64_t _19_main(void);
struct2 _21_get_array(int64_t _21_a,int64_t _21_b);

/* Function definitions */
int64_t _19_main(void) {
    function0 _19_t0;
    int64_t _19_t2;
    int64_t _19_t3;
    struct2 _19_t1;
    int64_t _20_z;
    int64_t* _19_t7;
    struct3 _20_y;
    int64_t _19_$retval;
    _19_t0 = _21_get_array;
    _19_t2 = 15;
    _19_t3 = 16;
    $lines[$line_idx++] = "tests/integration/tuples/mix.orng:3:31:\n    let x: [4]Int = get_array(15, 16)\n                             ^";
    _19_t1 = _19_t0(_19_t2, _19_t3);
    $line_idx--;
    (void)_19_t1;
    _20_z = 64;
    _19_t7 = &_20_z;
    _20_y = (struct3) {_20_z, _19_t7};
    _19_$retval = _20_y._0;
    return _19_$retval;
}

struct2 _21_get_array(int64_t _21_a,int64_t _21_b) {
    struct2 _21_$retval;
    _21_$retval = (struct2) {_21_a, _21_b, _21_a, _21_b};
    return _21_$retval;
}

int main(void) {
  printf("%ld",_19_main());
  return 0;
}
