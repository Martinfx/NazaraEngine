// Copyright (C) 2020 Jérôme Leclercq
// This file is part of the "Nazara Engine - Vulkan Renderer"
// For conditions of distribution and use, see copyright notice in Config.hpp

#include <Nazara/VulkanRenderer/VulkanBuffer.hpp>
#include <Nazara/VulkanRenderer/Debug.hpp>

namespace Nz
{
	inline VulkanBuffer::VulkanBuffer(Vk::Device& device, Buffer* /*parent*/, BufferType type) :
	m_device(device),
	m_parent(parent),
	m_type(type)
	{
	}

	inline Nz::Vk::Buffer& Nz::VulkanBuffer::GetBufferHandle()
	{
		return m_buffer;
	}
}

#include <Nazara/VulkanRenderer/DebugOff.hpp>
