/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* Debug information */
static const char* $lines[1024];
static uint16_t $line_idx = 0;

inline static void $panic(const char *restrict msg) {
    fprintf(stderr, "panic: %s\n", msg);
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
}

inline static void $bounds_check(const int64_t idx, const int64_t length, const char *restrict line) {
    if (0 > idx || idx >= length) {
        $lines[$line_idx++] = line;
        $panic("bounds check failed");
    }
}

inline static void $tag_check(const int64_t tag, const int64_t sel, const char *restrict line) {
    if (tag != sel) {
        $lines[$line_idx++] = line;
        $panic("inactive field");
    }
}
/* Function forward definitions */
int64_t _1_main();
int64_t _3_div(int64_t _3_x,int64_t _3_y);

/* Function definitions */
int64_t _1_main() {
    int64_t _1_t0;
    int64_t _1_$retval;
    $lines[$line_idx++] = "tests/integration/functions/named-arg.orng:3:9:\n    div(.x = 510, .y = 10)\n       ^";
    _1_t0 = _3_div(510, 10);
    $line_idx--;
    _1_$retval = _1_t0;
    return _1_$retval;
}

int64_t _3_div(int64_t _3_x,int64_t _3_y) {
    int64_t _3_$retval;
    _3_$retval = _3_x / _3_y;
    return _3_$retval;
}

int main()
{
  printf("%ld",_1_main());
  return 0;
}
