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
int64_t _1035_main(void);
int64_t _1037_$anon97(int64_t _1037_x, int64_t _1037_y);


/* Function definitions */
int64_t _1035_main(void){
    function0 _1035_t0;
    int64_t _1035_t2;
    int64_t _1035_t3;
    int64_t _1035_t1;
    int64_t _1035_$retval;
    _1035_t0 = (function0) _1037_$anon97;
    _1035_t2 = 300;
    _1035_t3 = 11;
    $lines[$line_idx++] = "tests/integration/generics/comptime-fn.orng:10:9:\n    add(Int, 300, 11)\n       ^";
    _1035_t1 = _1035_t0(_1035_t2, _1035_t3);
    $line_idx--;
    _1035_$retval = _1035_t1;
    return _1035_$retval;
}

int64_t _1037_$anon97(int64_t _1037_x, int64_t _1037_y){
    int64_t _1037_$retval;
    _1037_$retval = $add_int64_t(_1037_x, _1037_y, "tests/integration/generics/comptime-fn.orng:5:45:\nfn add(const T: Type, x: T, y: T) -> T { x + y }\n                                           ^");
    return _1037_$retval;
}


int main(void) {
  printf("%ld",_1035_main());
  return 0;
}
