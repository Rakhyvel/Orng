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
int64_t _1506_main(void);
struct2 _1508_get_array(int64_t _1508_a, int64_t _1508_b);

/* Function definitions */
int64_t _1506_main(void){
    function0 _1506_t0;
    int64_t _1506_t2;
    int64_t _1506_t3;
    struct2 _1506_t1;
    int64_t _1507_z;
    int64_t* _1506_t7;
    struct3 _1507_y;
    int64_t _1506_$retval;
    _1506_t0 = _1508_get_array;
    _1506_t2 = 15;
    _1506_t3 = 16;
    $lines[$line_idx++] = "tests/integration/tuples/mix.orng:3:31:\n    let x: [4]Int = get_array(15, 16)\n                             ^";
    _1506_t1 = _1506_t0(_1506_t2, _1506_t3);
    $line_idx--;
    (void)_1506_t1;
    _1507_z = 64;
    _1506_t7 = &_1507_z;
    _1507_y = (struct3) {_1507_z, _1506_t7};
    _1506_$retval = _1507_y._0;
    return _1506_$retval;
}

struct2 _1508_get_array(int64_t _1508_a, int64_t _1508_b){
    struct2 _1508_$retval;
    _1508_$retval = (struct2) {_1508_a, _1508_b, _1508_a, _1508_b};
    return _1508_$retval;
}

int main(void) {
  printf("%ld",_1506_main());
  return 0;
}
