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
int64_t _949_main(void);
int64_t _951_add(int64_t _951_x, int64_t _951_y);


/* Function definitions */
int64_t _949_main(void){
    function0 _949_t0;
    int64_t _949_t2;
    int64_t _949_t3;
    int64_t _949_t1;
    int64_t _949_$retval;
    _949_t0 = (function0) _951_add;
    _949_t2 = 40;
    _949_t3 = 3;
    $lines[$line_idx++] = "tests/integration/functions/call.orng:2:23:\nfn main() -> Int {add(40, 3)}\n                     ^";
    _949_t1 = _949_t0(_949_t2, _949_t3);
    $line_idx--;
    _949_$retval = _949_t1;
    return _949_$retval;
}

int64_t _951_add(int64_t _951_x, int64_t _951_y){
    int64_t _951_$retval;
    _951_$retval = $add_int64_t(_951_x, _951_y, "tests/integration/functions/call.orng:4:35:\nfn add(x: Int, y: Int) -> Int {x + y}\n                                 ^");
    return _951_$retval;
}


int main(void) {
  printf("%ld",_949_main());
  return 0;
}
