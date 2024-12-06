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

typedef struct struct1(*function0)(void);

/* Function forward definitions */
int64_t _1887_main(void);
struct struct1 _1889_f(void);


/* Function definitions */
int64_t _1887_main(void){
    function0 _1887_t0;
    struct struct1 _1887_t1;
    int64_t _1887_$retval;
    _1887_t0 = (function0) _1889_f;
    $lines[$line_idx++] = "tests/integration/tuples/returned.orng:3:7:\n    f().y\n     ^";
    _1887_t1 = _1887_t0();
    $line_idx--;
    _1887_$retval = _1887_t1._1;
    return _1887_$retval;
}

struct struct1 _1889_f(void){
    int64_t _1889_t1;
    int64_t _1889_t2;
    struct struct1 _1889_$retval;
    _1889_t1 = 45;
    _1889_t2 = 221;
    _1889_$retval = (struct struct1) {_1889_t1, _1889_t2};
    return _1889_$retval;
}


int main(void) {
  printf("%ld",_1887_main());
  return 0;
}
