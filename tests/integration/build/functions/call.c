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
int64_t _9_main(void);
int64_t _11_add(int64_t _11_x,int64_t _11_y);

/* Function definitions */
int64_t _9_main(void) {
    function0 _9_t0;
    int64_t _9_t2;
    int64_t _9_t3;
    int64_t _9_t1;
    int64_t _9_$retval;
    _9_t0 = _11_add;
    _9_t2 = 40;
    _9_t3 = 3;
    $lines[$line_idx++] = "tests/integration/functions/call.orng:2:23:\nfn main() -> Int {add(40, 3)}\n                     ^";
    _9_t1 = _9_t0(_9_t2, _9_t3);
    $line_idx--;
    _9_$retval = _9_t1;
    return _9_$retval;
}

int64_t _11_add(int64_t _11_x,int64_t _11_y) {
    int64_t _11_$retval;
    _11_$retval = $add_int64_t(_11_x, _11_y, "tests/integration/functions/call.orng:4:35:\nfn add(x: Int, y: Int) -> Int {x + y}\n                                 ^");
    return _11_$retval;
}

int main(void) {
  printf("%ld",_9_main());
  return 0;
}
