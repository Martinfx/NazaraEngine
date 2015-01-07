// Copyright (C) 2014 Jérôme Leclercq
// This file is part of the "Nazara Engine - Core module"
// For conditions of distribution and use, see copyright notice in Config.hpp

#pragma once

#ifndef NAZARA_RESOURCE_HPP
#define NAZARA_RESOURCE_HPP

#include <Nazara/Prerequesites.hpp>
#include <atomic>
#include <unordered_map>

#if NAZARA_CORE_THREADSAFE && NAZARA_THREADSAFETY_RESOURCE
	#include <Nazara/Core/ThreadSafety.hpp>
#else
	#include <Nazara/Core/ThreadSafetyOff.hpp>
#endif

class NzResourceConstListener;
class NzResourceListener;

class NAZARA_API NzResource
{
	public:
		NzResource(bool persistent = true);
		virtual ~NzResource();

		void AddResourceConstListener(const NzResourceConstListener* listener, int index = 0) const;
		void AddResourceListener(NzResourceListener* listener, int index = 0) const;
		void AddResourceReference() const;

		unsigned int GetResourceReferenceCount() const;

		bool IsPersistent() const;

		void RemoveResourceConstListener(const NzResourceConstListener* listener) const;
		void RemoveResourceListener(NzResourceListener* listener) const;
		bool RemoveResourceReference() const;

		bool SetPersistent(bool persistent = true, bool checkReferenceCount = false);

	protected:
		void NotifyCreated();
		void NotifyDestroy();
		void NotifyModified(unsigned int code);

	private:
		using ResourceConstListenerMap = std::unordered_map<const NzResourceConstListener*, std::pair<int, unsigned int>>;
		using ResourceListenerMap = std::unordered_map<NzResourceListener*, std::pair<int, unsigned int>>;

		void RemoveResourceConstListenerIterator(ResourceConstListenerMap::iterator iterator) const;
		void RemoveResourceListenerIterator(ResourceListenerMap::iterator iterator) const;

		NazaraMutexAttrib(m_mutex, mutable)

		// Je fais précéder le nom par 'resource' pour éviter les éventuels conflits de noms
		mutable ResourceConstListenerMap m_resourceConstListeners;
		mutable ResourceListenerMap m_resourceListeners;
		        std::atomic_bool m_resourcePersistent;
		mutable std::atomic_uint m_resourceReferenceCount;
		        bool m_resourceListenersLocked;
};

#endif // NAZARA_RESOURCE_HPP
