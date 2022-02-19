/*-----------------------------------------------------------------------------------------------------
��ƽ    ̨��keil
���� �� �� Ƭ ����msp432P401R
���� �� �⡿TIVA WARE /msp432p4xx
���� ����eо������
/*@@ ������ο� ����Ը�
 *
 * �汾 v1.0
 * ʱ�� 2021��10��5��15:13:36
-------------------------------------------------------------------------------------------------------*/


/************************************************************************************
 *
 * ע�����������ΪMPU6050��������
 *           MPU6050 AD0���Žӵ� ������ַΪ0x68
 *           ��MPU6050ͨ�Ŵ���ʱ������P1.0LED(�����)����˸������IIC������������ַ����û���⣬��ϵ�����
 *           ��������ȫ���μ��ٶȼƣ����ݼ��ٶ�ֱ�ӵó����
 *************************************************************************************/



#include "headfile.h"


short MPU_ID,temp,gx,gy,gz,ax,ay,az;
float roll,yaw,pitch;
uint8 MPU_txt[50]={};//������ʾ
int8 Page=0;//��ǰҳ


void OLED_MPU_SHOW()
{
    if(Page % 3 == 0)
    {
        OLED_ShowString(11,0,"MPU_6050:Gyro  ");

        OLED_ShowString(0,1,"Gyrox:");
        sprintf(MPU_txt,"%d    ",gx);
        OLED_ShowString(41,1,MPU_txt);//��ʾx��Ǽ��ٶ�

        OLED_ShowString(0,2,"Gyroy:");
        sprintf(MPU_txt,"%d    ",gy);
        OLED_ShowString(41,2,MPU_txt);//��ʾy��Ǽ��ٶ�


        OLED_ShowString(0,3,"Gytoz:");
        sprintf(MPU_txt,"%d    ",gz);
        OLED_ShowString(41,3,MPU_txt);//��ʾz��Ǽ��ٶ�


        OLED_ShowString(0,4,"temp:");
        OLED_Showfloat(41,4,((float)temp/100));//������ǰ�¶�ֵ
    }
    else if(Page % 3 == 1)
    {
        OLED_ShowString(11,0,"MPU_6050:Acc  ");

        OLED_ShowString(0,1,"Accx:");
        sprintf(MPU_txt,"%d    ",ax);
        OLED_ShowString(41,1,MPU_txt);//��ʾx����ٶ�

        OLED_ShowString(0,2,"Accy:");
        sprintf(MPU_txt,"%d    ",ay);
        OLED_ShowString(41,2,MPU_txt);//��ʾy����ٶ�


        OLED_ShowString(0,3,"Accz:");
        sprintf(MPU_txt,"%d    ",az);
        OLED_ShowString(41,3,MPU_txt);//��ʾz����ٶ�


        OLED_ShowString(0,4,"temp:");
        OLED_Showfloat(41,4,((float)temp/100));//������ǰ�¶�ֵ
    }
    else
    {
        OLED_ShowString(11,0,"MPU_6050:Angle  ");

        OLED_ShowString(0,1,"Pitch:");
        sprintf(MPU_txt,"%.2f    ",pitch);
        OLED_ShowString(41,1,MPU_txt);//��ʾx����ٶ�

        OLED_ShowString(0,2,"Roll:");
        sprintf(MPU_txt,"%.2f    ",roll);
        OLED_ShowString(41,2,MPU_txt);//��ʾy����ٶ�


        OLED_ShowString(0,3,"Yaw:");
        sprintf(MPU_txt,"%.2f    ",yaw);
        OLED_ShowString(41,3,MPU_txt);//��ʾz����ٶ�


        OLED_ShowString(0,4,"temp:");
        OLED_Showfloat(41,4,((float)temp/100));//������ǰ�¶�ֵ
    }
    if(!key_get(KEY1))
    {
        delay_ms(10);
        Page--;
        OLED_Clear();//����
        if(Page == -1)
            Page=3;
        while(!key_get(KEY1));
    }
    if(!key_get(KEY2))
    {
        delay_ms(10);
        Page++;
        OLED_Clear();//����
        if(Page == 3)
            Page=0;
        while(!key_get(KEY2));
    }
}

int main()
{
    system_init(1);//��ʼ���δ��ʱ��
    set_DCO_48MH();
    gpio_init(GPIO_PORT_P1,GPIO_PIN0,GPO,0);//��ʼ��LED  IO��
    OLED_Init();//OLED��ʼ��
    OLED_Clear();//����
    MPU_init();//MPU6050�Ĵ�����ʼ��
    key_init(KEY1|KEY2);//��ʼ������S1��S2���ڷ�ҳ

    while(1)
    {
        temp= MPU_Get_Temp();                     //��ȡ�������¶�
        MPU_Get_Gyro(&gx,&gy,&gz);                //��ȡ������ԭʼ����
        MPU_Get_Acc(&ax,&ay,&az);                 //��ȡԭʼ���ٶ�����
        MPU_Get_Angel(ax,ay,az,&roll,&pitch,&yaw);//ͨ�����ٶȻ���Ƕ�����
        OLED_MPU_SHOW();
    }
		return 0 ;
}