#include "ComplexNoiseBase.hpp"
#include <cmath>

NzComplexNoiseBase::NzComplexNoiseBase()
{
    m_parametersModified = true;
    m_lacunarity = 5.0f;
    m_hurst = 1.2f;
    m_octaves = 3.0f;
}

void NzComplexNoiseBase::SetLacunarity(float lacunarity)
{
    if(lacunarity != m_lacunarity)
    {
        m_lacunarity = lacunarity;
        m_parametersModified = true;
    }
}

void NzComplexNoiseBase::SetHurstParameter(float h)
{
    if(h != m_hurst)
    {
        m_hurst = h;
        m_parametersModified = true;
    }
}

void NzComplexNoiseBase::SetOctavesNumber(float octaves)
{
    if(octaves != m_octaves && octaves < 30)
    {
        m_octaves = octaves;
        m_parametersModified = true;
    }
}

void NzComplexNoiseBase::RecomputeExponentArray()
{
    if(m_parametersModified)
    {
        float frequency = 1.0;
        m_sum = 0.f;
        for (int i(0) ; i < m_octaves; ++i)
        {
            exponent_array[i] = std::pow( frequency, -m_hurst );
            frequency *= m_lacunarity;

            m_sum += exponent_array[i];

        }
        m_parametersModified = false;
    }
}


NzComplexNoiseBase::~NzComplexNoiseBase()
{
    //dtor
}
