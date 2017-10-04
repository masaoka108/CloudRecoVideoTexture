#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>
#include <assert.h>
#include <exception>

// VideoPlayerHelper
struct VideoPlayerHelper_t1808751630;
// System.String
struct String_t;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_IntPtr2504060609.h"
#include "mscorlib_System_String2029220233.h"
#include "Vuforia_UnityExtensions_Vuforia_VuforiaRenderer_Ren804170727.h"
#include "AssemblyU2DCSharp_VideoPlayerHelper_MediaType3153657181.h"
#include "AssemblyU2DCSharp_VideoPlayerHelper_MediaState921245858.h"

// System.Void VideoPlayerHelper::.ctor()
extern "C"  void VideoPlayerHelper__ctor_m2990413863 (VideoPlayerHelper_t1808751630 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.IntPtr VideoPlayerHelper::GetNativeRenderEventFunc()
extern "C"  IntPtr_t VideoPlayerHelper_GetNativeRenderEventFunc_m963743145 (Il2CppObject * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void VideoPlayerHelper::SetFilename(System.String)
extern "C"  void VideoPlayerHelper_SetFilename_m2897880026 (VideoPlayerHelper_t1808751630 * __this, String_t* ___filename0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean VideoPlayerHelper::Init(Vuforia.VuforiaRenderer/RendererAPI)
extern "C"  bool VideoPlayerHelper_Init_m2677709536 (VideoPlayerHelper_t1808751630 * __this, int32_t ___rendererAPI0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean VideoPlayerHelper::Deinit()
extern "C"  bool VideoPlayerHelper_Deinit_m3914484638 (VideoPlayerHelper_t1808751630 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean VideoPlayerHelper::Load(System.String,VideoPlayerHelper/MediaType,System.Boolean,System.Single)
extern "C"  bool VideoPlayerHelper_Load_m1499357464 (VideoPlayerHelper_t1808751630 * __this, String_t* ___filename0, int32_t ___requestedType1, bool ___playOnTextureImmediately2, float ___seekPosition3, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean VideoPlayerHelper::Unload()
extern "C"  bool VideoPlayerHelper_Unload_m1616588048 (VideoPlayerHelper_t1808751630 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean VideoPlayerHelper::IsPlayableOnTexture()
extern "C"  bool VideoPlayerHelper_IsPlayableOnTexture_m1678376193 (VideoPlayerHelper_t1808751630 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean VideoPlayerHelper::IsPlayableFullscreen()
extern "C"  bool VideoPlayerHelper_IsPlayableFullscreen_m3667057644 (VideoPlayerHelper_t1808751630 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean VideoPlayerHelper::SetVideoTexturePtr(System.IntPtr)
extern "C"  bool VideoPlayerHelper_SetVideoTexturePtr_m1144094767 (VideoPlayerHelper_t1808751630 * __this, IntPtr_t ___texturePtr0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// VideoPlayerHelper/MediaState VideoPlayerHelper::GetStatus()
extern "C"  int32_t VideoPlayerHelper_GetStatus_m3147268202 (VideoPlayerHelper_t1808751630 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 VideoPlayerHelper::GetVideoWidth()
extern "C"  int32_t VideoPlayerHelper_GetVideoWidth_m1642609846 (VideoPlayerHelper_t1808751630 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 VideoPlayerHelper::GetVideoHeight()
extern "C"  int32_t VideoPlayerHelper_GetVideoHeight_m1301576521 (VideoPlayerHelper_t1808751630 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single VideoPlayerHelper::GetLength()
extern "C"  float VideoPlayerHelper_GetLength_m4032419859 (VideoPlayerHelper_t1808751630 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean VideoPlayerHelper::Play(System.Boolean,System.Single)
extern "C"  bool VideoPlayerHelper_Play_m1992276925 (VideoPlayerHelper_t1808751630 * __this, bool ___fullScreen0, float ___seekPosition1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean VideoPlayerHelper::Pause()
extern "C"  bool VideoPlayerHelper_Pause_m2396057477 (VideoPlayerHelper_t1808751630 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean VideoPlayerHelper::Stop()
extern "C"  bool VideoPlayerHelper_Stop_m2503777039 (VideoPlayerHelper_t1808751630 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// VideoPlayerHelper/MediaState VideoPlayerHelper::UpdateVideoData()
extern "C"  int32_t VideoPlayerHelper_UpdateVideoData_m368678036 (VideoPlayerHelper_t1808751630 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean VideoPlayerHelper::SeekTo(System.Single)
extern "C"  bool VideoPlayerHelper_SeekTo_m2766766085 (VideoPlayerHelper_t1808751630 * __this, float ___position0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single VideoPlayerHelper::GetCurrentPosition()
extern "C"  float VideoPlayerHelper_GetCurrentPosition_m4118493247 (VideoPlayerHelper_t1808751630 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean VideoPlayerHelper::SetVolume(System.Single)
extern "C"  bool VideoPlayerHelper_SetVolume_m2990968142 (VideoPlayerHelper_t1808751630 * __this, float ___value0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 VideoPlayerHelper::GetCurrentBufferingPercentage()
extern "C"  int32_t VideoPlayerHelper_GetCurrentBufferingPercentage_m3764199406 (VideoPlayerHelper_t1808751630 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void VideoPlayerHelper::OnPause()
extern "C"  void VideoPlayerHelper_OnPause_m3355667376 (VideoPlayerHelper_t1808751630 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.IntPtr VideoPlayerHelper::videoPlayerInitIOS(System.Boolean)
extern "C"  IntPtr_t VideoPlayerHelper_videoPlayerInitIOS_m3962364758 (Il2CppObject * __this /* static, unused */, bool ___isMetalRendering0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean VideoPlayerHelper::videoPlayerDeinitIOS(System.IntPtr)
extern "C"  bool VideoPlayerHelper_videoPlayerDeinitIOS_m3635511669 (Il2CppObject * __this /* static, unused */, IntPtr_t ___videoPlayerPtr0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean VideoPlayerHelper::videoPlayerLoadIOS(System.IntPtr,System.String,System.Int32,System.Boolean,System.Single)
extern "C"  bool VideoPlayerHelper_videoPlayerLoadIOS_m3211674785 (Il2CppObject * __this /* static, unused */, IntPtr_t ___videoPlayerPtr0, String_t* ___filename1, int32_t ___requestType2, bool ___playOnTextureImmediately3, float ___seekPosition4, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean VideoPlayerHelper::videoPlayerUnloadIOS(System.IntPtr)
extern "C"  bool VideoPlayerHelper_videoPlayerUnloadIOS_m364788659 (Il2CppObject * __this /* static, unused */, IntPtr_t ___videoPlayerPtr0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean VideoPlayerHelper::videoPlayerIsPlayableOnTextureIOS(System.IntPtr)
extern "C"  bool VideoPlayerHelper_videoPlayerIsPlayableOnTextureIOS_m313003860 (Il2CppObject * __this /* static, unused */, IntPtr_t ___videoPlayerPtr0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean VideoPlayerHelper::videoPlayerIsPlayableFullscreenIOS(System.IntPtr)
extern "C"  bool VideoPlayerHelper_videoPlayerIsPlayableFullscreenIOS_m1755006933 (Il2CppObject * __this /* static, unused */, IntPtr_t ___videoPlayerPtr0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean VideoPlayerHelper::videoPlayerSetVideoTexturePtrIOS(System.IntPtr,System.IntPtr)
extern "C"  bool VideoPlayerHelper_videoPlayerSetVideoTexturePtrIOS_m2476490678 (Il2CppObject * __this /* static, unused */, IntPtr_t ___videoPlayerPtr0, IntPtr_t ___texturePtr1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 VideoPlayerHelper::videoPlayerGetStatusIOS(System.IntPtr)
extern "C"  int32_t VideoPlayerHelper_videoPlayerGetStatusIOS_m1855316680 (Il2CppObject * __this /* static, unused */, IntPtr_t ___videoPlayerPtr0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 VideoPlayerHelper::videoPlayerGetVideoWidthIOS(System.IntPtr)
extern "C"  int32_t VideoPlayerHelper_videoPlayerGetVideoWidthIOS_m3040234369 (Il2CppObject * __this /* static, unused */, IntPtr_t ___videoPlayerPtr0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 VideoPlayerHelper::videoPlayerGetVideoHeightIOS(System.IntPtr)
extern "C"  int32_t VideoPlayerHelper_videoPlayerGetVideoHeightIOS_m231081034 (Il2CppObject * __this /* static, unused */, IntPtr_t ___videoPlayerPtr0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single VideoPlayerHelper::videoPlayerGetLengthIOS(System.IntPtr)
extern "C"  float VideoPlayerHelper_videoPlayerGetLengthIOS_m2958159138 (Il2CppObject * __this /* static, unused */, IntPtr_t ___videoPlayerPtr0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean VideoPlayerHelper::videoPlayerPlayIOS(System.IntPtr,System.Boolean,System.Single)
extern "C"  bool VideoPlayerHelper_videoPlayerPlayIOS_m4173957476 (Il2CppObject * __this /* static, unused */, IntPtr_t ___videoPlayerPtr0, bool ___fullScreen1, float ___seekPosition2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean VideoPlayerHelper::videoPlayerPauseIOS(System.IntPtr)
extern "C"  bool VideoPlayerHelper_videoPlayerPauseIOS_m3696506696 (Il2CppObject * __this /* static, unused */, IntPtr_t ___videoPlayerPtr0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean VideoPlayerHelper::videoPlayerStopIOS(System.IntPtr)
extern "C"  bool VideoPlayerHelper_videoPlayerStopIOS_m1945539750 (Il2CppObject * __this /* static, unused */, IntPtr_t ___videoPlayerPtr0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 VideoPlayerHelper::videoPlayerUpdateVideoDataIOS(System.IntPtr)
extern "C"  int32_t VideoPlayerHelper_videoPlayerUpdateVideoDataIOS_m3521022778 (Il2CppObject * __this /* static, unused */, IntPtr_t ___videoPlayerPtr0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean VideoPlayerHelper::videoPlayerSeekToIOS(System.IntPtr,System.Single)
extern "C"  bool VideoPlayerHelper_videoPlayerSeekToIOS_m2239692620 (Il2CppObject * __this /* static, unused */, IntPtr_t ___videoPlayerPtr0, float ___position1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single VideoPlayerHelper::videoPlayerGetCurrentPositionIOS(System.IntPtr)
extern "C"  float VideoPlayerHelper_videoPlayerGetCurrentPositionIOS_m2470028788 (Il2CppObject * __this /* static, unused */, IntPtr_t ___videoPlayerPtr0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean VideoPlayerHelper::videoPlayerSetVolumeIOS(System.IntPtr,System.Single)
extern "C"  bool VideoPlayerHelper_videoPlayerSetVolumeIOS_m3678970657 (Il2CppObject * __this /* static, unused */, IntPtr_t ___videoPlayerPtr0, float ___value1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 VideoPlayerHelper::videoPlayerGetCurrentBufferingPercentageIOS(System.IntPtr)
extern "C"  int32_t VideoPlayerHelper_videoPlayerGetCurrentBufferingPercentageIOS_m1151287047 (Il2CppObject * __this /* static, unused */, IntPtr_t ___videoPlayerPtr0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void VideoPlayerHelper::videoPlayerOnPauseIOS(System.IntPtr)
extern "C"  void VideoPlayerHelper_videoPlayerOnPauseIOS_m1381523325 (Il2CppObject * __this /* static, unused */, IntPtr_t ___videoPlayerPtr0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean VideoPlayerHelper::videoPlayerInit(Vuforia.VuforiaRenderer/RendererAPI)
extern "C"  bool VideoPlayerHelper_videoPlayerInit_m4104006758 (VideoPlayerHelper_t1808751630 * __this, int32_t ___rendererAPI0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean VideoPlayerHelper::videoPlayerDeinit()
extern "C"  bool VideoPlayerHelper_videoPlayerDeinit_m2996476724 (VideoPlayerHelper_t1808751630 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean VideoPlayerHelper::videoPlayerLoad(System.String,System.Int32,System.Boolean,System.Single)
extern "C"  bool VideoPlayerHelper_videoPlayerLoad_m235514828 (VideoPlayerHelper_t1808751630 * __this, String_t* ___filename0, int32_t ___requestType1, bool ___playOnTextureImmediately2, float ___seekPosition3, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean VideoPlayerHelper::videoPlayerUnload()
extern "C"  bool VideoPlayerHelper_videoPlayerUnload_m2085537158 (VideoPlayerHelper_t1808751630 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean VideoPlayerHelper::videoPlayerIsPlayableOnTexture()
extern "C"  bool VideoPlayerHelper_videoPlayerIsPlayableOnTexture_m1091384519 (VideoPlayerHelper_t1808751630 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean VideoPlayerHelper::videoPlayerIsPlayableFullscreen()
extern "C"  bool VideoPlayerHelper_videoPlayerIsPlayableFullscreen_m4253182806 (VideoPlayerHelper_t1808751630 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean VideoPlayerHelper::videoPlayerSetVideoTexturePtr(System.IntPtr)
extern "C"  bool VideoPlayerHelper_videoPlayerSetVideoTexturePtr_m3252772981 (VideoPlayerHelper_t1808751630 * __this, IntPtr_t ___texturePtr0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 VideoPlayerHelper::videoPlayerGetStatus()
extern "C"  int32_t VideoPlayerHelper_videoPlayerGetStatus_m1475928605 (VideoPlayerHelper_t1808751630 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 VideoPlayerHelper::videoPlayerGetVideoWidth()
extern "C"  int32_t VideoPlayerHelper_videoPlayerGetVideoWidth_m1870841896 (VideoPlayerHelper_t1808751630 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 VideoPlayerHelper::videoPlayerGetVideoHeight()
extern "C"  int32_t VideoPlayerHelper_videoPlayerGetVideoHeight_m1488125603 (VideoPlayerHelper_t1808751630 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single VideoPlayerHelper::videoPlayerGetLength()
extern "C"  float VideoPlayerHelper_videoPlayerGetLength_m1774387097 (VideoPlayerHelper_t1808751630 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean VideoPlayerHelper::videoPlayerPlay(System.Boolean,System.Single)
extern "C"  bool VideoPlayerHelper_videoPlayerPlay_m1892101403 (VideoPlayerHelper_t1808751630 * __this, bool ___fullScreen0, float ___seekPosition1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean VideoPlayerHelper::videoPlayerPause()
extern "C"  bool VideoPlayerHelper_videoPlayerPause_m4191091815 (VideoPlayerHelper_t1808751630 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean VideoPlayerHelper::videoPlayerStop()
extern "C"  bool VideoPlayerHelper_videoPlayerStop_m2479749713 (VideoPlayerHelper_t1808751630 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 VideoPlayerHelper::videoPlayerUpdateVideoData()
extern "C"  int32_t VideoPlayerHelper_videoPlayerUpdateVideoData_m1122450783 (VideoPlayerHelper_t1808751630 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean VideoPlayerHelper::videoPlayerSeekTo(System.Single)
extern "C"  bool VideoPlayerHelper_videoPlayerSeekTo_m2108514915 (VideoPlayerHelper_t1808751630 * __this, float ___position0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single VideoPlayerHelper::videoPlayerGetCurrentPosition()
extern "C"  float VideoPlayerHelper_videoPlayerGetCurrentPosition_m3242347473 (VideoPlayerHelper_t1808751630 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean VideoPlayerHelper::videoPlayerSetVolume(System.Single)
extern "C"  bool VideoPlayerHelper_videoPlayerSetVolume_m2321198500 (VideoPlayerHelper_t1808751630 * __this, float ___value0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 VideoPlayerHelper::videoPlayerGetCurrentBufferingPercentage()
extern "C"  int32_t VideoPlayerHelper_videoPlayerGetCurrentBufferingPercentage_m3662509572 (VideoPlayerHelper_t1808751630 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void VideoPlayerHelper::videoPlayerOnPause()
extern "C"  void VideoPlayerHelper_videoPlayerOnPause_m615032094 (VideoPlayerHelper_t1808751630 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
