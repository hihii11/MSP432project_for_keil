/*-----------------------------------------------------------------------------------------------------
【平    台】keil
【适 用 单 片 机】msp432P401R
【底 层 库】TIVA WARE /msp432p4xx
【开 发】e芯工作室
/*@@ 库仅供参考 后果自负
 *
 * 版本 v1.0
 * 时间 2020年10月23日22:29:47
-------------------------------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------------------------
OLED显示例程
D0: P6.0
D1: P4.3
DC: P6.1
CS: P1.5
RES:P4.0
-------------------------------------------------------------------------------------------------------*/
#include "headfile.h"

int main()
{
    system_init(0);
    set_DCO_48MH();
    OLED_Init();
    OLED_SHOW();
    while(1);
	return 0 ;
}
