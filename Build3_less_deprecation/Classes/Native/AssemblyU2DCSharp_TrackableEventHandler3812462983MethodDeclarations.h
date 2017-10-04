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

// TrackableEventHandler
struct TrackableEventHandler_t3812462983;
// VideoPlaybackBehaviour
struct VideoPlaybackBehaviour_t222960481;

#include "codegen/il2cpp-codegen.h"
#include "Vuforia_UnityExtensions_Vuforia_TrackableBehaviour4057911311.h"
#include "AssemblyU2DCSharp_VideoPlaybackBehaviour222960481.h"

// System.Void TrackableEventHandler::.ctor()
extern "C"  void TrackableEventHandler__ctor_m1129889398 (TrackableEventHandler_t3812462983 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void TrackableEventHandler::Start()
extern "C"  void TrackableEventHandler_Start_m2993524002 (TrackableEventHandler_t3812462983 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void TrackableEventHandler::Update()
extern "C"  void TrackableEventHandler_Update_m1208808523 (TrackableEventHandler_t3812462983 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void TrackableEventHandler::OnTrackableStateChanged(Vuforia.TrackableBehaviour/Status,Vuforia.TrackableBehaviour/Status)
extern "C"  void TrackableEventHandler_OnTrackableStateChanged_m518110183 (TrackableEventHandler_t3812462983 * __this, int32_t ___previousStatus0, int32_t ___newStatus1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void TrackableEventHandler::OnTrackingFound()
extern "C"  void TrackableEventHandler_OnTrackingFound_m2617313194 (TrackableEventHandler_t3812462983 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void TrackableEventHandler::OnTrackingLost()
extern "C"  void TrackableEventHandler_OnTrackingLost_m4003082174 (TrackableEventHandler_t3812462983 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void TrackableEventHandler::PauseOtherVideos(VideoPlaybackBehaviour)
extern "C"  void TrackableEventHandler_PauseOtherVideos_m1134478257 (TrackableEventHandler_t3812462983 * __this, VideoPlaybackBehaviour_t222960481 * ___currentVideo0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
