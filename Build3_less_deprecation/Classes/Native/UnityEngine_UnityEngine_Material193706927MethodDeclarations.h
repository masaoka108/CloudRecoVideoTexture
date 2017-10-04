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

// UnityEngine.Material
struct Material_t193706927;
// UnityEngine.Shader
struct Shader_t2430389951;
// UnityEngine.Texture
struct Texture_t2243626319;
// System.String
struct String_t;
// UnityEngine.ComputeBuffer
struct ComputeBuffer_t1827099467;

#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UnityEngine_Shader2430389951.h"
#include "UnityEngine_UnityEngine_Material193706927.h"
#include "UnityEngine_UnityEngine_Color2020392075.h"
#include "UnityEngine_UnityEngine_Texture2243626319.h"
#include "UnityEngine_UnityEngine_Vector22243707579.h"
#include "mscorlib_System_String2029220233.h"
#include "UnityEngine_UnityEngine_Vector42243707581.h"
#include "UnityEngine_UnityEngine_Matrix4x42933234003.h"
#include "UnityEngine_UnityEngine_ComputeBuffer1827099467.h"

// System.Void UnityEngine.Material::.ctor(UnityEngine.Shader)
extern "C"  void Material__ctor_m1897560860 (Material_t193706927 * __this, Shader_t2430389951 * ___shader0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Material::.ctor(UnityEngine.Material)
extern "C"  void Material__ctor_m1440882780 (Material_t193706927 * __this, Material_t193706927 * ___source0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Shader UnityEngine.Material::get_shader()
extern "C"  Shader_t2430389951 * Material_get_shader_m2320486867 (Material_t193706927 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Color UnityEngine.Material::get_color()
extern "C"  Color_t2020392075  Material_get_color_m668215843 (Material_t193706927 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Material::set_color(UnityEngine.Color)
extern "C"  void Material_set_color_m577844242 (Material_t193706927 * __this, Color_t2020392075  ___value0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Texture UnityEngine.Material::get_mainTexture()
extern "C"  Texture_t2243626319 * Material_get_mainTexture_m432794412 (Material_t193706927 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Material::set_mainTexture(UnityEngine.Texture)
extern "C"  void Material_set_mainTexture_m3584203343 (Material_t193706927 * __this, Texture_t2243626319 * ___value0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Material::set_mainTextureScale(UnityEngine.Vector2)
extern "C"  void Material_set_mainTextureScale_m723074403 (Material_t193706927 * __this, Vector2_t2243707579  ___value0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Material::SetColor(System.String,UnityEngine.Color)
extern "C"  void Material_SetColor_m650857509 (Material_t193706927 * __this, String_t* ___propertyName0, Color_t2020392075  ___color1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Material::SetColor(System.Int32,UnityEngine.Color)
extern "C"  void Material_SetColor_m1191533068 (Material_t193706927 * __this, int32_t ___nameID0, Color_t2020392075  ___color1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Material::INTERNAL_CALL_SetColor(UnityEngine.Material,System.Int32,UnityEngine.Color&)
extern "C"  void Material_INTERNAL_CALL_SetColor_m1364511001 (Il2CppObject * __this /* static, unused */, Material_t193706927 * ___self0, int32_t ___nameID1, Color_t2020392075 * ___color2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Color UnityEngine.Material::GetColor(System.String)
extern "C"  Color_t2020392075  Material_GetColor_m2326771174 (Material_t193706927 * __this, String_t* ___propertyName0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Color UnityEngine.Material::GetColor(System.Int32)
extern "C"  Color_t2020392075  Material_GetColor_m2968960621 (Material_t193706927 * __this, int32_t ___nameID0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Material::INTERNAL_CALL_GetColor(UnityEngine.Material,System.Int32,UnityEngine.Color&)
extern "C"  void Material_INTERNAL_CALL_GetColor_m558759949 (Il2CppObject * __this /* static, unused */, Material_t193706927 * ___self0, int32_t ___nameID1, Color_t2020392075 * ___value2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Material::SetVector(System.String,UnityEngine.Vector4)
extern "C"  void Material_SetVector_m3298399397 (Material_t193706927 * __this, String_t* ___propertyName0, Vector4_t2243707581  ___vector1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Material::SetTexture(System.String,UnityEngine.Texture)
extern "C"  void Material_SetTexture_m141095205 (Material_t193706927 * __this, String_t* ___propertyName0, Texture_t2243626319 * ___texture1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Material::SetTexture(System.Int32,UnityEngine.Texture)
extern "C"  void Material_SetTexture_m58378708 (Material_t193706927 * __this, int32_t ___nameID0, Texture_t2243626319 * ___texture1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Texture UnityEngine.Material::GetTexture(System.String)
extern "C"  Texture_t2243626319 * Material_GetTexture_m1257877102 (Material_t193706927 * __this, String_t* ___propertyName0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Texture UnityEngine.Material::GetTexture(System.Int32)
extern "C"  Texture_t2243626319 * Material_GetTexture_m648312929 (Material_t193706927 * __this, int32_t ___nameID0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Material::SetTextureScale(System.String,UnityEngine.Vector2)
extern "C"  void Material_SetTextureScale_m1622979841 (Material_t193706927 * __this, String_t* ___propertyName0, Vector2_t2243707579  ___scale1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Material::INTERNAL_CALL_SetTextureScale(UnityEngine.Material,System.String,UnityEngine.Vector2&)
extern "C"  void Material_INTERNAL_CALL_SetTextureScale_m2049074868 (Il2CppObject * __this /* static, unused */, Material_t193706927 * ___self0, String_t* ___propertyName1, Vector2_t2243707579 * ___scale2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Material::SetMatrix(System.String,UnityEngine.Matrix4x4)
extern "C"  void Material_SetMatrix_m1387972957 (Material_t193706927 * __this, String_t* ___propertyName0, Matrix4x4_t2933234003  ___matrix1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Material::SetMatrix(System.Int32,UnityEngine.Matrix4x4)
extern "C"  void Material_SetMatrix_m819317148 (Material_t193706927 * __this, int32_t ___nameID0, Matrix4x4_t2933234003  ___matrix1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Material::INTERNAL_CALL_SetMatrix(UnityEngine.Material,System.Int32,UnityEngine.Matrix4x4&)
extern "C"  void Material_INTERNAL_CALL_SetMatrix_m1389870997 (Il2CppObject * __this /* static, unused */, Material_t193706927 * ___self0, int32_t ___nameID1, Matrix4x4_t2933234003 * ___matrix2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Material::SetFloat(System.String,System.Single)
extern "C"  void Material_SetFloat_m1926275467 (Material_t193706927 * __this, String_t* ___propertyName0, float ___value1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Material::SetFloat(System.Int32,System.Single)
extern "C"  void Material_SetFloat_m953675160 (Material_t193706927 * __this, int32_t ___nameID0, float ___value1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Material::SetInt(System.String,System.Int32)
extern "C"  void Material_SetInt_m522302436 (Material_t193706927 * __this, String_t* ___propertyName0, int32_t ___value1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Material::SetBuffer(System.String,UnityEngine.ComputeBuffer)
extern "C"  void Material_SetBuffer_m483625040 (Material_t193706927 * __this, String_t* ___name0, ComputeBuffer_t1827099467 * ___value1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Material::SetBuffer(System.Int32,UnityEngine.ComputeBuffer)
extern "C"  void Material_SetBuffer_m3022399463 (Material_t193706927 * __this, int32_t ___nameID0, ComputeBuffer_t1827099467 * ___value1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Material::SetBufferImpl(System.Int32,UnityEngine.ComputeBuffer)
extern "C"  void Material_SetBufferImpl_m3804001291 (Material_t193706927 * __this, int32_t ___nameID0, ComputeBuffer_t1827099467 * ___value1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.Material::HasProperty(System.String)
extern "C"  bool Material_HasProperty_m3511389613 (Material_t193706927 * __this, String_t* ___propertyName0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.Material::HasProperty(System.Int32)
extern "C"  bool Material_HasProperty_m3175512802 (Material_t193706927 * __this, int32_t ___nameID0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.Material::get_passCount()
extern "C"  int32_t Material_get_passCount_m1778920671 (Material_t193706927 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.Material::SetPass(System.Int32)
extern "C"  bool Material_SetPass_m2448940266 (Material_t193706927 * __this, int32_t ___pass0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Material::Internal_CreateWithShader(UnityEngine.Material,UnityEngine.Shader)
extern "C"  void Material_Internal_CreateWithShader_m4029381963 (Il2CppObject * __this /* static, unused */, Material_t193706927 * ___mono0, Shader_t2430389951 * ___shader1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Material::Internal_CreateWithMaterial(UnityEngine.Material,UnityEngine.Material)
extern "C"  void Material_Internal_CreateWithMaterial_m2907597451 (Il2CppObject * __this /* static, unused */, Material_t193706927 * ___mono0, Material_t193706927 * ___source1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Material::EnableKeyword(System.String)
extern "C"  void Material_EnableKeyword_m3724752646 (Material_t193706927 * __this, String_t* ___keyword0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Material::DisableKeyword(System.String)
extern "C"  void Material_DisableKeyword_m1204728089 (Material_t193706927 * __this, String_t* ___keyword0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
