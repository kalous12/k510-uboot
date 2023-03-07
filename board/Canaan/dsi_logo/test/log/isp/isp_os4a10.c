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
#include "isp/isp.h"
#include "isp/isp_ds_calc.h"

/******************************************************************************
*wrap
******************************************************************************/
static int ISP_TEST_setOs4a10NormalWrap(ISP_WRAP_CONFIG_S *ispWrapInfo,ISP_SIZE_S *sizeInfo)
{
    ISP_CHECK_POINTER(ispWrapInfo);

    ispWrapInfo->isp_out_sel = MAIN_OUT;
    ispWrapInfo->dvp_ch_mode = BT1120_MIPI;
    ispWrapInfo->hist_3a_out_en = 0;
    //WDR
    ispWrapInfo->wdrInfo.wdr_mode = ISP_PIPE_WDR_NONE;
    //3DNR
    ispWrapInfo->nr3dInfo.nr3d_en = 0;
    ispWrapInfo->nr3dInfo.nr3d_mfbcd_en = 0;
    ispWrapInfo->nr3dInfo.nr3d_mv_out_en = 0;
    //LDC
    ispWrapInfo->ldcInfo.ldc_en = 0;
    //MAIN
    IMAGE_SIZE *main_size = &sizeInfo->in_size;
    ispWrapInfo->mainInfo.main_out_en = 1;
    ispWrapInfo->mainInfo.main_size.Width = main_size->Width;//1920;
    ispWrapInfo->mainInfo.main_size.Height = main_size->Height;//1080;
    //DS0 out
    IMAGE_SIZE *ds0_size = &sizeInfo->ds0_size;
    ispWrapInfo->ds0Info.ds0_out_en  = 0;
    ispWrapInfo->ds0Info.ds0_osd0_en = 0;
    ispWrapInfo->ds0Info.ds0_osd1_en = 0;
    ispWrapInfo->ds0Info.ds0_osd2_en = 0;
    ispWrapInfo->ds0Info.pix_remap_out0_en = 0;
    ispWrapInfo->ds0Info.ds0_size.Width = ds0_size->Width;//960 
    ispWrapInfo->ds0Info.ds0_size.Height = ds0_size->Height;//1080
    //DS1 out
    IMAGE_SIZE *ds1_size = &sizeInfo->ds1_size;
    ispWrapInfo->ds1Info.ds1_out_en = 0;
    ispWrapInfo->ds1Info.ds1_osd0_en = 0;
    ispWrapInfo->ds1Info.ds1_osd1_en = 0;
    ispWrapInfo->ds1Info.ds1_osd2_en = 0;
    ispWrapInfo->ds1Info.pix_remap_out1_en = 0;
    ispWrapInfo->ds1Info.ds1_size.Width = ds1_size->Width;//320;
    ispWrapInfo->ds1Info.ds1_size.Height = ds1_size->Height;//240;
    //DS2 out
    IMAGE_SIZE *ds2_size = &sizeInfo->ds2_size;
    ispWrapInfo->ds2Info.ds2_out_en = 0;
    ispWrapInfo->ds2Info.ds2_osd0_en = 0;
    ispWrapInfo->ds2Info.ds2_osd1_en = 0;
    ispWrapInfo->ds2Info.ds2_size.Width = ds2_size->Width;//256;
    ispWrapInfo->ds2Info.ds2_size.Height = ds2_size->Height;//240;
    //
    ISP_TEST_setWrap(ispWrapInfo);

    return 0;
}
/******************************************************************************
*core
******************************************************************************/
//ITC
static int ISP_TEST_setItc(ISP_ITC_CONFIG_S *itcInfo,IMAGE_SIZE *in_size)
{
    ISP_CHECK_POINTER(itcInfo);

 	  itcInfo->hsync_pol = ISP_SYNC_POL_LOW;
	  itcInfo->vsync_pol = ISP_SYNC_POL_LOW;
	  itcInfo->hsync_input_timing = HSYNC_BASE_ON_INPUT;
	  itcInfo->vsync_input_timing = VSYNC_BASE_ON_INPUT;   
	  itcInfo->flip_ctl = FALSE;         
    itcInfo->video_fmt_sel = ISP_RGBRAW_DATA;    
    itcInfo->total_img_size.Width = 2200-1;
    itcInfo->total_img_size.Height = 1125-1;
    itcInfo->itc_out_szie.Width_st = 0x3;//0;
    itcInfo->itc_out_szie.Width = in_size->Width;//1920;
    itcInfo->itc_out_szie.Height_st = 0x2;//0;
    itcInfo->itc_out_szie.Height = in_size->Height;//1080;

    return 0;
}
//TPG
static int ISP_TEST_setTpg(ISP_TPG_CONFIG_S	*tpgInfo)
{
    ISP_CHECK_POINTER(tpgInfo);

    tpgInfo->tpg_en = FALSE;
	tpgInfo->tpg_sel = 0x9;
    tpgInfo->bayer_mode_sel = 0x3; //BGGR/RGGB /GRGB/GBGR 
    tpgInfo->motion_mode_sel = 0x0;    
    tpgInfo->wdr_l_mul_data = 0x0;  
    tpgInfo->wdr_m_mul_data = 0x0;  
    tpgInfo->wdr_s_mul_data = 0x0; 

    return 0;
}
//BLC
static int ISP_TEST_setBlc(ISP_BLC_CONFIG_S	*blcInfo)
{
    ISP_CHECK_POINTER(blcInfo);

    blcInfo->blc_en = TRUE;
    blcInfo->blc_offset =0x0;
    blcInfo->blc_ratio =0x100;

    return 0;
}
//Lsc
static int ISP_TEST_setLsc(ISP_LSC_CONFIG_S	*lscInfo)
{
    ISP_CHECK_POINTER(lscInfo);

    lscInfo->lsc_en = FALSE;
    lscInfo->lsc_v_center = 0x21c;
    lscInfo->lsc_h_center = 0x3c0;
    lscInfo->lsc_r_ratio = 0x100;
    lscInfo->lsc_g_ratio = 0x100;
    lscInfo->lsc_b_ratio = 0x100;
    lscInfo->lsc_ir_ratio = 0;
    return 0;
}
//AE
static int ISP_TEST_setAE(ISP_AE_CONFIG_S	*aeInfo)
{
    ISP_CHECK_POINTER(aeInfo);

    aeInfo->ae_as_en = TRUE; 
    aeInfo->ae_ag_en = TRUE;      
    aeInfo->ae_airis_en = FALSE;      
    aeInfo->ae_enter_ls_sel = 0x1; 
    aeInfo->ae_exit_ls_sel = 0x0;     
    aeInfo->ae_win_mode_sel = 0x0;    
    aeInfo->ae_back_light_mode_sel = 0x1;
    aeInfo->ae_day_change_en = FALSE;    
    aeInfo->ae_day_change_sel = 0x0;

    aeInfo->ae_win_size.v_start = 0x10e;
    aeInfo->ae_win_size.v_end = 0x32a;
    aeInfo->ae_win_size.h_start = 0x1e0;
    aeInfo->ae_win_size.h_end = 0x5a0;

    aeInfo->ae_tar_bright = 0x50;    
    aeInfo->ae_tar_bright_range = 0x8;     
    aeInfo->ae_l_ex_time = 512;
    aeInfo->ae_m_ex_time = 32;
    aeInfo->ae_s_ex_time = 2;     
    aeInfo->ae_agc = 0x0;       
    aeInfo->ae_ad_shuttle_freq = 0x1;
    aeInfo->ae_ad_gain_freq = 0x0;    
    aeInfo->ae_adjust_step_max = 0x11;     
    aeInfo->ae_ex_value_max = 0x460;  
    aeInfo->ae_ex_value_mid = 0x230;    
    aeInfo->ae_ex_value_min = 0x10;     
    aeInfo->ae_gain_value_max = 0x900;    
    aeInfo->ae_gain_value_mid = 0x200;
    aeInfo->ae_gain_value_min = 0x0;    
    aeInfo->ae_dn_switch_ad_step_max = 0x200;
    aeInfo->ae_dn_switch_wait_time = 0xff;
    aeInfo->ape_max_diff = 0x0c;    
    aeInfo->ape_drv_signal_max = 0xf00;    
    aeInfo->ape_coeff_distance = 0x0;    
    aeInfo->ape_coeff_speed = 0x0;
    aeInfo->ape_coeff_acceleration = 0x0;     
    aeInfo->ape_drv_manual_value = 0xfff;  
    aeInfo->ape_damp_manual_value = 0x800;

    return 0;
}
//AWB
static int ISP_TEST_setAWB(ISP_AWB_CONFIG_S	*awbInfo)
{
    ISP_CHECK_POINTER(awbInfo);

    awbInfo->awb_d65_en = TRUE; 
    awbInfo->awb_ccm_en = TRUE; 
    awbInfo->awb_en = TRUE;     
    awbInfo->awb_mode_sel = 0x1;

    awbInfo->awb_hist_mode_sel = 0x0;
    awbInfo->awb_veri_en = FALSE;      
    awbInfo->awb_fb_en = 0x1;     
    awbInfo->awb_value_save_en = FALSE;
    awbInfo->awb_ccm_adp_adjust_en = TRUE;
    awbInfo->awb_stab_en = TRUE; 

    awbInfo->awb_d65_red_gain = 0x204;
    awbInfo->awb_d65_blue_gain = 0x1e8;

    awbInfo->ccm_coff[0][0] = 0x160;
    awbInfo->ccm_coff[0][1] = 0x60;
    awbInfo->ccm_coff[0][2] = 0x04;  
    awbInfo->ccm_coff[1][0] = 0x64;
    awbInfo->ccm_coff[1][1] = 0x1a0;
    awbInfo->ccm_coff[1][2] = 0x40;  
    awbInfo->ccm_coff[2][0] = 0x4;
    awbInfo->ccm_coff[2][1] = 0x40;
    awbInfo->ccm_coff[2][2] = 0x144;  
    awbInfo->ccm_correct_coff = 0x104;

	awbInfo->awb_win_size.v_start = 0x0;
    awbInfo->awb_win_size.v_end = 0x437; 
    awbInfo->awb_win_size.h_start = 0x0; 
    awbInfo->awb_win_size.h_end = 0x77f; 

    awbInfo->awb_correct_diff_th = 0x20;     
    awbInfo->awb_color_changeres_time = 0x08;
    awbInfo->awb_historgram_th = 0x40;

    awbInfo->awb_red_gain_adjust = 0x100;     
    awbInfo->awb_green_gain_adjust = 0x100;   
    awbInfo->awb_blue_gain_adjust = 0x100;    
    awbInfo->awb_red_max_value = 0x200;
    awbInfo->awb_blue_max_value = 0x3ff;      
    awbInfo->awb_red_min_value = 0x40;
    awbInfo->awb_blue_min_value = 0x80;

//    awbInfo->awb_red_obj_value = ;
//    awbInfo->awb_blue_obj_value = ;

    return 0;
}
//WDR
static int ISP_TEST_setWDR(ISP_WDR_CONFIG_S	*wdrInfo)
{
    ISP_CHECK_POINTER(wdrInfo);

    wdrInfo->wdr_fusion_en= FALSE;      
    wdrInfo->wdr_frame_sel= 0x0;      
    wdrInfo->wdr_adp_adjust_en= FALSE;  
    wdrInfo->wdr_stab_en= FALSE;
    
    wdrInfo->wdr_en= FALSE;             
    wdrInfo->wdr_ghost_remove_en= FALSE; 
    wdrInfo->wdr_3frame_out_mode= 0x0;
    wdrInfo->wdr_mode_sel= 0x0;
    
    wdrInfo->wdr_2frame_ex_ratio= 0x0;
    wdrInfo->wdr_3frame_ex_ratio= 0x2; 
    wdrInfo->wdr_stat_img_sel= 0x0;   
    wdrInfo->wdr_ltm_data_sel= 0x0;
    
    wdrInfo->wdr_tz_data_sel= 0x0;
    wdrInfo->wdr_remove_purple_en= FALSE;

    wdrInfo->wdr_over_ex_ratio_th1= 0x180;    
    wdrInfo->wdr_over_ex_ratio_th2= 0x20;
    wdrInfo->wdr_fusion_ratio_th= 0xc0;    
    wdrInfo->wdr_fusion_value1= 0x00;  
    wdrInfo->wdr_fusion_value2= 0xff;

    return 0;
}
//csc
static int ISP_TEST_setCSC(ISP_CSC_CONFIG_S	*cscInfo)
{
    ISP_CHECK_POINTER(cscInfo);

    cscInfo->csc_r2y[0][0] = 0x99;
    cscInfo->csc_r2y[0][1] = 0x13b;
    cscInfo->csc_r2y[0][2] = 0x4b;
    cscInfo->csc_r2y[1][0] = 0x12d;
    cscInfo->csc_r2y[1][1] = 0x108;
    cscInfo->csc_r2y[1][2] = 0x94;
    cscInfo->csc_r2y[2][0] = 0x3a;
    cscInfo->csc_r2y[2][1] = 0x33;
    cscInfo->csc_r2y[2][2] = 0xdf;

    return 0;
}
//ada
static int ISP_TEST_setADA(ISP_ADA_CONFIG_S	*adaInfo)
{
    ISP_CHECK_POINTER(adaInfo);

    adaInfo->ada_rgb_gamma_en= TRUE; 
    adaInfo->ada_yuv_gamma_en= TRUE; 
    adaInfo->ada_adjust_en= TRUE;    
    adaInfo->ada_img_stab_en= TRUE;
    
    adaInfo->ada_ccr_en= TRUE;       
    adaInfo->ada_adp_en= TRUE;       
    adaInfo->ada_adp_ccr_en= FALSE;   
    adaInfo->ada_stat_mode_sel= 0x0;
        
    adaInfo->ada_enh_mode_sel= 0x2;
    adaInfo->ada_stat_max_value= 0x40; 
    adaInfo->ada_ad_stren_max_value= 0x40;
     
    adaInfo->ada_win_size.h_start = 0x0;
    adaInfo->ada_win_size.h_end = 0x77f;
    adaInfo->ada_win_size.v_start = 0x0;
    adaInfo->ada_win_size.v_end = 0x437;

    return 0;
}
//RGBIR
static int ISP_TEST_setRgbir(ISP_RGBIR_CONFIG_S	*rgbirInfo)
{
    ISP_CHECK_POINTER(rgbirInfo);
    
    rgbirInfo->rgbir_en = FALSE;   
    rgbirInfo->rgbir_rtf_en = FALSE;    
    rgbirInfo->rgbir_rpc_en = FALSE;    
    rgbirInfo->rgbir_fusion_en = FALSE;
    
    rgbirInfo->rgbir_output_sel = 0x0;
 
    rgbirInfo->rgbir_rpc_max_value = 0x100; 
    rgbirInfo->rgbir_rpc_color_coff = 0x0;
    rgbirInfo->rgbir_rpc_luma_coff = 0x0; 
    
    rgbirInfo->rgbir_rpc_th = 0x100;       
    rgbirInfo->rgbir_rpc_th1 = 0x100;
 
    return 0;
}   
//2dnr
static int ISP_TEST_setNr2d(ISP_NR2D_CONFIG_S	*nr2dInfo)
{
    ISP_CHECK_POINTER(nr2dInfo);
    
    nr2dInfo->d2nr_pcf_en= TRUE;       
    nr2dInfo->d2nr_raw_en= TRUE;       
    nr2dInfo->d2nr_edge_en= TRUE;      
    nr2dInfo->d2nr_bap_en= TRUE;       
    
    nr2dInfo->d2nr_luma_en= TRUE;      
    nr2dInfo->d2nr_chroma_en= TRUE;    
    nr2dInfo->d2nr_pcf_adp_en= TRUE;   
    nr2dInfo->d2nr_raw_adp_en= TRUE;   
    
    nr2dInfo->d2nr_luma_adp_en= TRUE;  
    nr2dInfo->d2nr_chroma_adp_en= TRUE;

    nr2dInfo->d2nr_raw_intensity= 0x80;
    nr2dInfo->d2nr_bap_intensity= 0x1ff;
    nr2dInfo->d2nr_edge_intensity= 0x300;
    nr2dInfo->d2nr_luma_intensity= 0x80;
    nr2dInfo->d2nr_chroma_intensity= 0x80;

    return 0;
}     
//3dnr
static int ISP_TEST_setNr3d(ISP_NR3D_CONFIG_S	*nr3dInfo)
{
    ISP_CHECK_POINTER(nr3dInfo);

    nr3dInfo->d3nr_en = FALSE;            
    nr3dInfo->d3nr_pre_luma_en = FALSE;  
    nr3dInfo->d3nr_pre_chroma_en = FALSE; 
    nr3dInfo->d3nr_main_luma_en = FALSE;
    
    nr3dInfo->d3nr_main_chroma_en = FALSE;
    nr3dInfo->d3nr_post_luma_en = FALSE;  
    nr3dInfo->d3nr_post_chroma_en = FALSE;
    nr3dInfo->d3nr_2d_luma_en = FALSE;
    
    nr3dInfo->d3nr_2d_chroma_en = FALSE;  
    nr3dInfo->d3nr_wb_en = FALSE;         
    nr3dInfo->d3nr_wb_sel = 0x0;
    nr3dInfo->d3nr_adp_luma_en = FALSE;
    
    nr3dInfo->d3nr_adp_chroma_en = FALSE;

    nr3dInfo->d3nr_pre_luma_th = 0x40;        
    nr3dInfo->d3nr_pre_luma_intensity = 0x40;   
    nr3dInfo->d3nr_pre_chroma_intensity = 0x20;
    
    nr3dInfo->d3nr_mid_filter_th = 0x80;
    nr3dInfo->d3nr_pre_mid_filter_th = 0x8;    
    nr3dInfo->d3nr_cur_mid_filter_th = 0x80;    
    nr3dInfo->d3nr_low_pass_filter_th = 0x80;
    nr3dInfo->d3nr_luma_th = 0x40;             
    nr3dInfo->d3nr_min_value = 0;
    nr3dInfo->d3nr_luma_intensity = 0x80;
    
    nr3dInfo->d3nr_chroma_intensity = 0x80;    
    nr3dInfo->d3nr_post_edge_th = 0x40;        
    nr3dInfo->d3nr_post_luma_intensity = 0x40;  
    nr3dInfo->d3nr_post_chroma_intensity = 0x10;
  
    return 0;
}   
//Enh
static int ISP_TEST_setEnh(ISP_ENH_CONFIG_S	*enhInfo)
{
    ISP_CHECK_POINTER(enhInfo);

    enhInfo->enh_ltm_en = TRUE;       
    enhInfo->enh_sharp_en = TRUE;     
    enhInfo->enh_cc_en = TRUE;        
    enhInfo->enh_adp_ltm_en = TRUE;
    
    enhInfo->enh_adp_sharp_en = TRUE; 
    enhInfo->enh_adp_cc_en = TRUE;    
    enhInfo->ltm_gain = 0xc0;  
    enhInfo->ltm_th = 0x80;    
    
    enhInfo->enh_nr_th = 0x08; 
    enhInfo->enh_th1 = 0x80;
    enhInfo->enh_th2 = 0x100;
    enhInfo->sharp_gain = 0xc0; 

    return 0;
}  
//POST
static int ISP_TEST_setPost(ISP_POST_CONFIG_S *postInfo)
{
    ISP_CHECK_POINTER(postInfo);

    postInfo->post_cont_ad_en= TRUE;   
    postInfo->post_luma_ad_en= TRUE;   
    postInfo->post_satu_ad_en= TRUE;   
    postInfo->cont_ad_intensity= 0x80;    
    postInfo->luma_ad_intensity= 0x80;
    postInfo->satu_ad_intensity= 0x80; 
  
    return 0;
}  
//otc
static int ISP_TEST_setOtc(ISP_OTC_CONFIG_S	*otcInfo,IMAGE_SIZE *out_size)
{
    ISP_CHECK_POINTER(otcInfo);

    otcInfo->post_otc_en = FALSE;  
    otcInfo->otc_yc_sel = 0x0;        
    otcInfo->otc_uv_format_sel = 0x1; 
    otcInfo->otc_hsync_pol_sel = 0x0;
    otcInfo->otc_vsync_pol_sel = 0x0;
	otcInfo->otc_out_size.Width_st = 0x4;
    otcInfo->otc_out_size.Width = out_size->Width;//1920; 
    otcInfo->otc_out_size.Height_st = 0x4; 
    otcInfo->otc_out_size.Height = out_size->Height;//1080; 
  
    return 0;
}    
//ldc
static int ISP_TEST_setLdc(ISP_LDC_CONFIG_S	*ldcInfo)
{
    ISP_CHECK_POINTER(ldcInfo);

    ldcInfo->ldc_en = FALSE;
    ldcInfo->ldc_arith_en = FALSE;   
    ldcInfo->ldc_req_freq = 0x3f;     
    ldcInfo->ldc_stt_ln = 0x21c;
    ldcInfo->ldc_h_center_pos = 950;
    ldcInfo->ldc_v_center_pos = 538;
    ldcInfo->ldc_rectify_cr = 0x2ac;    
    ldcInfo->ldc_rectify_cz = 0x2ac; 
   
    return 0;
}    
//af
static int ISP_TEST_setAf(ISP_AF_CONFIG_S	*afInfo)
{
    ISP_CHECK_POINTER(afInfo);

    afInfo->af_stat_en  = FALSE;
    afInfo->af_stat_mode_sel = 0x0;
    afInfo->af_win_size.h_start =0x0;
    afInfo->af_win_size.h_end =0x77F;
    afInfo->af_win_size.v_start =0x0;
    afInfo->af_win_size.v_end =0x437;
    return 0;
} 
//3dnr mfbc
static int ISP_TEST_setIspMfbc(ISP_MFBC_CONFIG_S *mfbcInfo,IMAGE_SIZE *in_size)
{
    ISP_CHECK_POINTER(mfbcInfo);
		mfbcInfo->mfbc_out_format_cfg = NR3D_YUV422_ENABLE;
		mfbcInfo->mfbc_input_size.Width = in_size->Width ;//1920 - 1;
		mfbcInfo->mfbc_input_size.Height = in_size->Height ;//1080 - 1;
		//
		ISP_MFBCD_BUF_S  *yDataBufInfo = &mfbcInfo->yDataBufInfo;
		yDataBufInfo->data_buf_base0 = ISP_BUF_MFBC_Y;
		yDataBufInfo->data_buf_base1 = ISP_BUF_MFBC_Y;
		yDataBufInfo->data_stride = ISP_BUF_MFBC_Y_STRIDE;
		yDataBufInfo->data_wr_blen = ISP_BUF_MFBC_Y_BLEN;
		
		ISP_MFBCD_BUF_S  *yHeadBufInfo = &mfbcInfo->yHeadBufInfo;
		yHeadBufInfo->data_buf_base0 = ISP_BUF_MFBC_Y_HEAD;
		yHeadBufInfo->data_buf_base1 = ISP_BUF_MFBC_Y_HEAD;
		yHeadBufInfo->data_stride = ISP_BUF_MFBC_Y_HEAD_STRIDE;
		yHeadBufInfo->data_wr_blen = ISP_BUF_MFBC_Y_HEAD_BLEN;
		//
		ISP_MFBCD_BUF_S *ylDataBufInfo = &mfbcInfo->ylDataBufInfo;
		ylDataBufInfo->data_buf_base0 = ISP_BUF_MFBC_YL;
		ylDataBufInfo->data_buf_base1 = ISP_BUF_MFBC_YL;
		ylDataBufInfo->data_stride = ISP_BUF_MFBC_YL_STRIDE;
		ylDataBufInfo->data_wr_blen = ISP_BUF_MFBC_YL_BLEN;
		ISP_MFBCD_BUF_S *ylHeadBufInfo = &mfbcInfo->ylHeadBufInfo;
		ylHeadBufInfo->data_buf_base0 = ISP_BUF_MFBC_YL_HEAD;
		ylHeadBufInfo->data_buf_base1 = ISP_BUF_MFBC_YL_HEAD;
		ylHeadBufInfo->data_stride = ISP_BUF_MFBC_YL_HEAD_STRIDE;
		ylHeadBufInfo->data_wr_blen = ISP_BUF_MFBC_YL_HEAD_BLEN;
		//
		ISP_MFBCD_BUF_S *uvDataBufInfo = &mfbcInfo->uvDataBufInfo;
		uvDataBufInfo->data_buf_base0 = ISP_BUF_MFBC_UV;
		uvDataBufInfo->data_buf_base1 = ISP_BUF_MFBC_UV;
		uvDataBufInfo->data_stride = ISP_BUF_MFBC_UV_STRIDE;
		uvDataBufInfo->data_wr_blen = ISP_BUF_MFBC_UV_BLEN;
		ISP_MFBCD_BUF_S *uvHeadBufInfo = &mfbcInfo->uvHeadBufInfo;
		uvHeadBufInfo->data_buf_base0 = ISP_BUF_MFBC_UV_HEAD;
		uvHeadBufInfo->data_buf_base1 = ISP_BUF_MFBC_UV_HEAD;
		uvHeadBufInfo->data_stride = ISP_BUF_MFBC_UV_HEAD_STRIDE;
		uvHeadBufInfo->data_wr_blen = ISP_BUF_MFBC_UV_HEAD_BLEN;

    return 0;
}
//3dnr mfbd
static int ISP_TEST_setIspMfbd(ISP_MFBD_CONFIG_S *mfbdInfo,IMAGE_SIZE *in_size)
{
    ISP_CHECK_POINTER(mfbdInfo);
		mfbdInfo->mfbd_en = FALSE;
		mfbdInfo->mfbd_format_cfg = NR3D_YUV422_ENABLE;
		//
		mfbdInfo->mfbd_input_size.Width = in_size->Width;// 1920 - 1;
		mfbdInfo->mfbd_input_size.Height = in_size->Height;// 1080 - 1;
		//
		ISP_MFBCD_BUF_S *yDataBufInfo = &mfbdInfo->yDataBufInfo;
		yDataBufInfo->data_buf_base0 = ISP_BUF_MFBD_Y;
		yDataBufInfo->data_buf_base1 = ISP_BUF_MFBD_Y;
		yDataBufInfo->data_stride = ISP_BUF_MFBD_Y_STRIDE;	
		ISP_MFBCD_BUF_S *yHeadBufInfo = &mfbdInfo->yHeadBufInfo;
		yHeadBufInfo->data_buf_base0 = ISP_BUF_MFBD_Y_HEAD;
		yHeadBufInfo->data_buf_base1 = ISP_BUF_MFBD_Y_HEAD;
		yHeadBufInfo->data_stride = ISP_BUF_MFBD_Y_HEAD_STRIDE;
	
		ISP_MFBCD_BUF_S  *ylDataBufInfo = &mfbdInfo->ylDataBufInfo;
		ylDataBufInfo->data_buf_base0 = ISP_BUF_MFBD_UV;
		ylDataBufInfo->data_buf_base1 = ISP_BUF_MFBD_UV;
		ylDataBufInfo->data_stride = ISP_BUF_MFBD_UV_STRIDE;
		ISP_MFBCD_BUF_S  *ylHeadBufInfo = &mfbdInfo->ylHeadBufInfo;
		ylHeadBufInfo->data_buf_base0 = ISP_BUF_MFBD_UV_HEAD;
		ylHeadBufInfo->data_buf_base1 = ISP_BUF_MFBD_UV_HEAD;
		ylHeadBufInfo->data_stride = ISP_BUF_MFBD_UV_HEAD_STRIDE;
	
		ISP_MFBCD_BUF_S  *uvDataBufInfo = &mfbdInfo->uvDataBufInfo;
		uvDataBufInfo->data_buf_base0 = ISP_BUF_MFBD_YL;
		uvDataBufInfo->data_buf_base1 = ISP_BUF_MFBD_YL;
		uvDataBufInfo->data_stride = ISP_BUF_MFBD_YL_STRIDE;
		ISP_MFBCD_BUF_S  *uvHeadBufInfo = &mfbdInfo->uvHeadBufInfo;
		uvHeadBufInfo->data_buf_base0 = ISP_BUF_MFBD_YL_HEAD;
		uvHeadBufInfo->data_buf_base1 = ISP_BUF_MFBD_YL_HEAD;
		uvHeadBufInfo->data_stride = ISP_BUF_MFBD_YL_HEAD_STRIDE;

    return 0;
}
//
static int ISP_TEST_setOs4a10NormalCore(ISP_CORE_CONFIG_S *ispCoreInfo,ISP_SIZE_S *sizeInfo)
{
    ISP_CHECK_POINTER(ispCoreInfo);

    ispCoreInfo->sensor_type = NORMAL_SENSOR;
    //itc
    ISP_ITC_CONFIG_S *itcInfo = &ispCoreInfo->itcInfo;
    IMAGE_SIZE *in_size = &sizeInfo->in_size;
    ISP_TEST_setItc(itcInfo,in_size);
    //tpg
	  ISP_TPG_CONFIG_S	*tpgInfo = &ispCoreInfo->tpgInfo;
    ISP_TEST_setTpg(tpgInfo);
    //blc
	  ISP_BLC_CONFIG_S	*blcInfo = &ispCoreInfo->blcInfo;
    ISP_TEST_setBlc(blcInfo);
    //lsc
	  ISP_LSC_CONFIG_S	*lscInfo = &ispCoreInfo->lscInfo;
    ISP_TEST_setLsc(lscInfo);
    //ae
	  ISP_AE_CONFIG_S		*aeInfo = &ispCoreInfo->aeInfo;
    ISP_TEST_setAE(aeInfo);
    //awb
	  ISP_AWB_CONFIG_S	*awbInfo = &ispCoreInfo->awbInfo;
    ISP_TEST_setAWB(awbInfo);
    //wdr
    ISP_WDR_CONFIG_S	*wdrInfo = &ispCoreInfo->wdrInfo;
    ISP_TEST_setWDR(wdrInfo);
    //csc
	  ISP_CSC_CONFIG_S	*cscInfo = &ispCoreInfo->cscInfo;
    ISP_TEST_setCSC(cscInfo);
    //ada
	  ISP_ADA_CONFIG_S	*adaInfo = &ispCoreInfo->adaInfo;
    ISP_TEST_setADA(adaInfo);
    //rgbir
	  ISP_RGBIR_CONFIG_S	*rgbirInfo = &ispCoreInfo->rgbirInfo;
    ISP_TEST_setRgbir(rgbirInfo);    
    //nr2d
	  ISP_NR2D_CONFIG_S	*nr2dInfo = &ispCoreInfo->nr2dInfo;
    ISP_TEST_setNr2d(nr2dInfo);
    //nr3d
	  ISP_NR3D_CONFIG_S	*nr3dInfo = &ispCoreInfo->nr3dInfo;
    ISP_TEST_setNr3d(nr3dInfo);
    //enh
	  ISP_ENH_CONFIG_S	*enhInfo = &ispCoreInfo->enhInfo;
    ISP_TEST_setEnh(enhInfo); 
    //post ctrl
	  ISP_POST_CONFIG_S	*postInfo = &ispCoreInfo->postInfo;
    ISP_TEST_setPost(postInfo);
    //otc
	  ISP_OTC_CONFIG_S	*otcInfo = &ispCoreInfo->otcInfo;
    IMAGE_SIZE *out_size = &sizeInfo->out_size;
    ISP_TEST_setOtc(otcInfo,out_size);
    //ldc
	  ISP_LDC_CONFIG_S	*ldcInfo = &ispCoreInfo->ldcInfo;
    ISP_TEST_setLdc(ldcInfo);
    //af
	  ISP_AF_CONFIG_S		*afInfo = &ispCoreInfo->afInfo;
    ISP_TEST_setAf(afInfo);
    //
    ISP_MFBC_CONFIG_S *mfbcInfo = &ispCoreInfo->mfbcInfo;

    ISP_TEST_setIspMfbc(mfbcInfo,in_size);
    //
    ISP_MFBD_CONFIG_S *mfbdInfo = &ispCoreInfo->mfbdInfo;
    ISP_TEST_setIspMfbd(mfbdInfo,in_size);
    //
    ISP_TEST_setCore(ispCoreInfo);
    return 0;
}
/******************************************************************************
*ds
******************************************************************************/
/*
*ds0
*/
static int ISP_TEST_setDS0(ISP_SIZE_S *sizeInfo,ISP_DS_INFO_S *dsInfo)
{
    ISP_CHECK_POINTER(sizeInfo);
    ISP_CHECK_POINTER(dsInfo);

    IMAGE_SIZE *out_size = &sizeInfo->out_size;
    IMAGE_SIZE *ds0_size = &sizeInfo->ds0_size;
    dsInfo->scale_en = TRUE;
    dsInfo->ds_out_size.Width = ds0_size->Width -1;//960 - 1;
    dsInfo->ds_out_size.Height = ds0_size->Height - 1;//1080 - 1;    
    isp_ds_calc_scale(out_size,dsInfo);
    dsInfo->hscale_filter_en = TRUE;
    dsInfo->vscale_filter_en = TRUE;
    dsInfo->out_rgb_mode = 0;
    dsInfo->out_rgb_en = FALSE;
    dsInfo->out_yuv_mode = 0;
    dsInfo->out_uv_swap = 0;

    ISP_OSD_INFO_S  *osdInfo = &dsInfo->osdInfo[0];
	osdInfo->osd_enable = FALSE;
	osdInfo->osd_type = OSD_RGB_24BIT;
	osdInfo->osd_alpha_tpye = OSD_FIXED_VALUE;
	osdInfo->osd_size.Width = 128;
    osdInfo->osd_size.Height = 128;
	osdInfo->osd_rgb_addr[0] = ISP_OSD_RGB_ADDR;
    osdInfo->osd_rgb_addr[1] = ISP_OSD_RGB_ADDR;     
	osdInfo->osd_alpha_addr[0] = ISP_OSD_ALPHA_ADDR;
    osdInfo->osd_alpha_addr[1] = ISP_OSD_ALPHA_ADDR;
	osdInfo->osd_stride = ISP_OSD_RGB_STRIDE;
	osdInfo->osd_alpha_stride = ISP_OSD_ALPHA_STRIDE;
	osdInfo->osd_position_win.v_start = 1;
    osdInfo->osd_position_win.v_end = osdInfo->osd_position_win.v_start + osdInfo->osd_size.Height -1;
    osdInfo->osd_position_win.h_start = 1;
    osdInfo->osd_position_win.h_end = osdInfo->osd_position_win.h_start + osdInfo->osd_size.Width -1;

	osdInfo->osd_dma_request_length = 15;
	osdInfo->osd_dma_map = OSD_ORIGINAL_ORDER;
	osdInfo->osd_rgb_rev = 0;
	osdInfo->osd_global_alpha = 0x80;
	osdInfo->osd_swap_64 = 0;
	osdInfo->osd_outstanding_num = 7;
	osdInfo->osd_bd_limit_en = 1;

    osdInfo = &dsInfo->osdInfo[1];
	osdInfo->osd_enable = FALSE;
	osdInfo->osd_type = OSD_RGB_24BIT;
	osdInfo->osd_alpha_tpye = OSD_FIXED_VALUE;
	osdInfo->osd_size.Width = 128;
    osdInfo->osd_size.Height = 128;
	osdInfo->osd_rgb_addr[0] = ISP_OSD_RGB_ADDR;
    osdInfo->osd_rgb_addr[1] = ISP_OSD_RGB_ADDR;     
	osdInfo->osd_alpha_addr[0] = ISP_OSD_ALPHA_ADDR;
    osdInfo->osd_alpha_addr[1] = ISP_OSD_ALPHA_ADDR;
	osdInfo->osd_stride = ISP_OSD_RGB_STRIDE;
	osdInfo->osd_alpha_stride = ISP_OSD_ALPHA_STRIDE;
	osdInfo->osd_position_win.v_start = 1;
    osdInfo->osd_position_win.v_end = osdInfo->osd_position_win.v_start + osdInfo->osd_size.Height -1;
    osdInfo->osd_position_win.h_start = 1;
    osdInfo->osd_position_win.h_end = osdInfo->osd_position_win.h_start + osdInfo->osd_size.Width -1;

	osdInfo->osd_dma_request_length = 15;
	osdInfo->osd_dma_map = OSD_ORIGINAL_ORDER;
	osdInfo->osd_rgb_rev = 0;
	osdInfo->osd_global_alpha = 0x80;
	osdInfo->osd_swap_64 = 0;
	osdInfo->osd_outstanding_num = 7;
	osdInfo->osd_bd_limit_en = 1;

    osdInfo = &dsInfo->osdInfo[2];
	osdInfo->osd_enable = FALSE;
	osdInfo->osd_type = OSD_RGB_24BIT;
	osdInfo->osd_alpha_tpye = OSD_FIXED_VALUE;
	osdInfo->osd_size.Width = 128;
    osdInfo->osd_size.Height = 128;
	osdInfo->osd_rgb_addr[0] = ISP_OSD_RGB_ADDR;
    osdInfo->osd_rgb_addr[1] = ISP_OSD_RGB_ADDR;     
	osdInfo->osd_alpha_addr[0] = ISP_OSD_ALPHA_ADDR;
    osdInfo->osd_alpha_addr[1] = ISP_OSD_ALPHA_ADDR;
	osdInfo->osd_stride = ISP_OSD_RGB_STRIDE;
	osdInfo->osd_alpha_stride = ISP_OSD_ALPHA_STRIDE;
	osdInfo->osd_position_win.v_start = 1;
    osdInfo->osd_position_win.v_end = osdInfo->osd_position_win.v_start + osdInfo->osd_size.Height -1;
    osdInfo->osd_position_win.h_start = 1;
    osdInfo->osd_position_win.h_end = osdInfo->osd_position_win.h_start + osdInfo->osd_size.Width -1;

	osdInfo->osd_dma_request_length = 15;
	osdInfo->osd_dma_map = OSD_ORIGINAL_ORDER;
	osdInfo->osd_rgb_rev = 0;
	osdInfo->osd_global_alpha = 0x80;
	osdInfo->osd_swap_64 = 0;
	osdInfo->osd_outstanding_num = 7;
	osdInfo->osd_bd_limit_en = 1;

    return 0;
}
/*
*ds1
*/
static int ISP_TEST_setDS1(ISP_SIZE_S *sizeInfo,ISP_DS_INFO_S *dsInfo)
{
    ISP_CHECK_POINTER(sizeInfo);
    ISP_CHECK_POINTER(dsInfo);

    IMAGE_SIZE *out_size = &sizeInfo->out_size;
    IMAGE_SIZE *ds1_size = &sizeInfo->ds1_size;
    dsInfo->scale_en = TRUE;
    dsInfo->ds_out_size.Width = ds1_size->Width - 1;//320 - 1;
    dsInfo->ds_out_size.Height = ds1_size->Height - 1;//240 - 1;    
    isp_ds_calc_scale(out_size,dsInfo);
    dsInfo->hscale_filter_en = TRUE;
    dsInfo->vscale_filter_en = TRUE;
    dsInfo->out_rgb_mode = 0;
    dsInfo->out_rgb_en = FALSE;
    dsInfo->out_yuv_mode = 0;
    dsInfo->out_uv_swap = 0;
    //
    ISP_OSD_INFO_S  *osdInfo = &dsInfo->osdInfo[0];
	osdInfo->osd_enable = FALSE;
	osdInfo->osd_type = OSD_RGB_24BIT;
	osdInfo->osd_alpha_tpye = OSD_FIXED_VALUE;
	osdInfo->osd_size.Width = 128;
    osdInfo->osd_size.Height = 128;
	osdInfo->osd_rgb_addr[0] = ISP_OSD_RGB_ADDR;
    osdInfo->osd_rgb_addr[1] = ISP_OSD_RGB_ADDR;     
	osdInfo->osd_alpha_addr[0] = ISP_OSD_ALPHA_ADDR;
    osdInfo->osd_alpha_addr[1] = ISP_OSD_ALPHA_ADDR;
	osdInfo->osd_stride = ISP_OSD_RGB_STRIDE;
	osdInfo->osd_alpha_stride = ISP_OSD_ALPHA_STRIDE;
	osdInfo->osd_position_win.v_start = 1;
    osdInfo->osd_position_win.v_end = osdInfo->osd_position_win.v_start + osdInfo->osd_size.Height -1;
    osdInfo->osd_position_win.h_start = 1;
    osdInfo->osd_position_win.h_end = osdInfo->osd_position_win.h_start + osdInfo->osd_size.Width -1;

	osdInfo->osd_dma_request_length = 15;
	osdInfo->osd_dma_map = OSD_ORIGINAL_ORDER;
	osdInfo->osd_rgb_rev = 0;
	osdInfo->osd_global_alpha = 0x80;
	osdInfo->osd_swap_64 = 0;
	osdInfo->osd_outstanding_num = 7;
	osdInfo->osd_bd_limit_en = 1;
    //
    osdInfo = &dsInfo->osdInfo[1];
	osdInfo->osd_enable = FALSE;
	osdInfo->osd_type = OSD_RGB_24BIT;
	osdInfo->osd_alpha_tpye = OSD_FIXED_VALUE;
	osdInfo->osd_size.Width = 128;
    osdInfo->osd_size.Height = 128;
	osdInfo->osd_rgb_addr[0] = ISP_OSD_RGB_ADDR;
    osdInfo->osd_rgb_addr[1] = ISP_OSD_RGB_ADDR;     
	osdInfo->osd_alpha_addr[0] = ISP_OSD_ALPHA_ADDR;
    osdInfo->osd_alpha_addr[1] = ISP_OSD_ALPHA_ADDR;
	osdInfo->osd_stride = ISP_OSD_RGB_STRIDE;
	osdInfo->osd_alpha_stride = ISP_OSD_ALPHA_STRIDE;
	osdInfo->osd_position_win.v_start = 1;
    osdInfo->osd_position_win.v_end = osdInfo->osd_position_win.v_start + osdInfo->osd_size.Height -1;
    osdInfo->osd_position_win.h_start = 1;
    osdInfo->osd_position_win.h_end = osdInfo->osd_position_win.h_start + osdInfo->osd_size.Width -1;

	osdInfo->osd_dma_request_length = 15;
	osdInfo->osd_dma_map = OSD_ORIGINAL_ORDER;
	osdInfo->osd_rgb_rev = 0;
	osdInfo->osd_global_alpha = 0x80;
	osdInfo->osd_swap_64 = 0;
	osdInfo->osd_outstanding_num = 7;
	osdInfo->osd_bd_limit_en = 1;
    //
    osdInfo = &dsInfo->osdInfo[2];
	osdInfo->osd_enable = FALSE;
	osdInfo->osd_type = OSD_RGB_24BIT;
	osdInfo->osd_alpha_tpye = OSD_FIXED_VALUE;
	osdInfo->osd_size.Width = 128;
    osdInfo->osd_size.Height = 128;
	osdInfo->osd_rgb_addr[0] = ISP_OSD_RGB_ADDR;
    osdInfo->osd_rgb_addr[1] = ISP_OSD_RGB_ADDR;     
	osdInfo->osd_alpha_addr[0] = ISP_OSD_ALPHA_ADDR;
    osdInfo->osd_alpha_addr[1] = ISP_OSD_ALPHA_ADDR;
	osdInfo->osd_stride = ISP_OSD_RGB_STRIDE;
	osdInfo->osd_alpha_stride = ISP_OSD_ALPHA_STRIDE;
	osdInfo->osd_position_win.v_start = 1;
    osdInfo->osd_position_win.v_end = osdInfo->osd_position_win.v_start + osdInfo->osd_size.Height -1;
    osdInfo->osd_position_win.h_start = 1;
    osdInfo->osd_position_win.h_end = osdInfo->osd_position_win.h_start + osdInfo->osd_size.Width -1;

	osdInfo->osd_dma_request_length = 15;
	osdInfo->osd_dma_map = OSD_ORIGINAL_ORDER;
	osdInfo->osd_rgb_rev = 0;
	osdInfo->osd_global_alpha = 0x80;
	osdInfo->osd_swap_64 = 0;
	osdInfo->osd_outstanding_num = 7;
	osdInfo->osd_bd_limit_en = 1;
    return 0;
} 
/*
*ds2
*/
static int ISP_TEST_setDS2(ISP_SIZE_S *sizeInfo,ISP_DS_INFO_S *dsInfo)
{
    ISP_CHECK_POINTER(dsInfo);

    IMAGE_SIZE *out_size = &sizeInfo->out_size;
    IMAGE_SIZE *ds2_size = &sizeInfo->ds2_size;
    dsInfo->scale_en = TRUE;
    dsInfo->ds_out_size.Width = ds2_size->Width - 1;//256 - 1;
    dsInfo->ds_out_size.Height = ds2_size->Height - 1;//240 - 1;    
    isp_ds_calc_scale(out_size,dsInfo);
    dsInfo->hscale_filter_en = TRUE;
    dsInfo->vscale_filter_en = TRUE;
    dsInfo->out_rgb_mode = 0x0;
    dsInfo->out_rgb_en = TRUE;
    dsInfo->out_yuv_mode = 0;
    dsInfo->out_uv_swap = 0;
    //
    ISP_OSD_INFO_S  *osdInfo = &dsInfo->osdInfo[0];
	osdInfo->osd_enable = FALSE;
	osdInfo->osd_type = OSD_RGB_24BIT;
	osdInfo->osd_alpha_tpye = OSD_FIXED_VALUE;
	osdInfo->osd_size.Width = 128;
    osdInfo->osd_size.Height = 128;
	osdInfo->osd_rgb_addr[0] = ISP_OSD_RGB_ADDR;
    osdInfo->osd_rgb_addr[1] = ISP_OSD_RGB_ADDR;     
	osdInfo->osd_alpha_addr[0] = ISP_OSD_ALPHA_ADDR;
    osdInfo->osd_alpha_addr[1] = ISP_OSD_ALPHA_ADDR;
	osdInfo->osd_stride = ISP_OSD_RGB_STRIDE;
	osdInfo->osd_alpha_stride = ISP_OSD_ALPHA_STRIDE;
	osdInfo->osd_position_win.v_start = 1;
    osdInfo->osd_position_win.v_end = osdInfo->osd_position_win.v_start + osdInfo->osd_size.Height -1;
    osdInfo->osd_position_win.h_start = 1;
    osdInfo->osd_position_win.h_end = osdInfo->osd_position_win.h_start + osdInfo->osd_size.Width -1;

	osdInfo->osd_dma_request_length = 15;
	osdInfo->osd_dma_map = OSD_ORIGINAL_ORDER;
	osdInfo->osd_rgb_rev = 0;
	osdInfo->osd_global_alpha = 0x80;
	osdInfo->osd_swap_64 = 0;
	osdInfo->osd_outstanding_num = 7;
	osdInfo->osd_bd_limit_en = 1;
    //
    osdInfo = &dsInfo->osdInfo[1];
	osdInfo->osd_enable = FALSE;
	osdInfo->osd_type = OSD_RGB_24BIT;
	osdInfo->osd_alpha_tpye = OSD_FIXED_VALUE;
	osdInfo->osd_size.Width = 128;
    osdInfo->osd_size.Height = 128;
	osdInfo->osd_rgb_addr[0] = ISP_OSD_RGB_ADDR;
    osdInfo->osd_rgb_addr[1] = ISP_OSD_RGB_ADDR;     
	osdInfo->osd_alpha_addr[0] = ISP_OSD_ALPHA_ADDR;
    osdInfo->osd_alpha_addr[1] = ISP_OSD_ALPHA_ADDR;
	osdInfo->osd_stride = ISP_OSD_RGB_STRIDE;
	osdInfo->osd_alpha_stride = ISP_OSD_ALPHA_STRIDE;
	osdInfo->osd_position_win.v_start = 1;
    osdInfo->osd_position_win.v_end = osdInfo->osd_position_win.v_start + osdInfo->osd_size.Height -1;
    osdInfo->osd_position_win.h_start = 1;
    osdInfo->osd_position_win.h_end = osdInfo->osd_position_win.h_start + osdInfo->osd_size.Width -1;

	osdInfo->osd_dma_request_length = 15;
	osdInfo->osd_dma_map = OSD_ORIGINAL_ORDER;
	osdInfo->osd_rgb_rev = 0;
	osdInfo->osd_global_alpha = 0x80;
	osdInfo->osd_swap_64 = 0;
	osdInfo->osd_outstanding_num = 7;
	osdInfo->osd_bd_limit_en = 1;
    return 0;
}
/*
*main remap
*/
static int ISP_TEST_setMainRemap(CRITICAL_MODULE_EN *module_en,ISP_REMAP_CONFIG_S *ispRemapInfo)
{
    ISP_CHECK_POINTER(ispRemapInfo);
    unsigned int drawNum;

    for(drawNum = ISP_LINE_DRAW_AREA_0; drawNum< ISP_LINE_DRAW_AREA_MAX;drawNum++ )
    {
			ispRemapInfo[drawNum].LineCtlSet = FALSE;
			ispRemapInfo[drawNum].LineDataSet = FALSE;

			ispRemapInfo[drawNum].LineDrawEn = FALSE;
			ispRemapInfo[drawNum].VlineRightEn = FALSE;
			ispRemapInfo[drawNum].VlineLeftEn = FALSE;
			ispRemapInfo[drawNum].HlineBottomEn = FALSE;
			ispRemapInfo[drawNum].HlineUpEn = FALSE;

			ispRemapInfo[drawNum].LineStartPosX = 128;
			ispRemapInfo[drawNum].LineEndPosX = ispRemapInfo[drawNum].LineStartPosX + 16*drawNum;
			ispRemapInfo[drawNum].LineStartPosY = 128;
			ispRemapInfo[drawNum].LineEndPosY = ispRemapInfo[drawNum].LineStartPosY + 16*drawNum;
			ispRemapInfo[drawNum].LineWidthL = 4;
			ispRemapInfo[drawNum].LineWidthH = 0;

			ispRemapInfo[drawNum].ValueCr = 226;
			ispRemapInfo[drawNum].ValueCb = 104;
			ispRemapInfo[drawNum].ValueY = 47;
			ispRemapInfo[drawNum].ValueAlpha = 0;
    }

    return 0;
}
/*
*remap0
*/
static int ISP_TEST_setRemap0(CRITICAL_MODULE_EN *module_en,ISP_REMAP_CONFIG_S *ispRemapInfo)
{
    ISP_CHECK_POINTER(ispRemapInfo);
    unsigned int drawNum;

    for(drawNum = ISP_LINE_DRAW_AREA_0; drawNum< ISP_LINE_DRAW_AREA_MAX;drawNum++ )
    {
			ispRemapInfo[drawNum].LineCtlSet = FALSE;
			ispRemapInfo[drawNum].LineDataSet = FALSE;
						
			ispRemapInfo[drawNum].LineDrawEn = FALSE;
			ispRemapInfo[drawNum].VlineRightEn = FALSE;
			ispRemapInfo[drawNum].VlineLeftEn = FALSE; 
			ispRemapInfo[drawNum].HlineBottomEn = FALSE;
			ispRemapInfo[drawNum].HlineUpEn = FALSE; 
						
			ispRemapInfo[drawNum].LineStartPosX = 128;
			ispRemapInfo[drawNum].LineEndPosX = ispRemapInfo[drawNum].LineStartPosX + 16*drawNum;
			ispRemapInfo[drawNum].LineStartPosY = 128;		
			ispRemapInfo[drawNum].LineEndPosY = ispRemapInfo[drawNum].LineStartPosY + 16*drawNum;
			ispRemapInfo[drawNum].LineWidthL = 4;
			ispRemapInfo[drawNum].LineWidthH = 0;
						
			ispRemapInfo[drawNum].ValueCr = 226;
			ispRemapInfo[drawNum].ValueCb = 104; 
			ispRemapInfo[drawNum].ValueY = 47;
			ispRemapInfo[drawNum].ValueAlpha = 0;
    }

    return 0;
}
/*
*remap1
*/
static int ISP_TEST_setRemap1(CRITICAL_MODULE_EN *module_en,ISP_REMAP_CONFIG_S	*ispRemapInfo)
{
    ISP_CHECK_POINTER(ispRemapInfo);

    unsigned int drawNum;
    for(drawNum = ISP_LINE_DRAW_AREA_0; drawNum< ISP_LINE_DRAW_AREA_MAX;drawNum++ )
    {
			ispRemapInfo[drawNum].LineCtlSet = FALSE;
			ispRemapInfo[drawNum].LineDataSet = FALSE;
						
			ispRemapInfo[drawNum].LineDrawEn = FALSE;
			ispRemapInfo[drawNum].VlineRightEn = FALSE;
			ispRemapInfo[drawNum].VlineLeftEn = FALSE; 
			ispRemapInfo[drawNum].HlineBottomEn = FALSE;
			ispRemapInfo[drawNum].HlineUpEn = FALSE; 
						
			ispRemapInfo[drawNum].LineStartPosX = 128;
			ispRemapInfo[drawNum].LineEndPosX = ispRemapInfo[drawNum].LineStartPosX + 16*drawNum;
			ispRemapInfo[drawNum].LineStartPosY = 128;		
			ispRemapInfo[drawNum].LineEndPosY = ispRemapInfo[drawNum].LineStartPosY + 16*drawNum;
			ispRemapInfo[drawNum].LineWidthL = 4;
			ispRemapInfo[drawNum].LineWidthH = 0;
						
			ispRemapInfo[drawNum].ValueCr = 226;
			ispRemapInfo[drawNum].ValueCb = 104; 
			ispRemapInfo[drawNum].ValueY = 47;
			ispRemapInfo[drawNum].ValueAlpha = 0;
    }
    return 0;
}
/*
*
*/
static int ISP_TEST_setOs4a10NormalDownscaler(CRITICAL_MODULE_EN *module_en,ISP_DS_CONFIG_S *ispDsInfo,ISP_SIZE_S *sizeInfo)
{
    ISP_CHECK_POINTER(ispDsInfo);
    //
    IMAGE_SIZE *out_size = &sizeInfo->out_size;
    ispDsInfo->dsInSizeInfo.Width = out_size->Width - 1;//1920 - 1;
    ispDsInfo->dsInSizeInfo.Height = out_size->Height -1;// 1080 - 1;
    //

	ispDsInfo->osd_rgb2yuv_coeff[0][0]= 0x00000132;
	ispDsInfo->osd_rgb2yuv_coeff[0][1]= 0x00000259;
	ispDsInfo->osd_rgb2yuv_coeff[0][2]= 0x00000075;
	ispDsInfo->osd_rgb2yuv_coeff[0][3]= 0x00000000;
	ispDsInfo->osd_rgb2yuv_coeff[1][0]= 0x00000f50;
	ispDsInfo->osd_rgb2yuv_coeff[1][1]= 0x00000ea5;
	ispDsInfo->osd_rgb2yuv_coeff[1][2]= 0x0000020b;
	ispDsInfo->osd_rgb2yuv_coeff[1][3]= 0x00000080;
	ispDsInfo->osd_rgb2yuv_coeff[2][0]= 0x0000020b;
	ispDsInfo->osd_rgb2yuv_coeff[2][1]= 0x00000e4a;
	ispDsInfo->osd_rgb2yuv_coeff[2][2]= 0x00000fab;
	ispDsInfo->osd_rgb2yuv_coeff[2][3]= 0x00000080;
    //
  	ispDsInfo->osd_yuv2rgb_coeff[0][0] = 0x00000400;
	ispDsInfo->osd_yuv2rgb_coeff[0][1] = 0x00000000;
	ispDsInfo->osd_yuv2rgb_coeff[0][2] = 0x000005a1;
	ispDsInfo->osd_yuv2rgb_coeff[0][3] = 0x00000f4c;
	ispDsInfo->osd_yuv2rgb_coeff[1][0] = 0x00000400;
	ispDsInfo->osd_yuv2rgb_coeff[1][1] = 0x00000e9e;
	ispDsInfo->osd_yuv2rgb_coeff[1][2] = 0x00000d22;
	ispDsInfo->osd_yuv2rgb_coeff[1][3] = 0x00000088;
	ispDsInfo->osd_yuv2rgb_coeff[2][0] = 0x00000400;
	ispDsInfo->osd_yuv2rgb_coeff[2][1] = 0x0000071e;
	ispDsInfo->osd_yuv2rgb_coeff[2][2] = 0x00000000;
	ispDsInfo->osd_yuv2rgb_coeff[2][3] = 0x00000f1c;
    //main remap
    ISP_REMAP_CONFIG_S	*ispRemapInfo = &ispDsInfo->ispRemapInfo[0];
    ISP_TEST_setMainRemap(module_en,ispRemapInfo);
    //ds0
    ISP_DS_INFO_S	*dsInfo = &ispDsInfo->dsInfo[0];
    ISP_TEST_setDS0(sizeInfo,dsInfo);
    //remap0
    ispRemapInfo = &dsInfo->ispRemapInfo[0];
    ISP_TEST_setRemap0(module_en,ispRemapInfo);
    //ds1
    dsInfo = &ispDsInfo->dsInfo[1];
    ISP_TEST_setDS1(sizeInfo,dsInfo);
    //remap1
    ispRemapInfo = &dsInfo->ispRemapInfo[0];
    ISP_TEST_setRemap1(module_en,ispRemapInfo);
    //ds2
    dsInfo = &ispDsInfo->dsInfo[2];
    ISP_TEST_setDS2(sizeInfo,dsInfo);
    //
    ISP_TEST_setDs(module_en,ispDsInfo);
    return 0;
}
/******************************************************************************
*Os4a10 Normal Mode
******************************************************************************/
int ISP_DRV_TEST_Os4a10NormalMode(CRITICAL_MODULE_EN *module_en,ISP_SIZE_S *sizeInfo)
{
    ISP_CONFIG_S ispInfo;
    //unsigned int width = 1920;
    //unsigned int height = 1080;
    //isp wrap
    ISP_WRAP_CONFIG_S *ispWrapInfo = &ispInfo.ispWrapInfo;
    ISP_TEST_setOs4a10NormalWrap(ispWrapInfo,sizeInfo);
    //isp core
    ISP_CORE_CONFIG_S *ispCoreInfo = &ispInfo.ispCoreInfo;
    ISP_TEST_setOs4a10NormalCore(ispCoreInfo,sizeInfo);
    //table init
    ISP_PIPE_WDR_MODE_E Wdrmode = ISP_PIPE_WDR_NONE;
    isp_core_table_init(Wdrmode);
    //isp downscaler
    ISP_DS_CONFIG_S *ispDsInfo = &ispInfo.ispDsInfo[0];
    ISP_TEST_setOs4a10NormalDownscaler(module_en,ispDsInfo,sizeInfo);

    return 0;
}

