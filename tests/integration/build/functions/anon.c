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
/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _1_main();
int64_t _3_$anon0(int64_t _3_x);
int64_t _5_apply(function0 _5_f,int64_t _5_x);

/* Function definitions */
int64_t _1_main() {
    function0 _2_id;
    int64_t _1_t1;
    int64_t _1_$retval;
    _2_id = _3_$anon0;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:4:11:\n    apply(id, 43)\n         ^";
    _1_t1 = _5_apply(_2_id, 43);
    $line_idx--;
    _1_$retval = _1_t1;
    return _1_$retval;
}

int64_t _3_$anon0(int64_t _3_x) {
    int64_t _3_$retval;
    _3_$retval = _3_x;
    return _3_$retval;
}

int64_t _5_apply(function0 _5_f,int64_t _5_x) {
    int64_t _5_t0;
    int64_t _5_$retval;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:7:39:\nfn apply(f: Int->Int, x: Int)->Int {f(x)}\n                                     ^";
    _5_t0 = _5_f(_5_x);
    $line_idx--;
    _5_$retval = _5_t0;
    return _5_$retval;
}

int main()
{
  printf("%ld",_1_main());
  return 0;
}
