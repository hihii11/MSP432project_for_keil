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
编码器测试例程
AB相编码器
编码器A接口：A：P4.4  B：P4.5
编码器B接口：A：P3.0  B：P2.3
-------------------------------------------------------------------------------------------------------*/
#include "headfile.h"

int main()
{
    system_init(0);
    set_DCO_48MH();
    ENCODER_TEST();//编码器测试例程
	
	return 0 ;
}
