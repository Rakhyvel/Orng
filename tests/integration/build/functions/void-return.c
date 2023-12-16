/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef void(*function0)(void);

/* Function forward definitions */
int64_t _966_main(void);
void _968_void(void);

/* Function definitions */
int64_t _966_main(void){
    function0 _966_t0;
    int64_t _966_$retval;
    _966_t0 = _968_void;
    $lines[$line_idx++] = "tests/integration/functions/void-return.orng:3:10:\n    void()\n        ^";
    _966_t0();
    $line_idx--;
    _966_$retval = 65;
    return _966_$retval;
}

void _968_void(void){
    return;
}

int main(void) {
  printf("%ld",_966_main());
  return 0;
}
