/*
 * Copyright 2018 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/**************************************************************************************************
 *** This file was autogenerated from GrConstColorProcessor.fp; do not modify.
 **************************************************************************************************/
#ifndef GrConstColorProcessor_DEFINED
#define GrConstColorProcessor_DEFINED
#include "SkTypes.h"
#if SK_SUPPORT_GPU
#include "GrFragmentProcessor.h"
#include "GrCoordTransform.h"
class GrConstColorProcessor : public GrFragmentProcessor {
public:
    enum class InputMode { kIgnore = 0, kLast = 2, kModulateA = 2, kModulateRGBA = 1 };

    static const int kInputModeCnt = (int)InputMode::kLast + 1;

    static OptimizationFlags OptFlags(GrColor4f color, InputMode mode) {
        OptimizationFlags flags = kConstantOutputForConstantInput_OptimizationFlag;
        if (mode != InputMode::kIgnore) {
            flags |= kCompatibleWithCoverageAsAlpha_OptimizationFlag;
        }
        if (color.isOpaque()) {
            flags |= kPreservesOpaqueInput_OptimizationFlag;
        }
        return flags;
    }

    GrColor4f constantOutputForConstantInput(GrColor4f input) const override {
        switch (fMode) {
            case InputMode::kIgnore:
                return fColor;
            case InputMode::kModulateA:
                return fColor.mulByScalar(input.fRGBA[3]);
            case InputMode::kModulateRGBA:
                return fColor.modulate(input);
        }
        SK_ABORT("Unexpected mode");
        return GrColor4f::TransparentBlack();
    }
    GrColor4f color() const { return fColor; }
    InputMode mode() const { return fMode; }
    static std::unique_ptr<GrFragmentProcessor> Make(GrColor4f color, InputMode mode) {
        return std::unique_ptr<GrFragmentProcessor>(new GrConstColorProcessor(color, mode));
    }
    GrConstColorProcessor(const GrConstColorProcessor& src);
    std::unique_ptr<GrFragmentProcessor> clone() const override;
    const char* name() const override { return "ConstColorProcessor"; }

private:
    GrConstColorProcessor(GrColor4f color, InputMode mode)
            : INHERITED(kGrConstColorProcessor_ClassID, (OptimizationFlags)OptFlags(color, mode))
            , fColor(color)
            , fMode(mode) {}
    GrGLSLFragmentProcessor* onCreateGLSLInstance() const override;
    void onGetGLSLProcessorKey(const GrShaderCaps&, GrProcessorKeyBuilder*) const override;
    bool onIsEqual(const GrFragmentProcessor&) const override;
    GR_DECLARE_FRAGMENT_PROCESSOR_TEST
    GrColor4f fColor;
    InputMode fMode;
    typedef GrFragmentProcessor INHERITED;
};
#endif
#endif
