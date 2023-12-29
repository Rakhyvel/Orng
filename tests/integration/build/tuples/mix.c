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
int64_t _1481_main(void);
struct2 _1483_get_array(int64_t _1483_a, int64_t _1483_b);

/* Function definitions */
int64_t _1481_main(void){
    function0 _1481_t0;
    int64_t _1481_t2;
    int64_t _1481_t3;
    struct2 _1481_t1;
    int64_t _1482_z;
    int64_t* _1481_t7;
    struct3 _1482_y;
    int64_t _1481_$retval;
    _1481_t0 = _1483_get_array;
    _1481_t2 = 15;
    _1481_t3 = 16;
    $lines[$line_idx++] = "tests/integration/tuples/mix.orng:3:31:\n    let x: [4]Int = get_array(15, 16)\n                             ^";
    _1481_t1 = _1481_t0(_1481_t2, _1481_t3);
    $line_idx--;
    (void)_1481_t1;
    _1482_z = 64;
    _1481_t7 = &_1482_z;
    _1482_y = (struct3) {_1482_z, _1481_t7};
    _1481_$retval = _1482_y._0;
    return _1481_$retval;
}

struct2 _1483_get_array(int64_t _1483_a, int64_t _1483_b){
    struct2 _1483_$retval;
    _1483_$retval = (struct2) {_1483_a, _1483_b, _1483_a, _1483_b};
    return _1483_$retval;
}

int main(void) {
  printf("%ld",_1481_main());
  return 0;
}
