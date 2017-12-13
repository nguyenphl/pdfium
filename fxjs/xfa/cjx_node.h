// Copyright 2017 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#ifndef FXJS_XFA_CJX_NODE_H_
#define FXJS_XFA_CJX_NODE_H_

#include <memory>
#include <vector>

#include "core/fxcrt/unowned_ptr.h"
#include "fxjs/CJX_Define.h"
#include "fxjs/xfa/cjx_object.h"
#include "fxjs/xfa/cjx_tree.h"
#include "xfa/fxfa/fxfa_basic.h"

class CXFA_LayoutItem;
class CXFA_Node;
class CXFA_WidgetData;

class CJX_Node : public CJX_Tree {
 public:
  explicit CJX_Node(CXFA_Node* node);
  ~CJX_Node() override;

  CXFA_Node* GetXFANode();
  const CXFA_Node* GetXFANode() const;

  void SetLayoutItem(CXFA_LayoutItem* item) { layout_item_ = item; }
  CXFA_LayoutItem* GetLayoutItem() const { return layout_item_.Get(); }

  void SetCalcRecursionCount(size_t count) { calc_recursion_count_ = count; }
  size_t GetCalcRecursionCount() const { return calc_recursion_count_; }

  pdfium::Optional<WideString> TryNamespace();

  void ThrowMissingPropertyException(const WideString& obj,
                                     const WideString& prop) const;
  void ThrowTooManyOccurancesException(const WideString& obj) const;

  int32_t InstanceManager_SetInstances(int32_t iDesired);
  int32_t InstanceManager_MoveInstance(int32_t iTo, int32_t iFrom);

  JS_METHOD(applyXSL, CJX_Node);
  JS_METHOD(assignNode, CJX_Node);
  JS_METHOD(clone, CJX_Node);
  JS_METHOD(getAttribute, CJX_Node);
  JS_METHOD(getElement, CJX_Node);
  JS_METHOD(isPropertySpecified, CJX_Node);
  JS_METHOD(loadXML, CJX_Node);
  JS_METHOD(saveFilteredXML, CJX_Node);
  JS_METHOD(saveXML, CJX_Node);
  JS_METHOD(setAttribute, CJX_Node);
  JS_METHOD(setElement, CJX_Node);

  void Script_NodeClass_Ns(CFXJSE_Value* pValue,
                           bool bSetting,
                           XFA_Attribute eAttribute);
  void Script_NodeClass_Model(CFXJSE_Value* pValue,
                              bool bSetting,
                              XFA_Attribute eAttribute);
  void Script_NodeClass_IsContainer(CFXJSE_Value* pValue,
                                    bool bSetting,
                                    XFA_Attribute eAttribute);
  void Script_NodeClass_IsNull(CFXJSE_Value* pValue,
                               bool bSetting,
                               XFA_Attribute eAttribute);
  void Script_NodeClass_OneOfChild(CFXJSE_Value* pValue,
                                   bool bSetting,
                                   XFA_Attribute eAttribute);
  void Script_ModelClass_Context(CFXJSE_Value* pValue,
                                 bool bSetting,
                                 XFA_Attribute eAttribute);
  void Script_ModelClass_AliasNode(CFXJSE_Value* pValue,
                                   bool bSetting,
                                   XFA_Attribute eAttribute);
  void Script_Delta_CurrentValue(CFXJSE_Value* pValue,
                                 bool bSetting,
                                 XFA_Attribute eAttribute);
  void Script_Delta_SavedValue(CFXJSE_Value* pValue,
                               bool bSetting,
                               XFA_Attribute eAttribute);
  void Script_Delta_Target(CFXJSE_Value* pValue,
                           bool bSetting,
                           XFA_Attribute eAttribute);
  void Script_Field_Length(CFXJSE_Value* pValue,
                           bool bSetting,
                           XFA_Attribute eAttribute);
  void Script_Field_EditValue(CFXJSE_Value* pValue,
                              bool bSetting,
                              XFA_Attribute eAttribute);
  void Script_Field_FormattedValue(CFXJSE_Value* pValue,
                                   bool bSetting,
                                   XFA_Attribute eAttribute);
  void Script_Field_ParentSubform(CFXJSE_Value* pValue,
                                  bool bSetting,
                                  XFA_Attribute eAttribute);
  void Script_Field_SelectedIndex(CFXJSE_Value* pValue,
                                  bool bSetting,
                                  XFA_Attribute eAttribute);
  void Script_ExclGroup_DefaultAndRawValue(CFXJSE_Value* pValue,
                                           bool bSetting,
                                           XFA_Attribute eAttribute);
  void Script_ExclGroup_ErrorText(CFXJSE_Value* pValue,
                                  bool bSetting,
                                  XFA_Attribute eAttribute);
  void Script_ExclGroup_Transient(CFXJSE_Value* pValue,
                                  bool bSetting,
                                  XFA_Attribute eAttribute);

  void Script_Subform_InstanceManager(CFXJSE_Value* pValue,
                                      bool bSetting,
                                      XFA_Attribute eAttribute);
  void Script_Subform_Locale(CFXJSE_Value* pValue,
                             bool bSetting,
                             XFA_Attribute eAttribute);
  void Script_InstanceManager_Count(CFXJSE_Value* pValue,
                                    bool bSetting,
                                    XFA_Attribute eAttribute);
  void Script_InstanceManager_Max(CFXJSE_Value* pValue,
                                  bool bSetting,
                                  XFA_Attribute eAttribute);
  void Script_InstanceManager_Min(CFXJSE_Value* pValue,
                                  bool bSetting,
                                  XFA_Attribute eAttribute);

  void Script_Occur_Max(CFXJSE_Value* pValue,
                        bool bSetting,
                        XFA_Attribute eAttribute);
  void Script_Occur_Min(CFXJSE_Value* pValue,
                        bool bSetting,
                        XFA_Attribute eAttribute);

  void Script_Form_Checksum(CFXJSE_Value* pValue,
                            bool bSetting,
                            XFA_Attribute eAttribute);

  void Script_Packet_Content(CFXJSE_Value* pValue,
                             bool bSetting,
                             XFA_Attribute eAttribute);

  void Script_Source_Db(CFXJSE_Value* pValue,
                        bool bSetting,
                        XFA_Attribute eAttribute);
  void Script_Xfa_This(CFXJSE_Value* pValue,
                       bool bSetting,
                       XFA_Attribute eAttribute);
  void Script_Handler_Version(CFXJSE_Value* pValue,
                              bool bSetting,
                              XFA_Attribute eAttribute);
  void Script_SubmitFormat_Mode(CFXJSE_Value* pValue,
                                bool bSetting,
                                XFA_Attribute eAttribute);
  void Script_Extras_Type(CFXJSE_Value* pValue,
                          bool bSetting,
                          XFA_Attribute eAttribute);
  void Script_Encrypt_Format(CFXJSE_Value* pValue,
                             bool bSetting,
                             XFA_Attribute eAttribute);
  void Script_Script_Stateless(CFXJSE_Value* pValue,
                               bool bSetting,
                               XFA_Attribute eAttribute);

 protected:
  int32_t execSingleEventByName(const WideStringView& wsEventName,
                                XFA_Element eType);

 private:
  UnownedPtr<CXFA_LayoutItem> layout_item_;
  size_t calc_recursion_count_ = 0;
  static const CJX_MethodSpec MethodSpecs[];
};

#endif  // FXJS_XFA_CJX_NODE_H_
