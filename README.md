# Simple logger example for MMSP 2025 mini project 4

這個資料夾提供一個簡單的 `logger.h` / `logger.c`，以及兩個示範程式，說明如何在
Huffman encoder / decoder 裡使用標準化的 log 格式。

## 檔案說明

- `logger.h` / `logger.c`  
  一個極簡的 logging 函式庫：
  - `log_info(component, fmt, ...)`
  - `log_warn(component, fmt, ...)`
  - `log_error(component, fmt, ...)`
  - INFO / WARN 預設輸出到 stdout，ERROR 預設輸出到 stderr。
- `encoder_example.c`  
  示範 encoder 的 `main()` 如何：
  - 檢查參數
  - 在開始 / 結束時寫 log
  - 輸出一行 `metrics` 的 summary（裡面有 entropy / bits per symbol 等假資料）
- `decoder_example.c`  
  示範 decoder 的 `main()` 如何：
  - 記錄使用了哪些輸入 / 輸出檔案
  - 輸出一行 `metrics` 的 summary（包含 `num_decoded_symbols`）
- `Makefile`  
  用來編譯上述程式。

## 編譯

在這個資料夾下執行：

```bash
make
```

會得到兩個執行檔：

- `encoder_example`
- `decoder_example`

如果要清除編譯結果：

```bash
make clean
```

## 測試

### 正常情況測試

執行以下指令會用正確的參數測試兩個程式：

```bash
make test
```

這會依序執行：

- `./encoder_example input.txt codebook.txt encoded.bin`
- `./decoder_example encoded.bin codebook.txt output.txt`

### 錯誤情況測試

執行以下指令會故意給錯誤的參數數量，測試 error log 的輸出：

```bash
make test-error
```

這會依序執行：

- `./encoder_example input.txt`（缺少參數，應產生 error log）
- `./decoder_example encoded.bin`（缺少參數，應產生 error log）

## 執行與產生 log 檔

一般建議將 stdout 重新導向到 `.log` 檔案，stderr 另外存到 `.err` 檔案，例如：

```bash
./encoder_example simple_input.txt codebook-1.csv encoded-1.bin \
    > encoder_simple_input.log 2> encoder_simple_input.err

./decoder_example encoded-1.bin codebook-1.csv output.txt \
    > decoder_simple_input.log 2> decoder_simple_input.err
```

在自己的 mini project 中，你可以：

1. 保留 `logger.h` / `logger.c`；
2. 刪除這裡的 `_example` 程式；
3. 在自己的 `encoder.c` / `decoder.c` 中：
   - `#include "logger.h"`
   - 依照作業說明的格式呼叫 `log_info` / `log_error` 輸出 log。
