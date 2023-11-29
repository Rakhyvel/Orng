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
int64_t _848_main(void);
int64_t _850_add(int64_t _850_x,int64_t _850_y);

/* Function definitions */
int64_t _848_main(void) {
    function0 _848_t0;
    int64_t _848_t2;
    int64_t _848_t3;
    int64_t _848_t1;
    int64_t _848_$retval;
    _848_t0 = _850_add;
    _848_t2 = 40;
    _848_t3 = 3;
    $lines[$line_idx++] = "tests/integration/functions/call.orng:2:23:\nfn main() -> Int {add(40, 3)}\n                     ^";
    _848_t1 = _848_t0(_848_t2, _848_t3);
    $line_idx--;
    _848_$retval = _848_t1;
    return _848_$retval;
}

int64_t _850_add(int64_t _850_x,int64_t _850_y) {
    int64_t _850_$retval;
    _850_$retval = $add_int64_t(_850_x, _850_y, "tests/integration/functions/call.orng:4:35:\nfn add(x: Int, y: Int) -> Int {x + y}\n                                 ^");
    return _850_$retval;
}

int main(void) {
  printf("%ld",_848_main());
  return 0;
}
