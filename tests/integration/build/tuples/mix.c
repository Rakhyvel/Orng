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
int64_t _1516_main(void);
struct2 _1523_get_array(int64_t _1523_a,int64_t _1523_b);

/* Function definitions */
int64_t _1516_main(void) {
    function0 _1516_t0;
    int64_t _1516_t2;
    int64_t _1516_t3;
    struct2 _1516_t1;
    int64_t _1517_z;
    int64_t* _1516_t7;
    struct3 _1517_y;
    int64_t _1516_$retval;
    _1516_t0 = _1523_get_array;
    _1516_t2 = 15;
    _1516_t3 = 16;
    $lines[$line_idx++] = "tests/integration/tuples/mix.orng:3:31:\n    let x: [4]Int = get_array(15, 16)\n                             ^";
    _1516_t1 = _1516_t0(_1516_t2, _1516_t3);
    $line_idx--;
    (void)_1516_t1;
    _1517_z = 64;
    _1516_t7 = &_1517_z;
    _1517_y = (struct3) {_1517_z, _1516_t7};
    _1516_$retval = _1517_y._0;
    return _1516_$retval;
}

struct2 _1523_get_array(int64_t _1523_a,int64_t _1523_b) {
    struct2 _1523_$retval;
    _1523_$retval = (struct2) {_1523_a, _1523_b, _1523_a, _1523_b};
    return _1523_$retval;
}

int main(void) {
  printf("%ld",_1516_main());
  return 0;
}
