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

// VideoPlaybackBehaviour
struct VideoPlaybackBehaviour_t222960481;
// VideoPlayerHelper
struct VideoPlayerHelper_t1808751630;
// UnityEngine.Texture
struct Texture_t2243626319;
// System.Collections.IEnumerator
struct IEnumerator_t1466026749;

#include "codegen/il2cpp-codegen.h"
#include "AssemblyU2DCSharp_VideoPlayerHelper_MediaState921245858.h"
#include "AssemblyU2DCSharp_VideoPlayerHelper_MediaType3153657181.h"
#include "UnityEngine_UnityEngine_Texture2243626319.h"

// System.Void VideoPlaybackBehaviour::.ctor()
extern "C"  void VideoPlaybackBehaviour__ctor_m2395409216 (VideoPlaybackBehaviour_t222960481 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// VideoPlayerHelper VideoPlaybackBehaviour::get_VideoPlayer()
extern "C"  VideoPlayerHelper_t1808751630 * VideoPlaybackBehaviour_get_VideoPlayer_m1396563428 (VideoPlaybackBehaviour_t222960481 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// VideoPlayerHelper/MediaState VideoPlaybackBehaviour::get_CurrentState()
extern "C"  int32_t VideoPlaybackBehaviour_get_CurrentState_m3399927984 (VideoPlaybackBehaviour_t222960481 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// VideoPlayerHelper/MediaType VideoPlaybackBehaviour::get_MediaType()
extern "C"  int32_t VideoPlaybackBehaviour_get_MediaType_m103129697 (VideoPlaybackBehaviour_t222960481 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void VideoPlaybackBehaviour::set_MediaType(VideoPlayerHelper/MediaType)
extern "C"  void VideoPlaybackBehaviour_set_MediaType_m1207632200 (VideoPlaybackBehaviour_t222960481 * __this, int32_t ___value0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Texture VideoPlaybackBehaviour::get_KeyframeTexture()
extern "C"  Texture_t2243626319 * VideoPlaybackBehaviour_get_KeyframeTexture_m4035123327 (VideoPlaybackBehaviour_t222960481 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void VideoPlaybackBehaviour::set_KeyframeTexture(UnityEngine.Texture)
extern "C"  void VideoPlaybackBehaviour_set_KeyframeTexture_m3603400620 (VideoPlaybackBehaviour_t222960481 * __this, Texture_t2243626319 * ___value0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean VideoPlaybackBehaviour::get_AutoPlay()
extern "C"  bool VideoPlaybackBehaviour_get_AutoPlay_m2673200620 (VideoPlaybackBehaviour_t222960481 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void VideoPlaybackBehaviour::Start()
extern "C"  void VideoPlaybackBehaviour_Start_m2427539744 (VideoPlaybackBehaviour_t222960481 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void VideoPlaybackBehaviour::setmIsInited()
extern "C"  void VideoPlaybackBehaviour_setmIsInited_m1761529450 (VideoPlaybackBehaviour_t222960481 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void VideoPlaybackBehaviour::VideoRender()
extern "C"  void VideoPlaybackBehaviour_VideoRender_m2290545635 (VideoPlaybackBehaviour_t222960481 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void VideoPlaybackBehaviour::SetState()
extern "C"  void VideoPlaybackBehaviour_SetState_m1938313737 (VideoPlaybackBehaviour_t222960481 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.IEnumerator VideoPlaybackBehaviour::InitVideoPlayer()
extern "C"  Il2CppObject * VideoPlaybackBehaviour_InitVideoPlayer_m4247181332 (VideoPlaybackBehaviour_t222960481 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.IEnumerator VideoPlaybackBehaviour::LoadVideo()
extern "C"  Il2CppObject * VideoPlaybackBehaviour_LoadVideo_m3550208269 (VideoPlaybackBehaviour_t222960481 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.IEnumerator VideoPlaybackBehaviour::PrepareVideo()
extern "C"  Il2CppObject * VideoPlaybackBehaviour_PrepareVideo_m1168943076 (VideoPlaybackBehaviour_t222960481 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void VideoPlaybackBehaviour::OnApplicationPause(System.Boolean)
extern "C"  void VideoPlaybackBehaviour_OnApplicationPause_m2056660370 (VideoPlaybackBehaviour_t222960481 * __this, bool ___pause0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void VideoPlaybackBehaviour::OnDestroy()
extern "C"  void VideoPlaybackBehaviour_OnDestroy_m1305955047 (VideoPlaybackBehaviour_t222960481 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void VideoPlaybackBehaviour::ShowBusyIcon()
extern "C"  void VideoPlaybackBehaviour_ShowBusyIcon_m1844638657 (VideoPlaybackBehaviour_t222960481 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void VideoPlaybackBehaviour::ShowPlayIcon()
extern "C"  void VideoPlaybackBehaviour_ShowPlayIcon_m4211087060 (VideoPlaybackBehaviour_t222960481 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void VideoPlaybackBehaviour::HideIcon()
extern "C"  void VideoPlaybackBehaviour_HideIcon_m866481823 (VideoPlaybackBehaviour_t222960481 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void VideoPlaybackBehaviour::InitVideoTexture(System.Boolean)
extern "C"  void VideoPlaybackBehaviour_InitVideoTexture_m829181239 (VideoPlaybackBehaviour_t222960481 * __this, bool ___isOpenGLRendering0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void VideoPlaybackBehaviour::HandleStateChange(VideoPlayerHelper/MediaState)
extern "C"  void VideoPlaybackBehaviour_HandleStateChange_m2184526295 (VideoPlaybackBehaviour_t222960481 * __this, int32_t ___newState0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void VideoPlaybackBehaviour::ScaleIcon()
extern "C"  void VideoPlaybackBehaviour_ScaleIcon_m3616562539 (VideoPlaybackBehaviour_t222960481 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void VideoPlaybackBehaviour::CheckIconPlaneVisibility()
extern "C"  void VideoPlaybackBehaviour_CheckIconPlaneVisibility_m3130946357 (VideoPlaybackBehaviour_t222960481 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void VideoPlaybackBehaviour::.cctor()
extern "C"  void VideoPlaybackBehaviour__cctor_m1115098547 (Il2CppObject * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
