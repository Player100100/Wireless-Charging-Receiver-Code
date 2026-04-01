#include "ASKcommunicate.hpp"
namespace ASKcomm
{
    void ASK_Init(void)
    {
        HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_1);
        HAL_TIM_PWM_Stop(&htim4, TIM_CHANNEL_1);
    }
    void packData(float wptPower, uint8_t powerRequirement)
    {
        static uint8_t packedPower = 0U;
        static uint16_t parity = 0U;


        packedPower = (uint8_t)wptPower* (255.0f/150.0f); // 将功率转换为0-255范围
//后面需要改
        ASKData.wptPowerLimit = packedPower;

        parity = (powerRequirement & 0b1) | (packedPower << 1);
        parity ^= (parity >> 8);
        parity ^= (parity >> 4);
        parity ^= (parity >> 2);
        parity ^= (parity >> 1);

        ASKData.txMessage = 0x0
            | (powerRequirement & 0b1)  // 功率要求
            | (packedPower << 1)        // uint8格式的功率
            | ((parity & 0b1) << 9);    // 奇偶校验

    }
}//namespace ASKcomm