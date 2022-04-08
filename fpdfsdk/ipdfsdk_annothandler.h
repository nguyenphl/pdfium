// Copyright 2016 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#ifndef FPDFSDK_IPDFSDK_ANNOTHANDLER_H_
#define FPDFSDK_IPDFSDK_ANNOTHANDLER_H_

#include <memory>

#include "core/fxcrt/fx_coordinates.h"
#include "core/fxcrt/mask.h"
#include "core/fxcrt/observed_ptr.h"
#include "core/fxcrt/unowned_ptr.h"
#include "fpdfsdk/cpdfsdk_annot.h"
#include "fpdfsdk/pwl/cpwl_wnd.h"
#include "public/fpdf_fwlevent.h"

class CPDF_Annot;
class CPDFSDK_FormFillEnvironment;
class CPDFSDK_PageView;

class IPDFSDK_AnnotHandler {
 public:
  IPDFSDK_AnnotHandler();
  virtual ~IPDFSDK_AnnotHandler();

  void SetFormFillEnvironment(CPDFSDK_FormFillEnvironment* pFormFillEnv) {
    m_pFormFillEnv = pFormFillEnv;
  }
  CPDFSDK_FormFillEnvironment* GetFormFillEnvironment() const {
    return m_pFormFillEnv.Get();
  }

  virtual std::unique_ptr<CPDFSDK_Annot> NewAnnot(
      CPDF_Annot* pAnnot,
      CPDFSDK_PageView* pPageView) = 0;

  virtual WideString GetText(CPDFSDK_Annot* pAnnot) = 0;
  virtual WideString GetSelectedText(CPDFSDK_Annot* pAnnot) = 0;
  virtual void ReplaceSelection(CPDFSDK_Annot* pAnnot,
                                const WideString& text) = 0;
  virtual bool SelectAllText(CPDFSDK_Annot* pAnnot) = 0;
  virtual bool SetIndexSelected(ObservedPtr<CPDFSDK_Annot>& pAnnot,
                                int index,
                                bool selected) = 0;
  virtual bool IsIndexSelected(ObservedPtr<CPDFSDK_Annot>& pAnnot,
                               int index) = 0;

 private:
  UnownedPtr<CPDFSDK_FormFillEnvironment> m_pFormFillEnv;
};

#endif  // FPDFSDK_IPDFSDK_ANNOTHANDLER_H_
