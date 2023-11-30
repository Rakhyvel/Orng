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
int64_t _41_main(void);
struct2 _48_get_array(int64_t _48_a,int64_t _48_b);

/* Function definitions */
int64_t _41_main(void) {
    function0 _41_t0;
    int64_t _41_t2;
    int64_t _41_t3;
    struct2 _41_t1;
    int64_t _42_z;
    int64_t* _41_t7;
    struct3 _42_y;
    int64_t _41_$retval;
    _41_t0 = _48_get_array;
    _41_t2 = 15;
    _41_t3 = 16;
    $lines[$line_idx++] = "tests/integration/tuples/mix.orng:3:31:\n    let x: [4]Int = get_array(15, 16)\n                             ^";
    _41_t1 = _41_t0(_41_t2, _41_t3);
    $line_idx--;
    (void)_41_t1;
    _42_z = 64;
    _41_t7 = &_42_z;
    _42_y = (struct3) {_42_z, _41_t7};
    _41_$retval = _42_y._0;
    return _41_$retval;
}

struct2 _48_get_array(int64_t _48_a,int64_t _48_b) {
    struct2 _48_$retval;
    _48_$retval = (struct2) {_48_a, _48_b, _48_a, _48_b};
    return _48_$retval;
}

int main(void) {
  printf("%ld",_41_main());
  return 0;
}
