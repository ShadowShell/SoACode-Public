/// 
///  BloomRenderStage.h
///  Seed of Andromeda
///
///  Created by Isaque Dutra on 2 June 2015
///  Copyright 2015 Regrowth Studios
///  All Rights Reserved
///  
///  This file implements a bloom render stage for
///  MainMenuRenderer.
///

#pragma once

#ifndef BloomRenderStage_h__
#define BloomRenderStage_h__

#include <Vorb/graphics/GLRenderTarget.h>
#include <Vorb/graphics/FullQuadVBO.h>
#include <Vorb/graphics/GLProgram.h>
#include "ShaderLoader.h"
#include "LoadContext.h"

#include "IRenderStage.h"

#define BLOOM_LUMA_THRESHOLD 0.75f	// Threshold for filtering image luma for bloom bluring
#define BLOOM_GAUSSIAN_N 20	// Radius number for gaussian blur. Has to be less than 50.
#define BLOOM_GAUSSIAN_VARIANCE 36.0f	// Gaussian variance for blur pass

#define TASK_WORK 4		// (arbitrary) weight of task
#define TOTAL_TASK 4	// number of tasks
#define TOTAL_WORK TOTAL_TASK * TASK_WORK

#define BLOOM_TEXTURE_SLOT_COLOR 0  // texture slot to bind color texture which luma info will be extracted
#define BLOOM_TEXTURE_SLOT_LUMA 0  // texture slot to bind luma texture
#define BLOOM_TEXTURE_SLOT_BLUR 1  // texture slot to bind blur texture

typedef enum {
    BLOOM_RENDER_STAGE_LUMA,
    BLOOM_RENDER_STAGE_GAUSSIAN_FIRST,
    BLOOM_RENDER_STAGE_GAUSSIAN_SECOND
} BloomRenderStagePass;

class BloomRenderStage : public IRenderStage {
public:

    void init(vui::GameWindow* window, StaticLoadContext& context) override;

    void load(StaticLoadContext& context) override;

    void hook(vg::FullQuadVBO* quad);

    void dispose(StaticLoadContext& context) override;

    /// Draws the render stage
    void render(const Camera* camera = nullptr) override;

private:
    vg::GLProgram m_program_luma, m_program_gaussian_first, m_program_gaussian_second;
    vg::FullQuadVBO* m_quad; ///< For use in processing through data
    vg::GLRenderTarget m_fbo1, m_fbo2;
    float gauss(int i, float sigma2);
    void render(BloomRenderStagePass stage);

};

#endif // BloomRenderStage_h__