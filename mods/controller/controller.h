/*
 * controller.h
 *
 *  Created on: Sep 28, 2016
 *      Author: lidq
 */

#ifndef MODS_CONTROLLER_CONTROLLER_H_
#define MODS_CONTROLLER_CONTROLLER_H_

#include <typedef.h>

//摇控器接收机的4个通道引脚
#define GPIO_FB						(12)
#define GPIO_LR						(14)
#define GPIO_PW						(13)
#define GPIO_MD						(1)
#define GPIO_UD						(5)
#define GPIO_DI						(4)

//摇控器接收机的4个通道读数范围
#define CTL_PWM_MIN					(980)
#define CTL_PWM_MAX					(2020)
//摇控器幅度通道比例范围,通过此通道来修改方向通道的数值比例
#define CTL_DI_MIN					(1000)
#define CTL_DI_MAX					(2000)
//最大倾斜角
#define MAX_ANGLE					(45)

typedef struct
{
	struct timeval timer_start;
	struct timeval timer_end;
} s_ctl_pwm;

int __init(s_engine *engine, s_params *params);

int __destory(s_engine *e, s_params *p);

int __status();

void controller_ctl_pwm(int gpio_port, s_ctl_pwm *ctl_pwm);

//读取摇控器接收机的PWM信号“前后”
void controller_ctl_pwm_fb();

//读取摇控器接收机的PWM信号“左右”
void controller_ctl_pwm_lr();

//读取摇控器接收机的PWM信号“油门”
void controller_ctl_pwm_pw();

//读取摇控器接收机的PWM第4通道
void controller_ctl_pwm_md();

//读取摇控器接收机的PWM第5通道
void controller_ctl_pwm_ud();

//读取摇控器接收机的PWM方向舵比例缩放通道
void controller_ctl_pwm_di();

//读入摇控器“前/后”的PWM信号
void controller_fb_pwm(int fb);

//读入摇控器“左/右”的PWM信号
void controller_lr_pwm(int lr);

//读入摇控器“油门”的PWM信号
void controller_pw_pwm(int pw);

//读入摇控器第4通道的PWM信号
void controller_md_pwm(int md);

//读入摇控器第5通道的PWM信号
void controller_ud_pwm(int md);

//读入摇控器方向舵比例缩放通道的PWM信号
void controller_di_pwm(int md);

//取绝对值
float controller_abs(float x);

//二次曲线函数
float controller_parabola(float x);

/***
 * est预估值
 * est_devi预估偏差
 * measure测量读数
 * measure_devi测量噪声
 * devi上一次最优偏差
 */
float controller_kalman_filter(float est, float est_devi, float measure, float measure_devi, float *devi);

#endif /* MODS_CONTROLLER_CONTROLLER_H_ */
