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
int64_t _409_main(void);
int64_t _411_add(int64_t _411_x, int64_t _411_y);


/* Function definitions */
int64_t _409_main(void){
    function0 _410_f;
    int64_t _409_t3;
    int64_t _409_t4;
    int64_t _409_t2;
    int64_t _409_$retval;
    _410_f = (function0) _411_add;
    _409_t3 = 200;
    _409_t4 = 43;
    $lines[$line_idx++] = "tests/integration/comptime/type-alias-function.orng:6:7:\n    f(200, 43)\n     ^";
    _409_t2 = _410_f(_409_t3, _409_t4);
    $line_idx--;
    _409_$retval = _409_t2;
    return _409_$retval;
}

int64_t _411_add(int64_t _411_x, int64_t _411_y){
    int64_t _411_$retval;
    _411_$retval = $add_int64_t(_411_x, _411_y, "tests/integration/comptime/type-alias-function.orng:9:36:\nfn add(x: Int, y: Int) -> Int { x + y }\n                                  ^");
    return _411_$retval;
}


int main(void) {
  printf("%ld",_409_main());
  return 0;
}
