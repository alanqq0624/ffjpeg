#ifndef __FFJPEG_DCT_H__
#define __FFJPEG_DCT_H__

#ifdef __cplusplus
extern "C" {
#endif

/* 函數聲明 */
/* 二維 8x8 的 DCT 變換函數 */
void init_dct_module(void);
void init_fdct_ftab(int *ftab, int *qtab);
void init_idct_ftab(int *ftab, int *qtab);
void fdct2d8x8(int *du, int *ftab);
void idct2d8x8(int *du, int *ftab);

#ifdef __cplusplus
}
#endif

#endif

