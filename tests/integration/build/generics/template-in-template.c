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
int64_t _61_main(void);
int64_t _63_$anon10(void);
int64_t _65_$anon11(void);


/* Function definitions */
int64_t _61_main(void){
    function0 _61_t0;
    int64_t _61_t1;
    int64_t _61_$retval;
    _61_t0 = (function0) _63_$anon10;
    $lines[$line_idx++] = "tests/integration/generics/template-in-template.orng:10:11:\n    tempa(149)\n         ^";
    _61_t1 = _61_t0();
    $line_idx--;
    _61_$retval = _61_t1;
    return _61_$retval;
}

int64_t _63_$anon10(void){
    function0 _63_t1;
    int64_t _63_t2;
    int64_t _63_t3;
    int64_t _63_$retval;
    _63_t1 = (function0) _65_$anon11;
    $lines[$line_idx++] = "tests/integration/generics/template-in-template.orng:6:11:\n    tempb(n + 1) + 19\n         ^";
    _63_t2 = _63_t1();
    $line_idx--;
    _63_t3 = 19;
    _63_$retval = $add_int64_t(_63_t2, _63_t3, "tests/integration/generics/template-in-template.orng:6:19:\n    tempb(n + 1) + 19\n                 ^");
    return _63_$retval;
}

int64_t _65_$anon11(void){
    int64_t _65_$retval;
    _65_$retval = 300;
    return _65_$retval;
}


int main(void) {
  printf("%ld",_61_main());
  return 0;
}
