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
int64_t _1730_main(void);
struct2 _1736_get_array(int64_t _1736_a,int64_t _1736_b);

/* Function definitions */
int64_t _1730_main(void){
    function0 _1730_t0;
    int64_t _1730_t2;
    int64_t _1730_t3;
    struct2 _1730_t1;
    int64_t _1731_z;
    int64_t* _1730_t7;
    struct3 _1731_y;
    int64_t _1730_$retval;
    _1730_t0 = _1736_get_array;
    _1730_t2 = 15;
    _1730_t3 = 16;
    $lines[$line_idx++] = "tests/integration/tuples/mix.orng:3:31:\n    let x: [4]Int = get_array(15, 16)\n                             ^";
    _1730_t1 = _1730_t0(_1730_t2, _1730_t3);
    $line_idx--;
    (void)_1730_t1;
    _1731_z = 64;
    _1730_t7 = &_1731_z;
    _1731_y = (struct3) {_1731_z, _1730_t7};
    _1730_$retval = _1731_y._0;
    return _1730_$retval;
}

struct2 _1736_get_array(int64_t _1736_a,int64_t _1736_b){
    struct2 _1736_$retval;
    _1736_$retval = (struct2) {_1736_a, _1736_b, _1736_a, _1736_b};
    return _1736_$retval;
}

int main(void) {
  printf("%ld",_1730_main());
  return 0;
}
