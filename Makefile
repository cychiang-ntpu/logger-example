# 編譯器設定
CC = gcc
# 編譯旗標：使用 C99 標準，開啟所有警告，優化等級 2
CFLAGS = -std=c99 -Wall -Wextra -O2

# 共用的目標檔案
OBJS = logger.o

# 預設目標：編譯所有範例程式
all: encoder_example decoder_example

# 編譯 logger.o：從 logger.c 和 logger.h 生成
logger.o: logger.c logger.h
	$(CC) $(CFLAGS) -c logger.c

# 編譯 encoder_example：需要 encoder_example.c 和 logger.o
encoder_example: encoder_example.c $(OBJS)
	$(CC) $(CFLAGS) -o encoder_example encoder_example.c $(OBJS)

# 編譯 decoder_example：需要 decoder_example.c 和 logger.o
decoder_example: decoder_example.c $(OBJS)
	$(CC) $(CFLAGS) -o decoder_example decoder_example.c $(OBJS)

# 清除所有編譯產物
clean:
	rm -f encoder_example decoder_example $(OBJS)

# 測試目標：用正確的參數執行兩個範例程式
# - encoder: 讀取 input.txt，產生 codebook.txt 和 encoded.bin
# - decoder: 讀取 encoded.bin 和 codebook.txt，產生 output.txt
test: all
	@echo "Running encoder_example..."
	./encoder_example input.txt codebook.txt encoded.bin
	@echo "\nRunning decoder_example..."
	./decoder_example encoded.bin codebook.txt output.txt

# 錯誤測試目標：故意給錯誤的參數數量來測試 error log
# - 前面的 '-' 符號表示即使命令失敗也繼續執行
test-error: all
	@echo "Testing encoder_example with wrong arguments (should produce error log)..."
	-./encoder_example input.txt
	@echo "\nTesting decoder_example with wrong arguments (should produce error log)..."
	-./decoder_example encoded.bin

# 宣告這些目標不是實際的檔案名稱
.PHONY: all clean test test-error
