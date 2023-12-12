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
int64_t _1174_main(void);
struct2 _1176_get_array(int64_t _1176_a,int64_t _1176_b);

/* Function definitions */
int64_t _1174_main(void) {
    function0 _1174_t0;
    int64_t _1174_t2;
    int64_t _1174_t3;
    struct2 _1174_t1;
    int64_t _1175_z;
    int64_t* _1174_t7;
    struct3 _1175_y;
    int64_t _1174_$retval;
    _1174_t0 = _1176_get_array;
    _1174_t2 = 15;
    _1174_t3 = 16;
    $lines[$line_idx++] = "tests/integration/tuples/mix.orng:3:31:\n    let x: [4]Int = get_array(15, 16)\n                             ^";
    _1174_t1 = _1174_t0(_1174_t2, _1174_t3);
    $line_idx--;
    (void)_1174_t1;
    _1175_z = 64;
    _1174_t7 = &_1175_z;
    _1175_y = (struct3) {_1175_z, _1174_t7};
    _1174_$retval = _1175_y._0;
    return _1174_$retval;
}

struct2 _1176_get_array(int64_t _1176_a,int64_t _1176_b) {
    struct2 _1176_$retval;
    _1176_$retval = (struct2) {_1176_a, _1176_b, _1176_a, _1176_b};
    return _1176_$retval;
}

int main(void) {
  printf("%ld",_1174_main());
  return 0;
}
