/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1_main(void);

/* Function definitions */
int64_t _1_main(void) {
    int64_t _2_x;
    int64_t* _2_y;
    int64_t _4_z;
    int64_t* _1_t8;
    int64_t _1_t2;
    int64_t _1_$retval;
    _2_x = 0;
    _2_y = &_2_x;
    if (*_2_y) {
        goto BB5;
    } else {
        goto BB1;
    }
BB5:
    _1_t2 = 1000;
    goto BB4;
BB1:
    _4_z = *_2_y;
    _1_t8 = _2_y;
    **&_1_t8 = $add_int64_t(_4_z, _4_z, "tests/integration/whitebox/pemdas.orng:7:24:\n        (&mut z)^ = z + z \n                      ^");
    _4_z = $sub_int64_t(_4_z, _4_z, "tests/integration/whitebox/pemdas.orng:8:16:\n        z = z - z \n              ^");
    _4_z = $mult_int64_t(_4_z, _4_z, "tests/integration/whitebox/pemdas.orng:9:16:\n        z = z * z \n              ^");
    _4_z = $div_int64_t(_4_z, ($add_int64_t(_4_z, 1, "tests/integration/whitebox/pemdas.orng:10:21:\n        z = z / (z + 1)\n                   ^")), "tests/integration/whitebox/pemdas.orng:10:16:\n        z = z / (z + 1)\n              ^");
    _4_z = $mod_int64_t(_4_z, ($add_int64_t(_4_z, 1, "tests/integration/whitebox/pemdas.orng:11:21:\n        z = z % (z + 1) \n                   ^")), "tests/integration/whitebox/pemdas.orng:11:16:\n        z = z % (z + 1) \n              ^");
    _1_t2 = $mult_int64_t(_4_z, -1.0e+00, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1.0)\n              ^");
BB4:
    _1_$retval = _1_t2;
    return _1_$retval;
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
