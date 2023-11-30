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
int64_t _900_main(void);
int64_t _902_div(int64_t _902_x,int64_t _902_y);

/* Function definitions */
int64_t _900_main(void) {
    function0 _900_t0;
    int64_t _900_t2;
    int64_t _900_t3;
    int64_t _900_t1;
    int64_t _900_$retval;
    _900_t0 = _902_div;
    _900_t2 = 510;
    _900_t3 = 10;
    $lines[$line_idx++] = "tests/integration/functions/named-arg.orng:3:9:\n    div(.x = 510, .y = 10)\n       ^";
    _900_t1 = _900_t0(_900_t2, _900_t3);
    $line_idx--;
    _900_$retval = _900_t1;
    return _900_$retval;
}

int64_t _902_div(int64_t _902_x,int64_t _902_y) {
    int64_t _902_$retval;
    _902_$retval = $div_int64_t(_902_x, _902_y, "tests/integration/functions/named-arg.orng:6:35:\nfn div(x: Int, y: Int) -> Int {x / y}\n                                 ^");
    return _902_$retval;
}

int main(void) {
  printf("%ld",_900_main());
  return 0;
}
