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
电机测试例程
通道：C、D
C：方向引脚8.6 pwm:p2.5
C：方向引脚8.7 pwm:p2.4
-------------------------------------------------------------------------------------------------------*/
#include "headfile.h"

int main()
{
    system_init(0);
    set_DCO_48MH();
    MOTOR_TEST();
    while(1);
	return 0 ;
}
