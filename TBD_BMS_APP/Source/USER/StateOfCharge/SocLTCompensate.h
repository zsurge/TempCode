//=======================================Copyright(c)===========================================
// 								  深圳易马达科技有限公司
//---------------------------------------文件信息----------------------------------------------
//文件名   	: SocLTCompensate.h
//创建人  	: Handry
//创建日期	:
//描述	    : SOC 低温补偿模块头文件
//-----------------------------------------------当前版本修订----------------------------------
//修改人   	:
//版本	    :
//修改日期	:
//描述	    :
//=============================================================================================
#ifndef _SOCLTCOMPENSATE_H
#define _SOCLTCOMPENSATE_H

//=============================================================================================
//包含头文件
//=============================================================================================
#include "BSPTypedef.h"

//=============================================================================================
//宏参数设定
//=============================================================================================
#define SOC_LT_COMPENSATE_ENABLE    1   //低温补偿使能
#define SOC_LT_COMPENSATE_POINT_NUM 3   //低温补偿点数

#define SOC_LT_COMPENSATE_PERIOD    5   //SOC 低温补偿周期
#define SOC_LT_COMPENSATE_TEMP	    0   //SOC 低温补偿温度 0℃
#define SOC_LT_COMPENSATE_RES_TEMP	30  //SOC 低温补偿恢复温度 3℃

//=============================================================================================
//定义数据类型
//=============================================================================================
//不同温度对应的补偿系数点
typedef struct
{
    s16 temp;   //温度
    u16 factor; //补偿系数
}t_ComPensatePoint;

//SOC 低温补偿结构体
typedef struct
{
	union
	{
		struct
		{
			u8 IsRdyOCV : 1;	//OCV条件    
			u8 IsLowTemp : 1;	//低温条件
			u8 IsCalFactor : 1;	//可以计算系数
			u8 IsNeedComp : 1;	//需要进入低温补偿
			u8 IsFirstComp: 1;	//第一次进入补偿
			u8 RVSD : 3;  //保留
		}CompStateBit;
		u8 CompStateByte;
	}CompState;
	u8 Timer;			//计数器
	s16 SumTemp;		//计算平均温度用的温度和
	s16  LastCompTemp;  //上次温度
	s16  CompTemp;      //当前温度
	u16  CompFactor;    //计算的补偿系数
	float CompSlope;    //温度补偿斜率

	u32 LtcAllCap;		//保存上次的总容量
}t_ComPensateCrt;

//=============================================================================================
//声明外部变量
//=============================================================================================
extern t_ComPensateCrt SocCompCrt;	//SOC低温补偿结构

//=============================================================================================
//声明接口函数
//=============================================================================================

//=============================================================================================
//函数名称	: void SocLTCompensateInit(void)
//输入参数	: void
//输出参数	: void
//函数功能	: SOC低温补偿模块初始化
//注意事项	: 
//=============================================================================================
void SocLTCompensateInit(void);

//=============================================================================================
//函数名称	: void SocLTCompensateEnterShDn(void)
//输入参数	: void
//输出参数	: void
//函数功能	: SOC低温补偿模块进入休眠处理任务
//注意事项	: 
//=============================================================================================
void SocLTCompensateEnterShDn(void);

//=============================================================================================
//函数名称	: void SocLTCompensateTask(void)
//输入参数	: void
//输出参数	: void
//函数功能	: SOC低温补偿模块主任务
//注意事项	: 
//=============================================================================================
void SocLTCompensateTask(void);

#endif

/*****************************************end of SocLTCompensate.h*****************************************/