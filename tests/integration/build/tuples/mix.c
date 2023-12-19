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
int64_t _1747_main(void);
struct2 _1753_get_array(int64_t _1753_a,int64_t _1753_b);

/* Function definitions */
int64_t _1747_main(void){
    function0 _1747_t0;
    int64_t _1747_t2;
    int64_t _1747_t3;
    struct2 _1747_t1;
    int64_t _1748_z;
    int64_t* _1747_t7;
    struct3 _1748_y;
    int64_t _1747_$retval;
    _1747_t0 = _1753_get_array;
    _1747_t2 = 15;
    _1747_t3 = 16;
    $lines[$line_idx++] = "tests/integration/tuples/mix.orng:3:31:\n    let x: [4]Int = get_array(15, 16)\n                             ^";
    _1747_t1 = _1747_t0(_1747_t2, _1747_t3);
    $line_idx--;
    (void)_1747_t1;
    _1748_z = 64;
    _1747_t7 = &_1748_z;
    _1748_y = (struct3) {_1748_z, _1747_t7};
    _1747_$retval = _1748_y._0;
    return _1747_$retval;
}

struct2 _1753_get_array(int64_t _1753_a,int64_t _1753_b){
    struct2 _1753_$retval;
    _1753_$retval = (struct2) {_1753_a, _1753_b, _1753_a, _1753_b};
    return _1753_$retval;
}

int main(void) {
  printf("%ld",_1747_main());
  return 0;
}
