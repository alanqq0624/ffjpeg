#ifndef __FFJPEG_BMP_H__
#define __FFJPEG_BMP_H__

#ifdef __cplusplus
extern "C" {
#endif

/* 類型定義 */
/* BMP 對象的類型定義 */
typedef struct
{
    int   width;   /* 寬度 */
    int   height;  /* 高度 */
    int   stride;  /* 行字節數 */
    void *pdata;   /* 指向數據 */
} BMP;

/* 函數聲明 */
int  bmp_load  (BMP *pb, char *file);
int  bmp_create(BMP *pb, int w, int h);

int  bmp_save(BMP *pb, char *file);
void bmp_free(BMP *pb);

#ifdef __cplusplus
}
#endif

#endif

