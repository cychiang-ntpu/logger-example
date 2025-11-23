#include <stdio.h>
#include <stdlib.h>
#include "logger.h"

/*
 * 範例 encoder main：
 * - 只示範 logger 的用法與 log 格式
 * - Huffman 的實作請同學自行完成
 */
int main(int argc, char **argv) {
    if (argc != 4) {
        log_error("encoder", "invalid_arguments argc=%d", argc);
        fprintf(stderr, "Usage: %s in_fn cb_fn enc_fn\n", argv[0]);
        return 1;
    }

    const char *in_fn  = argv[1];
    const char *cb_fn  = argv[2];
    const char *enc_fn = argv[3];

    log_info("encoder", "start input_file=%s cb_fn=%s enc_fn=%s",
             in_fn, cb_fn, enc_fn);

    /* TODO: 在這裡加入 Huffman encoder 的實作
       以下只是示範用的假資料，請同學改成自己計算出的結果 */

    int    num_symbols         = 48;
    double fixed_bps           = 5.000000000000000;
    double entropy_bps         = 4.080000000000000;
    double perplexity          = 17.000000000000000;
    double huffman_bps         = 4.020000000000000;
    double total_bits_fixed    = num_symbols * fixed_bps;
    double total_bits_huffman  = num_symbols * huffman_bps;
    double compression_ratio   = total_bits_fixed / total_bits_huffman; /* > 1 越大越好 */
    double compression_factor  = total_bits_huffman / total_bits_fixed; /* < 1 越小越好 */
    double saving_percentage   = 1.0 - compression_factor;

    log_info("metrics",
             "summary input_file=%s num_symbols=%d "
             "fixed_code_bits_per_symbol=%.15f "
             "entropy_bits_per_symbol=%.15f "
             "perplexity=%.15f "
             "huffman_bits_per_symbol=%.15f "
             "total_bits_fixed=%.15f "
             "total_bits_huffman=%.15f "
             "compression_ratio=%.15f "
             "compression_factor=%.15f "
             "saving_percentage=%.15f",
             in_fn,
             num_symbols,
             fixed_bps,
             entropy_bps,
             perplexity,
             huffman_bps,
             total_bits_fixed,
             total_bits_huffman,
             compression_ratio,
             compression_factor,
             saving_percentage);

    log_info("encoder", "finish status=ok");

    return 0;
}
