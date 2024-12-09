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
int64_t _392_main(void);
int64_t _394_add(int64_t _394_x, int64_t _394_y);


/* Function definitions */
int64_t _392_main(void){
    function0 _393_f;
    int64_t _392_t3;
    int64_t _392_t4;
    int64_t _392_t2;
    int64_t _392_$retval;
    _393_f = (function0) _394_add;
    _392_t3 = 200;
    _392_t4 = 43;
    $lines[$line_idx++] = "tests/integration/comptime/type-alias-function.orng:6:7:\n    f(200, 43)\n     ^";
    _392_t2 = _393_f(_392_t3, _392_t4);
    $line_idx--;
    _392_$retval = _392_t2;
    return _392_$retval;
}

int64_t _394_add(int64_t _394_x, int64_t _394_y){
    int64_t _394_$retval;
    _394_$retval = $add_int64_t(_394_x, _394_y, "tests/integration/comptime/type-alias-function.orng:9:36:\nfn add(x: Int, y: Int) -> Int { x + y }\n                                  ^");
    return _394_$retval;
}


int main(void) {
  printf("%ld",_392_main());
  return 0;
}
