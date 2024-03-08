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
int64_t _388_main(void);
int64_t _390_add(int64_t _390_x, int64_t _390_y);


/* Function definitions */
int64_t _388_main(void){
    function0 _389_f;
    int64_t _388_t2;
    int64_t _388_t3;
    int64_t _388_t1;
    int64_t _388_$retval;
    _389_f = (function0) _390_add;
    _388_t2 = 200;
    _388_t3 = 43;
    $lines[$line_idx++] = "tests/integration/comptime/type-alias-function.orng:6:7:\n    f(200, 43)\n     ^";
    _388_t1 = _389_f(_388_t2, _388_t3);
    $line_idx--;
    _388_$retval = _388_t1;
    return _388_$retval;
}

int64_t _390_add(int64_t _390_x, int64_t _390_y){
    int64_t _390_$retval;
    _390_$retval = $add_int64_t(_390_x, _390_y, "tests/integration/comptime/type-alias-function.orng:9:36:\nfn add(x: Int, y: Int) -> Int { x + y }\n                                  ^");
    return _390_$retval;
}


int main(void) {
  printf("%ld",_388_main());
  return 0;
}
