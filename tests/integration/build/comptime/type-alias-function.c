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
int64_t _305_main(void);
int64_t _307_add(int64_t _307_x, int64_t _307_y);


/* Function definitions */
int64_t _305_main(void){
    function0 _306_f;
    int64_t _305_t3;
    int64_t _305_t4;
    int64_t _305_t2;
    int64_t _305_$retval;
    _306_f = (function0) _307_add;
    _305_t3 = 200;
    _305_t4 = 43;
    $lines[$line_idx++] = "tests/integration/comptime/type-alias-function.orng:6:7:\n    f(200, 43)\n     ^";
    _305_t2 = _306_f(_305_t3, _305_t4);
    $line_idx--;
    _305_$retval = _305_t2;
    return _305_$retval;
}

int64_t _307_add(int64_t _307_x, int64_t _307_y){
    int64_t _307_$retval;
    _307_$retval = $add_int64_t(_307_x, _307_y, "tests/integration/comptime/type-alias-function.orng:9:36:\nfn add(x: Int, y: Int) -> Int { x + y }\n                                  ^");
    return _307_$retval;
}


int main(void) {
  printf("%ld",_305_main());
  return 0;
}
