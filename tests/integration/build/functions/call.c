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

typedef int64_t(*function0)(int64_t, int64_t);

/* Function forward definitions */
int64_t _688_main(void);
int64_t _690_add(int64_t _690_x,int64_t _690_y);

/* Function definitions */
int64_t _688_main(void) {
    function0 _688_t0;
    int64_t _688_t2;
    int64_t _688_t3;
    int64_t _688_t1;
    int64_t _688_$retval;
    _688_t0 = _690_add;
    _688_t2 = 40;
    _688_t3 = 3;
    $lines[$line_idx++] = "tests/integration/functions/call.orng:2:23:\nfn main() -> Int {add(40, 3)}\n                     ^";
    _688_t1 = _688_t0(_688_t2, _688_t3);
    $line_idx--;
    _688_$retval = _688_t1;
    return _688_$retval;
}

int64_t _690_add(int64_t _690_x,int64_t _690_y) {
    int64_t _690_$retval;
    _690_$retval = $add_int64_t(_690_x, _690_y, "tests/integration/functions/call.orng:4:35:\nfn add(x: Int, y: Int) -> Int {x + y}\n                                 ^");
    return _690_$retval;
}

int main(void) {
  printf("%ld",_688_main());
  return 0;
}
