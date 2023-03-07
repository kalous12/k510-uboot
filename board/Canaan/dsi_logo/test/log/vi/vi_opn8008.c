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
#include "vi/vi.h"

/************************************************************
*opn8008
*************************************************************/
/*
*wrap
*/


static int VI_TEST_Setopn8008Wrap(VI_WRAP_CONFIG_S *viwrapInfo )
{
	VI_CHECK_POINTER(viwrapInfo);
	//
	viwrapInfo->dphy_mode = 1;
	viwrapInfo->sony_mode = SONY_POL_MODE_DIS;
	//
	MIPI0_SENSOR_INFO *mipi0Info = &viwrapInfo->sensor_info.mipi0Info;
	mipi0Info->sensor_interface_enable = 1;
	mipi0Info->mipi_mode = 0;
	mipi0Info->wdr_mode = ISP_PIPE_WDR_NONE;
	mipi0Info->isp_pipeline = ISP_TOF;
	//
	MIPI1_SENSOR_INFO *mipi1Info = &viwrapInfo->sensor_info.mipi1Info;
	mipi1Info->sensor_interface_enable = 0;
	mipi1Info->mipi_mode = 0;
	//
	DVP_SENSOR_INFO   *dvpInfo = &viwrapInfo->sensor_info.dvpInfo;
	dvpInfo->sensor_interface_enable = 0;
	dvpInfo->mipi_mode = NORMAL_MODE;
	dvpInfo->tpgEn = FALSE;
	dvpInfo->isp_pipeline = ISP_R_2K; 
	//
	VI_TEST_SetWrap(viwrapInfo);
	return 0;
}
/*
*pipe
*/
static int VI_TEST_Setopn8008PipeCtrl(VI_PIPE_CTRL_INFO *ctrlInfo)
{
	VI_CHECK_POINTER(ctrlInfo);

    ctrlInfo->win_mode_en= 1;
    ctrlInfo->emb_en= 0;
    ctrlInfo->hsync_vsync_out_en= 1;
    ctrlInfo->sensor_input_swap_en= 0; 

    ctrlInfo->sync_source_sel= 0;
    ctrlInfo->input_ch_sel= 1;
    ctrlInfo->ch_mode_sel= 1;
    ctrlInfo->emb_enable= 0;

	ctrlInfo->isp_clk_pol= 1;
	ctrlInfo->isp_field_pol= 1;
	ctrlInfo->isp_hsync_pol= 1;
	ctrlInfo->isp_vsync_pol= 1;

	ctrlInfo->sen_mipi_clk_pol= 1;
	ctrlInfo->sen_mipi_field_pol = 1;
	ctrlInfo->sen_mipi_hsync_pol = 1;
	ctrlInfo->sen_mipi_vsync_pol = 1;

    ctrlInfo->emb_mode_sel= 0;
    ctrlInfo->emb_ecc_mode_en= 0;
    ctrlInfo->sync_code_remove_en= 0;
    ctrlInfo->sync_code_ext_en= 0;

	return 0;
}
/*
*timing
*/
static int VI_TEST_Setopn8008TimingCtrl(VI_PIPE_TIMING_CTRL_INFO *timingInfo)
{
	VI_CHECK_POINTER(timingInfo);

    timingInfo->input_pixel_type= 0; /*RAW input*/
    timingInfo->input_yuv_format= 0;
  //  timingInfo->output_yuv_format= 1;
    timingInfo->yuv_order= 0;
    timingInfo->raw_pixel_width= 2; /*RAW 12bit*/
    timingInfo->data_out_timming_ctrl= 3;/*four cycle delay*/
    timingInfo->sync_mode= 4;
    timingInfo->sync_pulse_mode= 1;
   // timingInfo->emb_timeout_set= ;
	return 0;
}
/*
*sync width
*/
static int VI_TEST_Setopn8008SyncWidth(VI_PIPE_SYNC_WIDTH_INFO *syncwidthInfo)
{
	VI_CHECK_POINTER(syncwidthInfo);

	syncwidthInfo->image_hsync_width = 0x7;
	syncwidthInfo->image_vsync_width = 0x7;

	return 0;
}
/*
*image size
*/
static int VI_TEST_Setopn8008ImageSize(VI_IMAGE_SZIE_INFO *imageSizeInfo)
{
	VI_CHECK_POINTER(imageSizeInfo);

	imageSizeInfo->vi_pipe_tpg_w_size_total.Width = 0x3fff;
	imageSizeInfo->vi_pipe_tpg_w_size_total.Height = 0x1f1;

	imageSizeInfo->vi_pipe_tpg_w_size_active.Width = 0x2e4;
	imageSizeInfo->vi_pipe_tpg_w_size_active.Height = 0x148;
	imageSizeInfo->vi_pipe_tpg_w_size_active.Width_st = 0x3fff;
	imageSizeInfo->vi_pipe_tpg_w_size_active.Height_st = 0x0;

	return 0;
}
/*
*tpg info
*/
static int VI_TEST_Setopn8008TpgInfo(VI_TPG_INFO  *tpgInfo)
{
	VI_CHECK_POINTER(tpgInfo);
	//
	VI_PIPE_TPG_DMA_INFO  *viTpgDmaInfo = &tpgInfo->viTpgDmaInfo;
    viTpgDmaInfo->dma_y_module_en     = FALSE;
    viTpgDmaInfo->dma_uv_module_en    = FALSE;
    viTpgDmaInfo->dma_tpg_read_en     = FALSE;
    viTpgDmaInfo->sync_out_en         = FALSE;
    viTpgDmaInfo->sw_triger_en        = FALSE;
    viTpgDmaInfo->dma_wr_ch_err_dec_en= FALSE;
    viTpgDmaInfo->dma_rd_ch_err_dec_en= FALSE;
	//
	tpgInfo->vi_pipe_w_addr_y0= ISP_TPG_W_Y_BUF;
	tpgInfo->vi_pipe_w_addr_y1= ISP_TPG_W_Y_BUF;
	tpgInfo->vi_pipe_w_addr_uv0= ISP_TPG_W_UV_BUF;
	tpgInfo->vi_pipe_w_addr_uv1= ISP_TPG_W_UV_BUF;
	tpgInfo->vi_pipe_w_addr_stride_y= ISP_TPG_W_Y_STRIDE;
	tpgInfo->vi_pipe_w_addr_stride_uv= ISP_TPG_W_UV_STRIDE;
	tpgInfo->vi_pipe_r_addr_y0= ISP_TPG_R_Y_BUF;
	tpgInfo->vi_pipe_r_addr_y1= ISP_TPG_R_Y_BUF;
	tpgInfo->vi_pipe_r_addr_stride_y= ISP_TPG_R_Y_STRIDE;
	//
	IMAGE_SIZE 	 *vi_pipe_tpg_r_size_total  = &tpgInfo->vi_pipe_tpg_r_size_total;
	vi_pipe_tpg_r_size_total->Width = 0x0;//0x897;
	vi_pipe_tpg_r_size_total->Height =  0x0;//0x464;
	//
	CROP_SIZE    *vi_pipe_tpg_r_size_active  = &tpgInfo->vi_pipe_tpg_r_size_active;
	vi_pipe_tpg_r_size_active->Width_st = 0x0;
	vi_pipe_tpg_r_size_active->Width =  0x0;//0x781;
	vi_pipe_tpg_r_size_active->Height_st = 0x0;
	vi_pipe_tpg_r_size_active->Height =  0x0;//0x437;
	//
#if 0
	VI_PIPE_DMA_CTRL_INFO *dmaCtrlInfo  = &tpgInfo->dmaCtrlInfo;

    dmaCtrlInfo->dma_y_outstand   = ;
    dmaCtrlInfo->dma_uv_outstand  = ;
    dmaCtrlInfo->dma_raw_outstand = ;
    dmaCtrlInfo->dma_y_blen       = ;
    dmaCtrlInfo->dma_uv_blen      = ;
    dmaCtrlInfo->dma_raw_blen     = ;
    dmaCtrlInfo->dma_y_uv_out_swap= 0;
    dmaCtrlInfo->dma_int_line_num = ;
#endif
	return 0;
}
/*
*isp tpg
*/
static int VI_TEST_Setopn8008IspTpg(VI_ISP_TPG_INFO *ispTpgInfo)
{
	VI_CHECK_POINTER(ispTpgInfo);

	ispTpgInfo->vi_pipe_tpg_en= FALSE;
	ispTpgInfo->vi_pipe_tpg_frm_ratio_mode= 0x1;
	ispTpgInfo->vi_pipe_tpg_frm_ratio= 0x1;
	ispTpgInfo->vi_tpg_sync_timing_gen_mode= 0x0;

	return 0;
}
/*
*tof tpg
*/
static int VI_TEST_Setopn8008TofTpg(VI_TOF_TPG_INFO *tofTpgInfo)
{
	VI_CHECK_POINTER(tofTpgInfo);

	tofTpgInfo->tof_mode_enable= FALSE;
	tofTpgInfo->vi_pipe_tpg_tof_frm_num= 0x0;
	tofTpgInfo->vi_pipe_tpg_tof_frm_stride= 0x0;//0x8;

	return 0;
}
/*
*
*/
static int VI_TEST_Setopn8008Pipe(unsigned char s8Index,VI_PIPE_CONFIG_S *vipipeInfo)
{
	VI_CHECK_POINTER(vipipeInfo);
	//
	VI_PIPE_CTRL_INFO *ctrlInfo = &vipipeInfo->ctrlInfo;
	VI_TEST_Setopn8008PipeCtrl(ctrlInfo);
	//
	VI_PIPE_TIMING_CTRL_INFO *timingInfo = &vipipeInfo->timingInfo;
	VI_TEST_Setopn8008TimingCtrl(timingInfo);
	//
	VI_PIPE_SYNC_WIDTH_INFO *syncwidthInfo = &vipipeInfo->syncwidthInfo;
	VI_TEST_Setopn8008SyncWidth(syncwidthInfo);
	//
	VI_IMAGE_SZIE_INFO *imageSizeInfo = &vipipeInfo->imageSizeInfo;
	VI_TEST_Setopn8008ImageSize(imageSizeInfo);
	//
	VI_TPG_INFO  *tpgInfo = &vipipeInfo->tpgInfo;
	VI_TEST_Setopn8008TpgInfo(tpgInfo);
	//
	VI_ISP_TPG_INFO	*ispTpgInfo = &vipipeInfo->ispTpgInfo;
	VI_TEST_Setopn8008IspTpg(ispTpgInfo);
	//
	VI_TOF_TPG_INFO	*tofTpgInfo = &vipipeInfo->tofTpgInfo;
	VI_TEST_Setopn8008TofTpg(tofTpgInfo);
	//
	VI_TEST_SetPipe(s8Index,vipipeInfo);
	return 0;
}
/*
*
*/
int VI_TEST_opn8008(void)
{
	VI_WRAP_CONFIG_S viwrapInfo;
	VI_PIPE_CONFIG_S vipipeInfo;
	//
	VI_TEST_Setopn8008Wrap(&viwrapInfo );
	//
	int s8Index = VI_MIPI_CSI00_PIPE_ID;//6;
	VI_TEST_Setopn8008Pipe(s8Index,&vipipeInfo);
	
	return 0;
}


#if 0
int VI_DRV_TEST_Opn8008Mode(void)
{
	VI_DEV viDev = 0;
	unsigned char s8PipeIndex = 0;
	VI_DRV_CTL_S *pstMipiDrvCtx = NULL;
	VI_WRAP_CSI_MODE_CTL_S *pstCsiMode = NULL;
	VI_WRAP_ISP_CH_SEL_S *pstIspChSel = NULL;
	VI_WRAP_CLOCK_CTL_S *pstClkConf = NULL;
	VI_WRAP_DMA_ATTR_S *pstDmaAttr = NULL;

	VI_PIPE_CTRL_S *pstPipeCtl = NULL;
	VI_PIPE_TIMING_CTRL_S *pstPipeTiming = NULL;
	VI_PIPE_SYNC_WIDTH_S *pstPipeSyncWidth = NULL;
	VI_PIPE_IMAGE_ATTR_S *pstImageAttr = NULL;

	pstMipiDrvCtx = VI_DRV_GET_CTX(viDev);
	VI_CHECK_POINTER(pstMipiDrvCtx);

	/*reset the vin wrap*/
	VI_DRV_WRAP_SetReset();

	/*config vi wrapper attibute*/
	pstCsiMode = &(pstMipiDrvCtx->stWrapAttr.stWrapCsiCtl);
	pstCsiMode->mipi_csi_0_mode = 0; 
	pstCsiMode->mipi_csi_1_mode = 0; 
	pstCsiMode->mipi_dphy_mode = 1; 
	VI_DRV_WRAP_SetCtlMode(pstCsiMode);


	/*config vi isp channel*/
	pstIspChSel = &(pstMipiDrvCtx->stWrapAttr.stWrapIspChSel);
	VI_DRV_GetWraptIspChannelDefaulConfig(pstIspChSel);
	pstIspChSel->isp_2k_l_ch_sel = VI_MIPI_CSI10_PIPE_ID;
	pstIspChSel->isp_2k_m_ch_sel = VI_MIPI_CSI11_PIPE_ID;
	pstIspChSel->isp_2k_s_ch_sel = VI_MIPI_CSI12_PIPE_ID;
	pstIspChSel->isp_3d_ch_sel = VI_MIPI_CSI00_PIPE_ID;
	VI_DRV_WRAP_SetIspChSel(pstIspChSel);

	/*enable vi clock*/
	pstClkConf = &(pstMipiDrvCtx->stWrapAttr.stWarpClockCtl);
	VI_DRV_GetWrapClkDefaultConfig(pstClkConf);
	pstClkConf->csi_00_dma_clk_en = 1;
	pstClkConf->csi_01_dma_clk_en = 1;
	pstClkConf->csi_02_dma_clk_en = 1;
	pstClkConf->csi_01_pixel_clk_en = 1;
	pstClkConf->csi_01_pixel_clk_en = 1;
	pstClkConf->csi_02_pixel_clk_en = 1;	
	pstClkConf->csi_10_dma_clk_en = 1;
	pstClkConf->csi_11_dma_clk_en = 1;
	pstClkConf->csi_12_dma_clk_en = 1;
	pstClkConf->csi_11_pixel_clk_en = 1;
	pstClkConf->csi_11_pixel_clk_en = 1;
	pstClkConf->csi_12_pixel_clk_en = 1;
	pstClkConf->dvp_0_dma_clk_en = 1;
	pstClkConf->dvp_1_dma_clk_en = 1;
	pstClkConf->axi_rd_ch_clk_en = 1;
	pstClkConf->axi_wr_ch_clk_en = 1;
	VI_DRV_WRAP_SetClockCtl(pstClkConf);

	/*config vi DMA */
	pstDmaAttr = &(pstMipiDrvCtx->stWrapAttr.stWrapDmaAttr);
	VI_DRV_GetWrapDmaDefaultConfig(pstDmaAttr);
	VI_DRV_WRAP_SetDmaAttr(pstDmaAttr);
	
	/*call wrap config done*/
	VI_DRV_WRAP_SetConfigDone();

	
	/*config vi pipe 0 attibute*/	
	s8PipeIndex = 0;
	pstMipiDrvCtx->stPipeId[s8PipeIndex] = VI_MIPI_CSI00_PIPE_ID;

	/*config pipe control*/
	pstPipeCtl = &(pstMipiDrvCtx->stPipeAttr[s8PipeIndex].stPipeCtl);
	pstPipeCtl->win_mode_en = 1;
	pstPipeCtl->hsync_vsync_out_en = 1;
	
	pstPipeCtl->sen_mipi_clk_pol = 1;
	pstPipeCtl->sen_mipi_field_pol = 1;
	
	pstPipeCtl->isp_clk_pol = 1;	
	pstPipeCtl->isp_vsync_pol = 1;
	pstPipeCtl->isp_hsync_pol = 1;
	pstPipeCtl->isp_field_pol = 1;
	
	pstPipeCtl->input_ch_sel = 1;
	pstPipeCtl->ch_mode_sel = 1;
	VI_DRV_PIPE_SetPipeCtl(pstMipiDrvCtx->stPipeId[s8PipeIndex], pstPipeCtl);

	/*config pipe timing and vi input info, the config values related to sensor*/
	pstPipeTiming = &(pstMipiDrvCtx->stPipeAttr[s8PipeIndex].stTimingCtl);
	pstPipeTiming->input_pixel_type = 0;/*RAW input*/
	pstPipeTiming->input_yuv_format = 0;
	pstPipeTiming->yuv_order = 0;
	pstPipeTiming->raw_pixel_width = 2; /*RAW 12bit*/
	pstPipeTiming->data_out_timming_ctrl = 3;/*four cycle delay*/
	pstPipeTiming->sync_mode = 4;
	VI_DRV_PIPE_SetTimingCtl(pstMipiDrvCtx->stPipeId[s8PipeIndex], pstPipeTiming);

	/*config pipe sync widht*/
	pstPipeSyncWidth = &(pstMipiDrvCtx->stPipeAttr[s8PipeIndex].stPipeSyncAttr);
	pstPipeSyncWidth->image_hsync_width = 7;
	pstPipeSyncWidth->image_vsync_width = 7;
	VI_DRV_PIPE_SetSyncWidthCtl(pstMipiDrvCtx->stPipeId[s8PipeIndex], pstPipeSyncWidth);
	
	/*config pipe image info*/
	pstImageAttr =  &(pstMipiDrvCtx->stPipeAttr[s8PipeIndex].stPipeImageAttr);
	
	pstImageAttr->stImageSizeTotal.image_v_size_total = 0x3fff;
	pstImageAttr->stImageSizeTotal.image_h_size_total = 0x1f1;
	pstImageAttr->stImageSizeActive.image_v_size_active = 0x2e4;
	pstImageAttr->stImageSizeActive.image_h_size_active = 0x148;


	pstImageAttr->stImageStart.image_v_start = 0x3fff;
	pstImageAttr->stImageStart.image_h_start = 0x0;
	VI_DRV_PIPE_SetImageAttr(pstMipiDrvCtx->stPipeId[s8PipeIndex], pstImageAttr);
	
	/*call pipe config done*/
	VI_DRV_PIPE_SetConfigDoneCtl(pstMipiDrvCtx->stPipeId[s8PipeIndex]);

	
	/*config vi pipe 0 attibute*/	
	s8PipeIndex = 0;
	pstMipiDrvCtx->stPipeId[s8PipeIndex] = VI_MIPI_CSI00_PIPE_ID;

	/*config pipe control*/
	pstPipeCtl = &(pstMipiDrvCtx->stPipeAttr[s8PipeIndex].stPipeCtl);
	pstPipeCtl->win_mode_en = 1;
	pstPipeCtl->hsync_vsync_out_en = 1;
	
	pstPipeCtl->sen_mipi_clk_pol = 1;
	pstPipeCtl->sen_mipi_field_pol = 1;
	
	pstPipeCtl->isp_clk_pol = 1;	
	pstPipeCtl->isp_vsync_pol = 1;
	pstPipeCtl->isp_hsync_pol = 1;
	pstPipeCtl->isp_field_pol = 1;
	
	pstPipeCtl->input_ch_sel = 1;
	pstPipeCtl->ch_mode_sel = 1;
	VI_DRV_PIPE_SetPipeCtl(pstMipiDrvCtx->stPipeId[s8PipeIndex], pstPipeCtl);

	/*config pipe timing and vi input info, the config values related to sensor*/
	pstPipeTiming = &(pstMipiDrvCtx->stPipeAttr[s8PipeIndex].stTimingCtl);
	pstPipeTiming->input_pixel_type = 0;/*RAW input*/
	pstPipeTiming->input_yuv_format = 0;
	pstPipeTiming->yuv_order = 0;
	pstPipeTiming->raw_pixel_width = 2; /*RAW 12bit*/
	pstPipeTiming->data_out_timming_ctrl = 3;/*four cycle delay*/
	pstPipeTiming->sync_mode = 4;
	VI_DRV_PIPE_SetTimingCtl(pstMipiDrvCtx->stPipeId[s8PipeIndex], pstPipeTiming);

	/*config pipe sync widht*/
	pstPipeSyncWidth = &(pstMipiDrvCtx->stPipeAttr[s8PipeIndex].stPipeSyncAttr);
	pstPipeSyncWidth->image_hsync_width = 7;
	pstPipeSyncWidth->image_vsync_width = 7;
	VI_DRV_PIPE_SetSyncWidthCtl(pstMipiDrvCtx->stPipeId[s8PipeIndex], pstPipeSyncWidth);
	
	/*config pipe image info*/
	pstImageAttr =  &(pstMipiDrvCtx->stPipeAttr[s8PipeIndex].stPipeImageAttr);
	
	pstImageAttr->stImageSizeTotal.image_v_size_total = 0x3fff;
	pstImageAttr->stImageSizeTotal.image_h_size_total = 0x1f1;
	pstImageAttr->stImageSizeActive.image_v_size_active = 0x2e4;
	pstImageAttr->stImageSizeActive.image_h_size_active = 0x148;


	pstImageAttr->stImageStart.image_v_start = 0x3fff;
	pstImageAttr->stImageStart.image_h_start = 0x0;
	VI_DRV_PIPE_SetImageAttr(pstMipiDrvCtx->stPipeId[s8PipeIndex], pstImageAttr);
	
	/*call pipe config done*/
	VI_DRV_PIPE_SetConfigDoneCtl(pstMipiDrvCtx->stPipeId[s8PipeIndex]);

	
	/*config vi pipe 1 attibute*/	
	s8PipeIndex = 3;
	pstMipiDrvCtx->stPipeId[s8PipeIndex] = VI_MIPI_CSI10_PIPE_ID;

	/*config pipe control*/
	pstPipeCtl = &(pstMipiDrvCtx->stPipeAttr[s8PipeIndex].stPipeCtl);
	pstPipeCtl->win_mode_en = 1;
	pstPipeCtl->hsync_vsync_out_en = 1;
	
	pstPipeCtl->sen_mipi_clk_pol = 1;
	pstPipeCtl->sen_mipi_field_pol = 1;
	
	pstPipeCtl->isp_clk_pol = 1;	
	pstPipeCtl->isp_vsync_pol = 1;
	pstPipeCtl->isp_hsync_pol = 1;
	pstPipeCtl->isp_field_pol = 1;
	
	pstPipeCtl->input_ch_sel = 1;
	pstPipeCtl->ch_mode_sel = 1;
	VI_DRV_PIPE_SetPipeCtl(pstMipiDrvCtx->stPipeId[s8PipeIndex], pstPipeCtl);

	/*config pipe timing and vi input info, the config values related to sensor*/
	pstPipeTiming = &(pstMipiDrvCtx->stPipeAttr[s8PipeIndex].stTimingCtl);
	pstPipeTiming->input_pixel_type = 0;/*RAW input*/
	pstPipeTiming->input_yuv_format = 0;
	pstPipeTiming->yuv_order = 2;
	pstPipeTiming->raw_pixel_width = 0; /*RAW 12bit*/
	pstPipeTiming->data_out_timming_ctrl = 3;/*four cycle delay*/
	pstPipeTiming->sync_mode = 4;
	VI_DRV_PIPE_SetTimingCtl(pstMipiDrvCtx->stPipeId[s8PipeIndex], pstPipeTiming);

	/*config pipe sync widht*/
	pstPipeSyncWidth = &(pstMipiDrvCtx->stPipeAttr[s8PipeIndex].stPipeSyncAttr);
	pstPipeSyncWidth->image_hsync_width = 7;
	pstPipeSyncWidth->image_vsync_width = 7;
	VI_DRV_PIPE_SetSyncWidthCtl(pstMipiDrvCtx->stPipeId[s8PipeIndex], pstPipeSyncWidth);
	
	/*config pipe image info*/
	pstImageAttr =  &(pstMipiDrvCtx->stPipeAttr[s8PipeIndex].stPipeImageAttr);
	
	pstImageAttr->stImageSizeTotal.image_v_size_total = 0x464;
	pstImageAttr->stImageSizeTotal.image_h_size_total = 0xa4f;
	pstImageAttr->stImageSizeActive.image_v_size_active = 0x437;
	pstImageAttr->stImageSizeActive.image_h_size_active = 0x781;


	pstImageAttr->stImageStart.image_v_start = 0x1fff;
	pstImageAttr->stImageStart.image_h_start = 0x0;
	VI_DRV_PIPE_SetImageAttr(pstMipiDrvCtx->stPipeId[s8PipeIndex], pstImageAttr);
	
	/*call pipe config done*/
	VI_DRV_PIPE_SetConfigDoneCtl(pstMipiDrvCtx->stPipeId[s8PipeIndex]);
	return 0;
}
#endif
