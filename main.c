#include <reg52.h>

/* 红外传感器 */
sbit LEFT_SENSOR  = P3^2;
sbit RIGHT_SENSOR = P3^3;

/* 电机驱动引脚 */
sbit IN1 = P1^0;
sbit IN2 = P1^1;
sbit IN3 = P1^2;
sbit IN4 = P1^3;

/* 小车前进 */
void forward(void)
{
    IN1 = 1;
    IN2 = 0;

    IN3 = 1;
    IN4 = 0;
}

/* 小车左转 */
void turn_left(void)
{
    IN1 = 0;
    IN2 = 0;

    IN3 = 1;
    IN4 = 0;
}

/* 小车右转 */
void turn_right(void)
{
    IN1 = 1;
    IN2 = 0;

    IN3 = 0;
    IN4 = 0;
}

/* 小车停止 */
void stop_car(void)
{
    IN1 = 0;
    IN2 = 0;

    IN3 = 0;
    IN4 = 0;
}

void main(void)
{
    while(1)
    {
        /*
         * 传感器输出为 0，表示检测到黑线
         */

        if(LEFT_SENSOR == 1 && RIGHT_SENSOR == 1)
        {
            /* 两边都没有检测到黑线，小车前进 */
            forward();
        }
        else if(LEFT_SENSOR == 0 && RIGHT_SENSOR == 1)
        {
            /* 左边检测到黑线，小车左转 */
            turn_left();
        }
        else if(LEFT_SENSOR == 1 && RIGHT_SENSOR == 0)
        {
            /* 右边检测到黑线，小车右转 */
            turn_right();
        }
        else
        {
            /* 两边都检测到黑线，小车停止 */
            stop_car();
        }
    }
}
