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
int64_t _1030_main(void);
int64_t _1032_$anon96(int64_t _1032_x, int64_t _1032_y);


/* Function definitions */
int64_t _1030_main(void){
    function0 _1030_t0;
    int64_t _1030_t2;
    int64_t _1030_t3;
    int64_t _1030_t1;
    int64_t _1030_$retval;
    _1030_t0 = (function0) _1032_$anon96;
    _1030_t2 = 300;
    _1030_t3 = 11;
    $lines[$line_idx++] = "tests/integration/generics/comptime-fn.orng:10:9:\n    add(Int, 300, 11)\n       ^";
    _1030_t1 = _1030_t0(_1030_t2, _1030_t3);
    $line_idx--;
    _1030_$retval = _1030_t1;
    return _1030_$retval;
}

int64_t _1032_$anon96(int64_t _1032_x, int64_t _1032_y){
    int64_t _1032_$retval;
    _1032_$retval = $add_int64_t(_1032_x, _1032_y, "tests/integration/generics/comptime-fn.orng:5:45:\nfn add(const T: Type, x: T, y: T) -> T { x + y }\n                                           ^");
    return _1032_$retval;
}


int main(void) {
  printf("%ld",_1030_main());
  return 0;
}
