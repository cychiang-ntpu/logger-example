#include <stdio.h>
#include <stdlib.h>
#include "logger.h"

/*
 * 範例 decoder main：
 * - 只示範 logger 的用法與 log 格式
 * - Huffman 的實作請同學自行完成
 */
int main(int argc, char **argv) {
    if (argc != 4) {
        log_error("decoder", "invalid_arguments argc=%d", argc);
        fprintf(stderr, "Usage: %s enc_fn cb_fn out_fn\n", argv[0]);
        return 1;
    }

    const char *enc_fn = argv[1];
    const char *cb_fn  = argv[2];
    const char *out_fn = argv[3];

    log_info("decoder", "start input_encoded=%s input_codebook=%s output_file=%s",
             enc_fn, cb_fn, out_fn);

    /* TODO: 在這裡加入 Huffman decoder 的實作
       以下只是示範用的假資料，請同學改成自己計算出的結果 */

    int num_decoded_symbols = 48;
    int status_ok = 1;

    log_info("metrics",
             "summary input_encoded=%s input_codebook=%s output_file=%s "
             "num_decoded_symbols=%d status=%s",
             enc_fn,
             cb_fn,
             out_fn,
             num_decoded_symbols,
             status_ok ? "ok" : "error");

    log_info("decoder", "finish status=%s", status_ok ? "ok" : "error");

    return status_ok ? 0 : 1;
}
