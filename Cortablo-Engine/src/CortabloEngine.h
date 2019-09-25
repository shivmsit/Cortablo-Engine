// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#pragma once

#include <iostream>
#include <unordered_map>

// *****************| Cortablo-Engine |*****************
// * Render-API										   *
// *****************************************************

#define RENDERAPI_OPENGL 0x0

#define RENDER_API RENDERAPI_OPENGL

namespace CortabloEngine
{
	class EngineParameters
	{
	private:
		template <typename T>
		static inline std::unordered_map<const char*, T> m_Values = { };
	public:
		template <typename T>
		static void Set(const char* name, T value)
		{
			m_Values<T>[name] = value;
		}

		template <typename T>
		static T Get(const char* name)
		{
			return m_Values<T>[name];
		}

		template <typename T>
		static void Remove(const char* name)
		{
			delete m_Values<T>[name];
		}
	};

	class GameParameters
	{
	private:
		template <typename T>
		static inline std::unordered_map<const char*, T> m_Values = { };
	public:
		template <typename T>
		static void Set(const char* name, T value)
		{
			m_Values<T>[name] = value;
		}

		template <typename T>
		static T Get(const char* name)
		{
			return m_Values<T>[name];
		}

		template <typename T>
		static void Remove(const char* name)
		{
			delete m_Values<T>[name];
		}
	};
		
	class LaunchParameters
	{
	private:
		static inline std::unordered_map<std::string, const char*> m_Values = { };
	public:
		static bool Check(const std::string& name)
		{
			if (m_Values.find(name) != m_Values.end())
				return true;

			return false;
		}

		static void Set(const std::string& name, const char* value)
		{
			m_Values[name] = value;
		}

		static const char* Get(const std::string& name)
		{
			return m_Values[name];
		}

		static void Remove(const std::string& name)
		{
			delete m_Values[name];
		}
	};
}

