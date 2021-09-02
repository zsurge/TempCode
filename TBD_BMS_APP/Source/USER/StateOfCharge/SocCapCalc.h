//=======================================Copyright(c)===========================================
// 								  深圳易马达科技有限公司
//---------------------------------------文件信息----------------------------------------------
//文件名   	: SocCapCalc.h
//创建人  	: Handry
//创建日期	:
//描述	    : SOC容量计算模块头文件
//-----------------------------------------------当前版本修订----------------------------------
//修改人   	:
//版本	    :
//修改日期	:
//描述	    :
//=============================================================================================
#ifndef _SOCCAPCALC_H
#define _SOCCAPCALC_H

//=============================================================================================
//包含头文件
//=============================================================================================
#include "BSPTypedef.h"

//=============================================================================================
//宏参数设定
//=============================================================================================
#define     CAP_ZERO_POINT                100000      //容量计算的零点值(底端容量)，为了防止越界而设置，100AH
#define     SOC_CHANGE_TO_WRITE_FLASH     10          //当前容量进行写flash的SOC变化值(单位:0.1%)

//=============================================================================================
//定义数据类型
//=============================================================================================
//容量计算结构体
typedef struct
{
	u32 nowCap;                 //当前容量(单位:1mAH)
	u32 baseCap;                //底端容量(单位:1mAH)
	u32 topCap;                 //顶端容量(单位:1mAH)
	u32 standCap;               //标称容量(单位:1mAH)
}t_CAPFORM;

typedef struct
{
    u16 tolcap;     //总容量
    u16 remaincap;  //剩余容量
    u16 realSOC;    //真实SOC
    u16 displaySOC; //显示SOC
    u16 soh;        //SOH
    u16 cycles;     //循环次数
    u16 Calibcycles;//发生容量校准时的循环次数
}t_SOC_INFO;

typedef struct
{
    u16 num;        //保存SOC的flash编号
    u16 tolcap;     //总容量
    u16 remaincap;  //剩余容量
    u16 displaySOC; //显示SOC
}t_SOC_SaveInfo;

//=============================================================================================
//声明变量，供外部使用
//=============================================================================================
extern t_SOC_INFO gSOCInfo;             //SOC信息

//=============================================================================================
//声明接口函数
//=============================================================================================
//=============================================================================================
//函数名称	:  void SocCalcInit(void)
//输入参数	:  void
//输出参数	:  void
//函数功能	:  SOC计算模块初始化
//注意事项	:  
//=============================================================================================
void SocCalcInit(void);

//=============================================================================================
//函数名称	:  void SocCalcTask(void)
//输入参数	:  void
//输出参数	:  void
//函数功能	:  SOC计算任务
//注意事项	:  10ms调用
//=============================================================================================
void SocCalcTask(void);

//=============================================================================================
//函数名称	:  void CorrNowCapBySoc(u16 soc)
//输入参数	:  soc:目标SOC(0.1%)
//输出参数	:  void
//函数功能	:  根据SOC修正当前容量
//注意事项	:  
//=============================================================================================
void CorrNowCapBySoc(u16 soc);

//=============================================================================================
//函数名称	:  void CorrTotalCap(u32 cap)
//输入参数	:  cap:总容量(单位:1mAH)
//输出参数	:  void
//函数功能	:  修正总容量
//注意事项	:  
//=============================================================================================
void CorrTotalCap(u32 cap);

//=============================================================================================
//函数名称	:  void LTCompensateCorrTotalCap(u32 cap)
//输入参数	:  cap:总容量(单位:1mAH)
//输出参数	:  void
//函数功能	:  低温补偿修正总容量
//注意事项	:  
//=============================================================================================
void LTCompensateCorrTotalCap(u32 cap);

//=============================================================================================
//函数名称	:  u32 GetRemainCap(void)
//输入参数	:  void
//输出参数	:  剩余电量,即当前容量(单位:1mAH)
//函数功能	:  获取剩余电量
//注意事项	:  
//=============================================================================================
u32 GetRemainCap(void);

//=============================================================================================
//函数名称	:  u32 GetTotalCap(void)
//输入参数	:  void
//输出参数	:  总容量(单位:1mAH)
//函数功能	:  获取总容量
//注意事项	:  
//=============================================================================================
u32 GetTotalCap(void);

//=============================================================================================
//函数名称	:  u32 GetStandCap(void)
//输入参数	:  void
//输出参数	:  标称容量(单位:1mAH)
//函数功能	:  获取标称容量
//注意事项	:  
//=============================================================================================
u32 GetStandCap(void);

//=============================================================================================
//函数名称	:  u16 GetRealSocThousand(void)
//输入参数	:  void
//输出参数	:  真实SOC值(单位:，0.1%)
//函数功能	:  获取真实SOC值
//注意事项	:  
//=============================================================================================
u16 GetRealSocThousand(void);

#endif

/*****************************************end of SocCapCalc.h*****************************************/