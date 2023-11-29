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
int64_t _696_main(void);
int64_t _698_add(int64_t _698_x,int64_t _698_y);

/* Function definitions */
int64_t _696_main(void) {
    function0 _696_t0;
    int64_t _696_t2;
    int64_t _696_t3;
    int64_t _696_t1;
    int64_t _696_$retval;
    _696_t0 = _698_add;
    _696_t2 = 40;
    _696_t3 = 3;
    $lines[$line_idx++] = "tests/integration/functions/call.orng:2:23:\nfn main() -> Int {add(40, 3)}\n                     ^";
    _696_t1 = _696_t0(_696_t2, _696_t3);
    $line_idx--;
    _696_$retval = _696_t1;
    return _696_$retval;
}

int64_t _698_add(int64_t _698_x,int64_t _698_y) {
    int64_t _698_$retval;
    _698_$retval = $add_int64_t(_698_x, _698_y, "tests/integration/functions/call.orng:4:35:\nfn add(x: Int, y: Int) -> Int {x + y}\n                                 ^");
    return _698_$retval;
}

int main(void) {
  printf("%ld",_696_main());
  return 0;
}
