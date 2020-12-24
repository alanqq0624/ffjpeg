#ifndef __FFJPEG_ZIGZAG_H__
#define __FFJPEG_ZIGZAG_H__

#ifdef __cplusplus
extern "C" {
#endif

/* 全局變量聲明 */
extern const int ZIGZAG[64];

/* 函數聲明 */
void zigzag_encode(int *data);
void zigzag_decode(int *data);

#ifdef __cplusplus
}
#endif

#endif

