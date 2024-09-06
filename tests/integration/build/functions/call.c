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
int64_t _938_main(void);
int64_t _940_add(int64_t _940_x, int64_t _940_y);


/* Function definitions */
int64_t _938_main(void){
    function0 _938_t0;
    int64_t _938_t2;
    int64_t _938_t3;
    int64_t _938_t1;
    int64_t _938_$retval;
    _938_t0 = (function0) _940_add;
    _938_t2 = 40;
    _938_t3 = 3;
    $lines[$line_idx++] = "tests/integration/functions/call.orng:2:23:\nfn main() -> Int {add(40, 3)}\n                     ^";
    _938_t1 = _938_t0(_938_t2, _938_t3);
    $line_idx--;
    _938_$retval = _938_t1;
    return _938_$retval;
}

int64_t _940_add(int64_t _940_x, int64_t _940_y){
    int64_t _940_$retval;
    _940_$retval = $add_int64_t(_940_x, _940_y, "tests/integration/functions/call.orng:4:35:\nfn add(x: Int, y: Int) -> Int {x + y}\n                                 ^");
    return _940_$retval;
}


int main(void) {
  printf("%ld",_938_main());
  return 0;
}
