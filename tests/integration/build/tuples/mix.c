/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct1;
struct struct2;
struct struct3;

/* Typedefs */
struct struct1 {
    int64_t _0;
    int64_t _1;
};

struct struct2 {
    int64_t _0;
    int64_t _1;
    int64_t _2;
    int64_t _3;
};

typedef struct struct2(*function0)(int64_t, int64_t);

struct struct3 {
    int64_t _0;
    int64_t* _1;
};

/* Function forward definitions */
int64_t _1547_main(void);
struct struct2 _1549_get_array(int64_t _1549_a, int64_t _1549_b);

/* Function definitions */
int64_t _1547_main(void){
    function0 _1547_t0;
    int64_t _1547_t2;
    int64_t _1547_t3;
    int64_t _1548_z;
    int64_t* _1547_t7;
    struct struct3 _1548_y;
    int64_t _1547_$retval;
    _1547_t0 = _1549_get_array;
    _1547_t2 = 15;
    _1547_t3 = 16;
    $lines[$line_idx++] = "tests/integration/tuples/mix.orng:3:31:\n    let x: [4]Int = get_array(15, 16)\n                             ^";
    (void) _1547_t0(_1547_t2, _1547_t3);
    $line_idx--;
    _1548_z = 64;
    _1547_t7 = &_1548_z;
    _1548_y = (struct struct3) {_1548_z, _1547_t7};
    _1547_$retval = _1548_y._0;
    return _1547_$retval;
}

struct struct2 _1549_get_array(int64_t _1549_a, int64_t _1549_b){
    struct struct2 _1549_$retval;
    _1549_$retval = (struct struct2) {_1549_a, _1549_b, _1549_a, _1549_b};
    return _1549_$retval;
}

int main(void) {
  printf("%ld",_1547_main());
  return 0;
}
