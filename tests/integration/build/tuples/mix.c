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
int64_t _1740_main(void);
struct2 _1746_get_array(int64_t _1746_a,int64_t _1746_b);

/* Function definitions */
int64_t _1740_main(void){
    function0 _1740_t0;
    int64_t _1740_t2;
    int64_t _1740_t3;
    struct2 _1740_t1;
    int64_t _1741_z;
    int64_t* _1740_t7;
    struct3 _1741_y;
    int64_t _1740_$retval;
    _1740_t0 = _1746_get_array;
    _1740_t2 = 15;
    _1740_t3 = 16;
    $lines[$line_idx++] = "tests/integration/tuples/mix.orng:3:31:\n    let x: [4]Int = get_array(15, 16)\n                             ^";
    _1740_t1 = _1740_t0(_1740_t2, _1740_t3);
    $line_idx--;
    (void)_1740_t1;
    _1741_z = 64;
    _1740_t7 = &_1741_z;
    _1741_y = (struct3) {_1741_z, _1740_t7};
    _1740_$retval = _1741_y._0;
    return _1740_$retval;
}

struct2 _1746_get_array(int64_t _1746_a,int64_t _1746_b){
    struct2 _1746_$retval;
    _1746_$retval = (struct2) {_1746_a, _1746_b, _1746_a, _1746_b};
    return _1746_$retval;
}

int main(void) {
  printf("%ld",_1740_main());
  return 0;
}
