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
int64_t _20_main(void);
int64_t _22_$anon3(int64_t _22_x, int64_t _22_y);


/* Function definitions */
int64_t _20_main(void){
    function0 _20_t0;
    int64_t _20_t2;
    int64_t _20_t3;
    int64_t _20_t1;
    int64_t _20_$retval;
    _20_t0 = (function0) _22_$anon3;
    _20_t2 = 300;
    _20_t3 = 11;
    $lines[$line_idx++] = "tests/integration/generics/comptime-fn.orng:10:9:\n    add(Int, 300, 11)\n       ^";
    _20_t1 = _20_t0(_20_t2, _20_t3);
    $line_idx--;
    _20_$retval = _20_t1;
    return _20_$retval;
}

int64_t _22_$anon3(int64_t _22_x, int64_t _22_y){
    int64_t _22_$retval;
    _22_$retval = $add_int64_t(_22_x, _22_y, "tests/integration/generics/comptime-fn.orng:5:45:\nfn add(const T: Type, x: T, y: T) -> T { x + y }\n                                           ^");
    return _22_$retval;
}


int main(void) {
  printf("%ld",_20_main());
  return 0;
}
