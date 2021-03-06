/*-----------------------------------------------------------------------------------------------------
【平    台】keil
【适 用 单 片 机】msp432P401R
【底 层 库】TIVA WARE /msp432p4xx
【开 发】e芯工作室
/*@@ 库仅供参考 后果自负
 *
 * 版本 v1.0
 * 时间 2021年2月23日22:29:47
-------------------------------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------------------------
滴答计时器测试
1.按键触发时间（电平时长）
2.秒表
按下key2转换
-------------------------------------------------------------------------------------------------------*/
#include "headfile.h"
char change_flag=0;
float press_time=0;
int main()
{
    system_init(1);//1:初始化滴答计时器
    set_DCO_48MH();
    OLED_Init();//OLED初始化
    key_init(KEY1|KEY2);
    gpio_init(GPIO_PORT_P1, GPIO_PIN0,GPO,1);//方向
    while(1)
    {
        if(!change_flag)//检测按键s1按下时间
        {
           OLED_ShowString(0,2,"KEY1:");
           OLED_Showfloat(64,2,press_time);
            if(key_get(KEY1)==0)
            {
                delay_ms(10);
                if(key_get(KEY1)==0)
                {
                    systic_start();//若检测到按键s1按下，则开始计时
                    while(!key_get(KEY1));
                    systic_end();//按键松开停止计时
                    press_time=(float)(systic_read( s)+(float)(systic_read(ms)%1000)/1000);//将计时器读取的时间转换为s
                }
            }
        }
        else//秒表
        {
            OLED_ShowString(96,0,"Ms");
            OLED_ShowString(48,0,"Sec");
            OLED_ShowString(0,0,"Min:");
            OLED_ShowNum(90, 1, (int)(systic_read(ms) / 10 % 100),3,12);//毫秒
            OLED_ShowNum(42,1,(int)(systic_read(s) % 60),2,12);//秒
            OLED_ShowNum(0,1,(int)(systic_read(s) / 60),2,12);//分
        }
        if(key_get(KEY2)==0)//按键key2用以状态切换
        {
           delay_ms(10);
           if(key_get(KEY2)==0)
           {
               change_flag=!change_flag;
               OLED_Clear();
               systic_end();
               if(change_flag)
               {
                   systic_start();//开启计时器
               }
               else
               {
                   systic_clr();//计数值清零
               }
               while(!key_get(KEY2));
           }
        }
    }
		return 0 ;
}
