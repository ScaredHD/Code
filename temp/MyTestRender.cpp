#include "MyTestRender.h"

#include "ShaderParameterStruct.h"
#include "PixelShaderUtils.h"

class FMyTestVS : public FGlobalShader
{
public:
	DECLARE_GLOBAL_SHADER(FMyTestVS);
};

IMPLEMENT_GLOBAL_SHADER(FMyTestVS, "/Engine/Private/MyShaders/MyTestShaders.usf", "MainVS", SF_Vertex);

class FMyTestPS : public FGlobalShader
{
public:
	DECLARE_GLOBAL_SHADER(FMyTestPS);
	SHADER_USE_PARAMETER_STRUCT(FMyTestPS, FGlobalShader);

	BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
		SHADER_PARAMETER(FVector2f, ViewportSize)
		SHADER_PARAMETER_RDG_TEXTURE(Texture2D, SceneColorTexture)
		SHADER_PARAMETER_RDG_TEXTURE_SRV(Texture2D, SceneColorSRV)
		SHADER_PARAMETER_SAMPLER(SamplerState, SceneColorSampler)
		SHADER_PARAMETER(FVector4f, SimpleColor)
		RENDER_TARGET_BINDING_SLOTS()
	END_SHADER_PARAMETER_STRUCT()
};

IMPLEMENT_GLOBAL_SHADER(FMyTestPS, "/Engine/Private/MyShaders/MyTestShaders.usf", "MainPS", SF_Pixel);

void AddMyTestPass(FRDGBuilder& GraphBuilder, const FViewInfo& View, FScreenPassTexture SceneColor, const FVector4f& SimpleColor)
{
	auto* ShaderParameters = GraphBuilder.AllocParameters<FMyTestPS::FParameters>();

	ShaderParameters->ViewportSize = FVector2f{static_cast<float>(SceneColor.ViewRect.Width()), static_cast<float>(SceneColor.ViewRect.Height())};
	ShaderParameters->SceneColorTexture = SceneColor.Texture;
	ShaderParameters->SceneColorSRV = GraphBuilder.CreateSRV(FRDGTextureSRVDesc::Create(SceneColor.Texture));
	ShaderParameters->SceneColorSampler = TStaticSamplerState<SF_Point>::GetRHI();
	ShaderParameters->SimpleColor = SimpleColor;
	ShaderParameters->RenderTargets[0] = FRenderTargetBinding(SceneColor.Texture, ERenderTargetLoadAction::ELoad);

	FPixelShaderUtils::AddFullscreenPass(
		GraphBuilder,
		View.ShaderMap,
		RDG_EVENT_NAME("MyTestPass"),
		TShaderMapRef<FMyTestPS>(View.ShaderMap),
		ShaderParameters,
		View.ViewRect
	);
}
