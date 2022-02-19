/*-----------------------------------------------------------------------------------------------------
��ƽ    ̨��keil
���� �� �� Ƭ ����msp432P401R
���� �� �⡿TIVA WARE /msp432p4xx
���� ����eо������
/*@@ ������ο� ����Ը�
 *
 * �汾 v1.0
 * ʱ�� 2021��10��5��19:47:48
-------------------------------------------------------------------------------------------------------*/


/************************************************************************************
 *
 * ע�����������ΪMPU6050��ͨ�˲�����̬��������
 *           MPU6050 AD0���Žӵ� ������ַΪ0x68
 *           ��MPU6050ͨ�Ŵ���ʱ������P1.0LED(�����)����˸������IIC������������ַ����û���⣬��ϵ�����
 *           ��������ȫ���μ��ٶȼƣ����ݻ����˲��õ����
 *           ����Ϊlaunch pad usb�ӿڣ��򿪴��ڵ������֣��۲�Ƕ�ֵ
 *           ������:115200
 *************************************************************************************/



#include "headfile.h"

/*���ٶ����ֵ,�����Ǿ�ֹ��������Ľ��ٶ�ֵ*/
#define Gyrox_erro          -36   //x����ٶ����
#define Gyroy_erro          -27   //y�����
#define Gyroz_erro          -37   //z�����

short MPU_ID,temp,gx,gy,gz,ax,ay,az;
float roll,yaw,pitch,yaw_mid;
int8 Page=0;//��ǰҳ
char txt[80]={};

void MPU_Low_fillter_Get_Angle()//��ͨ�˲�����������
{
    float acc_roll,acc_pitch,acc_yaw;

    float a = 0.9;//�����˲�ϵ��
    MPU_Get_Gyro(&gx,&gy,&gz);
    MPU_Get_Acc(&ax,&ay,&az);

    MPU_Get_Angel(ax,ay,az,&acc_roll,&acc_pitch,&acc_yaw);

    roll =(a*(roll+(gy-Gyroy_erro)*0.005)+(1-a)*acc_roll);//5ms
    pitch =(a*(pitch+(gx-Gyrox_erro)*0.005)+(1-a)*acc_pitch);//5ms
    yaw =((yaw+(gz-Gyroz_erro)*0.005));//5ms
}

void MPU6050_uart_send()//MPU6050�������̬���ͳ���
{
    sprintf(txt,"PITCH:%.2f ",pitch);
    UART_send_string(UART0,txt);
		sprintf(txt,"ROLL:%.2f ",roll);
		UART_send_string(UART0,txt);
		sprintf(txt,"YAW:%.2f \n",yaw);
		UART_send_string(UART0,txt);
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
    UART_init(UART0,115200);//��ʼ������
    TimerA_CCR0INT_init(TIMERA_A1 , 5);//ÿ500ms����һ������
    Interrupt_setPriority(INT_TA1_0, 0x80);//���Ե�����һ����������ʱ���ж����ȼ�

    while(1)
    {

    }
		return 0 ;
}
