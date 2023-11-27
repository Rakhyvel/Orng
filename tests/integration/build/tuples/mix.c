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
int64_t _1085_main(void);
struct2 _1087_get_array(int64_t _1087_a,int64_t _1087_b);

/* Function definitions */
int64_t _1085_main(void) {
    function0 _1085_t0;
    int64_t _1085_t2;
    int64_t _1085_t3;
    struct2 _1085_t1;
    int64_t _1086_z;
    int64_t* _1085_t7;
    struct3 _1086_y;
    int64_t _1085_$retval;
    _1085_t0 = _1087_get_array;
    _1085_t2 = 15;
    _1085_t3 = 16;
    $lines[$line_idx++] = "tests/integration/tuples/mix.orng:3:31:\n    let x: [4]Int = get_array(15, 16)\n                             ^";
    _1085_t1 = _1085_t0(_1085_t2, _1085_t3);
    $line_idx--;
    (void)_1085_t1;
    _1086_z = 64;
    _1085_t7 = &_1086_z;
    _1086_y = (struct3) {_1086_z, _1085_t7};
    _1085_$retval = _1086_y._0;
    return _1085_$retval;
}

struct2 _1087_get_array(int64_t _1087_a,int64_t _1087_b) {
    struct2 _1087_$retval;
    _1087_$retval = (struct2) {_1087_a, _1087_b, _1087_a, _1087_b};
    return _1087_$retval;
}

int main(void) {
  printf("%ld",_1085_main());
  return 0;
}
