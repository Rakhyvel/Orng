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
int64_t _707_main(void);
int64_t _709_add(int64_t _709_x,int64_t _709_y);

/* Function definitions */
int64_t _707_main(void) {
    function0 _707_t0;
    int64_t _707_t2;
    int64_t _707_t3;
    int64_t _707_t1;
    int64_t _707_$retval;
    _707_t0 = _709_add;
    _707_t2 = 40;
    _707_t3 = 3;
    $lines[$line_idx++] = "tests/integration/functions/call.orng:2:23:\nfn main() -> Int {add(40, 3)}\n                     ^";
    _707_t1 = _707_t0(_707_t2, _707_t3);
    $line_idx--;
    _707_$retval = _707_t1;
    return _707_$retval;
}

int64_t _709_add(int64_t _709_x,int64_t _709_y) {
    int64_t _709_$retval;
    _709_$retval = $add_int64_t(_709_x, _709_y, "tests/integration/functions/call.orng:4:35:\nfn add(x: Int, y: Int) -> Int {x + y}\n                                 ^");
    return _709_$retval;
}

int main(void) {
  printf("%ld",_707_main());
  return 0;
}
