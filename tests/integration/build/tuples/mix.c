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
int64_t _1496_main(void);
struct2 _1502_get_array(int64_t _1502_a,int64_t _1502_b);

/* Function definitions */
int64_t _1496_main(void){
    function0 _1496_t0;
    int64_t _1496_t2;
    int64_t _1496_t3;
    struct2 _1496_t1;
    int64_t _1497_z;
    int64_t* _1496_t7;
    struct3 _1497_y;
    int64_t _1496_$retval;
    _1496_t0 = _1502_get_array;
    _1496_t2 = 15;
    _1496_t3 = 16;
    $lines[$line_idx++] = "tests/integration/tuples/mix.orng:3:31:\n    let x: [4]Int = get_array(15, 16)\n                             ^";
    _1496_t1 = _1496_t0(_1496_t2, _1496_t3);
    $line_idx--;
    (void)_1496_t1;
    _1497_z = 64;
    _1496_t7 = &_1497_z;
    _1497_y = (struct3) {_1497_z, _1496_t7};
    _1496_$retval = _1497_y._0;
    return _1496_$retval;
}

struct2 _1502_get_array(int64_t _1502_a,int64_t _1502_b){
    struct2 _1502_$retval;
    _1502_$retval = (struct2) {_1502_a, _1502_b, _1502_a, _1502_b};
    return _1502_$retval;
}

int main(void) {
  printf("%ld",_1496_main());
  return 0;
}
