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
int64_t _962_main(void);
int64_t _964_div(int64_t _964_x, int64_t _964_y);

/* Function definitions */
int64_t _962_main(void){
    function0 _962_t0;
    int64_t _962_t2;
    int64_t _962_t3;
    int64_t _962_t1;
    int64_t _962_$retval;
    _962_t0 = _964_div;
    _962_t2 = 510;
    _962_t3 = 10;
    $lines[$line_idx++] = "tests/integration/functions/named-arg.orng:3:9:\n    div(.x = 510, .y = 10)\n       ^";
    _962_t1 = _962_t0(_962_t2, _962_t3);
    $line_idx--;
    _962_$retval = _962_t1;
    return _962_$retval;
}

int64_t _964_div(int64_t _964_x, int64_t _964_y){
    int64_t _964_$retval;
    _964_$retval = $div_int64_t(_964_x, _964_y, "tests/integration/functions/named-arg.orng:6:35:\nfn div(x: Int, y: Int) -> Int {x / y}\n                                 ^");
    return _964_$retval;
}

int main(void) {
  printf("%ld",_962_main());
  return 0;
}
