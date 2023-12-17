/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef void(*function0)(int64_t*);

/* Function forward definitions */
int64_t _759_main(void);
void _762_f(int64_t* _762_y);

/* Function definitions */
int64_t _759_main(void){
    int64_t _760_x;
    int64_t* _760_y;
    function0 _759_t2;
    int64_t _759_$retval;
    _760_x = 4;
    _760_y = &_760_x;
    _759_t2 = _762_f;
    $lines[$line_idx++] = "tests/integration/expressions/deref-copy-param.orng:5:7:\n    f(y)\n     ^";
    _759_t2(_760_y);
    $line_idx--;
    _759_$retval = *_760_y;
    return _759_$retval;
}

void _762_f(int64_t* _762_y){
    int64_t* _765_z;
    _765_z = _762_y;
    *_765_z = 195;
    return;
}

int main(void) {
  printf("%ld",_759_main());
  return 0;
}
