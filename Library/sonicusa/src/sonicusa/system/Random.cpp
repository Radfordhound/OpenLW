// TODO: The name of this file is correct, but the path was guessed!
#include "pch.h"
#include "sonicusa/system/Random.h"

namespace SonicUSA
{
namespace System
{
MtRandom::~MtRandom()
{
    // TODO
}

void MtRandom::Init(unsigned int seed)
{
    // TODO
}

void MtRandom::InitByArray(const unsigned int* param_1, int param_2)
{
    // TODO
}

unsigned int MtRandom::Rand()
{
    // TODO
	return 0;
}

Random Random::Instance = Random(0xbaded9a7);

Random::Random()
{
    // TODO
}

Random::Random(unsigned int seed)
{
    // TODO
}

Random::~Random()
{
    // TODO
}

std::int32_t Random::genrand_int32()
{
    return static_cast<std::int32_t>(m_MtRand.Rand());
}
} // System
} // SonicUSA
