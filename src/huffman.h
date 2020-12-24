#ifndef __FFJPEG_HUFFMAN_H__
#define __FFJPEG_HUFFMAN_H__

/* 包含頭文件 */
#include "stdefine.h"

#ifdef __cplusplus
extern "C" {
#endif

/* 常量定義 */
#define MAX_HUFFMAN_CODE_LEN  16

extern const BYTE STD_HUFTAB_LUMIN_AC[];
extern const BYTE STD_HUFTAB_LUMIN_DC[];
extern const BYTE STD_HUFTAB_CHROM_AC[];
extern const BYTE STD_HUFTAB_CHROM_DC[];

/* 類型定義 */
/* 編碼表項類型定義 */
typedef struct
{
    int symbol; /* 符號 */
    int freq;   /* 頻率 */
    int group;  /* 分組 */
    int depth;  /* 碼長 */
    int code;   /* 碼字 */
} HUFCODEITEM;

/* 編碼器類型定義 */
typedef struct
{
    BYTE         huftab[MAX_HUFFMAN_CODE_LEN + 256]; /* 哈夫曼表 */
    int          first [MAX_HUFFMAN_CODE_LEN];       /* first   */
    int          index [MAX_HUFFMAN_CODE_LEN];       /* index   */
    HUFCODEITEM  codelist[256];/* 編碼表 */
    void        *input;        /* input bit stream  */
    void        *output;       /* output bit stream */
} HUFCODEC;


/* 函數聲明 */
/* 標準的符號頻率統計器 */
void huffman_stat_freq(HUFCODEITEM codelist[256], void *stream);


/* 編碼 */
/*
  編碼方法：
      1. 初始化 HUFCODEC 中的 freqlist 成員，可以採用
         huffman_stat_freq 進行頻率統計，也可以自己編
         碼實現頻率統計

      2. 調用 huffman_encode_init 函數將會生成 huftab,
         codelist 分別對應了哈夫曼表 (JPEG format) 和
         編碼表

      3. 指定 input 和 output 分別代表編碼過程中的輸入
         數據流和輸出數據流

      4. 調用 huffman_encode_run 可以完成自動的編碼操
         作編碼的結束條件是 input 或 output 到達了尾部

      5. 調用 huffman_encode_done 結束哈夫曼編碼

      6. 也可以通過 huffman_encode_step 進行單步的哈夫
         曼編碼操作
 */
// flag == 0, init from code freq list
// flag == 1, init from huffman table
void huffman_encode_init(HUFCODEC *phc, int flag);
void huffman_encode_done(HUFCODEC *phc);
BOOL huffman_encode_run (HUFCODEC *phc);

/* 一次只編碼一個符號 */
BOOL huffman_encode_step(HUFCODEC *phc, int symbol);


/* 解碼 */
/*
  解碼方法：
      1. 初始化 HUFCODEC 中的 huftab 成員，huftab
         是 JPEG format 的範式哈夫曼表

      2. 調用 huffman_decode_init 將會根據 huftab
         生成 first 和 index 兩個表

      3. 指定 input 和 output 分別代表解碼過程中的輸
         入數據流和輸出數據流

      4. 調用 huffman_decode_run 可以完成自動的解碼
         操作解碼的結束條件是 input 或 output 到達了
         尾部

      5. 調用 huffman_decode_done 結束哈夫曼解碼

      6. 也可以通過 huffman_decode_step 進行單步
         的哈夫曼解碼操作，該函數每次調用只會從數
         據流中解碼出一個符號
 */
void huffman_decode_init(HUFCODEC *phc);
void huffman_decode_done(HUFCODEC *phc);
BOOL huffman_decode_run (HUFCODEC *phc);

/* 一次只解碼一個符號 */
int  huffman_decode_step(HUFCODEC *phc);

#ifdef __cplusplus
}
#endif

#endif

