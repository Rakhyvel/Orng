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
int64_t _937_main(void);
int64_t _939_add(int64_t _939_x, int64_t _939_y);


/* Function definitions */
int64_t _937_main(void){
    function0 _937_t0;
    int64_t _937_t2;
    int64_t _937_t3;
    int64_t _937_t1;
    int64_t _937_$retval;
    _937_t0 = _939_add;
    _937_t2 = 40;
    _937_t3 = 3;
    $lines[$line_idx++] = "tests/integration/functions/call.orng:2:23:\nfn main() -> Int {add(40, 3)}\n                     ^";
    _937_t1 = _937_t0(_937_t2, _937_t3);
    $line_idx--;
    _937_$retval = _937_t1;
    return _937_$retval;
}

int64_t _939_add(int64_t _939_x, int64_t _939_y){
    int64_t _939_$retval;
    _939_$retval = $add_int64_t(_939_x, _939_y, "tests/integration/functions/call.orng:4:35:\nfn add(x: Int, y: Int) -> Int {x + y}\n                                 ^");
    return _939_$retval;
}


int main(void) {
  printf("%ld",_937_main());
  return 0;
}
