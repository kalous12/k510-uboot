/* Copyright (c) 2022, Canaan Bright Sight Co., Ltd
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
 * CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#include <video/isp_com.h>
#include "hw_dev/inc/dev_hw.h"
#include "hw_dev/inc/ext_ctl_hw.h"
#include "sensor/sensor.h"
/*
*
*/
void Imx385_init(void)
{
    Set_manu(0x01);
    Set_manu(0x00);
    I2cWr(0x3000,0x01);
    msleep(1);
    I2cWr(0x3001,0x00);
    msleep(1);
    I2cWr(0x3002,0x01);
    msleep(1);
    I2cWr(0x3004,0x10);
    msleep(1);
    //I2cRd(0x3004);
    msleep(1);
    I2cWr(0x3005,0x01);
    msleep(1);
    I2cWr(0x3007,0x03);
    msleep(1);
    I2cWr(0x3009,0x02);
    msleep(1);
    I2cWr(0x300a,0x00);
    msleep(1);
    I2cWr(0x300b,0x00);
    msleep(1);
    I2cWr(0x3012,0x2c);
    msleep(1);
    //I2cRd(0x3012);
    msleep(1);
    I2cWr(0x3013,0x01);
    msleep(1);
    I2cWr(0x3014,0x80);
    msleep(1);
    //I2cRd(0x3014);
    msleep(1);
    I2cWr(0x3015,0x00);
    msleep(1);
    I2cWr(0x3016,0x09);
    msleep(1);
    I2cWr(0x3018,0x65);
    msleep(1);
    //I2cRd(0x3018);
    msleep(1);
    I2cWr(0x3019,0x04);
    msleep(1);
    I2cWr(0x301a,0x00);
    msleep(1);
    I2cWr(0x301b,0x30);
    msleep(1);
    I2cWr(0x301c,0x11);
    msleep(1);
    I2cWr(0x3020,0x02);
    msleep(1);
    I2cWr(0x3021,0x00);
    msleep(1);
    I2cWr(0x3022,0x00);
    msleep(1);
    I2cWr(0x303a,0x0c);
    msleep(1);
    I2cWr(0x303b,0x00);
    msleep(1);
    I2cWr(0x303c,0x00);
    msleep(1);
    I2cWr(0x303d,0x00);
    msleep(1);
    I2cWr(0x303e,0x49);
    msleep(1);
    I2cWr(0x303f,0x04);
    msleep(1);
    I2cWr(0x3044,0x01);
    msleep(1);
    I2cWr(0x3046,0x30);
    msleep(1);
    I2cWr(0x3047,0x38);
    msleep(1);
    I2cWr(0x3049,0x0a);
    msleep(1);
    I2cWr(0x3054,0x66);
    msleep(1);
    I2cWr(0x305c,0x18);
    msleep(1);
    I2cWr(0x305d,0x10);
    msleep(1);
    I2cWr(0x305e,0x20);
    msleep(1);
    I2cWr(0x305f,0x10);
    msleep(1);
    I2cWr(0x310b,0x07);
    msleep(1);
    I2cWr(0x3110,0x12);
    msleep(1);
    I2cWr(0x31ed,0x38);
    msleep(1);
    I2cWr(0x3338,0xd4);
    msleep(1);
    I2cWr(0x3339,0x40);
    msleep(1);
    I2cWr(0x333a,0x10);
    msleep(1);
    I2cWr(0x333b,0x00);
    msleep(1);
    I2cWr(0x333c,0xd4);
    msleep(1);
    I2cWr(0x333d,0x40);
    msleep(1);
    I2cWr(0x333e,0x10);
    msleep(1);
    I2cWr(0x333f,0x00);
    msleep(1);
    I2cWr(0x3344,0x00);
    msleep(1);
    I2cWr(0x3346,0x01);
    msleep(1);
    I2cWr(0x3357,0x49);
    msleep(1);
    I2cWr(0x3358,0x04);
    msleep(1);
    I2cWr(0x336b,0x3f);
    msleep(1);
    I2cWr(0x336c,0x1f);
    msleep(1);
    I2cWr(0x337d,0x0c);
    msleep(1);
    I2cWr(0x337e,0x0c);
    msleep(1);
    I2cWr(0x337f,0x01);
    msleep(1);
    I2cWr(0x3380,0x40);
    msleep(1);
    I2cWr(0x3381,0x4a);
    msleep(1);
    I2cWr(0x3382,0x67);
    msleep(1);
    I2cWr(0x3383,0x1F);
    msleep(1);
    I2cWr(0x3384,0x3f);
    msleep(1);
    I2cWr(0x3385,0x27);
    msleep(1);
    I2cWr(0x3386,0x1F);
    msleep(1);
    I2cWr(0x3387,0x17);
    msleep(1);
    I2cWr(0x3388,0x77);
    msleep(1);
    I2cWr(0x3389,0x27);
    msleep(1);
    I2cWr(0x338d,0x67);
    msleep(1);
    I2cWr(0x338e,0x03);
    msleep(1);
    I2cWr(0x3000,0x00);
    sleep(1);
    I2cWr(0x3002,0x00);
    msleep(3);
    Set_auto(0x01);
    Set_auto(0x00);
    msleep(3);

}
/*
*
*/
void Imx385_Rd(void)
{
    Set_manu(0x01);
    Set_manu(0x00);
    I2cRd(0x3000);
    msleep(1);
    I2cRd(0x3001);
    msleep(1);
    I2cRd(0x3002);
    msleep(1);
    I2cRd(0x3004);
    msleep(1);
    //I2cRd(0x3004);
    msleep(1);
    I2cRd(0x3005);
    msleep(1);
    I2cRd(0x3007);
    msleep(1);
    I2cRd(0x3009);
    msleep(1);
    I2cRd(0x300a);
    msleep(1);
    I2cRd(0x300b);
    msleep(1);
    I2cRd(0x3012);
    msleep(1);
    //I2cRd(0x3012);
    msleep(1);
    I2cRd(0x3013);
    msleep(1);
    I2cRd(0x3014);
    msleep(1);
    //I2cRd(0x3014);
    msleep(1);
    I2cRd(0x3015);
    msleep(1);
    I2cRd(0x3016);
    msleep(1);
    I2cRd(0x3018);
    msleep(1);
    //I2cRd(0x3018);
    msleep(1);
    I2cRd(0x3019);
    msleep(1);
    I2cRd(0x301a);
    msleep(1);
    I2cRd(0x301b);
    msleep(1);
    I2cRd(0x301c);
    msleep(1);
    I2cRd(0x3020);
    msleep(1);
    I2cRd(0x3021);
    msleep(1);
    I2cRd(0x3022);
    msleep(1);
    I2cRd(0x303a);
    msleep(1);
    I2cRd(0x303b);
    msleep(1);
    I2cRd(0x303c);
    msleep(1);
    I2cRd(0x303d);
    msleep(1);
    I2cRd(0x303e);
    msleep(1);
    I2cRd(0x303f);
    msleep(1);
    I2cRd(0x3044);
    msleep(1);
    I2cRd(0x3046);
    msleep(1);
    I2cRd(0x3047);
    msleep(1);
    I2cRd(0x3049);
    msleep(1);
    I2cRd(0x3054);
    msleep(1);
    I2cRd(0x305c);
    msleep(1);
    I2cRd(0x305d);
    msleep(1);
    I2cRd(0x305e);
    msleep(1);
    I2cRd(0x305f);
    msleep(1);
    I2cRd(0x310b);
    msleep(1);
    I2cRd(0x3110);
    msleep(1);
    I2cRd(0x31ed);
    msleep(1);
    I2cRd(0x3338);
    msleep(1);
    I2cRd(0x3339);
    msleep(1);
    I2cRd(0x333a);
    msleep(1);
    I2cRd(0x333b);
    msleep(1);
    I2cRd(0x333c);
    msleep(1);
    I2cRd(0x333d);
    msleep(1);
    I2cRd(0x333e);
    msleep(1);
    I2cRd(0x333f);
    msleep(1);
    I2cRd(0x3344);
    msleep(1);
    I2cRd(0x3346);
    msleep(1);
    I2cRd(0x3357);
    msleep(1);
    I2cRd(0x3358);
    msleep(1);
    I2cRd(0x336b);
    msleep(1);
    I2cRd(0x336c);
    msleep(1);
    I2cRd(0x337d);
    msleep(1);
    I2cRd(0x337e);
    msleep(1);
    I2cRd(0x337f);
    msleep(1);
    I2cRd(0x3380);
    msleep(1);
    I2cRd(0x3381);
    msleep(1);
    I2cRd(0x3382);
    msleep(1);
    I2cRd(0x3383);
    msleep(1);
    I2cRd(0x3384);
    msleep(1);
    I2cRd(0x3385);
    msleep(1);
    I2cRd(0x3386);
    msleep(1);
    I2cRd(0x3387);
    msleep(1);
    I2cRd(0x3388);
    msleep(1);
    I2cRd(0x3389);
    msleep(1);
    I2cRd(0x338d);
    msleep(1);
    I2cRd(0x338e);
    msleep(1);
    I2cRd(0x3000);
    sleep(1);
    I2cRd(0x3002);
    msleep(3);
    Set_auto(0x01);
    Set_auto(0x00);
}
/*
*
*/
void Imx385_Rd_DisableAuto(void)
{
    Set_manu(0x01);
    Set_manu(0x00);
    I2cRd(0x3000);
    msleep(1);
    I2cRd(0x3001);
    msleep(1);
    I2cRd(0x3002);
    msleep(1);
    I2cRd(0x3004);
    msleep(1);
    //I2cRd(0x3004);
    msleep(1);
    I2cRd(0x3005);
    msleep(1);
    I2cRd(0x3007);
    msleep(1);
    I2cRd(0x3009);
    msleep(1);
    I2cRd(0x300a);
    msleep(1);
    I2cRd(0x300b);
    msleep(1);
    I2cRd(0x3012);
    msleep(1);
    //I2cRd(0x3012);
    msleep(1);
    I2cRd(0x3013);
    msleep(1);
    I2cRd(0x3014);
    msleep(1);
    //I2cRd(0x3014);
    msleep(1);
    I2cRd(0x3015);
    msleep(1);
    I2cRd(0x3016);
    msleep(1);
    I2cRd(0x3018);
    msleep(1);
    //I2cRd(0x3018);
    msleep(1);
    I2cRd(0x3019);
    msleep(1);
    I2cRd(0x301a);
    msleep(1);
    I2cRd(0x301b);
    msleep(1);
    I2cRd(0x301c);
    msleep(1);
    I2cRd(0x3020);
    msleep(1);
    I2cRd(0x3021);
    msleep(1);
    I2cRd(0x3022);
    msleep(1);
    I2cRd(0x303a);
    msleep(1);
    I2cRd(0x303b);
    msleep(1);
    I2cRd(0x303c);
    msleep(1);
    I2cRd(0x303d);
    msleep(1);
    I2cRd(0x303e);
    msleep(1);
    I2cRd(0x303f);
    msleep(1);
    I2cRd(0x3044);
    msleep(1);
    I2cRd(0x3046);
    msleep(1);
    I2cRd(0x3047);
    msleep(1);
    I2cRd(0x3049);
    msleep(1);
    I2cRd(0x3054);
    msleep(1);
    I2cRd(0x305c);
    msleep(1);
    I2cRd(0x305d);
    msleep(1);
    I2cRd(0x305e);
    msleep(1);
    I2cRd(0x305f);
    msleep(1);
    I2cRd(0x310b);
    msleep(1);
    I2cRd(0x3110);
    msleep(1);
    I2cRd(0x31ed);
    msleep(1);
    I2cRd(0x3338);
    msleep(1);
    I2cRd(0x3339);
    msleep(1);
    I2cRd(0x333a);
    msleep(1);
    I2cRd(0x333b);
    msleep(1);
    I2cRd(0x333c);
    msleep(1);
    I2cRd(0x333d);
    msleep(1);
    I2cRd(0x333e);
    msleep(1);
    I2cRd(0x333f);
    msleep(1);
    I2cRd(0x3344);
    msleep(1);
    I2cRd(0x3346);
    msleep(1);
    I2cRd(0x3357);
    msleep(1);
    I2cRd(0x3358);
    msleep(1);
    I2cRd(0x336b);
    msleep(1);
    I2cRd(0x336c);
    msleep(1);
    I2cRd(0x337d);
    msleep(1);
    I2cRd(0x337e);
    msleep(1);
    I2cRd(0x337f);
    msleep(1);
    I2cRd(0x3380);
    msleep(1);
    I2cRd(0x3381);
    msleep(1);
    I2cRd(0x3382);
    msleep(1);
    I2cRd(0x3383);
    msleep(1);
    I2cRd(0x3384);
    msleep(1);
    I2cRd(0x3385);
    msleep(1);
    I2cRd(0x3386);
    msleep(1);
    I2cRd(0x3387);
    msleep(1);
    I2cRd(0x3388);
    msleep(1);
    I2cRd(0x3389);
    msleep(1);
    I2cRd(0x338d);
    msleep(1);
    I2cRd(0x338e);
    msleep(1);
    I2cRd(0x3000);
    sleep(1);
    I2cRd(0x3002);
    msleep(3);

}
/*
*
*/
void imx385_wdr3f_6p25fps_12bit_2lane(void)
{
    Set_manu(0x01);
    Set_manu(0x00);
    I2cWr(0x3000,0x01);
    msleep(1);
    I2cWr(0x3001,0x00);
    msleep(1);
    I2cWr(0x3002,0x01);
    msleep(1);
    I2cWr(0x3005,0x01);
    msleep(1);
    I2cWr(0x3007,0x03);
    msleep(1);
    I2cWr(0x3009,0x02);
    msleep(1);
    I2cWr(0x300a,0x00);
    msleep(1);
    I2cWr(0x300b,0x00);
    msleep(1);
    I2cWr(0x300c,0x21);
    msleep(1);
    I2cWr(0x3012,0x2c);
    msleep(1);
    I2cWr(0x3013,0x01);
    msleep(1);
    I2cWr(0x3014,0x80);
    msleep(1);
    I2cWr(0x3015,0x00);
    msleep(1);
    I2cWr(0x3016,0x09);
    msleep(1);
    I2cWr(0x3018,0x65);
    msleep(1);
    I2cWr(0x3019,0x04);
    msleep(1);
    I2cWr(0x301a,0x00);
    msleep(1);
    I2cWr(0x301b,0xa0);
    msleep(1);
    I2cWr(0x301c,0x14);
    msleep(1);
    I2cWr(0x3020,0x03);
    msleep(1);
    I2cWr(0x3021,0x00);
    msleep(1);
    I2cWr(0x3022,0x00);
    msleep(1);
    I2cWr(0x3023,0x49);
    msleep(1);
    I2cWr(0x3024,0x00);
    msleep(1);
    I2cWr(0x3025,0x00);
    msleep(1);
    I2cWr(0x3026,0x68);
    msleep(1);
    I2cWr(0x3027,0x10);
    msleep(1);
    I2cWr(0x3028,0x00);
    msleep(1);
    I2cWr(0x302c,0x2b);
    msleep(1);
    I2cWr(0x302d,0x00);
    msleep(1);
    I2cWr(0x302e,0x00);
    msleep(1);
    I2cWr(0x302f,0x3B);
    msleep(1);
    I2cWr(0x3030,0x00);
    msleep(1);
    I2cWr(0x3031,0x00);
    msleep(1);
    I2cWr(0x303a,0x0c);
    msleep(1);
    I2cWr(0x303b,0x00);
    msleep(1);
    I2cWr(0x303c,0x00);
    msleep(1);
    I2cWr(0x303d,0x00);
    msleep(1);
    I2cWr(0x303e,0x49);
    msleep(1);
    I2cWr(0x303f,0x04);
    msleep(1);
    I2cWr(0x3043,0x05);
    msleep(1);
    I2cWr(0x3044,0x01);
    msleep(1);
    I2cWr(0x3046,0x30);
    msleep(1);
    I2cWr(0x3047,0x38);
    msleep(1);
    I2cWr(0x3049,0x0a);
    msleep(1);
    I2cWr(0x3054,0x66);
    msleep(1);
    I2cWr(0x305c,0x18);
    msleep(1);
    I2cWr(0x305d,0x10);
    msleep(1);
    I2cWr(0x305e,0x20);
    msleep(1);
    I2cWr(0x305f,0x10);
    msleep(1);
    I2cWr(0x3108,0x23);
    msleep(1);
    I2cWr(0x3109,0x03);
    msleep(1);
    I2cWr(0x310A,0x00);
    msleep(1);
    I2cWr(0x310b,0x07);
    msleep(1);
    I2cWr(0x3110,0x12);
    msleep(1);
    I2cWr(0x31ed,0x38);
    msleep(1);
    I2cWr(0x3338,0xd4);
    msleep(1);
    I2cWr(0x3339,0x40);
    msleep(1);
    I2cWr(0x333a,0x10);
    msleep(1);
    I2cWr(0x333b,0x00);
    msleep(1);
    I2cWr(0x333c,0xd4);
    msleep(1);
    I2cWr(0x333d,0x40);
    msleep(1);
    I2cWr(0x333e,0x10);
    msleep(1);
    I2cWr(0x333f,0x00);
    msleep(1);
    I2cWr(0x3344,0x00);
    msleep(1);
    I2cWr(0x3346,0x01);
    msleep(1);
    I2cWr(0x3354,0x00);
    msleep(1);
    I2cWr(0x3357,0x17);
    msleep(1);
    I2cWr(0x3358,0x0d);
    msleep(1);
    I2cWr(0x336b,0x3f);
    msleep(1);
    I2cWr(0x336c,0x1f);
    msleep(1);
    I2cWr(0x337d,0x0c);
    msleep(1);
    I2cWr(0x337e,0x0c);
    msleep(1);
    I2cWr(0x337f,0x01);
    msleep(1);
    I2cWr(0x3380,0x40);
    msleep(1);
    I2cWr(0x3381,0x4a);
    msleep(1);
    I2cWr(0x3382,0x67);
    msleep(1);
    I2cWr(0x3383,0x1f);
    msleep(1);
    I2cWr(0x3384,0x3f);
    msleep(1);
    I2cWr(0x3385,0x27);
    msleep(1);
    I2cWr(0x3386,0x1F);
    msleep(1);
    I2cWr(0x3387,0x17);
    msleep(1);
    I2cWr(0x3388,0x77);
    msleep(1);
    I2cWr(0x3389,0x27);
    msleep(1);
    I2cWr(0x338d,0x67);
    msleep(1);
    I2cWr(0x338e,0x03);
    msleep(1);
    I2cWr(0x3000,0x00);
    msleep(1);
    I2cWr(0x3002,0x00);
    msleep(1);
    I2cWr(0x308c,0x00);
    msleep(3);
    Set_auto(0x01);
    Set_auto(0x00);
    msleep(3);
}
/*
*
*/
void imx385_wdr2f_12p5fps_12bit_2lane(void)
{
    Set_manu(0x01);
    Set_manu(0x00);
    I2cWr(0x3000,0x01);
    msleep(1);
    I2cWr(0x3001,0x00);
    msleep(1);
    I2cWr(0x3002,0x01);
    msleep(1);
    I2cWr(0x3005,0x01);
    msleep(1);
    I2cWr(0x3007,0x13);
    msleep(1);
    I2cWr(0x3009,0x02);
    msleep(1);
    I2cWr(0x300a,0x00);
    msleep(1);
    I2cWr(0x300b,0x00);
    msleep(1);
    I2cWr(0x300c,0x11);
    msleep(1);
    I2cWr(0x3012,0x2c);
    msleep(1);
    I2cWr(0x3013,0x01);
    msleep(1);
    I2cWr(0x3014,0x80);
    msleep(1);
    I2cWr(0x3015,0x00);
    msleep(1);
    I2cWr(0x3016,0x09);
    msleep(1);
    I2cWr(0x3018,0x65);
    msleep(1);
    I2cWr(0x3019,0x04);
    msleep(1);
    I2cWr(0x301a,0x00);
    msleep(1);
    I2cWr(0x301b,0xa0);
    msleep(1);
    I2cWr(0x301c,0x14);
    msleep(1);
    I2cWr(0x3020,0x03);
    msleep(1);
    I2cWr(0x3021,0x00);
    msleep(1);
    I2cWr(0x3022,0x00);
    msleep(1);
    I2cWr(0x3023,0x49);
    msleep(1);
    I2cWr(0x3024,0x00);
    msleep(1);
    I2cWr(0x3025,0x00);
    msleep(1);
    I2cWr(0x302c,0x25);
    msleep(1);
    I2cWr(0x302d,0x00);
    msleep(1);
    I2cWr(0x302e,0x00);
    msleep(1);
    I2cWr(0x303a,0x0c);
    msleep(1);
    I2cWr(0x303b,0x00);
    msleep(1);
    I2cWr(0x303c,0x00);
    msleep(1);
    I2cWr(0x303d,0x00);
    msleep(1);
    I2cWr(0x303e,0x49);
    msleep(1);
    I2cWr(0x303f,0x04);
    msleep(1);
    I2cWr(0x3043,0x05);
    msleep(1);
    I2cWr(0x3044,0x01);
    msleep(1);
    I2cWr(0x3046,0x30);
    msleep(1);
    I2cWr(0x3047,0x38);
    msleep(1);
    I2cWr(0x3049,0x0a);
    msleep(1);
    I2cWr(0x3054,0x66);
    msleep(1);
    I2cWr(0x305c,0x18);
    msleep(1);
    I2cWr(0x305d,0x10);
    msleep(1);
    I2cWr(0x305e,0x20);
    msleep(1);
    I2cWr(0x305f,0x10);
    msleep(1);
    I2cWr(0x3108,0x11);
    msleep(1);
    I2cWr(0x3109,0x01);
    msleep(1);
    I2cWr(0x310A,0x00);
    msleep(1);
    I2cWr(0x310b,0x07);
    msleep(1);
    I2cWr(0x3110,0x12);
    msleep(1);
    I2cWr(0x31ed,0x38);
    msleep(1);
    I2cWr(0x3338,0xd4);
    msleep(1);
    I2cWr(0x3339,0x40);
    msleep(1);
    I2cWr(0x333a,0x10);
    msleep(1);
    I2cWr(0x333b,0x00);
    msleep(1);
    I2cWr(0x333c,0xd4);
    msleep(1);
    I2cWr(0x333d,0x40);
    msleep(1);
    I2cWr(0x333e,0x10);
    msleep(1);
    I2cWr(0x333f,0x00);
    msleep(1);
    I2cWr(0x3344,0x00);
    msleep(1);
    I2cWr(0x3346,0x01);
    msleep(1);
    I2cWr(0x3354,0x00);
    msleep(1);
    I2cWr(0x3357,0xb2);
    msleep(1);
    I2cWr(0x3358,0x08);
    msleep(1);
    I2cWr(0x336b,0x3f);
    msleep(1);
    I2cWr(0x336c,0x1f);
    msleep(1);
    I2cWr(0x337d,0x0c);
    msleep(1);
    I2cWr(0x337e,0x0c);
    msleep(1);
    I2cWr(0x337f,0x01);
    msleep(1);
    I2cWr(0x3380,0x40);
    msleep(1);
    I2cWr(0x3381,0x4a);
    msleep(1);
    I2cWr(0x3382,0x67);
    msleep(1);
    I2cWr(0x3383,0x1f);
    msleep(1);
    I2cWr(0x3384,0x3f);
    msleep(1);
    I2cWr(0x3385,0x27);
    msleep(1);
    I2cWr(0x3386,0x1F);
    msleep(1);
    I2cWr(0x3387,0x17);
    msleep(1);
    I2cWr(0x3388,0x77);
    msleep(1);
    I2cWr(0x3389,0x27);
    msleep(1);
    I2cWr(0x338d,0x67);
    msleep(1);
    I2cWr(0x338e,0x03);
    msleep(1);
    I2cWr(0x3000,0x00);
    msleep(1);
    I2cWr(0x3002,0x00);
    msleep(1);
    I2cWr(0x308c,0x00);
    msleep(1);
}

void imx_385_2k_wdr_sensor_config(void)
{
    imx385_wdr3f_6p25fps_12bit_2lane();
    printf("IMX385    has been configed\n");
    Imx385_Rd();
    return;
}

void imx_385_2k_normal_vi_isp_config(void)
{
   // InitIsp2KWrap();
  //  video_in_im385_normal_12bit_30fps();
  //  cdns_mipi_reg_init_1920x1080xRAW12_mipi_2lane_imx385_normal_30fps();
    return;
}

void imx_385_2k_normal_sensor(BOOL enInt)
{
    //Imx385_init_pg();
    Imx385_init();
    printf("IMX385    has been configed\n");
    if(TRUE == enInt)
    {
        Imx385_Rd_DisableAuto();
    }
    else
    {
        Imx385_Rd();
    }
    
    //Imx385_init_pg(); //comment out to remove color bar
    return;
}
