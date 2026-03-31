//
// Created by 18640 on 26-3-17.
//

#ifndef ASK_H
#define ASK_H
#include"main.h"
#include "tim.h"
#include "stdlib.h"
#include "math.h"

namespace ASKcomm
{
    void ASK_Init(void);
    void ASK_Send(void);
    void ASK_pack(float OutputPower,int FULL);
    struct ASK_Data
    {
        bool enableASK = true; // 是否启用ASK通信
        uint16_t txMessage;
        uint8_t askLoopIndex;
        uint32_t txBitSequence; // 当前发送的bit序列


        uint8_t wptPowerLimit; // WPT功率，单位W
        uint8_t powerRequirement = 1U; // 功率要求，0-1

        uint16_t lowPowerCnt = 0;
        uint32_t lastPowerOnTime = 0;

        bool allowRestart = 0;
    };
    extern ASK_Data ASKData;
}//namespace ASKcomm
#endif //ASK_H
