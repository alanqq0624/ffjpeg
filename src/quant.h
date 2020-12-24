#ifndef __FFJPEG_QUANT_H__
#define __FFJPEG_QUANT_H__

#ifdef __cplusplus
extern "C" {
#endif

/* 全局變量聲明 */
extern const int STD_QUANT_TAB_LUMIN[64];
extern const int STD_QUANT_TAB_CHROM[64];

/* 函數聲明 */
void quant_encode(int du[64], int qtab[64]);
void quant_decode(int du[64], int qtab[64]);

#ifdef __cplusplus
}
#endif

#endif

