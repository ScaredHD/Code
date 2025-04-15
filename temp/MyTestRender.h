#pragma once

#include "SceneRendering.h"
#include "RenderGraphBuilder.h"
#include "ScreenPass.h"

void AddMyTestPass(FRDGBuilder& GraphBuilder, const FViewInfo& View, FScreenPassTexture SceneColor, const FVector4f& SimpleColor);