// Copyright 2016 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#ifndef FPDFSDK_CPDFSDK_BAANNOTHANDLER_H_
#define FPDFSDK_CPDFSDK_BAANNOTHANDLER_H_

#include <memory>

#include "core/fxcrt/fx_coordinates.h"
#include "fpdfsdk/ipdfsdk_annothandler.h"

class CPDF_Annot;
class CPDFSDK_Annot;
class CPDFSDK_PageView;

class CPDFSDK_BAAnnotHandler final : public IPDFSDK_AnnotHandler {
 public:
  CPDFSDK_BAAnnotHandler();
  ~CPDFSDK_BAAnnotHandler() override;

  // IPDFSDK_AnnotHandler:
  std::unique_ptr<CPDFSDK_Annot> NewAnnot(CPDF_Annot* pAnnot,
                                          CPDFSDK_PageView* pPageView) override;

  WideString GetText(CPDFSDK_Annot* pAnnot) override;
  WideString GetSelectedText(CPDFSDK_Annot* pAnnot) override;
  void ReplaceSelection(CPDFSDK_Annot* pAnnot, const WideString& text) override;
  bool SelectAllText(CPDFSDK_Annot* pAnnot) override;

  bool SetIndexSelected(ObservedPtr<CPDFSDK_Annot>& pAnnot,
                        int index,
                        bool selected) override;
  bool IsIndexSelected(ObservedPtr<CPDFSDK_Annot>& pAnnot, int index) override;
};

#endif  // FPDFSDK_CPDFSDK_BAANNOTHANDLER_H_
