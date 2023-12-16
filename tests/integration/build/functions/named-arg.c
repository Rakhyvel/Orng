/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _0;
    int64_t _1;
} struct1;

typedef int64_t(*function0)(int64_t, int64_t);

/* Function forward definitions */
int64_t _935_main(void);
int64_t _937_div(int64_t _937_x,int64_t _937_y);

/* Function definitions */
int64_t _935_main(void){
    function0 _935_t0;
    int64_t _935_t2;
    int64_t _935_t3;
    int64_t _935_t1;
    int64_t _935_$retval;
    _935_t0 = _937_div;
    _935_t2 = 510;
    _935_t3 = 10;
    $lines[$line_idx++] = "tests/integration/functions/named-arg.orng:3:9:\n    div(.x = 510, .y = 10)\n       ^";
    _935_t1 = _935_t0(_935_t2, _935_t3);
    $line_idx--;
    _935_$retval = _935_t1;
    return _935_$retval;
}

int64_t _937_div(int64_t _937_x,int64_t _937_y){
    int64_t _937_$retval;
    _937_$retval = $div_int64_t(_937_x, _937_y, "tests/integration/functions/named-arg.orng:6:35:\nfn div(x: Int, y: Int) -> Int {x / y}\n                                 ^");
    return _937_$retval;
}

int main(void) {
  printf("%ld",_935_main());
  return 0;
}
