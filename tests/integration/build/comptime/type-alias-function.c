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
int64_t _407_main(void);
int64_t _409_add(int64_t _409_x, int64_t _409_y);


/* Function definitions */
int64_t _407_main(void){
    function0 _408_f;
    int64_t _407_t3;
    int64_t _407_t4;
    int64_t _407_t2;
    int64_t _407_$retval;
    _408_f = (function0) _409_add;
    _407_t3 = 200;
    _407_t4 = 43;
    $lines[$line_idx++] = "tests/integration/comptime/type-alias-function.orng:6:7:\n    f(200, 43)\n     ^";
    _407_t2 = _408_f(_407_t3, _407_t4);
    $line_idx--;
    _407_$retval = _407_t2;
    return _407_$retval;
}

int64_t _409_add(int64_t _409_x, int64_t _409_y){
    int64_t _409_$retval;
    _409_$retval = $add_int64_t(_409_x, _409_y, "tests/integration/comptime/type-alias-function.orng:9:36:\nfn add(x: Int, y: Int) -> Int { x + y }\n                                  ^");
    return _409_$retval;
}


int main(void) {
  printf("%ld",_407_main());
  return 0;
}
