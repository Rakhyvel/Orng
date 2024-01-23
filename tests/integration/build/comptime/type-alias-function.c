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
int64_t _362_main(void);
int64_t _364_add(int64_t _364_x, int64_t _364_y);


/* Function definitions */
int64_t _362_main(void){
    function0 _363_f;
    int64_t _362_t2;
    int64_t _362_t3;
    int64_t _362_t1;
    int64_t _362_$retval;
    _363_f = _364_add;
    _362_t2 = 200;
    _362_t3 = 43;
    $lines[$line_idx++] = "tests/integration/comptime/type-alias-function.orng:6:7:\n    f(200, 43)\n     ^";
    _362_t1 = _363_f(_362_t2, _362_t3);
    $line_idx--;
    _362_$retval = _362_t1;
    return _362_$retval;
}

int64_t _364_add(int64_t _364_x, int64_t _364_y){
    int64_t _364_$retval;
    _364_$retval = $add_int64_t(_364_x, _364_y, "tests/integration/comptime/type-alias-function.orng:9:36:\nfn add(x: Int, y: Int) -> Int { x + y }\n                                  ^");
    return _364_$retval;
}


int main(void) {
  printf("%ld",_362_main());
  return 0;
}
