//=======================================Copyright(c)===========================================
// 								  深圳易马达科技有限公司
//---------------------------------------文件信息----------------------------------------------
//文件名   	: NTC.c
//创建人  	: Handry
//创建日期	: 
//描述	    : NTC列表文件
//-----------------------------------------------当前版本修订----------------------------------
//修改人   	:
//版本	    :
//修改日期	:
//描述	    :
//=============================================================================================

//=============================================================================================
//包含头文件
//=============================================================================================
#include "NTC.h"

//=============================================================================================
//全局变量定义
//=============================================================================================
//科帝特,KDT-P01,10K,B=3950K		NTC表    -50℃ - 125℃
const unsigned short NTC_3950_14BTAB[] = 
{
	16156 , 16139 , 16121 , 16102 , 16082 , 16060 , 16037 , 16012 , 15986 , 15959 ,
	15930 , 15899 , 15866 , 15832 , 15795 , 15757 , 15717 , 15674 , 15629 , 15582 ,
	15532 , 15479 , 15425 , 15367 , 15307 , 15243 , 15177 , 15108 , 15036 , 14960 ,
	14881 , 14799 , 14714 , 14625 , 14533 , 14437 , 14337 , 14234 , 14128 , 14017 ,
	13903 , 13786 , 13664 , 13539 , 13411 , 13279 , 13143 , 13004 , 12861 , 12715 ,
	12566 , 12413 , 12258 , 12099 , 11938 , 11774 , 11608 , 11439 , 11267 , 11094 ,
	10920 , 10742 , 10564 , 10384 , 10203 , 10021 , 9839  , 9655  , 9472  , 9288  ,
	9104  , 8920  , 8737  , 8554  , 8373  , 8192  , 8012  , 7833  , 7655  , 7480  ,
	7306  , 7133  , 6963  , 6794  , 6628  , 6465  , 6304  , 6144  , 5988  , 5834  ,
	5683  , 5535  , 5389  , 5246  , 5106  , 4969  , 4834  , 4703  , 4575  , 4449  ,
	4326  , 4206  , 4089  , 3974  , 3863  , 3754  , 3648  , 3545  , 3444  , 3346  ,
	3251  , 3158  , 3068  , 2980  , 2895  , 2812  , 2731  , 2653  , 2576  , 2503  ,
	2431  , 2361  , 2293  , 2227  , 2163  , 2101  , 2041  , 1983  , 1926  , 1871  ,
	1818  , 1766  , 1716  , 1667  , 1620  , 1574  , 1530  , 1487  , 1446  , 1405  ,
	1365  , 1328  , 1290  , 1254  , 1221  , 1187  , 1154  , 1122  , 1092  , 1062  ,
	1033  , 1004  , 978   , 951   , 926   , 901   , 876   , 854   , 831   , 808   ,
	788   , 767   , 747   , 728   , 708   , 690   , 672   , 654   , 638   , 623   ,
	606   , 591   , 575   , 562   , 546   , 534
};


//赛斯通,SK103FJ1000ST,10K,B=3435K 	NTC表    -50℃ - 120℃
const unsigned short NTC_3435_14BTAB[] =
{
	15910 , 15883 , 15854 , 15824 , 15793 , 15760 , 15726 , 15690 , 15652 , 15613 ,
	15572 , 15529 , 15484 , 15437 , 15388 , 15337 , 15285 , 15230 , 15173 , 15113 ,
	15051 , 14988 , 14920 , 14852 , 14780 , 14706 , 14630 , 14551 , 14469 , 14385 ,
	14297 , 14208 , 14115 , 14020 , 13922 , 13822 , 13718 , 13612 , 13504 , 13392 ,
	13278 , 13161 , 13042 , 12920 , 12796 , 12670 , 12541 , 12409 , 12276 , 12140 ,
	12002 , 11862 , 11720 , 11577 , 11432 , 11285 , 11136 , 10987 , 10836 , 10684 ,
	10530 , 10376 , 10221 , 10066 , 9910  , 9753  , 9596  , 9440  , 9282  , 9126  ,
	8969  , 8812  , 8656  , 8500  , 8346  , 8192  , 8038  , 7886  , 7734  , 7584  ,
	7435  , 7288  , 7142  , 6997  , 6854  , 6712  , 6572  , 6434  , 6298  , 6163  ,
	6030  , 5900  , 5771  , 5644  , 5519  , 5397  , 5276  , 5157  , 5041  , 4926  ,
	4813  , 4703  , 4594  , 4488  , 4384  , 4282  , 4182  , 4084  , 3989  , 3894  ,
	3802  , 3712  , 3625  , 3539  , 3454  , 3372  , 3291  , 3213  , 3137  , 3061  ,
	2988  , 2917  , 2847  , 2779  , 2712  , 2647  , 2584  , 2523  , 2463  , 2403  ,
	2346  , 2290  , 2235  , 2183  , 2129  , 2080  , 2030  , 1982  , 1935  , 1890  ,
	1845  , 1801  , 1759  , 1717  , 1678  , 1638  , 1601  , 1563  , 1527  , 1492  ,
	1457  , 1424  , 1391  , 1359  , 1328  , 1298  , 1268  , 1239  , 1211  , 1184  ,
	1158  , 1132  , 1106  , 1082  , 1058  , 1035  , 1012  , 990   , 968   , 947   ,
	926
};

//103KT 	NTC表    -40℃ - 120℃
const unsigned long NTC_103KT1608T_RESTAB[] =
{
	192010 , 181838 , 172236 , 163182 , 154653 , 146625 , 139208 , 132090 , 125397 , 119000 ,
	112995 , 107441 , 101982 , 97008  , 92202  , 87692  , 83457  , 79427  , 75596  , 71997  ,
	68538  , 65324  , 62235  , 59331  , 56570  , 53971  , 51475  , 49123  , 46905  , 44774  ,
	42763  , 40847  , 39036  , 37309  , 35673  , 34123  , 32642  , 31225  , 29890  , 28612  ,
	27396  , 26238  , 25134  , 24089  , 23090  , 22136  , 21224  , 20361  , 19535  , 18747  ,
	17991  , 17273  , 16587  , 15935  , 15310  , 14710  , 14139  , 13596  , 13071  , 12575  ,
	12097  , 11639  , 11202  , 10783  , 10384  , 10001  , 9632   , 9281   , 8942   , 8619   ,
	8309   , 8013   , 7729   , 7455   , 7193   , 6940   , 6699   , 6467   , 6245   , 6030   ,
	5824   , 5628   , 5438   , 5256   , 5080   , 4913   , 4750   , 4594   , 4445   , 4300   ,
	4160   , 4027   , 3897   , 3773   , 3654   , 3539   , 3428   , 3321   , 3218   , 3118   ,
	3022   , 2930   , 2841   , 2755   , 2672   , 2592   , 2514   , 2440   , 2368   , 2298   ,
	2231   , 2166   , 2103   , 2043   , 1984   , 1927   , 1873   , 1820   , 1769   , 1719   ,
	1671   , 1625   , 1580   , 1537   , 1494   , 1454   , 1414   , 1376   , 1339   , 1304   ,
	1269   , 1235   , 1203   , 1171   , 1141   , 1111   , 1083   , 1055   , 1028   , 1002   ,
	976    , 952    , 928    , 905    , 882    , 860    , 839    , 818    , 798    , 779    ,
	761    , 742    , 724    , 707    , 690    , 674    , 658    , 643    , 628    , 614    ,
	599    ,
};

//拓邦 贴片NTC
const unsigned long NTC_SMT_NTC0603[] =
{
    248300,233100,219000,205900,193600,182200,171600,161600,152300,143600,	//-40
    135500,127800,120700,114000,107800,101900,96390,91220,86370,81810,	//-30
    77520,73490,69700,66130,62770,59610,56620,53810,51160,48650,	//-20
    46290,44060,41950,39960,38070,36290,34600,33010,31490,30060,	//-10
    28700,27420,26200,25040,23940,22900,21910,20960,20070,19220,	//0
    18410,17640,16910,16210,15550,14920,14310,13740,13190,12670,	//10
    12170,11700,11240,10810,10400,10000,9622,9261,8916,8585,	//20
    8269,7967,7678,7400,7135,6881,6637,6403,6179,5965,	//30
    5759,5561,5372,5189,5015,4847,4686,4531,4382,4239,	//40
    4101,3969,3842,3719,3601,3488,3379,3274,3172,3075,	//50
    2981,2890,2803,2719,2638,2559,2484,2411,2341,2273,	//60
    2207,2144,2083,2024,1967,1912,1858,1807,1757,1709,	//70
    1662,1617,1574,1532,1491,1451,1413,1376,1340,1305,	//80
    1272,1239,1208,1177,1147,1118,1091,1063,1037,1012,	//90
    987,963,939,917,895,874,853,833,814,795,	//100
    776,758,740,724,707,691,676,660,646,631,	//110
    618,604,591,578,565,553,	//120
};

//拓邦水滴形NTC
const unsigned long NTC_TB_WD_NTC[] =
{
    248300,233100,219000,205900,193600,182200,171600,161600,152300,143600,	//-40
    135500,127800,120700,114000,107800,101900,96390,91220,86370,81810,	//-30
    77520,73490,69700,66130,62770,59610,56620,53810,51160,48650,	//-20
    46290,44060,41950,39960,38070,36290,34600,33010,31490,30060,	//-10
    28700,27420,26200,25040,23940,22900,21910,20960,20070,19220,	//0
    18410,17640,16910,16210,15550,14920,14310,13740,13190,12670,	//10
    12170,11700,11240,10810,10400,10000,9622,9261,8916,8585,	//20
    8269,7967,7678,7400,7135,6881,6637,6403,6179,5965,	//30
    5759,5561,5372,5189,5015,4847,4686,4531,4382,4239,	//40
    4101,3969,3842,3719,3601,3488,3379,3274,3172,3075,	//50
    2981,2890,2803,2719,2638,2559,2484,2411,2341,2273,	//60
    2207,2144,2083,2024,1967,1912,1858,1807,1757,1709,	//70
    1662,1617,1574,1532,1491,1451,1413,1376,1340,1305,	//80
    1272,1239,1208,1177,1147,1118,1091,1063,1037,1012,	//90
    987,963,939,917,895,874,853,833,814,795,	//100
    776,758,740,724,707,691,676,660,646,631,	//110
    618,604,591,578,565,553,	//120
};

const t_NTCTAB NTC_RESTAB[]=
{
    {NTC_103KT1608T_RESTAB, 160, -400},   //B=3435, -40℃ - 120℃
    
    #if defined(LFP_TB_20000MAH_20S)
    //tb 贴片
    {NTC_SMT_NTC0603, 160, -400},   //B=3435, -40℃ - 125℃
    {NTC_TB_WD_NTC, 160, -400},     //B=3435, -40℃ - 120℃    
    #endif
    
};

//=============================================================================================
//定义接口函数
//=============================================================================================
//=========================================================================================================
//函数名称:	short NTCTempQuery(unsigned long volt,const unsigned long *table,unsigned short n,short offset)
//输入参数:	volt:NTCA采样数据
//		    table:NTC data-temperature 表
//			n: NTC表长度-1
//			offset:温度偏移0.1°每bit。
//输出参数: short: NTC温度值0.1°每bit。
//功能描述: 依据NTC电压值，通过折半法查询对应的温度
//注意事项:
//=========================================================================================================
short NTCTempQuery(unsigned long volt,const unsigned long *table,unsigned short n,short offset)
{
	unsigned long mid,top,bot,vtop,vbot;
    short T;

    if(volt > *(table))
    {
        return NTC_TEMP_OFF;
    }
    else if(volt < *(table+n))
    {
        return NTC_TEMP_SHORT;
    }
    else
    {
        bot = 0;
        top = n;
        for(;(top-bot) != 1;)
        {
            mid = (top + bot) >> 1;		//mid是n/2；
            if(volt < (*(table + mid)))
            {
                bot = mid;
            }
            else
            {
                top = mid;
            }
        }
        
        vtop = *(table + top);
        vbot = *(table + bot);
        bot = bot * 10;
        top = top * 10;   
        T = (short)(((long)bot * (volt - vtop) + (long)top * (vbot - volt)) / (vbot - vtop)) + offset;
        return T;
    }

}

//=========================================================================================================
//函数名称:	unsigned long NTCFindResByTemp(s16 temp)
//输入参数:	temp：寻找的温度；0.1℃
//输出参数: 
//功能描述: 依据温度查找的对应的NTC阻值
//注意事项:
//=========================================================================================================
unsigned long NTCFindResByTemp(s16 temp)
{
    u8 index = 0;
    
    index = (temp + 400) / 10;
    
    #if defined(LFP_TB_20000MAH_20S)
    return NTC_TB_WD_NTC[index];
    #else
    return NTC_103KT1608T_RESTAB[index];
    #endif
}

/*****************************************end of NTC.c*****************************************/