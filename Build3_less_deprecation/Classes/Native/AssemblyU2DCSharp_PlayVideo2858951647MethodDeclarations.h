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

// PlayVideo
struct PlayVideo_t2858951647;
// System.Collections.IEnumerator
struct IEnumerator_t1466026749;
// VideoPlaybackBehaviour
struct VideoPlaybackBehaviour_t222960481;

#include "codegen/il2cpp-codegen.h"
#include "AssemblyU2DCSharp_VideoPlaybackBehaviour222960481.h"
#include "UnityEngine_UnityEngine_Vector32243707580.h"

// System.Void PlayVideo::.ctor()
extern "C"  void PlayVideo__ctor_m605244024 (PlayVideo_t2858951647 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void PlayVideo::TryPickingVideo()
extern "C"  void PlayVideo_TryPickingVideo_m1120052837 (PlayVideo_t2858951647 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.IEnumerator PlayVideo::PlayFullscreenVideoAtEndOfFrame(VideoPlaybackBehaviour)
extern "C"  Il2CppObject * PlayVideo_PlayFullscreenVideoAtEndOfFrame_m1166211511 (Il2CppObject * __this /* static, unused */, VideoPlaybackBehaviour_t222960481 * ___video0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// VideoPlaybackBehaviour PlayVideo::PickVideo(UnityEngine.Vector3)
extern "C"  VideoPlaybackBehaviour_t222960481 * PlayVideo_PickVideo_m3939837543 (PlayVideo_t2858951647 * __this, Vector3_t2243707580  ___screenPoint0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void PlayVideo::PauseOtherVideos(VideoPlaybackBehaviour)
extern "C"  void PlayVideo_PauseOtherVideos_m3347916665 (PlayVideo_t2858951647 * __this, VideoPlaybackBehaviour_t222960481 * ___currentVideo0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
