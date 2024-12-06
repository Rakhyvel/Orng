/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct1;

/* Struct, union, and function definitions */
struct struct1 {
    int64_t _0;
    int64_t _1;
};

typedef int64_t(*function0)(int64_t, int64_t);

/* Function forward definitions */
int64_t _936_main(void);
int64_t _938_add(int64_t _938_x, int64_t _938_y);


/* Function definitions */
int64_t _936_main(void){
    function0 _936_t0;
    int64_t _936_t2;
    int64_t _936_t3;
    int64_t _936_t1;
    int64_t _936_$retval;
    _936_t0 = (function0) _938_add;
    _936_t2 = 40;
    _936_t3 = 3;
    $lines[$line_idx++] = "tests/integration/functions/call.orng:2:23:\nfn main() -> Int {add(40, 3)}\n                     ^";
    _936_t1 = _936_t0(_936_t2, _936_t3);
    $line_idx--;
    _936_$retval = _936_t1;
    return _936_$retval;
}

int64_t _938_add(int64_t _938_x, int64_t _938_y){
    int64_t _938_$retval;
    _938_$retval = $add_int64_t(_938_x, _938_y, "tests/integration/functions/call.orng:4:35:\nfn add(x: Int, y: Int) -> Int {x + y}\n                                 ^");
    return _938_$retval;
}


int main(void) {
  printf("%ld",_936_main());
  return 0;
}
