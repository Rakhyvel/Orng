/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _2023_main(void);


/* Function definitions */
int64_t _2023_main(void){
    int64_t _2024_x;
    int64_t* _2024_y;
    int64_t _2023_t5;
    uint8_t _2023_t7;
    int64_t _2023_t4;
    int64_t _2023_$retval;
    int64_t _2026_z;
    int64_t* _2023_t10;
    int64_t _2023_t13;
    int64_t _2023_t14;
    int64_t _2023_t16;
    int64_t _2023_t17;
    int64_t _2023_t20;
    _2024_x = 0;
    _2024_y = &_2024_x;
    _2023_t5 = 0;
    _2023_t7 = *_2024_y==_2023_t5;
    if (_2023_t7) {
        goto BB2225;
    } else {
        goto BB2229;
    }
BB2225:
    _2026_z = *_2024_y;
    _2023_t10 = &_2026_z;
    *_2023_t10 = $add_int64_t(_2026_z, _2026_z, "tests/integration/whitebox/pemdas.orng:7:24:\n        (&mut z)^ = z + z \n                      ^");
    _2026_z = $sub_int64_t(_2026_z, _2026_z, "tests/integration/whitebox/pemdas.orng:8:16:\n        z = z - z \n              ^");
    _2026_z = $mult_int64_t(_2026_z, _2026_z, "tests/integration/whitebox/pemdas.orng:9:16:\n        z = z * z \n              ^");
    _2023_t13 = 1;
    _2023_t14 = $add_int64_t(_2026_z, _2023_t13, "tests/integration/whitebox/pemdas.orng:10:21:\n        z = z / (z + 1)\n                   ^");
    _2026_z = $div_int64_t(_2026_z, _2023_t14, "tests/integration/whitebox/pemdas.orng:10:16:\n        z = z / (z + 1)\n              ^");
    _2023_t16 = 1;
    _2023_t17 = $add_int64_t(_2026_z, _2023_t16, "tests/integration/whitebox/pemdas.orng:11:21:\n        z = z % (z + 1) \n                   ^");
    _2026_z = $mod_int64_t(_2026_z, _2023_t17, "tests/integration/whitebox/pemdas.orng:11:16:\n        z = z % (z + 1) \n              ^");
    _2023_t20 = -1;
    _2026_z = $mult_int64_t(_2026_z, _2023_t20, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    _2023_t4 = $mult_int64_t(_2026_z, _2023_t20, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    goto BB2228;
BB2229:
    _2023_t4 = 1000;
    goto BB2228;
BB2228:
    _2023_$retval = _2023_t4;
    return _2023_$retval;
}


int main(void) {
  printf("%ld",_2023_main());
  return 0;
}
