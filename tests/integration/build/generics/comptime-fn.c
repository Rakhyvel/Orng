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
int64_t _1049_main(void);
int64_t _1051_$anon97(int64_t _1051_x, int64_t _1051_y);


/* Function definitions */
int64_t _1049_main(void){
    function0 _1049_t0;
    int64_t _1049_t2;
    int64_t _1049_t3;
    int64_t _1049_t1;
    int64_t _1049_$retval;
    _1049_t0 = (function0) _1051_$anon97;
    _1049_t2 = 300;
    _1049_t3 = 11;
    $lines[$line_idx++] = "tests/integration/generics/comptime-fn.orng:10:9:\n    add(Int, 300, 11)\n       ^";
    _1049_t1 = _1049_t0(_1049_t2, _1049_t3);
    $line_idx--;
    _1049_$retval = _1049_t1;
    return _1049_$retval;
}

int64_t _1051_$anon97(int64_t _1051_x, int64_t _1051_y){
    int64_t _1051_$retval;
    _1051_$retval = $add_int64_t(_1051_x, _1051_y, "tests/integration/generics/comptime-fn.orng:5:45:\nfn add(const T: Type, x: T, y: T) -> T { x + y }\n                                           ^");
    return _1051_$retval;
}


int main(void) {
  printf("%ld",_1049_main());
  return 0;
}
