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
int64_t _1054_main(void);
int64_t _1056_$anon99(int64_t _1056_x, int64_t _1056_y);


/* Function definitions */
int64_t _1054_main(void){
    function0 _1054_t0;
    int64_t _1054_t2;
    int64_t _1054_t3;
    int64_t _1054_t1;
    int64_t _1054_$retval;
    _1054_t0 = (function0) _1056_$anon99;
    _1054_t2 = 300;
    _1054_t3 = 11;
    $lines[$line_idx++] = "tests/integration/generics/comptime-fn.orng:10:9:\n    add(Int, 300, 11)\n       ^";
    _1054_t1 = _1054_t0(_1054_t2, _1054_t3);
    $line_idx--;
    _1054_$retval = _1054_t1;
    return _1054_$retval;
}

int64_t _1056_$anon99(int64_t _1056_x, int64_t _1056_y){
    int64_t _1056_$retval;
    _1056_$retval = $add_int64_t(_1056_x, _1056_y, "tests/integration/generics/comptime-fn.orng:5:45:\nfn add(const T: Type, x: T, y: T) -> T { x + y }\n                                           ^");
    return _1056_$retval;
}


int main(void) {
  printf("%ld",_1054_main());
  return 0;
}
