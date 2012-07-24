// Copyright (C) 2012 J�r�me Leclercq
// This file is part of the "Nazara Engine".
// For conditions of distribution and use, see copyright notice in Config.hpp

#pragma once

#ifndef NAZARA_ENUMS_CORE_HPP
#define NAZARA_ENUMS_CORE_HPP

enum nzEndianness
{
	nzEndianness_BigEndian,
	nzEndianness_LittleEndian,
	nzEndianness_Unknown
};

enum nzErrorType
{
	nzErrorType_AssertFailed,
	nzErrorType_Internal,
	nzErrorType_Normal,
	nzErrorType_Warning
};

#endif // NAZARA_ENUMS_CORE_HPP
