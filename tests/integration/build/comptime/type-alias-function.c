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
int64_t _387_main(void);
int64_t _389_add(int64_t _389_x, int64_t _389_y);


/* Function definitions */
int64_t _387_main(void){
    function0 _388_f;
    int64_t _387_t3;
    int64_t _387_t4;
    int64_t _387_t2;
    int64_t _387_$retval;
    _388_f = (function0) _389_add;
    _387_t3 = 200;
    _387_t4 = 43;
    $lines[$line_idx++] = "tests/integration/comptime/type-alias-function.orng:6:7:\n    f(200, 43)\n     ^";
    _387_t2 = _388_f(_387_t3, _387_t4);
    $line_idx--;
    _387_$retval = _387_t2;
    return _387_$retval;
}

int64_t _389_add(int64_t _389_x, int64_t _389_y){
    int64_t _389_$retval;
    _389_$retval = $add_int64_t(_389_x, _389_y, "tests/integration/comptime/type-alias-function.orng:9:36:\nfn add(x: Int, y: Int) -> Int { x + y }\n                                  ^");
    return _389_$retval;
}


int main(void) {
  printf("%ld",_387_main());
  return 0;
}
