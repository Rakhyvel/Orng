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
int64_t _1641_main(void);
struct2 _1647_get_array(int64_t _1647_a,int64_t _1647_b);

/* Function definitions */
int64_t _1641_main(void){
    function0 _1641_t0;
    int64_t _1641_t2;
    int64_t _1641_t3;
    struct2 _1641_t1;
    int64_t _1642_z;
    int64_t* _1641_t7;
    struct3 _1642_y;
    int64_t _1641_$retval;
    _1641_t0 = _1647_get_array;
    _1641_t2 = 15;
    _1641_t3 = 16;
    $lines[$line_idx++] = "tests/integration/tuples/mix.orng:3:31:\n    let x: [4]Int = get_array(15, 16)\n                             ^";
    _1641_t1 = _1641_t0(_1641_t2, _1641_t3);
    $line_idx--;
    (void)_1641_t1;
    _1642_z = 64;
    _1641_t7 = &_1642_z;
    _1642_y = (struct3) {_1642_z, _1641_t7};
    _1641_$retval = _1642_y._0;
    return _1641_$retval;
}

struct2 _1647_get_array(int64_t _1647_a,int64_t _1647_b){
    struct2 _1647_$retval;
    _1647_$retval = (struct2) {_1647_a, _1647_b, _1647_a, _1647_b};
    return _1647_$retval;
}

int main(void) {
  printf("%ld",_1641_main());
  return 0;
}
