/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef void(*function0)(void);

/* Function forward definitions */
int64_t _1119_main(void);
void _1121_void(void);

/* Function definitions */
int64_t _1119_main(void){
    function0 _1119_t0;
    int64_t _1119_$retval;
    _1119_t0 = _1121_void;
    $lines[$line_idx++] = "tests/integration/functions/void-return.orng:3:10:\n    void()\n        ^";
    _1119_t0();
    $line_idx--;
    _1119_$retval = 65;
    return _1119_$retval;
}

void _1121_void(void){
    return;
}

int main(void) {
  printf("%ld",_1119_main());
  return 0;
}
