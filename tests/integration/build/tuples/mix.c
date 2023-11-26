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
int64_t _1054_main(void);
struct2 _1056_get_array(int64_t _1056_a,int64_t _1056_b);

/* Function definitions */
int64_t _1054_main(void) {
    function0 _1054_t0;
    int64_t _1054_t2;
    int64_t _1054_t3;
    struct2 _1054_t1;
    int64_t _1055_z;
    int64_t* _1054_t7;
    struct3 _1055_y;
    int64_t _1054_$retval;
    _1054_t0 = _1056_get_array;
    _1054_t2 = 15;
    _1054_t3 = 16;
    $lines[$line_idx++] = "tests/integration/tuples/mix.orng:3:31:\n    let x: [4]Int = get_array(15, 16)\n                             ^";
    _1054_t1 = _1054_t0(_1054_t2, _1054_t3);
    $line_idx--;
    (void)_1054_t1;
    _1055_z = 64;
    _1054_t7 = &_1055_z;
    _1055_y = (struct3) {_1055_z, _1054_t7};
    _1054_$retval = _1055_y._0;
    return _1054_$retval;
}

struct2 _1056_get_array(int64_t _1056_a,int64_t _1056_b) {
    struct2 _1056_$retval;
    _1056_$retval = (struct2) {_1056_a, _1056_b, _1056_a, _1056_b};
    return _1056_$retval;
}

int main(void) {
  printf("%ld",_1054_main());
  return 0;
}
