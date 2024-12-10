/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _2021_main(void);


/* Function definitions */
int64_t _2021_main(void){
    int64_t _2022_x;
    int64_t* _2022_y;
    int64_t _2021_t5;
    uint8_t _2021_t7;
    int64_t _2021_t4;
    int64_t _2021_$retval;
    int64_t _2024_z;
    int64_t* _2021_t10;
    int64_t _2021_t13;
    int64_t _2021_t14;
    int64_t _2021_t16;
    int64_t _2021_t17;
    int64_t _2021_t20;
    _2022_x = 0;
    _2022_y = &_2022_x;
    _2021_t5 = 0;
    _2021_t7 = *_2022_y==_2021_t5;
    if (_2021_t7) {
        goto BB2223;
    } else {
        goto BB2227;
    }
BB2223:
    _2024_z = *_2022_y;
    _2021_t10 = &_2024_z;
    *_2021_t10 = $add_int64_t(_2024_z, _2024_z, "tests/integration/whitebox/pemdas.orng:7:24:\n        (&mut z)^ = z + z \n                      ^");
    _2024_z = $sub_int64_t(_2024_z, _2024_z, "tests/integration/whitebox/pemdas.orng:8:16:\n        z = z - z \n              ^");
    _2024_z = $mult_int64_t(_2024_z, _2024_z, "tests/integration/whitebox/pemdas.orng:9:16:\n        z = z * z \n              ^");
    _2021_t13 = 1;
    _2021_t14 = $add_int64_t(_2024_z, _2021_t13, "tests/integration/whitebox/pemdas.orng:10:21:\n        z = z / (z + 1)\n                   ^");
    _2024_z = $div_int64_t(_2024_z, _2021_t14, "tests/integration/whitebox/pemdas.orng:10:16:\n        z = z / (z + 1)\n              ^");
    _2021_t16 = 1;
    _2021_t17 = $add_int64_t(_2024_z, _2021_t16, "tests/integration/whitebox/pemdas.orng:11:21:\n        z = z % (z + 1) \n                   ^");
    _2024_z = $mod_int64_t(_2024_z, _2021_t17, "tests/integration/whitebox/pemdas.orng:11:16:\n        z = z % (z + 1) \n              ^");
    _2021_t20 = -1;
    _2024_z = $mult_int64_t(_2024_z, _2021_t20, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    _2021_t4 = $mult_int64_t(_2024_z, _2021_t20, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    goto BB2226;
BB2227:
    _2021_t4 = 1000;
    goto BB2226;
BB2226:
    _2021_$retval = _2021_t4;
    return _2021_$retval;
}


int main(void) {
  printf("%ld",_2021_main());
  return 0;
}
