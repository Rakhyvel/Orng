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
int64_t _1071_main(void);
int64_t _1073_$anon103(void);
int64_t _1075_$anon104(void);


/* Function definitions */
int64_t _1071_main(void){
    function0 _1071_t0;
    int64_t _1071_t1;
    int64_t _1071_$retval;
    _1071_t0 = (function0) _1073_$anon103;
    $lines[$line_idx++] = "tests/integration/generics/template-in-template.orng:10:11:\n    tempa(149)\n         ^";
    _1071_t1 = _1071_t0();
    $line_idx--;
    _1071_$retval = _1071_t1;
    return _1071_$retval;
}

int64_t _1073_$anon103(void){
    function0 _1073_t1;
    int64_t _1073_t2;
    int64_t _1073_t3;
    int64_t _1073_$retval;
    _1073_t1 = (function0) _1075_$anon104;
    $lines[$line_idx++] = "tests/integration/generics/template-in-template.orng:6:11:\n    tempb(n + 1) + 19\n         ^";
    _1073_t2 = _1073_t1();
    $line_idx--;
    _1073_t3 = 19;
    _1073_$retval = $add_int64_t(_1073_t2, _1073_t3, "tests/integration/generics/template-in-template.orng:6:19:\n    tempb(n + 1) + 19\n                 ^");
    return _1073_$retval;
}

int64_t _1075_$anon104(void){
    int64_t _1075_$retval;
    _1075_$retval = 300;
    return _1075_$retval;
}


int main(void) {
  printf("%ld",_1071_main());
  return 0;
}
