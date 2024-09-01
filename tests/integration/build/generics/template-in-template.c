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
int64_t _55_main(void);
int64_t _57_$anon9(void);
int64_t _59_$anon10(void);


/* Function definitions */
int64_t _55_main(void){
    function0 _55_t0;
    int64_t _55_t1;
    int64_t _55_$retval;
    _55_t0 = (function0) _57_$anon9;
    $lines[$line_idx++] = "tests/integration/generics/template-in-template.orng:10:11:\n    tempa(149)\n         ^";
    _55_t1 = _55_t0();
    $line_idx--;
    _55_$retval = _55_t1;
    return _55_$retval;
}

int64_t _57_$anon9(void){
    function0 _57_t1;
    int64_t _57_t2;
    int64_t _57_t3;
    int64_t _57_$retval;
    _57_t1 = (function0) _59_$anon10;
    $lines[$line_idx++] = "tests/integration/generics/template-in-template.orng:6:11:\n    tempb(n + 1) + 19\n         ^";
    _57_t2 = _57_t1();
    $line_idx--;
    _57_t3 = 19;
    _57_$retval = $add_int64_t(_57_t2, _57_t3, "tests/integration/generics/template-in-template.orng:6:19:\n    tempb(n + 1) + 19\n                 ^");
    return _57_$retval;
}

int64_t _59_$anon10(void){
    int64_t _59_$retval;
    _59_$retval = 300;
    return _59_$retval;
}


int main(void) {
  printf("%ld",_55_main());
  return 0;
}
