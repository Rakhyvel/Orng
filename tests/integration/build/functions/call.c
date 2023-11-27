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
int64_t _624_main(void);
int64_t _626_add(int64_t _626_x,int64_t _626_y);

/* Function definitions */
int64_t _624_main(void) {
    function0 _624_t0;
    int64_t _624_t2;
    int64_t _624_t3;
    int64_t _624_t1;
    int64_t _624_$retval;
    _624_t0 = _626_add;
    _624_t2 = 40;
    _624_t3 = 3;
    $lines[$line_idx++] = "tests/integration/functions/call.orng:2:23:\nfn main() -> Int {add(40, 3)}\n                     ^";
    _624_t1 = _624_t0(_624_t2, _624_t3);
    $line_idx--;
    _624_$retval = _624_t1;
    return _624_$retval;
}

int64_t _626_add(int64_t _626_x,int64_t _626_y) {
    int64_t _626_$retval;
    _626_$retval = $add_int64_t(_626_x, _626_y, "tests/integration/functions/call.orng:4:35:\nfn add(x: Int, y: Int) -> Int {x + y}\n                                 ^");
    return _626_$retval;
}

int main(void) {
  printf("%ld",_624_main());
  return 0;
}
