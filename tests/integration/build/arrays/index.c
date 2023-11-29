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

/* Function forward definitions */
int64_t _96_main(void);
struct2 _99_get_array(int64_t _99_a,int64_t _99_b);

/* Function definitions */
int64_t _96_main(void) {
    function0 _96_t0;
    int64_t _96_t2;
    int64_t _96_t3;
    struct2 _96_t1;
    struct2 _97_x;
    int64_t _96_t4;
    int64_t _96_t5;
    int64_t _96_t6;
    int64_t _96_t7;
    int64_t _96_t8;
    int64_t _96_t9;
    int64_t _96_$retval;
    _96_t0 = _99_get_array;
    _96_t2 = 15;
    _96_t3 = 16;
    $lines[$line_idx++] = "tests/integration/arrays/index.orng:3:32:\n    let x: [4]Int  = get_array(15, 16)\n                              ^";
    _96_t1 = _96_t0(_96_t2, _96_t3);
    $line_idx--;
    _97_x = _96_t1;
    _96_t4 = 0;
    _96_t5 = 1;
    _96_t6 = $add_int64_t(*((int64_t*)&_97_x + _96_t4), *((int64_t*)&_97_x + _96_t5), "tests/integration/arrays/index.orng:4:11:\n    x[0] + x[1] + x[2] + x[3]\n         ^");
    _96_t7 = 2;
    _96_t8 = $add_int64_t(_96_t6, *((int64_t*)&_97_x + _96_t7), "tests/integration/arrays/index.orng:4:18:\n    x[0] + x[1] + x[2] + x[3]\n                ^");
    _96_t9 = 3;
    _96_$retval = $add_int64_t(_96_t8, *((int64_t*)&_97_x + _96_t9), "tests/integration/arrays/index.orng:4:25:\n    x[0] + x[1] + x[2] + x[3]\n                       ^");
    return _96_$retval;
}

struct2 _99_get_array(int64_t _99_a,int64_t _99_b) {
    struct2 _99_$retval;
    _99_$retval = (struct2) {_99_a, _99_b, _99_a, _99_b};
    return _99_$retval;
}

int main(void) {
  printf("%ld",_96_main());
  return 0;
}
