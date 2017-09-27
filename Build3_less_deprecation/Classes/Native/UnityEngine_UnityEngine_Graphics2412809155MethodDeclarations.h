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

// UnityEngine.Mesh
struct Mesh_t1356156583;
// UnityEngine.ComputeBuffer
struct ComputeBuffer_t1827099467;
// UnityEngine.Texture
struct Texture_t2243626319;
// UnityEngine.RenderTexture
struct RenderTexture_t2666733923;
// UnityEngine.Material
struct Material_t193706927;
// UnityEngine.Vector2[]
struct Vector2U5BU5D_t686124026;

#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UnityEngine_Mesh1356156583.h"
#include "UnityEngine_UnityEngine_Matrix4x42933234003.h"
#include "UnityEngine_UnityEngine_MeshTopology3586470668.h"
#include "UnityEngine_UnityEngine_ComputeBuffer1827099467.h"
#include "UnityEngine_UnityEngine_Texture2243626319.h"
#include "UnityEngine_UnityEngine_RenderTexture2666733923.h"
#include "UnityEngine_UnityEngine_Material193706927.h"
#include "UnityEngine_UnityEngine_RenderBuffer2767087968.h"
#include "UnityEngine_UnityEngine_CubemapFace1725775554.h"

// System.Void UnityEngine.Graphics::DrawMeshNow(UnityEngine.Mesh,UnityEngine.Matrix4x4)
extern "C"  void Graphics_DrawMeshNow_m150453421 (Il2CppObject * __this /* static, unused */, Mesh_t1356156583 * ___mesh0, Matrix4x4_t2933234003  ___matrix1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Graphics::Internal_DrawMeshNow2(UnityEngine.Mesh,UnityEngine.Matrix4x4,System.Int32)
extern "C"  void Graphics_Internal_DrawMeshNow2_m2841272972 (Il2CppObject * __this /* static, unused */, Mesh_t1356156583 * ___mesh0, Matrix4x4_t2933234003  ___matrix1, int32_t ___materialIndex2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Graphics::INTERNAL_CALL_Internal_DrawMeshNow2(UnityEngine.Mesh,UnityEngine.Matrix4x4&,System.Int32)
extern "C"  void Graphics_INTERNAL_CALL_Internal_DrawMeshNow2_m434064341 (Il2CppObject * __this /* static, unused */, Mesh_t1356156583 * ___mesh0, Matrix4x4_t2933234003 * ___matrix1, int32_t ___materialIndex2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Graphics::DrawProceduralIndirect(UnityEngine.MeshTopology,UnityEngine.ComputeBuffer,System.Int32)
extern "C"  void Graphics_DrawProceduralIndirect_m1742458937 (Il2CppObject * __this /* static, unused */, int32_t ___topology0, ComputeBuffer_t1827099467 * ___bufferWithArgs1, int32_t ___argsOffset2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.Graphics::Internal_GetMaxDrawMeshInstanceCount()
extern "C"  int32_t Graphics_Internal_GetMaxDrawMeshInstanceCount_m3046083541 (Il2CppObject * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Graphics::Blit(UnityEngine.Texture,UnityEngine.RenderTexture)
extern "C"  void Graphics_Blit_m2123328641 (Il2CppObject * __this /* static, unused */, Texture_t2243626319 * ___source0, RenderTexture_t2666733923 * ___dest1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Graphics::Blit(UnityEngine.Texture,UnityEngine.RenderTexture,UnityEngine.Material)
extern "C"  void Graphics_Blit_m4129959705 (Il2CppObject * __this /* static, unused */, Texture_t2243626319 * ___source0, RenderTexture_t2666733923 * ___dest1, Material_t193706927 * ___mat2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Graphics::Blit(UnityEngine.Texture,UnityEngine.RenderTexture,UnityEngine.Material,System.Int32)
extern "C"  void Graphics_Blit_m2987760672 (Il2CppObject * __this /* static, unused */, Texture_t2243626319 * ___source0, RenderTexture_t2666733923 * ___dest1, Material_t193706927 * ___mat2, int32_t ___pass3, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Graphics::Internal_BlitMaterial(UnityEngine.Texture,UnityEngine.RenderTexture,UnityEngine.Material,System.Int32,System.Boolean)
extern "C"  void Graphics_Internal_BlitMaterial_m2512431126 (Il2CppObject * __this /* static, unused */, Texture_t2243626319 * ___source0, RenderTexture_t2666733923 * ___dest1, Material_t193706927 * ___mat2, int32_t ___pass3, bool ___setRT4, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Graphics::BlitMultiTap(UnityEngine.Texture,UnityEngine.RenderTexture,UnityEngine.Material,UnityEngine.Vector2[])
extern "C"  void Graphics_BlitMultiTap_m1361831915 (Il2CppObject * __this /* static, unused */, Texture_t2243626319 * ___source0, RenderTexture_t2666733923 * ___dest1, Material_t193706927 * ___mat2, Vector2U5BU5D_t686124026* ___offsets3, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Graphics::Internal_BlitMultiTap(UnityEngine.Texture,UnityEngine.RenderTexture,UnityEngine.Material,UnityEngine.Vector2[])
extern "C"  void Graphics_Internal_BlitMultiTap_m671685431 (Il2CppObject * __this /* static, unused */, Texture_t2243626319 * ___source0, RenderTexture_t2666733923 * ___dest1, Material_t193706927 * ___mat2, Vector2U5BU5D_t686124026* ___offsets3, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Graphics::Internal_SetNullRT()
extern "C"  void Graphics_Internal_SetNullRT_m3380023195 (Il2CppObject * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Graphics::Internal_SetRTSimple(UnityEngine.RenderBuffer&,UnityEngine.RenderBuffer&,System.Int32,UnityEngine.CubemapFace,System.Int32)
extern "C"  void Graphics_Internal_SetRTSimple_m1052203585 (Il2CppObject * __this /* static, unused */, RenderBuffer_t2767087968 * ___color0, RenderBuffer_t2767087968 * ___depth1, int32_t ___mip2, int32_t ___face3, int32_t ___depthSlice4, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Graphics::SetRandomWriteTarget(System.Int32,UnityEngine.ComputeBuffer)
extern "C"  void Graphics_SetRandomWriteTarget_m3626433912 (Il2CppObject * __this /* static, unused */, int32_t ___index0, ComputeBuffer_t1827099467 * ___uav1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Graphics::SetRandomWriteTarget(System.Int32,UnityEngine.ComputeBuffer,System.Boolean)
extern "C"  void Graphics_SetRandomWriteTarget_m946408349 (Il2CppObject * __this /* static, unused */, int32_t ___index0, ComputeBuffer_t1827099467 * ___uav1, bool ___preserveCounterValue2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Graphics::ClearRandomWriteTargets()
extern "C"  void Graphics_ClearRandomWriteTargets_m1829463965 (Il2CppObject * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Graphics::Internal_SetRandomWriteTargetBuffer(System.Int32,UnityEngine.ComputeBuffer,System.Boolean)
extern "C"  void Graphics_Internal_SetRandomWriteTargetBuffer_m1619563557 (Il2CppObject * __this /* static, unused */, int32_t ___index0, ComputeBuffer_t1827099467 * ___uav1, bool ___preserveCounterValue2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Graphics::SetRenderTargetImpl(UnityEngine.RenderBuffer,UnityEngine.RenderBuffer,System.Int32,UnityEngine.CubemapFace,System.Int32)
extern "C"  void Graphics_SetRenderTargetImpl_m2993156656 (Il2CppObject * __this /* static, unused */, RenderBuffer_t2767087968  ___colorBuffer0, RenderBuffer_t2767087968  ___depthBuffer1, int32_t ___mipLevel2, int32_t ___face3, int32_t ___depthSlice4, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Graphics::SetRenderTargetImpl(UnityEngine.RenderTexture,System.Int32,UnityEngine.CubemapFace,System.Int32)
extern "C"  void Graphics_SetRenderTargetImpl_m2225187728 (Il2CppObject * __this /* static, unused */, RenderTexture_t2666733923 * ___rt0, int32_t ___mipLevel1, int32_t ___face2, int32_t ___depthSlice3, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Graphics::SetRenderTarget(UnityEngine.RenderTexture)
extern "C"  void Graphics_SetRenderTarget_m3661877391 (Il2CppObject * __this /* static, unused */, RenderTexture_t2666733923 * ___rt0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Graphics::SetRenderTarget(UnityEngine.RenderBuffer,UnityEngine.RenderBuffer)
extern "C"  void Graphics_SetRenderTarget_m3373863973 (Il2CppObject * __this /* static, unused */, RenderBuffer_t2767087968  ___colorBuffer0, RenderBuffer_t2767087968  ___depthBuffer1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Graphics::.cctor()
extern "C"  void Graphics__cctor_m3711221683 (Il2CppObject * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
