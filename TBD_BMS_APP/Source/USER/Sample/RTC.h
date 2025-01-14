/****************************************************************************/
/* 	File    	RTC.h 			 
 * 	Author		Hollis
 *	Notes		用于替代原来的 PCF85063 的功能
 * 
 *	Version		Date    		Change Logs:
 *  V1.0.0 		2021-07-04		first version         	
 * 	
 * Copyright (c) 2021, Immotor
*****************************************************************************/
#ifndef _RTC_H
#define _RTC_H

//=============================================================================================
//包含头文件
//=============================================================================================
#include "BSPTypeDef.h"


//=============================================================================================
//数据结构定义
//=============================================================================================
//RTC的iic读写状态枚举
typedef	enum
{ 
	eRTCRead = 0, 
	eRTCWrite = 1
}e_RTCWR;

//时间日期结构体
typedef struct _PCF85063_DATE
{
   u8  year;
   u8  month;
   u8  day;
   u8  hour;
   u8  minute;
   u8  second;
   //u8  week;     //保留，后面可以去除
}t_PCF85063_DATE;

//RTC运行相关结构体
typedef struct _RTC_COND
{
//   u8  rtcchn;      //RTC通道
   u8  ctrl;	    //RTC控制字节，控制读取时间和校准时间
   u8  err;         //RTC通信错误计数器
//   u8  iicres;      //阻塞时使用变量，用于等待IIC通信的结果
   //u8  runflag;   //RTC读取或校准运行标志，0，未运行或运行完成，1，正在读取
   u8  calflag;     //RTC校准标志：0:未校准；1：校准
}t_PCF85063_COND;

//=============================================================================================
//宏定义
//=============================================================================================
//=============================================================================================
#define		PCF85063_IIC_CHANNEL		eIIC1	//RTC使用IIC1通道

#define		PCF85063_IIC_NOFAULT_STAT	0		//IIC通信无错误状态
#define		PCF85063_IIC_FAULT_STAT		1		//IIC通信错误状态

#define		PCF85063_READBUFF_LEN		10		//读数组缓存长度
#define		PCF85063_WRITEBUFF_LEN		10		//写数组缓存长度

#define		PCF85063_WRITE_ADDR			0XA2	//读取8位地址
#define		PCF85063_READ_ADDR			PCF85063_WRITE_ADDR | 0x01

#define		PCF85063_COMM_FAULT_CNT		100
#define		PCF85063_MAX_WAIT_TIMEOUT	50000	//最大等待时间，超过这个时间，直接回复错误信号
#define		PCF85063_MAX_TIMEOUT		10000	//最大等待时间，超过这个时间，直接回复错误信号
#define		PCF85063_PT_MAX_TIMEOUT		200		//最大等待时间，超过这个时间，直接回复错误信号，单位ms

//=============================================================================================
//配置位参数
#define		PCF85063_START_READ			0X01        //开始获取时间位置
#define		PCF85063_START_WRITE		0X02        //开始校准时间位置

//=============================================================================================
//PCF85063 IC寄存器地址
#define 	PCF85063_CONTROL1_ADDR   	0x00	//控制和状态寄存器1地址
#define 	PCF85063_CONTROL2_ADDR  	0x01	//控制和状态寄存器2地址
#define 	PCF85063_OFFSET_ADDR     	0x02	//偏移寄存器地址
#define 	PCF85063_RAM_ADDR    		0x03	//RAM 字节寄存器地址

#define 	PCF85063_SECOND_ADDR      	0x04 	//秒寄存器地址
#define 	PCF85063_MINUTE_ADDR      	0x05	//分寄存器地址
#define 	PCF85063_HOUR_ADDR        	0x06	//时寄存器地址
#define 	PCF85063_DAY_ADDR        	0x07	//日寄存器地址
#define 	PCF85063_WEEK_ADDR        	0x08	//周寄存器地址
#define 	PCF85063_MONTH_ADDR       	0x09	//月寄存器地址
#define 	PCF85063_YEAR_ADDR        	0x0A	//年寄存器地址

#define     PCF85063_OS_MASK            0x80    //指示时钟是否校准的标志位；0：已校准；1：未校准

//=============================================================================================
// 数据转换
#define 	PCF85063_BCD_to_HEC(b)  	(((b >> 4) * 10) + (b & 0x0f))	//BCD数转为16进制
#define  	PCF85063_HEC_to_BCD(h)  	(((h / 10) << 4) | (h % 10))	//16进制转为BCD数

//=============================================================================================
//全局变量声明，供外部调用
//=============================================================================================
extern t_PCF85063_DATE    gRdTimeAndDate; //读时间日期结构体
extern t_PCF85063_DATE    gWrTimeAndDate; //写时间日期结构体
extern t_PCF85063_COND    gRTCCond;       //RTC芯片控制/状态结构体

//=============================================================================================
//声明接口函数
//=============================================================================================
//=============================================================================================
//函数名称	: u8 PCF85063Init(void)
//输入参数	: void
//输出参数	: 初始化是否成功，TURE:成功  FALSE:失败
//静态变量	: void
//功    能	: PCF85063初始化函数
//注    意	:
//=============================================================================================
u8 PCF85063Init(void);

//=============================================================================================
//函数名称	: void PCF85063ClearCtrl(u8 ctrl)
//输入参数	: ctrl:控制位，详细定义见头文件宏定义
//输出参数	: void
//静态变量	: void
//功	能	: PCF85063设置控制标志位函数
//注	意	:
//=============================================================================================
void PCF85063SetCtrl(u8 ctrl);

//=============================================================================================
//函数名称	: void PCF85063ClearCtrl(u8 ctrl)
//输入参数	: ctrl:控制位，详细定义见头文件宏定义
//输出参数	: void
//静态变量	: void
//功	能	: PCF85063清除控制标志位函数
//注	意	:
//=============================================================================================
void PCF85063ClearCtrl(u8 ctrl);

//=============================================================================================
//函数名称	: u8 PCF85063Start(void)
//输入参数	: void
//输出参数	: 是否运行成功，0：运行成功，1：运行失败
//静态变量	: void
//功    能	: PCF85063 RTC正常运行
//注    意	:
//=============================================================================================
//u8 PCF85063Start(void);

//=============================================================================================
//函数名称	: u8 PCF85063Stop(void)
//输入参数	: void
//输出参数	: 是否停止成功，0：停止成功，1：停止失败
//静态变量	: void
//功    能	: PCF85063 RTC停止运行
//注    意	:
//=============================================================================================
//u8 PCF85063Stop(void);

//=============================================================================================
//函数名称	: u8 PCF85063SetDate(t_PCF85063_DATE *tp)
//输入参数	: tp:写入的时间日期指针
//输出参数	: 是否写入成功，0：写入成功，1：写入失败
//静态变量	: void
//功    能	: PCF85063写入时间函数
//注    意	:
//=============================================================================================
u8 PCF85063SetDate(t_PCF85063_DATE *tp);

//=============================================================================================
//函数名称	: u8 PCF85063ReadDate(t_PCF85063_DATE *tp)
//输入参数	: tp:读取的时间日期指针
//输出参数	: 是否读取成功，0：读取成功，1：读取失败
//静态变量	: void
//功    能	: PCF85063读取时间函数
//注    意	:
//=============================================================================================
u8 PCF85063ReadDate(t_PCF85063_DATE *tp);

//=============================================================================================
//函数名称	: void PCF85063MainTask(void *p)
//输入参数	: void
//输出参数	: void
//静态变量	: void
//功	能	: PCF85063获取或处理时间函数
//注	意	:
//=============================================================================================
void PCF85063MainTask(void *p);

#endif

/*****************************************end of PCF85063.h*****************************************/
