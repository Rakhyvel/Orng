/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */

/* Struct, union, and function definitions */
typedef int64_t(*function0)(void);

/* Function forward definitions */
int64_t _1110_main(void);
int64_t _1112_$anon109(void);
int64_t _1114_$anon110(void);


/* Function definitions */
int64_t _1110_main(void){
    function0 _1110_t0;
    int64_t _1110_t1;
    int64_t _1110_$retval;
    _1110_t0 = (function0) _1112_$anon109;
    $lines[$line_idx++] = "tests/integration/generics/template-in-template.orng:10:11:\n    tempa(149)\n         ^";
    _1110_t1 = _1110_t0();
    $line_idx--;
    _1110_$retval = _1110_t1;
    return _1110_$retval;
}

int64_t _1112_$anon109(void){
    function0 _1112_t1;
    int64_t _1112_t2;
    int64_t _1112_t3;
    int64_t _1112_$retval;
    _1112_t1 = (function0) _1114_$anon110;
    $lines[$line_idx++] = "tests/integration/generics/template-in-template.orng:6:11:\n    tempb(n + 1) + 19\n         ^";
    _1112_t2 = _1112_t1();
    $line_idx--;
    _1112_t3 = 19;
    _1112_$retval = $add_int64_t(_1112_t2, _1112_t3, "tests/integration/generics/template-in-template.orng:6:19:\n    tempb(n + 1) + 19\n                 ^");
    return _1112_$retval;
}

int64_t _1114_$anon110(void){
    int64_t _1114_$retval;
    _1114_$retval = 300;
    return _1114_$retval;
}


int main(void) {
  printf("%ld",_1110_main());
  return 0;
}
