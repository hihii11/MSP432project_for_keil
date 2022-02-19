//////////////////////////////////////////////////////////////////////////////////
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//�о�԰����
//���̵�ַ��http://shop73023976.taobao.com/?spm=2013.1.0.0.M4PqC2
//
//  �� �� ��   : oled.c
//  �� �� ��   : v2.0
//  ��    ��   : HuangKai
//  ��������   : 2014-0101
//  ����޸�   :
//  ��������   : 0.96��OLED �ӿ���ʾ����(MSP430F5438Aϵ��)
//  ����IC     :SSD1306
//              ˵��:
//              ----------------------------------------------------------------
//              GND    ��Դ��
//              VCC  ��3.3v��Դ
//              D0(SCL)   P86��ʱ�ӣ�
//              D1(SDA)  P84�����ݣ�
//              RES  ��P83
//              DC   ��P91
//              CS   ��P93
//              ----------------------------------------------------------------
// �޸���ʷ   :
// ��    ��   :
// ��    ��   : HuangKai
// �޸�����   : �����ļ�
//��Ȩ���У�����ؾ���
//Copyright(C) �о�԰����2018/3/16
//All rights reserved
//******************************************************************************/
#ifndef __OLED_H
#define __OLED_H

#include "dat.h"

extern uint8 screen_buf[128][64];
extern unsigned char bmp[1024];
extern void oled_update(char mode);
extern void OLED_PutPixel(unsigned char x,unsigned char y);
extern void OLED_pos_clr(unsigned char x,unsigned char y);
extern void OLED_Showfloat(unsigned char x, unsigned char y, float din);
#define uint8 unsigned char
#define uint32 unsigned int
#define OLED_CMD 0  //д����
#define OLED_DATA 1 //д����

//----------------------------------------------------------------------------------
//OLED SSD1306 SPI  ʱ��D0
//#define       OLED_SSD1306_SCLK_DIR           (P1DIR)
//#define       OLED_SSD1306_SCLK_OUT           (P1OUT)
#define OLED_SSD1306_SCLK_PIN_NUM (GPIO_PIN0)
#define OLED_SSD1306_SCLK_PORT_NUM (GPIO_PORT_P6)

#define OLED_SSD1306_SCLK_IO_INIT (gpio_set_Asout(OLED_SSD1306_SCLK_PORT_NUM, OLED_SSD1306_SCLK_PIN_NUM))
#define OLED_SCLK_Set() (gpio_set_High(OLED_SSD1306_SCLK_PORT_NUM, OLED_SSD1306_SCLK_PIN_NUM))
#define OLED_SCLK_Clr() (gpio_set_Low(OLED_SSD1306_SCLK_PORT_NUM, OLED_SSD1306_SCLK_PIN_NUM))

//----------------------------------------------------------------------------------
//OLED SSD1306 SPI ����D1
//#define       OLED_SSD1306_SDIN_DIR           (P1DIR)
//#define       OLED_SSD1306_SDIN_OUT           (P1OUT)
#define OLED_SSD1306_SDIN_PIN_NUM (GPIO_PIN3)
#define OLED_SSD1306_SDIN_PORT_NUM (GPIO_PORT_P4)//3.2

#define OLED_SSD1306_SDIN_IO_INIT (gpio_set_Asout(OLED_SSD1306_SDIN_PORT_NUM, OLED_SSD1306_SDIN_PIN_NUM))
#define OLED_SDIN_Set() (gpio_set_High(OLED_SSD1306_SDIN_PORT_NUM, OLED_SSD1306_SDIN_PIN_NUM))
#define OLED_SDIN_Clr() (gpio_set_Low(OLED_SSD1306_SDIN_PORT_NUM, OLED_SSD1306_SDIN_PIN_NUM))

//----------------------------------------------------------------------------------
//OLED SSD1306 ����/����DC
//#define       OLED_SSD1306_DC_DIR             (P1DIR)
//#define       OLED_SSD1306_DC_OUT             (P1OUT)
#define OLED_SSD1306_DC_PIN_NUM (GPIO_PIN1)
#define OLED_SSD1306_DC_PORT_NUM (GPIO_PORT_P6)

#define OLED_SSD1306_DC_IO_INIT (gpio_set_Asout(OLED_SSD1306_DC_PORT_NUM, OLED_SSD1306_DC_PIN_NUM))
#define OLED_DC_Set() (gpio_set_High(OLED_SSD1306_DC_PORT_NUM, OLED_SSD1306_DC_PIN_NUM))
#define OLED_DC_Clr() (gpio_set_Low(OLED_SSD1306_DC_PORT_NUM, OLED_SSD1306_DC_PIN_NUM))

//----------------------------------------------------------------------------------
//OLED SSD1306 ??ƬѡCS
//#define       OLED_SSD1306_CE_DIR             (P1DIR)
//#define       OLED_SSD1306_CE_OUT             (P1OUT)
#define OLED_SSD1306_CE_PIN_NUM (GPIO_PIN5)
#define OLED_SSD1306_CE_PORT_NUM (GPIO_PORT_P1)

#define OLED_SSD1306_CE_IO_INIT (gpio_set_Asout(OLED_SSD1306_CE_PORT_NUM, OLED_SSD1306_CE_PIN_NUM))
#define OLED_CS_Set() (gpio_set_High(OLED_SSD1306_CE_PORT_NUM, OLED_SSD1306_CE_PIN_NUM))
#define OLED_CS_Clr() (gpio_set_Low(OLED_SSD1306_CE_PORT_NUM, OLED_SSD1306_CE_PIN_NUM))

//----------------------------------------------------------------------------------
//OLED SSD1306 ��λ/RES
//#define       OLED_SSD1306_RST_DIR            (P2DIR)
//#define       OLED_SSD1306_RST_OUT            (P1OUT)
#define OLED_SSD1306_RST_PIN_NUM (GPIO_PIN0)
#define OLED_SSD1306_RST_PORT_NUM (GPIO_PORT_P4)

#define OLED_SSD1306_RST_IO_INIT (gpio_set_Asout(OLED_SSD1306_RST_PORT_NUM, OLED_SSD1306_RST_PIN_NUM))
#define OLED_RST_Set() (gpio_set_High(OLED_SSD1306_RST_PORT_NUM, OLED_SSD1306_RST_PIN_NUM))
#define OLED_RST_Clr() (gpio_set_Low(OLED_SSD1306_RST_PORT_NUM, OLED_SSD1306_RST_PIN_NUM))

#define SIZE 16
#define XLevelL 0x02
#define XLevelH 0x10
#define Max_Column 128
#define Max_Row 64
#define Brightness 0xFF
#define X_WIDTH 128
#define Y_WIDTH 64
//-----------------OLED�˿ڶ���----------------

//OLED�����ú���
void OLED_PutPixel(unsigned char x,unsigned char y);
void OLED_WR_Byte(uint8 dat, uint8 cmd);
void OLED_Display_On(void);
void OLED_Display_Off(void);
void OLED_Init(void);
void OLED_Clear(void);
void OLED_DrawPoint(uint8 x, uint8 y, uint8 t);
void OLED_Fill(uint8 x1, uint8 y1, uint8 x2, uint8 y2, uint8 dot);
void OLED_ShowChar(uint8 x, uint8 y, uint8 chr);
void OLED_ShowNum(uint8 x, uint8 y, uint32 num, uint8 len, uint8 size2);
void OLED_ShowString(uint8 x, uint8 y, uint8 *p);
void OLED_Set_Pos(unsigned char x, unsigned char y);
void OLED_ShowCHinese(uint8 x, uint8 y, uint8 no);
void OLED_DrawBMP(unsigned char x0, unsigned char y0, unsigned char x1,
                  unsigned char y1, unsigned char BMP[]);
#endif
