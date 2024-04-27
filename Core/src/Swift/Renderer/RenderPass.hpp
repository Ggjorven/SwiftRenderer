#pragma once

#include "Swift/Core/Core.hpp"
#include "Swift/Utils/Utils.hpp"

#include "Swift/Renderer/Image.hpp"

#include <glm/glm.hpp>

namespace Swift
{

	class CommandBuffer;

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Specification 
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	enum class ColourLoadOperation : uint8_t
	{
		Load = 0, Clear = 1
	};
	DEFINE_BITWISE_OPS(ColourLoadOperation)

	struct RenderPassSpecification
	{
	public:
		std::vector<Ref<Image2D>> ColourAttachment = { };
		ColourLoadOperation ColourLoadOp = ColourLoadOperation::Clear;
		glm::vec4 ColourClearColour = { 0.0f, 0.0f, 0.0f, 1.0f };

		Ref<Image2D> DepthAttachment = nullptr;

		ImageLayout PreviousImageLayout = ImageLayout::Undefined;
		ImageLayout FinalImageLayout = ImageLayout::Presentation;
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// RenderPass 
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	class RenderPass
	{
	public:
		RenderPass() = default;
		virtual ~RenderPass() = default;

		virtual void Begin() = 0;
		virtual void End() = 0;
		virtual void Submit(const std::vector<Ref<CommandBuffer>>& waitOn = { }) = 0;

		virtual void Resize(uint32_t width, uint32_t height) = 0;

		virtual Ref<CommandBuffer> GetCommandBuffer() = 0;

		static Ref<RenderPass> Create(RenderPassSpecification specs, Ref<CommandBuffer> commandBuffer);
	};

}