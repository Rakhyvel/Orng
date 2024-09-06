/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct1;
struct struct2;

/* Struct, union, and function definitions */
struct struct2 {
    int64_t _0;
    int64_t _1;
};

struct struct1 {
    int64_t _0;
    struct struct2 _1;
};

typedef int64_t(*function0)(int64_t, struct struct2);

/* Function forward definitions */
int64_t _550_main(void);
int64_t _552_add_fields(int64_t _552_scale, struct struct2 _552_mt);


/* Function definitions */
int64_t _550_main(void){
    function0 _550_t0;
    int64_t _550_t2;
    int64_t _550_t4;
    int64_t _550_t5;
    struct struct2 _550_t3;
    int64_t _550_t1;
    int64_t _550_$retval;
    _550_t0 = (function0) _552_add_fields;
    _550_t2 = 2;
    _550_t4 = 450;
    _550_t5 = 50;
    _550_t3 = (struct struct2) {_550_t4, _550_t5};
    $lines[$line_idx++] = "tests/integration/default/default-keyword.orng:8:16:\n    add_fields(2)\n              ^";
    _550_t1 = _550_t0(_550_t2, _550_t3);
    $line_idx--;
    _550_$retval = _550_t1;
    return _550_$retval;
}

int64_t _552_add_fields(int64_t _552_scale, struct struct2 _552_mt){
    int64_t _552_t0;
    int64_t _552_$retval;
    _552_t0 = $add_int64_t(_552_mt._0, _552_mt._1, "tests/integration/default/default-keyword.orng:14:12:\n    (mt.x + mt.y) / scale\n          ^");
    _552_$retval = $div_int64_t(_552_t0, _552_scale, "tests/integration/default/default-keyword.orng:14:20:\n    (mt.x + mt.y) / scale\n                  ^");
    return _552_$retval;
}


int main(void) {
  printf("%ld",_550_main());
  return 0;
}
